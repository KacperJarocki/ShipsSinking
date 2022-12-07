#include "ships.h"

#include <iostream>

bool ifOutsideOfArrey(int x, int y,int maszty)
{
	if (11>x && 11 > y && x>0 && y>0 && maszty > 0 && maszty < 6)
		return false;
	return true;

}

/**
is checking if ship can be placed
returns true when its possible
 */
bool ships::canIPlaceShip(int x, int y, int rzad, int miejsca  ) const
{
	for (int i = x; i < rzad + x; i++)
		for (int j = y; j < miejsca + y; j++)
			if(i>-1 && i<10 && j>-1 && j < 10)
				if (positions[i][j] == 1)
					return false;
	return true;
}


/**
 todo:dodac ship::where w odpowiednie miejsce w add ship to game
 
 */
void ships::addShipToGame(shipArray& shipTab,int maszty)///bezpieczne dodanie statku ze sprawdzeniami
{
	int x=-1, y = -1;
	ship shipToAdd;

	std::cout << "podaj x , y a ten statek ma "<<maszty<<" masztow\n";
		std::cin >>  x;
		std::cin >>  y;

	
	
	shipToAdd.setMasztAndLives(maszty);
	
	
	if (ifOutsideOfArrey(x, y, maszty) == false)
	{
		if (positions[x-1][y-1]==1)
		{
			std::cout << "ju¿ jest tam statek\n";
			addShipToGame(shipTab, maszty);
		}
		if (positions[x-1][y-1] == 0)
		{
			x = x - 1;
			y = y - 1;
			if (canIPlaceShip(x-1, y-1, 3, 3) == true)
			{
				if (maszty == 1)addShip(x, y, shipToAdd);
				else
				{
					addLongShip(x, y, maszty, shipToAdd);
				}
				shipTab.addShipToArray(shipToAdd);
			}
			else
			{
				std::cout << "to wbrew zasada\n";
				addShipToGame(shipTab, maszty);
			}
			return;
		}
		
	}
	else
	{
		std::cout << "wyszedles poza pola gry albo ilosc masztow w twoim statku jest za duza\n";
		addShipToGame(shipTab,maszty);
	}		

}





void ships::clearPositions()// raczej nie potrzebne do weryfikacji
{
	for(int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			positions[i][j] = 0;
}

/**
todo: poprawic player screen
 */
void ships::addShip(int x, int y,ship &p)
{	
	
	positions[x][y] = 1;
	p.setWhere(x, y);
	//sum++;
	
	
}

/**
 checks if there is any ship at given coordinates
 todo: napisac metode hit z zabezpieczeniami
 */
bool ships::hit(int x, int y)
{
	int hitted = 2, missed = 3;
	
	if (positions[x-1][y-1] == 1)
	{
		positions[x-1][y-1] = hitted;
		return true;
	std::cout<<"u got a hit"<<std::endl;
		
	}
	else
	{
		positions[x-1][y-1] = missed;
		std::cout << "u missed" << std::endl;
		return false;
	}
	playerScreen();
}

/**
 do poprawy
 */
void ships::playerScreen() const

{
	std::cout << "kolejna tura\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			std::cout << positions[i][j] << "\t";
		std::cout << std::endl;
	}
	
}


void ships::addLongShip(int x,int y,int maszty,ship& shipToAdd)
{
	char whichWay;
	bool prawo = false, gora = false, dol = false, lewo = false;
	///if direction is false -> u cant move that direction
	///if direction is true -> u can move that direction
						/// up
	if (x >= maszty -1)
	{
		if(canIPlaceShip(x-maszty,y-1,maszty, 3)==true)gora = true;
	}

						/// down
	if(x+maszty<11)
	{
		if (canIPlaceShip(x-1, y - 1, maszty, 3) == true)dol = true;
	}

							/// right
	if(y + maszty < 11)
	{
		if (canIPlaceShip(x - 1, y, 3, maszty) == true)prawo = true;
	}
						///	left
	if(y >= maszty - 1)
	{
		if (canIPlaceShip(x - 1, y - maszty, 3, maszty) == true)lewo = true;
	}
	std::cout << "aby przedlozyc statki o reszte masztow w prawo wcisnij P aby w dol D w gore G i w lewo l\n";
	while (true)
	{
		std::cin >> whichWay;

		if ((whichWay == 'p' && prawo==true) || (whichWay == 'd' && dol ==true) || ( whichWay == 'g' && gora == true)||(whichWay == 'l' && lewo == true))break;

		else std::cout << "kliknij prawidlowa opcje\n";
	}
	std::cout << lewo<<"\n";
	switch (whichWay)
	{
	case 'p':
		for (int i = 0; i < maszty; i++)
			addShip(x, y + i, shipToAdd);
		break;
	case 'd':
		for (int i = 0; i < maszty; i++)
			addShip(x + i, y, shipToAdd);
		break;
	case 'g':
		for (int i = 0; i < maszty; i++)
			addShip(x - i, y, shipToAdd);
		break; 
	case 'l':
		for (int i = 0; i < maszty; i++)
			addShip(x, y - i, shipToAdd);
		break;
	}

	

}



