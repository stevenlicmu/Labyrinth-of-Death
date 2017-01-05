//
//  Player.h
//  Player
//
#include "GameObject.h"


#ifndef Player_h
#define Player_h


class Player : public GameObject{
private:
	int health = 3;
	int width = 0;
	int item = 0;
	int init_x = 0, init_y = 0;
	void SetPlace();
public:
	Player(int inputx, int inputy,int block_size);


	bool CheckHit(int xx, int yy, int category);
	void CheckHitWall(bool hitted, int signal);
    bool CheckDestination(int des_x, int des_y);
	
	void Move(int signal);

	int GetItem();
	int GetHealth();
	int GetWidth();
	void Draw(int level);
	void BackDoor(int inputx, int inputy);
};





#endif /* Player_h */
#pragma once