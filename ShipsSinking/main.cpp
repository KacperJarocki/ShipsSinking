
#include "player.h"
#include "computer.h"
#include <iostream>







int main()
{
	srand(time(0));
	player gamer;
	computer enemy;
	char nextMove;
	
	int nowaTura = 1;

	//faza 1 rozstawienie statkow
	while (gamer.AutomaticAddShips() == false);
	while (enemy.AutomaticAddShips() == false);
	//faza 2 gra
	while (gamer.getLives() > 0 || enemy.getLives() > 0)
	{
		system("cls");
		std::cout << nowaTura << " tura\n";
		std::cout << "przeciwnik oddal strzal w nastepujace koordynaty\t"<<enemy.showNextX()+1<<"\t"<<enemy.showNextY()+1<<"\n";
		gamer.showTheBoard();
		enemy.showTheBoard();
		enemy.hit(0, 0);
		while (true)
		{
			std::cout << "wcisnij k aby kontynuowac rozgrywke\n";
			std::cin >> nextMove;
			if (nextMove == 'k')
			{
				break;
			}
		}
		
		while (enemy.wasLastShotHit() == true)
		{
			
			gamer.showTheBoard();
			enemy.showTheBoard();
			enemy.hit(0, 0);
			while (true)
			{
				std::cout << "wcisnij k aby kontynuowac rozgrywke\n";
				std::cin >> nextMove;
				if (nextMove == 'k')
				{
					break;
				}
			}
		}
		enemy.nextTarget();
		while (gamer.hit(enemy.showNextX(), enemy.showNextY())==false)
		{
			enemy.nextTarget();
			gamer.hit(enemy.showNextX(), enemy.showNextY());
		}
		
		while (gamer.wasLastShotHit() == true)
		{
			enemy.nextTarget();
			while (gamer.hit(enemy.showNextX(), enemy.showNextY()) == false)
			{
				enemy.nextTarget();
				gamer.hit(enemy.showNextX(), enemy.showNextY());
			}
		}
		nowaTura++;
	}
	
	

}