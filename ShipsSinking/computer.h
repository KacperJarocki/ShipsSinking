#pragma once
#include "user.h"
#include <iostream>

class computer :public user
{
	int firstX;// first hit
	int firstY;
	int lastX;// last shot
	int lastY;
	int nextX;
	int nextY;
	int deadlyHit;
	bool wasFirstHit;
public:
	computer();
	void nextTarget();
	int showNextX() const{ return nextX; }
	int showNextY()const{ return nextY; }
};

