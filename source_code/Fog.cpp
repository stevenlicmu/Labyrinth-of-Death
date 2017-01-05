#include <stdio.h>
#include <stdlib.h>
#include "fssimplewindow.h"
#include "Fog.h"

void Fog::Reset(int level)
{
	int blockPerLine, fogLen;
	char *tmp_fog = GetFog(level);
	switch (level) {
	case 2:
		fogLen = arrayLen2;
		blockPerLine = blockPerLine2;
		break;
	case 3:
		fogLen = arrayLen3;
		blockPerLine = blockPerLine3;
		break;
	default:
		fogLen = arrayLen1;
		blockPerLine = blockPerLine1;
		break;
	}

	for (int i = 0; i < fogLen; i++)
	{
		tmp_fog[i] = '0';
	}
}

void Fog::Cheat(int level)
{
	int fogLen;
	char *tmp_fog = GetFog(level);
	switch (level) {
	case 2:
		fogLen = arrayLen2;
		break;
	case 3:
		fogLen = arrayLen3;
		break;
	default:
		fogLen = arrayLen1;
		break;
	}

	char *tmp;
	tmp = new char[fogLen];
	memcpy(tmp, tmp_fog, fogLen);

	for (int i = 0; i < fogLen; i++)
	{
		tmp_fog[i] = ' ';
	}
	delete tmp;
}

void Fog::SetEmpty(int x, int y, int level)
{
	int blockPerLine, fogLen;
	char *tmp_fog = GetFog(level);
	switch (level) {
	case 2:
		fogLen = arrayLen2;
		blockPerLine = blockPerLine2;
		break;
	case 3:
		fogLen = arrayLen3;
		blockPerLine = blockPerLine3;
		break;
	default:
		fogLen = arrayLen1;
		blockPerLine = blockPerLine1;
		break;
	}

	tmp_fog[y*blockPerLine + x] = ' ';
	if (y*blockPerLine + x + 1 >= 0 && y*blockPerLine + x + 1 < fogLen)
	{
		tmp_fog[y*blockPerLine + x + 1] = ' ';
	}
	if (y*blockPerLine + x - 1 >= 0 && y*blockPerLine + x - 1 < fogLen)
	{
		tmp_fog[y*blockPerLine + x - 1] = ' ';
	}
	if ((y - 1)*blockPerLine + x >= 0 && (y - 1)*blockPerLine + x < fogLen)
	{
		tmp_fog[(y - 1)*blockPerLine + x] = ' ';
	}
	if ((y - 1)*blockPerLine + x + 1 >= 0 && (y - 1)*blockPerLine + x + 1 < fogLen)
	{
		tmp_fog[(y - 1)*blockPerLine + x + 1] = ' ';
	}
	if ((y - 1)*blockPerLine + x - 1 >= 0 && (y - 1)*blockPerLine + x - 1 < fogLen)
	{
		tmp_fog[(y - 1)*blockPerLine + x - 1] = ' ';
	}
	if ((y + 1)*blockPerLine + x >= 0 && (y + 1)*blockPerLine + x < fogLen)
	{
		tmp_fog[(y + 1)*blockPerLine + x] = ' ';
	}
	if ((y + 1)*blockPerLine + x + 1 >= 0 && (y + 1)*blockPerLine + x + 1 < fogLen)
	{
		tmp_fog[(y + 1)*blockPerLine + x + 1] = ' ';
	}
	if ((y + 1)*blockPerLine + x - 1 >= 0 && (y + 1)*blockPerLine + x - 1 < fogLen)
	{
		tmp_fog[(y + 1)*blockPerLine + x - 1] = ' ';
	}

	if ((y + 2)*blockPerLine + x >= 0 && (y + 2)*blockPerLine + x < fogLen)
	{
		tmp_fog[(y+2)*blockPerLine + x] = ' ';
	}
	if ((y + 2)*blockPerLine + x + 1 >= 0 && (y + 2)*blockPerLine + x + 1 < fogLen)
	{
		tmp_fog[(y + 2)*blockPerLine + x + 1] = ' ';
	}
	if ((y + 2)*blockPerLine + x + 2 >= 0 && (y + 2)*blockPerLine + x + 2 < fogLen && (y + 2)*blockPerLine + x + 2 < (y + 3)*blockPerLine)
	{
		tmp_fog[(y + 2)*blockPerLine + x + 2] = ' ';
	}
	if ((y + 2)*blockPerLine + x - 1 >= 0 && (y + 2)*blockPerLine + x - 1 < fogLen)
	{
		tmp_fog[(y + 2)*blockPerLine + x - 1] = ' ';
	}
	if ((y + 2)*blockPerLine + x - 2 >= 0 && (y + 2)*blockPerLine + x - 2 < fogLen && (y + 2)*blockPerLine + x - 2 > (y + 2)*blockPerLine)
	{
		tmp_fog[(y + 2)*blockPerLine + x - 2] = ' ';
	}
	if ((y - 2)*blockPerLine + x >= 0 && (y - 2)*blockPerLine + x < fogLen)
	{
		tmp_fog[(y - 2)*blockPerLine + x] = ' ';
	}
	if ((y - 2)*blockPerLine + x + 1 >= 0 && (y - 2)*blockPerLine + x + 1 < fogLen)
	{
		tmp_fog[(y - 2)*blockPerLine + x + 1] = ' ';
	}
	if ((y - 2)*blockPerLine + x + 2 >= 0 && (y - 2)*blockPerLine + x + 2 < fogLen && (y - 2)*blockPerLine + x + 2 < (y - 1)*blockPerLine)
	{
		tmp_fog[(y - 2)*blockPerLine + x + 2] = ' ';
	}
	if ((y - 2)*blockPerLine + x - 1 >= 0 && (y - 2)*blockPerLine + x - 1 < fogLen)
	{
		tmp_fog[(y - 2)*blockPerLine + x - 1] = ' ';
	}
	if ((y - 2)*blockPerLine + x - 2 >= 0 && (y - 2)*blockPerLine + x - 2 < fogLen && (y - 2)*blockPerLine + x - 2 > (y - 2)*blockPerLine)
	{
		tmp_fog[(y - 2)*blockPerLine + x - 2] = ' ';
	}
	//
	if ((y + 1)*blockPerLine + x + 2 >= 0 && (y + 1)*blockPerLine + x + 2 < fogLen && (y + 1)*blockPerLine + x + 2 < (y + 2)*blockPerLine)
	{
		tmp_fog[(y + 1)*blockPerLine + x + 2] = ' ';
	}
	if ((y + 1)*blockPerLine + x - 2 >= 0 && (y + 1)*blockPerLine + x - 2 < fogLen && (y + 1)*blockPerLine + x - 2 > (y + 1)*blockPerLine)
	{
		tmp_fog[(y + 1)*blockPerLine + x - 2] = ' ';
	}
	if (y*blockPerLine + x + 2 >= 0 && y*blockPerLine + x + 2 < fogLen && y*blockPerLine + x + 2 < (y+1)*blockPerLine)
	{
		tmp_fog[y*blockPerLine + x + 2] = ' ';
	}
	if (y*blockPerLine + x - 2 >= 0 && y*blockPerLine + x - 2 < fogLen && y*blockPerLine + x - 2 > y*blockPerLine)
	{
		tmp_fog[y*blockPerLine + x - 2] = ' ';
	}
	if ((y - 1)*blockPerLine + x + 2 >= 0 && (y - 1)*blockPerLine + x + 2 < fogLen && (y - 1)*blockPerLine + x + 2 < y*blockPerLine)
	{
		tmp_fog[(y - 1)*blockPerLine + x + 2] = ' ';
	}
	if ((y - 1)*blockPerLine + x - 2 >= 0 && (y - 1)*blockPerLine + x - 2 < fogLen && (y - 1)*blockPerLine + x - 2 > (y - 1)*blockPerLine)
	{
		tmp_fog[(y - 1)*blockPerLine + x - 2] = ' ';
	}
}

