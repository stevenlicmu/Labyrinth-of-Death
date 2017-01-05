#include <stdio.h>
#include <stdlib.h>
#include "fssimplewindow.h"
#include "Map.h"
#include "ysglfontdata.h"
#include "yspng.h"

/* DrawPixel: draw every block pixel. */
void DrawPixel(int x, int y, char state, int blockWid, int choice)
{
	if (choice == 1)
	{
		glColor3ub(100, 40, 0);
	}
	else if (choice == 0)
	{
		glColor3ub(0, 0, 0);
	}
	if (state == '0')
	{
		glBegin(GL_QUADS);
		glVertex2d(200 + blockWid * x, blockWid * y);
		glVertex2d(200 + blockWid * x + blockWid, blockWid * y);
		glVertex2d(200 + blockWid * x + blockWid, (blockWid * y + blockWid));
		glVertex2d(200 + blockWid * x, (blockWid * y + blockWid));
		glEnd();

		if (choice == 1)
		{
			glColor3ub(30, 30, 30);
			glLineWidth(2);
			glBegin(GL_LINES);
			glVertex2d(200 + blockWid * x + 0.25*blockWid, blockWid * y);
			glVertex2d(200 + blockWid * x + 0.25*blockWid, blockWid * y + 0.25*blockWid);
			glVertex2d(200 + blockWid * x + 0.75*blockWid, blockWid * y);
			glVertex2d(200 + blockWid * x + 0.75*blockWid, blockWid * y + 0.25*blockWid);

			glVertex2d(200 + blockWid * x + 0.25*blockWid, blockWid * y + 0.5*blockWid);
			glVertex2d(200 + blockWid * x + 0.25*blockWid, blockWid * y + 0.75*blockWid);
			glVertex2d(200 + blockWid * x + 0.75*blockWid, blockWid * y + 0.5*blockWid);
			glVertex2d(200 + blockWid * x + 0.75*blockWid, blockWid * y + 0.75*blockWid);

			glVertex2d(200 + blockWid * x + 0.5*blockWid, blockWid * y + 0.25*blockWid);
			glVertex2d(200 + blockWid * x + 0.5*blockWid, blockWid * y + 0.5*blockWid);
			glVertex2d(200 + blockWid * x + 0.5*blockWid, blockWid * y + 0.75*blockWid);
			glVertex2d(200 + blockWid * x + 0.5*blockWid, blockWid * y + blockWid);

			glVertex2d(200 + blockWid * x, blockWid * y + 0.25*blockWid);
			glVertex2d(200 + blockWid * x + blockWid, blockWid * y + 0.25*blockWid);
			glVertex2d(200 + blockWid * x, blockWid * y + 0.5*blockWid);
			glVertex2d(200 + blockWid * x + blockWid, blockWid * y + 0.5*blockWid);
			glVertex2d(200 + blockWid * x, blockWid * y + 0.75*blockWid);
			glVertex2d(200 + blockWid * x + blockWid, blockWid * y + 0.75*blockWid);

			glVertex2d(200 + blockWid * x, blockWid * y);
			glVertex2d(200 + blockWid * x + blockWid, blockWid * y);
			glVertex2d(200 + blockWid * x, blockWid * y + blockWid);
			glVertex2d(200 + blockWid * x + blockWid, blockWid * y + blockWid);

			glEnd();
		}
	}
}

const char Map::map1[290] =
{
	"000 0000000000000"
	"0 0   0   0     0"
	"0 000 0 0 000 0 0"
	"0 0 0 0 0   0 0 0"
	"0 0 0 0 000 0 000"
	"0       0 0 0   0"
	"0 000 000 000 000"
	"0 0 0         0 0"
	"000 0000000 0 0 0"
	"0       0 0 0   0"
	"0 000 000 000   0"
	"0 0 0 0       0 0"
	"000 0 000 000 000"
	"0         0 0   0"
	"000 0000000 000 0"
	"0     0         0"
	"0000000000000 000"
};

const char Map::map2[442] =
{ 
	"0000000000000 0000000"
	"0             0     0"
	"0 0 000 0000000 0 0 0"
	"0 0 0   0       0 0 0"
	"0 0 00000 0000000 0 0"
	"0 0     0   0   0 0 0"
	"0000000 000 0 000 000"
	"0           0   0   0"
	"0 0 0000000 0 0 000 0"
	"0 0 0       0 0 0   0"
	"0 000 000000000 0 0 0"
	"0   0           0 0 0"
	"0 0 000 000000000 0 0"
	"0 0   0 0       0 0 0"
	"000 0 0 0 00000 0 000"
	"0   0 0 0 0     0   0"
	"0 00000 0 0 000 000 0"
	"0       0 0 0   0   0"
	"0 0000000 0 0 000 0 0"
	"0   0     0 0     0 0"
	"00000 000000000000000"
};

