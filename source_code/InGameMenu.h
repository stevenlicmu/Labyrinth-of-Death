#ifndef INGAMEMENU_H_IS_INCLUDED
#define INGAMEMENU_H_IS_INCLUDED
#include "TextString.h"

class InGameMenu {
public:
	InGameMenu(int x);
	int level;
	int key;
	TextString showlevel;
	TextString showlife;
	void Text(int level, int life);
	void Display(int life);
};

#endif
