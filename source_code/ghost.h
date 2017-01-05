#ifndef GHOST_H_IS_INCLUDED
#define GHOST_H_IS_INCLUDED
#include "GameObject.h"
class Ghost : public GameObject
{
protected:
	int x0, y0;
public:
	void initialize( int xx, int yy);
	void move(int bx, int by, int rangeX, int rangeY);
	void Drawghost(int level);
};


#endif