//
//  Player.cpp
//  Player
//
//  Created by LiXiaojie on 16/11/20.
//
/*Here is the game object defined by our group*/
#include "fssimplewindow.h"
#include "Player.h"
#include <stdio.h>
#include "yspng.h"
#include <stdlib.h>

//#define DEBUG

#ifdef DEBUG
#define SCREENX 1000
#define SCREENY 800
#endif // DEBUG


void Player::SetPlace() {
	/*Set the player to a particular place as
	it was hitted by the ghost*/
	this->x = this->init_x;
	this->y = this->init_y;
}

Player::Player(int inputx, int inputy, int block_size) {
	x = inputx;
	y = inputy;
	width = block_size;
	this->init_x = inputx;
	this->init_y = inputy;
}


bool Player::CheckHit(int xx, int yy, int category) {
	bool hitted = false;
	int relativeX, relativeY;
	relativeX = abs(xx - x*width);
	relativeY = abs(yy - y*width);
	if (relativeX < width && relativeY < width){
		hitted = true;
	}

	if (hitted) {
		switch (category) {
		case 1://"life supply"
			item++;
			if (health < 3) {
				health++;
			}
			break;
		//case 2://"gun"
		//	item[1]++;
		//	break;
		case 3://"ghost"
			health--;
			if (health == 0) {
				/*set the lose var to 1*/
			}
			else {
				SetPlace();
			}
			break;
		}
	}
	return hitted;
}

void Player::Move(int signal) {
	switch (signal) {
	case 1://left
		x -= 1;
		break;
	case 2://up
		y -= 1;
		break;
	case 3://right
		x += 1;
		break;
	case 4://down
		y += 1;
		break;
	default://else do nothing
		break;
	}
}

int Player::GetItem() {
	return item;
	/*This method is used to obtain the number of each index
	in item array, in order to display on
	InGame Menu's status bar*/
}
int Player::GetHealth() {
	return health;
	/*This method is used to obtain the health status of player,
	in order to display on InGame Menu's status bar*/
}

int Player::GetWidth() {
	return width;
}

void Player::Draw(int level) {
	YsRawPngDecoder png;
	switch (level) {
	case 1:
		png.Decode("mplayer.png");
		break;
	case 2:
		png.Decode("mplayer.png");
		break;
	case 3:
		png.Decode("ssplayer.png");
		break;
	default:
		break;
	}
	png.Flip();
	glRasterPos2d(200+width*x, width*y+png.hei);
	glDrawPixels(png.wid, png.hei, GL_RGBA, GL_UNSIGNED_BYTE, png.rgba);
}


void Player::CheckHitWall(bool hitted, int signal) {
	if (hitted) {
		switch (signal) {
		case 1:
			x += 1;
			break;
		case 2:
			y += 1;
			break;
		case 3:
			x -= 1;
			break;
		case 4:
			y -= 1;
			break;
		default:
			break;
		}
	}
	if (y < 0) {
		y = 0;
	}
}

bool Player::CheckDestination(int des_x, int des_y) {
	if (des_x == x && des_y == y) {
		return true;
	}
	return false;
}

void Player::BackDoor(int inputx, int inputy) {
	x = inputx;
	y = inputy;
}