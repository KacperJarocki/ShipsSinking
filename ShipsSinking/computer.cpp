#include "computer.h"

computer::computer()
{
	firstX = -1;
	firstY = -1;
	nextY = -1;
	nextX = -1;
	LastShotHit = false;
	automaticSpotsAroundShip = true;
	automaticShips = true;
	wasFirstHit = false;
	RUCOmputer = true;
	deadlyHit = true;
	right = true;
	left = true;
	up = true;
	down = true;
	firstShotInDirection = true;
	quantityShips[0] = 3;
	quantityShips[1] = 3;
	quantityShips[2] = 2;
	quantityShips[3] = 2;
	quantityShips[4] = 1;
}

void computer::nextTarget(player &play)
{
	int range = 10;
	player gamer(play);
	if (gamer.didHitKill() == true)
	{
		wasFirstHit = false;
		right = true;
		left = true;
		up = true;
		down = true;
	}
	

	if (wasFirstHit == false)
	{
		nextX = std::rand() % range;
		nextY = std::rand() % range;

		gamer.hit(nextX, nextY);
		
		wasFirstHit = gamer.wasLastShotHit();
		if(wasFirstHit == true)
		{
			
			firstX = nextX;
			firstY = nextY;
			lastX = nextX;
			lastY = nextY;
		}
		return;
	}
	if (wasFirstHit == true)
	{
		if (right == true && nextY < 9)
		{
			if (firstShotInDirection == true)
			{
				std::cout << "pierwszy strzal prawo\n";
				nextY = firstY + 1;
				lastY = nextY;
				firstShotInDirection= false;
				
			}
			else
			{
				nextY = lastY + 1;
				lastY = nextY;
			}
			
			gamer.hit(nextX, nextY);
			right = gamer.wasLastShotHit();
			
			if (right == false)firstShotInDirection = true;
			return;
		}
		
		if (left == true && nextY>0)
		{
			if (firstShotInDirection == true)
			{
				nextY = firstY - 1;
				lastY = nextY;
				firstShotInDirection = false;
			}
			else
			{
				nextY = lastY - 1;
				lastY = nextY;
			}
			gamer.hit(nextX, nextY);
		
			left = gamer.wasLastShotHit();
			if (left == false)firstShotInDirection = true;
			return;
			
		}
		if (up == true && nextX > 0)
		{
			if (firstShotInDirection == true)
			{
				nextX= firstX - 1;
				nextY = firstY;
				lastX = nextX;
				firstShotInDirection = false;
				
			}
			else
			{
				nextX = lastX - 1;
				lastX = nextX;
			}
			gamer.hit(nextX, nextY);
			
			up = gamer.wasLastShotHit();
			if (up == false)firstShotInDirection = true;
			return;
			
		}
		if (down == true && nextX < 9)
		{
			if (firstShotInDirection == true)
			{
				nextX = firstX + 1;
				lastX = nextX;
				firstShotInDirection = false;
			}
			else
			{
				nextX = lastX + 1;
				lastX = nextX;
			}
			gamer.hit(nextX, nextY);
			
			down = gamer.wasLastShotHit();
			if (down == false)firstShotInDirection = true;
			return;
		}


		
		
	}
	
	
		
}
