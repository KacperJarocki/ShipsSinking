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
		system("cls");
		myBoard.playerScreen();
		for (int j = 0; j < quantityShips[4-i]; j++)
			while (myBoard.addShipToGame(shipTab, 5 - i) == false) { system("cls"); myBoard.playerScreen(); }
		
	}
	setLives();
}

void user::hit(int x, int y)
{

	if(RUCOmputer == true)
	{
		std::cout << "podaj x nastepnie y\n";
		std::cin >> x;
		std::cin >> y;
		
	}
	if(x>0 && x<11 && y>0 && y < 11)
	{
		if (RUCOmputer == true)
		{
			x = x - 1;
			y = y - 1;
		}
		
		LastShotHit = myBoard.hit(x, y);
		if(LastShotHit == true)
		{
			if (shipTab.wasItDeadlyShot(x,y))
			{
				deadlyHit = shipTab.wasItDeadlyShot(x,y);
				std::cout << "trafiony zatopiony\n";
				if (ifAutomaticSpotsAroundShip() == true)
					spotsAroundShip();
			}
		}
		setLives();
	}
	else
	{
		std::cout << "poza tablica\n";
		hit(0, 0);
	}
	if (RUCOmputer == false)
		myBoard.playerScreen();
	else
	{
		myBoard.enemyScreen();
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

bool user::AutomaticAddShips()
{
	int x, y;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < quantityShips[4 - i]; j++)
		{
			int licznikWstawianiaStatku = 0;
			while (true)
			{

				 x = std::rand() % (10);
				 y = std::rand() % (10);
				if(myBoard.AutomaticAddShipToGame(shipTab,5-i,x,y)==true)
					break;
				licznikWstawianiaStatku++;
				if (licznikWstawianiaStatku > 1000000)
				{
					
					myBoard.clearPositions();
					shipTab.clearArray();
					return false;
				}
			}
		}
	}
	if (RUCOmputer == false)
		myBoard.playerScreen();
	else
	{
		myBoard.enemyScreen();
	}

	setLives();
	return true;
	
	
}

void user::showTheBoard()const
{
	if (RUCOmputer == false)
		myBoard.playerScreen();
	else
	{
		myBoard.enemyScreen();
	}

}

