#ifndef MAP_H_IS_INCLUDED
#define MAP_H_IS_INCLUDED
////////////////////////////////////////////////////////////////////////////////Map
/* DrawPixel: draw every block pixel. */
void DrawPixel(int x, int y, char state, int blockWid, int choice);

class Map
{
private:
	/* the length of the map array */
	const int arrayLen1 = 290;
	const int arrayLen2 = 442;
	const int arrayLen3 = 1445;

	/*
	* the array represents the map.
	* '0' represents walls(blocks),
	* ' ' represents paths.
	*/
	const static char map1[290];
	const static char map2[442];
	const static char map3[1445];

	/* number of pixels on every row of the map */
	const int blockPerLine1 = 17;
	const int blockPerLine2 = 21;
	const int blockPerLine3 = 38;

public:
	const char *GetMap(int i) const;
	const int GetBlockWidth(int i) const;
	const int GetArrayLen(int i) const;
	const void Draw(int i) const;
	const int GetStartX(int choice) const;
	const int GetStartY() const;
	const int GetEndX(int choice) const;
	const int GetEndY(int choice) const;
	const bool CheckHit(int player_x, int player_y, int choice) const;
	const void DrawBackground() const;
	const void Victory() const;
	const void Death() const;
};
#endif
