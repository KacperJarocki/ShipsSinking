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

int shipArray::countOfLives() const
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

int shipArray::findAShip(int x, int y) const
{
	ship checkedShip;
	int addres=-1;
	for(int i = 0;i<countOfShips;i++)
	{
		checkedShip = arrayOfShips[i];
		if (checkedShip.isThisShipHere(x,y))
		{
			addres = i;
			break;
		}
	}
	return addres;
}

void shipArray::minusOneLive(int x, int y)
{
	ship hittedShip;
	int addres;
	addres = findAShip(x, y);
	hittedShip = arrayOfShips[addres];
	hittedShip.oneLiveDown();
	arrayOfShips[addres] = hittedShip;
	
}

int shipArray::specificLives(int index) const
{
	ship shipL;
	shipL = arrayOfShips[index];
	return shipL.getLive();
}

