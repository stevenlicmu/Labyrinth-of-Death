#include <stdio.h>
#include <stdlib.h>
#include "ghost.h"
#include "fssimplewindow.h"
#include "yspng.h"


void Ghost::initialize(int xx, int yy)
{
	x = xx;
	y = yy;
	
	x0 = x;
	y0 = y;
}

void Ghost::move(int bx, int by, int rangeX, int rangeY)
{
	if (abs(x - bx) <= rangeX && abs(y - by) <= rangeY)
	{
		if (x - bx < 0)
		{
			x += 1;
		}
		else
		{
			x -= 1;
		}
		if (y - by < 0)
		{
			y += 1;
		}
		else
		{
			y -= 1;
		}
	}
	else
	{
		if (x - x0 < 0)
		{
			x += 1;
		}
		else if (x > x0)
		{
			x -= 1;
		}
		else
		{
			x = x0;
		}

		if (y - y0 < 0)
		{
			y += 1;
		}
		else if (y > y0)
		{
			y -= 1;
		}
		else
		{
			y = y0;
		}
	}
}


void Ghost::Drawghost(int level)
{
	YsRawPngDecoder png;
	switch (level) {
	case 1:
		png.Decode("bat.png");
		break;
	case 2:
		png.Decode("ghost.png");
		break;
	case 3:
		png.Decode("ghost2.png");
		break;
	default:
		break;
	}
	png.Flip();
	glRasterPos2d(200+x, y+png.hei);
	glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);
}

