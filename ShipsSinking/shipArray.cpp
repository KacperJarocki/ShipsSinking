    #include "shipArray.h"

shipArray::shipArray()
{
	countOfShips = 0;
}

void shipArray::addShipToArray(ship& ship)
{
	arrayOfShips[countOfShips] = ship;
	countOfShips++;
}

int shipArray::countOfLives()
{
if(countOfShips == 0)return 0;
	
	int suma = 0;
	ship shipToSum;
	for (int i = 0; i < countOfShips; i++)
	{
		shipToSum = arrayOfShips[i];
		suma = suma + shipToSum.getLive();
	}
	return suma;
}

ship shipArray::findAShip(int x, int y)
{
	ship checkedShip;
	for(int i = 0;i<countOfShips;i++)
	{
		checkedShip = arrayOfShips[i];
		if (checkedShip.isThisShipHere(x,y))
		{
			break;
		}
	}
	return checkedShip;
}
