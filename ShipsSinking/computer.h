#pragma once
#include "user.h"
#include <iostream>

class computer :public user
{
	friend class ships;
	int firstX;// first hit
	int firstY;
	int lastX;// last shot
	int lastY;
	int nextX;
	int nextY;
	int deadlyHit;
	bool left;
	bool right;
	bool up;
	bool down;
	bool wasFirstHit;
public:
	computer();
	void nextTarget();
	int showNextX() const{ return nextX; }
	int showNextY()const{ return nextY; }
};

