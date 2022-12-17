
#include "player.h"
#include "computer.h"
#include <iostream>







int main()
{
	srand(time(0));
	player gamer;
	computer enemy;
	char nextMove = ' ';
	int nowaTura = 1;
	// INTRO PHASES
	std::cout << "wazne symbole:\n - = nieznane tzn woda\n [] = statek \n X- trafiony statek\n * = nietrafiony strzal \n O = oznaczenia do okola zatopionego statku\n zasady gry:\n wpisuj¹c koordynaty np 1 1 odajemy strzaly, koordynat pierwszy jest w pionie(rosnie w dol ), drugi w poziomie (rosnie do prawej)\n2.po trafionym strzale mozna oddac kolejny w ramach  tej samej tury\n3.Sa 4 rodzaje statkow 2 masztowy 3 masztowy 4 masztowy i 5 masztowy\n4.gra konczy sie po zatopieniu wszytkich statkow przeciwnik\n5.Koordynaty mozna podawac w sposob np.: 1 spacja 1 lub 1 enter 1\n6.nie da sie cofac oddanych strzalow\n\n\ dodatkowe opcje:\n1.jest mozliwosc wlaczenia automatycznego kropkowania statku(gdy zatopi sie statek w okol niego znajda sie symbol 'O' tam juz strzelac nie trzeba)\n2.automatyczne rozstawienie statków\n 3. dobranie ilosci statkow(przeciwnik bedzie mial tyle samo)\n";
	// GAME PHASES
	while (nextMove != 'k')
	{
			std::cout << "wcisnij k aby kontynuowac rozgrywke\n";
			std::cin >> nextMove;
	}
	system("cls");
		nextMove = ' ';
	//setting the automatic ship placer
	std::cout << "czy chcesz aby statki zostaly rozstawione automatycznie? y/n\n";
	std::cin >> nextMove;
	gamer.setAutomaticShip(nextMove);
	//seting the automatic ship spots
	std::cout << "czy chcesz aby statki zostaly oznaczane dookola automatycznie? y/n\n";
	std::cin >> nextMove;
	enemy.setAutomaticSpotting(nextMove);
	//setting the ships
	std::cout << "czy chcesz ilosci statkow zostaly zmienione? y/n\n";
	std::cin >> nextMove;
	gamer.setShips(nextMove);
	enemy.copyTheShips(gamer);
	while (nextMove != 'k')
	{
		std::cout << "wcisnij k aby kontynuowac rozgrywke\n";
		std::cin >> nextMove;
	}
	system("cls");
	

	//faza 1 rozstawienie statkow
	int licznikRozstawienia = 0;
	while (true)
	{
		if (gamer.ifAutomaticShips() == true)
			while (gamer.AutomaticAddShips() == false);
		else
			gamer.addShips();
		while (enemy.AutomaticAddShips() == false);
		std::cout << "czy statki zostaly poprawnie rozstawione? y/n\n";
		std::cin >> nextMove;
		licznikRozstawienia++;
		if(nextMove == 'y')
			break;
		if(licznikRozstawienia > 5)
		{
			std::cout << "prosze zmienic ilosc statków y/n\n";
			std::cin >> nextMove;
			if (nextMove == 'y')
			{
				gamer.setShips(nextMove);
				enemy.copyTheShips(gamer);
				licznikRozstawienia = 0;
				system("cls");
			}
			else
			{
				exit(-1);
			}
		}

	}
	
	
	//faza 2 gra
	while (gamer.getLives() > 0 || enemy.getLives() > 0)
	{
		system("cls");
		std::cout << "rozpoczyna gracz\n";
		std::cout << nowaTura << " tura\n";
		std::cout << "przeciwnik oddal strzal w nastepujace koordynaty\t"<<enemy.showNextX()+1<<"\t"<<enemy.showNextY()+1<<"\n";
		gamer.showTheBoard();
		enemy.showTheBoard();
		while (enemy.hit(0, 0) == false);
	//	while (nextMove != 'k')
		//{
		//	std::cout << "wcisnij k aby kontynuowac rozgrywke\n";
	//		std::cin >> nextMove;
		//}
		//nextMove = ' ';
		
		while (enemy.wasLastShotHit() == true)
		{
			
			gamer.showTheBoard();
			enemy.showTheBoard();
			while (enemy.hit(0, 0) == false);
			//while (nextMove != 'k')
			//{
			//	std::cout << "wcisnij k aby kontynuowac rozgrywke\n";
			//	std::cin >> nextMove;
			//}
		}
		int innylicznik = 0;
			enemy.nextTarget(gamer);
			bool didcomputerhit = gamer.hit(enemy.showNextX(),enemy.showNextY());
			while (didcomputerhit == false&& innylicznik<100)
			{
				enemy.nextTarget(gamer);
				
				didcomputerhit = gamer.hit(enemy.showNextX(), enemy.showNextY());
				innylicznik++;
				if (innylicznik >50)
				{
					break;
				}
			}
	
			int licznik = 0;
		while (gamer.wasLastShotHit() == true)
			{
			licznik++;
				enemy.nextTarget(gamer);
			
				while (gamer.hit(enemy.showNextX(), enemy.showNextY()) == false)
				{
					if(licznik>50)
					{
						break;
					}
					licznik++;
				enemy.nextTarget(gamer);
				}
				if (licznik > 50)
				{
					break;
				}
			}
		
		
		
		
		nowaTura++;
	}
	
	

}