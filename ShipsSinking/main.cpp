
#include "player.h"
#include "computer.h"
#include <iostream>







int main()
{
	srand(time(0));
	player gamer;
	computer enemy;
	int nowaTura = 1;
	//faza 1 rozstawienie statkow
	while (gamer.AutomaticAddShips() == false);
	while (enemy.AutomaticAddShips() == false);
	
	//faza 2 gra
	while (gamer.getLives() > 0 || enemy.getLives() > 0)
	{
		system("cls");
		std::cout << nowaTura << " tura\n";
		gamer.showTheBoard();
		enemy.showTheBoard();
		enemy.hit(0, 0);
		
		while (gamer.wasLastShotHit() == true)
		{
			
			gamer.showTheBoard();
			enemy.showTheBoard();
			enemy.hit(0, 0);
			
			
			
		}
		
		gamer.showTheBoard();
		enemy.showTheBoard();
		enemy.hit(0, 0);
		nowaTura++;
		while (enemy.wasLastShotHit() == true)
		{
			gamer.showTheBoard();
			enemy.showTheBoard();
			enemy.hit(0, 0);
			enemy.nextTarget();
			
			
		}
	}
	
	

}