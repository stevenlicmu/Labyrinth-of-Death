#ifndef FOG_H_IS_INCLUDED
#define FOG_H_IS_INCLUDED

void DrawPixel(int x, int y, char state, int blockWid, int choice);

class Fog
{
	/* the length of the fog array */
	int arrayLen1 = 290;
	int arrayLen2 = 442;
	int arrayLen3 = 1445;

	/*
	* the array represents the map.
	* '0' represents fog,
	* ' ' represents air.
	*/
	static char fog1[290];
	static char fog2[442];
	static char fog3[1445];

	/* number of pixels on every row of the map */
	int blockPerLine1 = 17;
	int blockPerLine2 = 21;
	int blockPerLine3 = 38;

public:
	char *GetFog(int i);
	void Draw(int i);
	void SetEmpty(int x, int y, int level);
	void Cheat(int level);
	void Reset(int level);
};

#endif