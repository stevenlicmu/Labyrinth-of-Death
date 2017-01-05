#include "fssimplewindow.h"
#include "ysglfontdata.h"
#include <stdio.h>
#include "Menu.h"
#include "yspng.h"

void GameMenu::DrawSelection(void) {
	int x = 450;
	int y;
	switch (level) {
	case 1:
		y = 518;
		break;
	case 2:
		y = 558;
		break;
	case 3:
		y = 598;
		break;
	}

	glColor3ub(255, 128, 0);
	glBegin(GL_TRIANGLES);
	glVertex2i(x, y);
	glVertex2i(x - 20, y - 10);
	glVertex2i(x - 20, y + 10);
	glEnd();

}

int GameMenu::Run(void)
{

	YsRawPngDecoder background;
	background.Decode("background.png");
	background.Flip();

	level = 1;
	for (;;)
	{
		FsPollDevice();

		lastKey = FsInkey();
		if (FSKEY_ESC == lastKey || FSKEY_ENTER == lastKey)
		{
			break;
		}

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glRasterPos2d(0, 799);
		glDrawPixels(background.wid, background.hei, GL_RGBA, GL_UNSIGNED_BYTE, background.rgba);

		glColor3ub(255, 255, 255);

		glRasterPos2d(330, 150);
		YsGlDrawFontBitmap20x32("Labyrinth of Death");

		glRasterPos2d(460, 530);
		YsGlDrawFontBitmap16x24("Level 1");
		glRasterPos2d(460, 570);
		YsGlDrawFontBitmap16x24("Level 2");
		glRasterPos2d(460, 610);
		YsGlDrawFontBitmap16x24("Level 3");

		glRasterPos2d(330, 680);
		YsGlDrawFontBitmap12x16("Press ARROW KEYS to select a level");
		glRasterPos2d(330, 700);
		YsGlDrawFontBitmap12x16("Press ENTER to start");
		glRasterPos2d(330, 720);
		YsGlDrawFontBitmap12x16("Press ESC to exit");

		if (lastKey == FSKEY_UP && level > 1) {
			level -= 1;
		}
		if (lastKey == FSKEY_DOWN && level < 3) {
			level += 1;
		}
		DrawSelection();


		FsSwapBuffers();

		FsSleep(25);
	}

	return level;
}



