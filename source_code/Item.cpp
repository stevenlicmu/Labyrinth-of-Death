#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fssimplewindow.h"
#include "Item.h"
#include "Map.h"
#include "yspng.h"
#include "math.h"


void Item::Generate(int i)
{
	//srand((int)time(NULL));

	Map map;

	const char *GetMap = map.GetMap(i);
	int arraylen = map.GetArrayLen(i);
	int blockwid = map.GetBlockWidth(i);

	ItemType = rand() % numItemType;

	int blockperline = 800 / blockwid;

	int nOpen = 0;
	for (int k = 0; k < arraylen; ++k)
	{
		if (GetMap[k] == ' ')
		{
			if (i != 3)
			{
				nOpen = nOpen + 1;
			}
			else if (i == 3)
			{
				if (k % blockperline != 0)
				{
					nOpen = nOpen + 1;
				}
			}
		}
	}

	int *index = new int[nOpen];
	int j = 0;
	for (int k = 0; k < arraylen; ++k)
	{
		if (GetMap[k] == ' ')
		{
			if (i != 3)
			{
				index[j] = k;
				j = j + 1;
			}
			else if (i == 3)
			{
				if (k % blockperline != 0)
				{
					index[j] = k;
					j = j + 1;
				}
			}
		}
	}

	int itemIndex = index[rand() % nOpen];
	
	x = itemIndex - (itemIndex / blockperline) * blockperline;
	y = itemIndex / blockperline;

	ItemWid = blockwid;
}

void Item::Initialize(void)
{
	state = 0;
	numItemType = 1;

	Map map;

	
}

void Item::SetAppearTime(int i)
{
	if (i == 1)
	{
		appearTime = 600;	
		originalAppearTime = 600;
	}
	if (i == 2)
	{
		appearTime = 500;
		originalAppearTime = 500;
	}
	if (i == 3)
	{
		appearTime = 400;
		originalAppearTime = 400;
	}
}

void Item::SetDisappearTime(int i)
{
	if (i == 1)
	{
		disappearTime = 200;
		originalDisappearTime = 200;
	}
	if (i == 2)
	{
		disappearTime = 300;
		originalDisappearTime = 300;
	}
	if (i == 3)
	{
		disappearTime = 400;
		originalDisappearTime = 400;
	}
}

void Item::DrawItem()
{

	////// Drawing a Heart //////

	glColor3ub(255, 0, 0);
	glBegin(GL_TRIANGLE_FAN);
	for (int k = 0; k < 360; k += 10)
	{
		double angle = (double)k*(3.1415927) / 180.0;
		double s = sin(angle);
		double c = cos(angle);
		double ct = cos(angle*2);
		double cth = cos(angle * 3);
		double cf = cos(angle * 4);
		double xh = (double)((ItemWid/2 * s*s*s));
		double yh = (double)-1*ItemWid/16/2*(13 * c - 5 * ct - 2 * cth - cf);
		glVertex2d(200+ItemWid*x+xh+(ItemWid/2), ItemWid*y+yh+(ItemWid/2));
	}
	glEnd();
	
}