const char Map::map3[1445] =
{
	"0 000000000000000000000000000000000000"
	"0             0 0 0       0   0     00"
	"0 0 000000000 0 0 0 00000 0 0 0 0 0 00"
	"0 0       0 0 0 0       0   0 0 0 0 00"
	"0 00000 0 0 0 0 0000000000000 0 0 0 00"
	"0     0 0 0 0 0   0             0 0 00"
	"00000 0 0 0   000 0 00000 0000000 0 00"
	"0     0 0 0   0   0 0   0 0 0     0 00"
	"0 0000000 00000 000 0 0 0 0 0 00000 00"
	"0   0 0       0 0   0 0 0 0 0 0     00"
	"000 0 0 00000 0 0 000 0 0 0 0 0 000000"
	"0   0 0 0   0 0 0 0 0 0 0 0   0     00"
	"0 0 0   0 0 0 0 0 0   0 0 000000000 00"
	"0 0 0   0 0 0 0 0 0   0 0 0   0   0 00"
	"0 0 00000 0 0 0 0 00000 0 0   0 000 00"
	"0 0       0 0   0 0     0 0 0 0     00"
	"0 000000000 00000 0 00000 0 0 00000 00"
	"0 0   0   0       0   0   0 0 0   0 00"
	"0 0 0 000 00000000000 0 000 0 0 0 0 00"
	"0   0     0   0     0 0 0   0 0 0 0 00"
	"00000000000 0 0 000 0 0 00000 0 0 0000"
	"0   0       0     0   0 0     0 0   00"
	"0   0 000000000 0000000 0 00000 000 00"
	"0 0 0 0       0 0       0   0   0   00"
	"0 0 0 0 00000 0 0 000000000 0   0   00"
	"0 0 0 0 0   0 000 0   0     0 000 0000"
	"0 0   0 0 0 0 0   0   0 0   0 0   0 00"
	"0 00000 0 0 0 0 000 0 0 0 000 0 000 00"
	"0     0 0 0 0   0   0   0 0   0     00"
	"00000 0 0 0000000 0 0000000 0 00000 00"
	"0   0 0 0         0 0       0     0 00"
	"0 0 0 0 000 000000000 000000000 000 00"
	"0 0   0   0       0   0   0     0   00"
	"0 0 00000 0000000   0 0 0 0 00000 0000"
	"0 0 0   0       0   0 0 0 0   0   0 00"
	"0 000 0 00000 0 0 000 000 000 0 000 00"
	"0     0       0   0     0     0     00"
	"00000000000000000000000000000000000 00"
};

const void Map::Death() const
{
	int counter = 0;
	int w = 0;
	while (1)
	{
		FsPollDevice();
		if (FsInkey() == FSKEY_ESC)
		{
			break;
		}
		counter++;
		w++;

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4ub(104, 10, 31, w);
		glBegin(GL_QUADS);
		glVertex2i(200, 0);
		glVertex2i(1000, 0);
		glVertex2i(1000, 800);
		glVertex2i(200, 800);
		glEnd();

		if (counter >= 50)
		{
			w += 1;
			if (w >= 250)
			{
				w = 100;
			}

			YsRawPngDecoder png;
			png.Decode("rip.png");
			png.Flip();
			glRasterPos2d(500, 500);
			
			glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);
			
		}

		if (counter >= 250)
		{
			break;
		}
		FsSwapBuffers();
		FsSleep(25);
	}
}

const void Map::Victory() const
{
	int counter = 0;
	int w = 0;
	while (1)
	{
		FsPollDevice();
		if (FsInkey() == FSKEY_ESC)
		{
			break;
		}
		counter++;
		w++;

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4ub(250, 98, 12, w);
		glBegin(GL_QUADS);
		glVertex2i(200, 0);
		glVertex2i(1000, 0);
		glVertex2i(1000, 800);
		glVertex2i(200, 800);
		glEnd();

		if (counter >= 50)
		{
			w += 1;
			if (w >= 250)
			{
				w = 100;
			}

			YsRawPngDecoder png;
			png.Decode("victory.png");
			png.Flip();
			glRasterPos2d(470, 520);
			glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);
		}
		
		if (counter >= 250)
		{
			break;
		}
		FsSwapBuffers();
		FsSleep(25);
	}
}

