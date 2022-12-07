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

void user::testing()
{
	setLives();
	std::cout << userLives;
}
