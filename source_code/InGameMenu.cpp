#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <stdio.h>
#include "TextString.h"
#include "InGameMenu.h"


InGameMenu::InGameMenu(int x) {
	level = x;
}

void InGameMenu::Text(int level, int life) {
	showlevel.CleanUp();
	showlife.CleanUp();
	showlevel.Add("Level: ");
	showlevel.Add(level + '0');
	showlife.Add("Life: ");
	showlife.Add(life + '0');
}

void InGameMenu::Display(int life) {
	Text(level, life);
		
	glColor3ub(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex2i(0, 0);
	glVertex2i(200, 0);
	glVertex2i(200, 800);
	glVertex2i(0, 800);
	glEnd();

	glColor3ub(255, 128, 0);
	glRasterPos2d(10, 80);
	YsGlDrawFontBitmap20x32(showlevel.GetPointer());
	glRasterPos2d(10, 150);
	YsGlDrawFontBitmap20x28(showlife.GetPointer());
	glRasterPos2d(10, 600);
	YsGlDrawFontBitmap6x10("Instruction:");
	glRasterPos2d(10, 620);
	YsGlDrawFontBitmap6x10("Use arrow keys to reach");
	glRasterPos2d(10, 640);
	YsGlDrawFontBitmap6x10("the exit");
	glRasterPos2d(10, 660);
	YsGlDrawFontBitmap6x10("Ghosts will kill you");
	glRasterPos2d(10, 680);
	YsGlDrawFontBitmap6x10("Items will restore health");
	glRasterPos2d(10, 700);
	YsGlDrawFontBitmap6x10("(max health: 3)");
	glRasterPos2d(10, 720);
	YsGlDrawFontBitmap6x10("Good luck and don't get killed");

}
