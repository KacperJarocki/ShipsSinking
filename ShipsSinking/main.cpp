
#include "player.h"
#include "computer.h"
#include <iostream>
#include "game.h"








int main()
{
	game sinikingShips;
	player player;
	computer enemy;
	char move = ' ';
	sinikingShips.intro();
	while (true)
	{
		srand(time(0));
		sinikingShips.phaseOne(player, enemy);
		sinikingShips.phaseTwo(player, enemy);
		sinikingShips.phaseThree(player, enemy);
		system("cls");
		std::cout << "Gra sie skonczyla jezeli chcesz zagrac kolejna to wprowadz y:\n";
		std::cin >> move;
		if (move != 'y')
			break;
	}
	
	


}