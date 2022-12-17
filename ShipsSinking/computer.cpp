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
	quantityShips[1] = 2;
	quantityShips[2] = 2;
	quantityShips[3] = 1;
}

void computer::nextTarget(const player &play)
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
		std::cout << "losuje pierwsze strzaly\n";
		while(gamer.hit(nextX, nextY) == false)
		{
			std::cout << "losuje kojene strzaly\n";
			nextX = std::rand() % range;
			nextY = std::rand() % range;
		}
		
		wasFirstHit = gamer.wasLastShotHit();
		if(wasFirstHit == true)
		{
			std::cout << "wchodze w  algorytm\n";
			
			firstX = nextX;
			firstY = nextY;
			lastX = nextX;
			lastY = nextY;
		}
		return;
	}
	if (wasFirstHit == true)
	{
		std::cout <<"jestem w algorytemie\n";
		if (right == true && nextY < 9)
		{
			if (firstShotInDirection == true)
			{
				
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
			if (nextY > 8)right = false;
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
			if (nextY < 1)left = false;
			if (left == false)firstShotInDirection = true;
			return;
			
		}
		std::cout << "przed gora " << up<<'\n';
		if (up == true && nextX > 0)
		{
			std::cout << "w gore\n";
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
			if (nextX < 1)up = false;
			if (up == false)firstShotInDirection = true;
			return;
			
		}
		std::cout << "przed dolem " << down << '\n';
		if (down == true && nextX < 9)
		{
			std::cout << "w dol\n";
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
			if (nextX > 8)down = false;
			if (down == false)firstShotInDirection = true;
			return;
		}


		
		
	}
	
	
		
}

void computer::copyTheShips(const player &play)
{
	for (int i = 0; i < 4; i++)
		quantityShips[i] = play.quantityShips[i];

}
