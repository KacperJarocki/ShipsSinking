
#include "player.h"
#include "computer.h"
#include <iostream>
#include "game.h"








int main()
{
	game sinikingShips;

	char move = ' ';
	sinikingShips.intro();
	while (true)
	{
		srand(time(0));
		sinikingShips.phaseOne();
		sinikingShips.phaseTwo();
		sinikingShips.phaseThree();
		system("cls");
		std::cout << "Gra sie skonczyla jezeli chcesz zagrac kolejna to wprowadz y:\n";
		std::cin >> move;
		if (move != 'y')
			break;
	}
	
	


}