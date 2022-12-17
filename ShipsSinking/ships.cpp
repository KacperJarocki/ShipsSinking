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

void ships::enemyScreen() const
{
	std::cout << "statki przeciwnika\n";
	for(int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			switch (positions[i][j])
			{
			case 0:
				std::cout << "-" << "\t";
				break;
			case 1:
				std::cout << "-" << "\t";
				break;
			case 2:
				std::cout << "X" << "\t";
				break;
			case 3:
				std::cout << "*" << "\t";
				break;
			case 4:
				std::cout << "O" << "\t";
				break;
			}
		std::cout << std::endl;
	}

}

bool ships::AutomaticAddShipToGame(shipArray& shipTab, int maszty, int x, int y)
{
	ship shipToAdd;
	bool zmianaKoordynatow;
	
	shipToAdd.setMasztAndLives(maszty);


	if (ifOutsideOfArrey(x, y, maszty) == false)
	{
		if (positions[x][y] == 1)
		{
			return false;
		}
		if (positions[x][y] == 0)
		{
			if (canIPlaceShip(x - 1, y - 1, 3, 3) == true)
			{
				if (maszty == 1)
				{
					addShip(x, y, shipToAdd);
					return true;
				}
				else
				{
					zmianaKoordynatow = AutomaticAddLongShip(x, y, maszty, shipToAdd);
					if (zmianaKoordynatow == false)
					{
						return false;
					}

				}
				shipTab.addShipToArray(shipToAdd);
				return true;

			}

		}

	}
	else
	{
		return false;
	}
	return false;
}

bool ships::AutomaticAddLongShip(int x, int y, int maszty, ship& shipToAdd)
{
	int whichWay;
	bool prawo = false, gora = false, dol = false, lewo = false;
	///if direction is false -> u cant move that direction
	///if direction is true -> u can move that direction
						/// up
	if (x >= maszty - 1)
	{
		if (canIPlaceShip(x - maszty, y - 1, maszty + 1, 3) == true)gora = true;
	}

	/// down
	if (x + maszty < 11)
	{
		if (canIPlaceShip(x, y - 1, maszty + 1, 3) == true)dol = true;
	}

	/// right
	if (y + maszty < 11)
	{
		if (canIPlaceShip(x - 1, y, 3, maszty + 1) == true)prawo = true;
	}
	///	left
	if (y >= maszty - 1)
	{
		if (canIPlaceShip(x - 1, y - maszty, 3, maszty + 1) == true)lewo = true;
	}
	if ((prawo | lewo | gora | dol) == false)
	{
	
		return false;
	}
	
	while (true)
	{
		whichWay =std::rand() % (4);

		if ((whichWay == 1 && prawo == true) || (whichWay == 2 && dol == true) || (whichWay == 3 && gora == true) || (whichWay == 0 && lewo == true))break;
	}

	switch (whichWay)
	{
	case 1:
		for (int i = 0; i < maszty; i++)
			addShip(x, y + i, shipToAdd);
		break;
	case 2:
		for (int i = 0; i < maszty; i++)
			addShip(x + i, y, shipToAdd);
		break;
	case 3:
		for (int i = 0; i < maszty; i++)
			addShip(x - i, y, shipToAdd);
		break;
	case 0:
		for (int i = 0; i < maszty; i++)
			addShip(x, y - i, shipToAdd);
		break;
	}
	return true;
}

void ships::spotting(int x, int y, int kwadrat, int miejsca)
{
	
	for (int i = x; i < kwadrat + x; i++)
		for (int j = y; j < miejsca + y; j++)
			if(i > -1 && i < 10 && j>-1 && j < 10)
				if(positions[i][j] == 0)
						positions[i][j] = 4;


				
	
}

bool ships::didIHit(int x, int y) const
{
	if(positions[x][y] == 1)
		return true;
	return false;
}


void ships::copy(const ships& copy)
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			positions[i][j] = copy.positions[i][j];
}

bool ships::canIshotThere(int x, int y) const
{
	if(positions[x][y]==2 || positions[x][y] == 3 || positions[x][y] == 4)
		return false;
	return true;
}