/*
* draw the fog
* i is the number of the fog
*/
void Fog::Draw(int i)
{
	int length;
	int blockWid;
	char *fog;
	int blockPerLine;

	switch (i)
	{
	case 2:
		blockPerLine = blockPerLine2;
		blockWid = 800 / blockPerLine2;
		length = arrayLen2;
		fog = new char[length];
		memcpy(fog, fog2, length);
		break;
	case 3:
		blockPerLine = blockPerLine3;
		blockWid = 800 / blockPerLine3;
		length = arrayLen3;
		fog = new char[length];
		memcpy(fog, fog3, length);
		break;
	default:
		blockPerLine = blockPerLine1;
		blockWid = 800 / blockPerLine1;
		length = arrayLen1;
		fog = new char[length];
		memcpy(fog, fog1, length);
		break;
	}

	for (int i = 0; i < length; i++)
	{
		if (fog[i] == '0')
		{
			DrawPixel(i - (i / blockPerLine) * blockPerLine, i / blockPerLine, fog[i], blockWid, 0);
		}
	}
	delete fog;
}

char Fog::fog1[290] =
{
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
	"00000000000000000"
};

char Fog::fog2[442] =
{
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
	"000000000000000000000"
};

char Fog::fog3[1445] =
{
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
	"00000000000000000000000000000000000000"
};

/*
* return the fog array
* i is the number of the fog
*/
char *Fog::GetFog(int i)
{
	switch (i)
	{
	case 2:
		return fog2;
		break;
	case 3:
		return fog3;
		break;
	default:
		return fog1;
		break;
	}
}