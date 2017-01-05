#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Menu.h"
#include "InGameMenu.h"
#include "Map.h"
#include "Item.h"
#include "ghost.h"
#include "Player.h"
#include "yssimplesound.h"
#include "Fog.h"

int main(void)
{
	int level;
	int ghost_num;
	int nItem = 3;
	int rangeX, rangeY;
	GameMenu menu;
	Map map; 
	Item item[10];
	Player* game_player = NULL;
	Fog fog;
	bool terminate;
	bool backdoor = false;
	bool state = true;
	
	YsSoundPlayer player;
	player.MakeCurrent();
	player.Start();
	YsSoundPlayer::SoundData Scarysong,death,victory;
	if (YSOK != Scarysong.LoadWav("Scarysong.wav") &&
		YSOK != Scarysong.LoadWav("datafiles/Scarysong.wav"))
	{
		printf("Error!  Cannot load Scarysong.wav!\n");
	}
	if (YSOK != death.LoadWav("death.wav") &&
		YSOK != death.LoadWav("datafiles/death.wav"))
	{
		printf("Error!  Cannot load death.wav!\n");
	}
	if (YSOK != victory.LoadWav("victory.wav") &&
		YSOK != victory.LoadWav("datafiles/victory.wav"))
	{
		printf("Error!  Cannot load victory.wav!\n");
	}

	FsOpenWindow(0, 0, 1000, 800, 1);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	for(;;)
	{
		terminate = false;
		state = true;
		player.PlayBackground(Scarysong);
		player.KeepPlaying();
		level = menu.Run();//get the choice from menu

		//based on the choice, generate different num of ghosts, and initialize ghost and item array
		Ghost *ghost;
		switch (level) {
		case 1:
			ghost_num = 2;
			nItem = 1;
			ghost = new Ghost[ghost_num];
			ghost[0].initialize(50, 620);
			ghost[1].initialize(700, 240);
			rangeX = 140;
			rangeY = 140;
			break;
		case 2:
			ghost_num = 3;
			nItem = 2;
			ghost = new Ghost[ghost_num];
			ghost[0].initialize(40, 180);
			ghost[1].initialize(40, 450);
			ghost[2].initialize(720, 480);
			rangeX = 140;
			rangeY = 140;
			break;
		case 3:
			ghost_num = 4;
			nItem = 3;
			ghost = new Ghost[ghost_num];
			ghost[0].initialize(150, 380);
			ghost[1].initialize(60, 700);
			ghost[2].initialize(560, 200);
			ghost[3].initialize(480, 690);
			rangeX = 100;
			rangeY = 100;
			break;
		}		
		
		for (int j = 0; j < nItem; j++)
		{
			item[j].Initialize();
			item[j].SetDisappearTime(level);
			item[j].SetAppearTime(level);
		}

		//base on the choice initialize the player for different locations
		game_player = new Player(map.GetStartX(level), map.GetStartY(), map.GetBlockWidth(level));
		fog.Reset(level);
		if (FSKEY_ENTER == menu.lastKey)
		{
			InGameMenu igmenu(level);
			/*igmenu.Display(player.GetLife(), player.GetItem());*/

			while(!terminate) {
				FsPollDevice();
				auto key = FsInkey();
				int player_sig = 0;
				switch (key) {
					case FSKEY_ESC:
						terminate = true;
						break;
					case FSKEY_LEFT:
					    player_sig = 1;
					    break;
					case FSKEY_UP:
					    player_sig = 2;
					    break;
					case FSKEY_RIGHT:
					    player_sig = 3;
					    break;
					case FSKEY_DOWN:
					    player_sig = 4;
					    break;
					case FSKEY_B:
						backdoor = true;
						break;
					case FSKEY_Y:
						backdoor = false;
						break;
					case FSKEY_W:
						game_player->BackDoor(map.GetEndX(level) - 1, map.GetEndY(level) - 1);
						break;
					case FSKEY_F:
						fog.Cheat(level);
						break;
					case FSKEY_G:
						fog.Reset(level);
						break;
				}

				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				map.DrawBackground();
				igmenu.Display(game_player->GetHealth()); //Use this line for displaying player status (with proper function). igmenu(int life, int item)
				map.Draw(level);

				/*insert the player constructor takes the 
				level as input to initialize the position*/
				game_player->Draw(level);

				for (int i = 0; i < ghost_num; i++) {
					if (!(backdoor)) {
						ghost[i].move(game_player->GetX() * map.GetBlockWidth(level), game_player->GetY() * map.GetBlockWidth(level), rangeX, rangeY);
					}
					ghost[i].Drawghost(level);
				}

				for (int j = 0; j < nItem; j++)
				{
					if (item[j].state == 0)
					{
						item[j].disappearTime = item[j].disappearTime - 1;
						if (item[j].disappearTime == 0)
						{
							item[j].state = 1;
							item[j].Generate(level);
							item[j].disappearTime = item[j].originalDisappearTime;
						}
					}
					if (item[j].state == 1)
					{
						item[j].appearTime = item[j].appearTime - 1;
						if (item[j].appearTime == 0)
						{
							item[j].state = 0;
							item[j].appearTime = item[j].originalAppearTime;
						}
					}
					if (0 != item[j].state)
					{
						item[j].DrawItem();
					}
				}

				//fog.Reset(level);
				fog.SetEmpty(game_player->GetX(), game_player->GetY(), level);
				fog.Draw(level);

				if (state == true)
				{
					game_player->Move(player_sig);

					for (int i = 0; i < ghost_num; i++)
					{
						game_player->CheckHit(ghost[i].GetX(), ghost[i].GetY(), 3);
					}
				}
				game_player->CheckHitWall(map.CheckHit(game_player->GetX(), game_player->GetY(), level), player_sig);

				for (int i = 0; i < nItem; i++) {
					if (item[i].state == 1) {
						if (game_player->CheckHit(item[i].GetX()*map.GetBlockWidth(level), item[i].GetY()* map.GetBlockWidth(level), 1) == true) {
							item[i].state = 0;
						}
					}
				}
				
				player_sig = 0;
				if (game_player->CheckDestination(map.GetEndX(level),map.GetEndY(level))) {
					state = false;
					player.PlayOneShot(victory);
					player.Stop(Scarysong);
					map.Victory();
					terminate = true;
					player.PlayBackground(Scarysong);
					player.KeepPlaying();
				}

				if (game_player->GetHealth() <= 0) {
					state = false;
					player.PlayOneShot(death);
					player.Stop(Scarysong);
					map.Death();
					terminate = true;
					player.PlayBackground(Scarysong);
					player.KeepPlaying();
				}
				FsSwapBuffers();
				FsSleep(25);
			}
		}

		if (FSKEY_ESC == menu.lastKey)
		{
			break;
		}
	}

	FsCloseWindow();
	return 0;
}