const void Map::DrawBackground() const
{
	glColor3ub(100, 100, 100);
	glBegin(GL_QUADS);
	glVertex2d(0, 0);
	glVertex2d(1000, 0);
	glVertex2d(1000, 800);
	glVertex2d(0, 800);
	glEnd();
}

/*
* draw the map
* i is the number of the map
*/
const void Map::Draw(int i) const
{
	int length;
	int blockWid;
	int blockPerLine;

	switch (i)
	{
	case 2:
		blockWid = 800 / blockPerLine2;
		for (int i = 0; i < arrayLen2; i++)
		{
			if (map2[i] == '0')
			{
				DrawPixel(i - (i / blockPerLine2) * blockPerLine2, i / blockPerLine2, map2[i], blockWid, 1);
			}
		}
		break;
	case 3:
		blockWid = 800 / blockPerLine3;
		for (int i = 0; i < arrayLen3; i++)
		{
			if (map3[i] == '0')
			{
				DrawPixel(i - (i / blockPerLine3) * blockPerLine3, i / blockPerLine3, map3[i], blockWid, 1);
			}
		}
		break;
	default:
		blockWid = 800 / blockPerLine1;
		for (int i = 0; i < arrayLen1; i++)
		{
			if (map1[i] == '0')
			{
				DrawPixel(i - (i / blockPerLine1) * blockPerLine1, i / blockPerLine1, map1[i], blockWid, 1);
			}
		}
		break;
	}

	
}

/*
* return the length of a map array
* i is the number of the map
*/
 const int Map::GetArrayLen(int i) const
{
	switch (i)
	{
	case 2:
		return arrayLen2;
		break;
	case 3:
		return arrayLen3;
		break;
	default:
		return arrayLen1;
		break;
	}
}

/*
* return the map array
* i is the number of the map
*/
 const char *Map::GetMap(int i) const
{
	switch (i)
	{
	case 2:
		return map2;
		break;
	case 3:
		return map3;
		break;
	default:
		return map1;
		break;
	}
}

/*
* return the width of a block
* i is the number of the map
*/
 const int Map::GetBlockWidth(int i) const
{
	switch (i)
	{
	case 2:
		return 800 / blockPerLine2;
		break;
	case 3:
		return 800 / blockPerLine3;
		break;
	default:
		return 800 / blockPerLine1;
		break;
	}
}

 const int Map::GetStartX(int choice) const 
 {
	 switch (choice)
	 {
	 case 2:
		 return 13;
	 case 3:
		 return 1;
	 default:
		 return 3;
	 }
 }
 const int Map::GetStartY() const 
 {
	 return 0;
 }
 const int Map::GetEndX(int choice) const 
 {
	 int blockPerLine = 0;
	 int i = 0;
	 switch (choice)
	 {
	 case 2:
		 blockPerLine = blockPerLine2;
		 i = 425;
		 break;
	 case 3:
		 blockPerLine = blockPerLine3;
		 return 35;
	 default:
		 blockPerLine = blockPerLine1;
		 i = 285;
		 break;
	 }
	 return (i - (i / blockPerLine) * blockPerLine);
 }
 const int Map::GetEndY(int choice) const 
 {
	 int blockPerLine = 0;
	 int i = 0;
	 switch (choice)
	 {
	 case 2:
		 blockPerLine = blockPerLine2;
		 i = 425;
		 break;
	 case 3:
		 blockPerLine = blockPerLine3;
		 return 37;
		 break;
	 default:
		 blockPerLine = blockPerLine1;
		 i = 285;
		 break;
	 }
	 return (i / blockPerLine);
 }

 const bool Map::CheckHit(int player_x, int player_y, int choice) const
 {
	 int blockPerLine = 0;
	 const char *tmp_map = GetMap(choice);
	 switch (choice) {
	 case 2:
		 blockPerLine = blockPerLine2;
		 break;
	 case 3:
		 blockPerLine = blockPerLine3;
		 break;
	 default:
		 blockPerLine = blockPerLine1;
		 break;
	 }
	 
	 if (tmp_map[player_y*blockPerLine + player_x] == '0') 
	 {
		 return true;
	 }
	 return false;
 }