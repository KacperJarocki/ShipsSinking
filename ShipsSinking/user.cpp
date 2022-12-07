#include "user.h"


void user::setLives()
{
	userLives = shipTab.countOfLives();
}

void user::liveCheck() const
{
	if (userLives < 1)
	{
		std::cout << "u lost :(";
		exit(0);
	}
}

void user::addShips()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < quantityShips[i]; j++)
			myBoard.addShipToGame(shipTab, i+1);
		myBoard.playerScreen();
	}
}

void user::hit(int x, int y)
{

	if(RUCOmputer == false)
	{
		std::cin >> x;
		std::cin >> y;
	}
	if(x>0 && x<11 && y>0 && y < 11)
	{
		LastShotHit = myBoard.hit(x, y);
		if(LastShotHit == true)
		{
			if (shipTab.wasItDeadlyShot(x,y))
			{
				deadlyHit = shipTab.wasItDeadlyShot(x,y);
				std::cout << "trafiony zatopiony";
				if (ifAutomaticSpotsAroundShip() == true)
					spotsAroundShip();
			}
		}
	}
	else
	{
		std::cout << "poza tablica";
		hit(0, 0);
	}


}


void user::testing()
{
	setLives();
	std::cout << userLives;
}

int user::getLives() const
{
	return userLives;
}

void user::spotsAroundShip()
{
}

void user::automaticShipsPlacer()
{
	
}
