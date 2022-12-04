#include "ships.h"
#include "user.h"
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
			if (positions[i][j] == 1)
				return false;
	return true;
}




void ships::addShipToGame()///bezpieczne dodanie statku ze sprawdzeniami
{
	int x, y, maszty;
	ship shipToAdd;
	
	std::cout << "podaj x , y, a nastepnie ilu masztowy jest to statek\n";
	std::cin >> x;
	std::cin >> y;
	std::cin >> maszty;
	shipToAdd.setMasztAndLives(maszty);
	
	
	if (ifOutsideOfArrey(x, y, maszty) == false)
	{
		
		if (positions[x-1][y-1]==1)
		{
			std::cout << "ju¿ jest tam statek\n";
			addShipToGame();
		}
		if (positions[x-1][y-1] == 0)
		{
			x = x - 1;
			y = y - 1;
			
			 ///dodawanie pierwszego pola lub jednego masztu
				if (x == 0 && y == 0)
				{
					if (canIPlaceShip(x, y, 2, 2) == true)
					{
						if (maszty == 1)addShip(x, y);
						else
						{
							addLongShip(x, y, maszty);
						}
					}
					else
					{
						std::cout << "to wbrew zasada\n";
						addShipToGame();
					}
					return;
				}
				if ((x == 0) && (y == 9))
				{
					if (canIPlaceShip(0, 8, 2, 2) == true)
					{
						if (maszty == 1)addShip(x, y);
						else
						{
							addLongShip(x, y, maszty);
						}
					}
					else
					{
						std::cout << "to wbrew zasada\n";
						addShipToGame();
					}

					return;
				}
				if ((x == 9) && (y == 0))
				{
					if (canIPlaceShip(8, y, 2, 2) == true)
					{
						if (maszty == 1)addShip(x, y);
						else
						{
							addLongShip(x, y, maszty);
						}
					}
					else
					{
						std::cout << "to wbrew zasada\n";
						addShipToGame();
					}

					return;

				}
				if ((x == 9) && (y == 9))
				{
					if (canIPlaceShip(8, 8, 2, 2) == true)
					{
						if (maszty == 1)addShip(x, y);
						else
						{
							addLongShip(x, y, maszty);
						}
					}
					else
					{
						std::cout << "to wbrew zasada\n";
						addShipToGame();
					}

					return;
				}
				if ((x == 0) && (y < 9))
				{
					if (canIPlaceShip(x, y - 1, 2, 3) == true)
					{
						if (maszty == 1)addShip(x, y);
						else
						{
							addLongShip(x, y, maszty);
						}
					}
					else
					{
						std::cout << "to wbrew zasada\n";
						addShipToGame();
					}

					return;
				}
				if ((x == 9) && (y < 9))
				{
					if (canIPlaceShip(x - 1, y - 1, 2, 3) == true)
					{
						if (maszty == 1)addShip(x, y);
						else
						{
							addLongShip(x, y, maszty);
						}
					}
					else
					{
						std::cout << "to wbrew zasada\n";
						addShipToGame();
					}

					return;
				}
				if ((y == 0) && (x < 9))
				{
					if (canIPlaceShip(x - 1, y, 3, 2) == true)
						addShip(x, y);
					else
					{
						std::cout << "to wbrew zasada\n";
						addShipToGame();
					}

					return;
				}
				if (y == 9 && x < 9)
				{
					if (canIPlaceShip(x - 1, y - 1, 3, 2) == true)
						addShip(x, y);
					{
						std::cout << "to wbrew zasada\n";
						addShipToGame();
					}

					return;
				}
				if (x > 0 && x < 9 && y>0 && y < 9)
				{
					if (canIPlaceShip(x - 1, y - 1, 3, 3) == true)
					{
						if(maszty == 1)addShip(x, y);
						else
						{
							addLongShip(x, y, maszty);
						}
					}
					else
					{
						std::cout << "to wbrew zasada\n";
						addShipToGame();
					}

					return;
				}
			
				
			


		}
		
	}
	else
	{
		std::cout << "wyszedles poza pola gry albo ilosc masztow w twoim statku jest za duza\n";
		addShipToGame();
	}		

}

void ships::addLives(int n)
{
	lives = n;
	sum = 0;
}

void ships::liveCheck() const
{
	if (lives < 1)
	{
		std::cout << "u lost :(";
		exit(0);
	}
}

void ships::clearPositions()
{
	for(int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			positions[i][j] = 0;
}

/**
 adds ship to the board
 */
void ships::addShip(int x, int y)
{	
	
	positions[x][y] = 1;
	sum++;
	
	playerScreen();
}

/**
 checks if there is any ship at given coordinates
 */
void ships::hit(int x, int y)
{
	int hitted = 2, missed = 3;
	if (positions[x-1][y-1] == 1)
	{
		positions[x-1][y-1] = hitted;
		std::cout<<"u got a hit"<<std::endl;
		lives--;
		liveCheck();
	}
	else
	{
		positions[x-1][y-1] = missed;
		std::cout << "u missed" << std::endl;
	}
	playerScreen();
}

void ships::playerScreen() const

{
	std::cout << "kolejna tura\n";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\n";
		for (int j = 0; j < 10; j++)
			std::cout << positions[i][j] << "\t";
	}
	std::cout << std::endl;
}

void ships::addLongShip(int x,int y,int maszty)
{
	char whichWay;
	bool prawo = false, gora = false, dol = false, lewo = false;
	///if direction is false -> u cant move that direction
	///if direction is true -> u can move that direction
						/// up
	if (x >= maszty -1)
	{
		if(canIPlaceShip(x-maszty-1,y-1,maszty, 3)==true)gora = true;
		
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
			addShip(x, y + i);
		break;
	case 'd':
		for (int i = 0; i < maszty; i++)
			addShip(x + i, y);
		break;
	case 'g':
		for (int i = 0; i < maszty; i++)
			addShip(x - i, y);
		break;
	case 'l':
		for (int i = 0; i < maszty; i++)
			addShip(x, y - i);
		break;
	}

	

}



