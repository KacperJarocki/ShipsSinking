#pragma once
#include "user.h"
#include "player.h"
#include <iostream>

class computer :public user
{
	bool firstShotInDirection;
	int shots[10][10]{};
	int firstX;// first hit
	int firstY;
	int lastX;// last shot
	int lastY;
	int nextX;
	int nextY;
	bool left;
	bool right;
	bool up;
	bool down;
	bool wasFirstHit;

public:
	computer();
	void nextTarget(const player &play);
	int showNextX() const{ return nextX; }
	int showNextY()const{ return nextY; }
	void copyTheShips(const player& play);
};

