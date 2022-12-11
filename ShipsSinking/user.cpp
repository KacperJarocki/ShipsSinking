#include "user.h"


user::user()
{
}

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

bool user::hit(int x, int y)
{
	
	
	if(RUCOmputer == true)
	{
		std::cout << "podaj x nastepnie y\n";
		std::cin >> x;
		std::cin >> y;
		x = x - 1;
		y = y - 1;
		
	}
	if (x > -1 && x < 10 && y>-1 && y < 10)
	{

		if (myBoard.canIshotThere(x, y) == true)
		{
		
		LastShotHit = myBoard.hit(x, y);
		if (LastShotHit == true)
		{
			deadlyHit = shipTab.wasItDeadlyShot(x, y);
			if (deadlyHit== true)
			{
				std::cout << "trafiony zatopiony\n";
				if (automaticShips == true)
				{
					spotsAroundShip(x, y);

				}
			}
		}
		setLives();
		}
		else
		{
			return false;
		}
	}	
	else
	{
		return false;
	}
	if (RUCOmputer == false)
		myBoard.playerScreen();
	else
	{
		myBoard.enemyScreen();
	}
	return true;


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

void user::spotsAroundShip(int x,int y)
{
	bool way;
	int headX, headY,maszty;
	maszty = shipTab.getMasztyShip(x, y);
	way = shipTab.czyPoziom(x, y);
	headX = shipTab.getHeadXofShip(x,y);
	headY = shipTab.getHeadYofShip(x,y);
	std::cout << headX;
	std::cout << headY;
	if(maszty == 1)
	{
		myBoard.spotting(headX - 1, headY - 1, 3, 3);
		std::cout << "powinnow sie wyswietlic 1";
	}
	else if(way == false)
	{
		myBoard.spotting(headX - 1, headY - 1, maszty + 2, 3);
		std::cout << "powinnow sie wyswietlic dol";
	}
	else
	{
		myBoard.spotting(headX - 1, headY - 1, 3, maszty + 2);
		std::cout << "powinnow sie wyswietlic bok";
}
	



	
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

bool user::didHit(int x, int y) const
{
	return myBoard.didIHit(x,y);
}

