#include "computer.h"

computer::computer()
{
	firstX = -1;
	firstY = -1;
	lastX = -1;
	lastY = -1;
	nextY = -1;
	nextX = -1;
	LastShotHit = false;
	automaticSpotsAroundShip = true;
	automaticShips = true;
	wasFirstHit = false;
	RUCOmputer = true;
	deadlyHit = true;
	right = false;
	left = false;
	up = false;
	down = false;
	quantityShips[0] = 3;
	quantityShips[1] = 3;
	quantityShips[2] = 2;
	quantityShips[3] = 2;
	quantityShips[4] = 1;
	
	
}

void computer::nextTarget()
{
	int range =10;

		nextX = std::rand() % range;
		nextY = std::rand() % range;
		
}
