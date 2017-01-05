#ifndef ITEM_H_IS_INCLUDED
#define ITEM_H_IS_INCLUDED
#include "GameObject.h"
////////////////////////////////////////////////////////////////////////////////Item


class Item : public GameObject
{
public:
	int state, ItemType,ItemWid, numItemType, appearTime, disappearTime, originalAppearTime, originalDisappearTime;

	void Initialize();
	void SetAppearTime(int i);
	void SetDisappearTime(int i);
	void Generate(int i);
	void DrawItem();
};

#endif