#include "game.h"

void game::intro() const
{
	char nextMove = ' ';
	std::cout << "wazne symbole:\n ~ - nieznane tzn woda\n = - statek \n X - trafiony statek\n * - nietrafiony strzal \n 0 - oznaczenia do okola zatopionego statku\n zasady gry:\n wpisujac koordynaty np 1 A odajemy strzaly, koordynat pierwszy jest w pionie(rosnie w dol ), drugi w poziomie (rosnie do prawej)\n2.po trafionym strzale mozna oddac kolejny w ramach  tej samej tury\n3.jest 5 rodzajow statkow 1 masztowy 2 masztowy 3 masztowy 4 masztowy i 5 masztowy\n4.gra konczy sie po zatopieniu wszytkich statkow przeciwnik\n5.Koordynaty mozna podawac w sposob 1 enter A\n6.nie da sie cofac oddanych strzalow\n\n\ dodatkowe opcje:\n1.jest mozliwosc wlaczenia automatycznego kropkowania statku(gdy zatopi sie statek w okol niego znajda sie symbol 'O' tam juz strzelac nie trzeba)\n2.automatyczne rozstawienie statkow\n 3. dobranie ilosci statkow(przeciwnik bedzie mial tyle samo)\n";

	while (nextMove != 'k')
	{
		std::cout << "wcisnij k aby kontynuowac rozgrywke\n";
		std::cin >> nextMove;
	}

}

void game::phaseOne(player& gamer, computer& enemy)
{
	char nextMove = ' ';
	system("cls");
	nextMove = ' ';
	//setting the automatic ship placer
	std::cout << "czy chcesz aby statki zostaly rozstawione automatycznie? y/jaka kolwiek litera\n";
	std::cin >> nextMove;
	gamer.setAutomaticShip(nextMove);
	//seting the automatic ship spots
	std::cout << "czy chcesz aby statki zostaly oznaczane dookola automatycznie? y/jaka kolwiek litera\n";
	std::cin >> nextMove;
	enemy.setAutomaticSpotting(nextMove);
	//setting the ships
	std::cout << "czy chcesz ilosci statkow zostaly zmienione? y/jaka kolwiek litera\n";
	std::cin >> nextMove;
	gamer.setShips(nextMove);
	enemy.copyTheShips(gamer);
	while (nextMove != 'k')
	{
		std::cout << "wcisnij k aby kontynuowac rozgrywke\n";
		std::cin >> nextMove;
	}
}

void game::phaseTwo(player& gamer, computer& enemy)
{
	system("cls");
	char nextMove = ' ';

	while (true)
	{
		if (gamer.ifAutomaticShips() == true)
			while (gamer.AutomaticAddShips() == false);
		else
			gamer.addShips();
		while (enemy.AutomaticAddShips() == false);
		std::cout << "Wpisz C jezeli chcesz wrocic na poprzednia strone nastepnie wcisnij eneter,\n jezeli nie to wpisz jaka kolwiek litere nastpnie wcisnij enter\n";
		std::cin >> nextMove;
		if (std::toupper(nextMove) == 'C')
		{
			phaseOne(gamer, enemy);
			phaseTwo(gamer, enemy);
		}
		else
			break;

	}
}

bool isItEnd(int pLives, int cLives)
{
	if (pLives < 1 || cLives < 1)
		return true;
	return false;
}
void game::phaseThree(player& gamer, computer& enemy)
{
	int nowaTura = 1;
	bool itsEnd = isItEnd(gamer.getLives(), enemy.getLives());
	
	
	while (itsEnd == false)
	{
		char nextMove = ' ';
		system("cls");
		std::cout << "rozpoczyna gracz\n";
		std::cout << nowaTura << " tura\n";
		std::cout << "przeciwnik oddal strzal w nastepujace koordynaty\t" << enemy.showNextX() + 1 << "\t" << enemy.showNextY() + 1 << "\n";
		gamer.showTheBoard();
		enemy.showTheBoard();
		while (enemy.hit(0, 0) == false);
		itsEnd = isItEnd(gamer.getLives(), enemy.getLives());
		while (nextMove != 'k')
		{
			std::cout << "wcisnij k aby oddbyl sie kolejny ostrzal\n";
			std::cin >> nextMove;
		}
		nextMove = ' ';

		while (enemy.wasLastShotHit() == true && itsEnd == false)
		{

			gamer.showTheBoard();
			enemy.showTheBoard();
			while (enemy.hit(0, 0) == false);
			itsEnd = isItEnd(gamer.getLives(), enemy.getLives());
			while (nextMove != 'k')
			{
				std::cout << "wcisnij k aby oddbyl sie kolejny ostrzal przypuscil ostrzal\n";
				std::cin >> nextMove;
			}
		}
		int innylicznik = 0;
		enemy.nextTarget(gamer);
		bool didcomputerhit = gamer.hit(enemy.showNextX(), enemy.showNextY());
		itsEnd = isItEnd(gamer.getLives(), enemy.getLives());
		while (didcomputerhit == false && innylicznik < 100)
		{
			enemy.nextTarget(gamer);

			didcomputerhit = gamer.hit(enemy.showNextX(), enemy.showNextY());
			itsEnd = isItEnd(gamer.getLives(), enemy.getLives());
			innylicznik++;
			if (innylicznik > 50)
			{
				break;
			}
		}

		int licznik = 0;
		while (gamer.wasLastShotHit() == true && itsEnd == false)
		{
			licznik++;
			enemy.nextTarget(gamer);

			while (gamer.hit(enemy.showNextX(), enemy.showNextY()) == false && itsEnd == false)
			{
				if (licznik > 50)
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
		itsEnd = isItEnd(gamer.getLives(), enemy.getLives());
	}

}