bool ships::addShipToGame(shipArray& shipTab,int maszty)///bezpieczne dodanie statku ze sprawdzeniami
{
	int x=-1, y = -1;
	ship shipToAdd;
	bool zmianaKoordynatow=true;

	std::cout << "podaj x , y a ten statek ma,wpisz "<<maszty<<" masztow\n";
		std::cin >>  x;
		std::cin >>  y;

	
	
	shipToAdd.setMasztAndLives(maszty);
	
	
	if (ifOutsideOfArrey(x, y, maszty) == false)
	{
		if (positions[x-1][y-1]==1)
		{
			std::cout << "ju¿ jest tam statek\n";
			return false;
		}
		if (positions[x-1][y-1] == 0)
		{
			x = x - 1;
			y = y - 1;
			if (canIPlaceShip(x-1, y-1, 3, 3) == true)
			{
				if (maszty == 1)
				{
					addShip(x, y, shipToAdd);
					shipToAdd.setShip();
					return true;
				}
				else
				{
					zmianaKoordynatow = addLongShip(x, y, maszty, shipToAdd);
					if (zmianaKoordynatow==false)
					{
						return false;
					}

				}
				shipTab.addShipToArray(shipToAdd);
				return true;
				
			}
			else
			{
				std::cout << "to wbrew zasada\n";
				return false;
			}
			
		}
		
	}
	else
	{
		std::cout << "wyszedles poza pola gry albo ilosc masztow w twoim statku jest za duza\n";
		return false;
	}		
	return false;
}





void ships::clearPositions()//clears the board
{
	for(int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			positions[i][j] = 0;
}


void ships::addShip(int x, int y,ship &p)
{	
	
	positions[x][y] = 1;
	p.setWhere(x, y);
	//sum++;
	
	
}


bool ships::hit(int x, int y)
{
	int hitted = 2, missed = 3 ;
	
	if (positions[x][y] == 1)
	{
		positions[x][y] = hitted;
		return true;
	}
	if(positions[x][y] == missed || positions[x][y] == hitted )
	{
		std::cout << "you already shot there";
		return false;
	}
	if (positions[x][y]==4)
	{
		std::cout << "its spotted";
		return false;
	}
	if(positions[x][y]==0)
	{
		positions[x][y] = missed;
		std::cout << "u missed" << std::endl;
		return false;
	}
	else
	{
		std::cout << "smt wrong with the board";
		return false;
	}
}


void ships::playerScreen() const

{
	std::cout << "moje statki\n";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			switch (positions[i][j])
			{
				case 0:
				std::cout << "-" << "\t";
				break;
				case 4:
					std::cout << "-" << "\t";
					break;
				case 1:
					std::cout << "[]" << "\t";
					break;
				case 2:
					std::cout << "X" << "\t";
					break;
				case 3:
					std::cout << "*" << "\t";
				break;
			}
		std::cout << std::endl;
	}
}


bool ships::addLongShip(int x,int y,int maszty,ship& shipToAdd)
{
	char whichWay;
	bool prawo = false, gora = false, dol = false, lewo = false;
	///if direction is false -> u cant move that direction
	///if direction is true -> u can move that direction
						/// up
	if (x >= maszty - 1)
	{
		if (canIPlaceShip(x - maszty, y - 1, maszty+1, 3) == true)gora = true;
	}

	/// down
	if (x + maszty < 11)
	{
		if (canIPlaceShip(x, y - 1, maszty+1, 3) == true)dol = true;
	}

	/// right
	if (y + maszty < 11)
	{
		if (canIPlaceShip(x -1,y, 3, maszty+1) == true)prawo = true;
	}
	///	left
	if (y >= maszty - 1)
	{
		if (canIPlaceShip(x - 1, y - maszty, 3, maszty+1) == true)lewo = true;
	}
	if((prawo|lewo|gora|dol)==false)
	{
		std::cout << "zamien koordynaty statku";
		return false;
	}
	
	std::cout << "aby przedlozyc statki o reszte masztow w prawo wcisnij P aby w dol D w gore G i w lewo l, lub c gdy chcesz zmienic polozenie statku\n";
	while (true)
	{
		std::cin >> whichWay;

		if ((whichWay == 'p' && prawo == true) || (whichWay == 'd' && dol == true) || (whichWay == 'g' && gora == true) || (whichWay == 'l' && lewo == true) || whichWay == 'c')break;
		else std::cout << "kliknij prawidlowa opcje\n";
	}
	
	switch (whichWay)
	{
	case 'p':
		for (int i = 0; i < maszty; i++)
			addShip(x, y + i, shipToAdd);
		shipToAdd.setShip();
		break;
	case 'd':
		for (int i = 0; i < maszty; i++)
			addShip(x + i, y, shipToAdd);
		shipToAdd.setShip();
		break;
	case 'g':
		for (int i = 0; i < maszty; i++)
			addShip(x - i, y, shipToAdd);
		shipToAdd.setShip();
		break; 
	case 'l':
		for (int i = 0; i < maszty; i++)
			addShip(x, y - i, shipToAdd);
		shipToAdd.setShip();
		break;
	case 'c':
		return false;
		
	}
	return true;
	

}



