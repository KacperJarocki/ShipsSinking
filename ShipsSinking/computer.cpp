#include "computer.h"
#include <iostream>
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
	quantity1ships = 0;
	quantity2ships = 0;
	quantity3ships = 0;
	quantity4ships = 0;
	quantity5ships = 0;
	deadlyHit = true;
	right = false;
	left = false;
	up = false;
	down = false;
	
	
}

void computer::nextTarget()
{
	int range =10;
	if(wasFirstHit == false || deadlyHit == true  )
	{
		nextX = std::rand() % range;
		nextY = std::rand() % range;
		deadlyHit = false;
		return;
	}
	if(wasFirstHit == true && deadlyHit == false)
	{
		///test 
/// wrote on ipad
	}

}
