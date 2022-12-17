    #include "shipArray.h"

void shipArray::copy(const shipArray& shiptab)
{
	countOfShips = shiptab.countOfShips;
	for (int i = 0; i < shiptab.countOfShips; i++)
	{
		arrayOfShips[i] = shiptab.arrayOfShips[i];
	}
}

shipArray::shipArray()
{
	countOfShips = 0;
}

void shipArray::addShipToArray(ship& ship)
{
	ship.setShip();
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

bool shipArray::wasItDeadlyShot(int x, int y)
{
	minusOneLive(x, y);
	if (specificLives(findAShip(x, y)) < 1)
		return true;
	return false;
}

void shipArray::clearArray()
{
	ship clear;
	for(int i = 0;i< countOfShips;i++)
	{
		arrayOfShips[i] = clear;
	}
}

int shipArray::getHeadXofShip(int x, int y) const
{
	int addres;
	ship shipKilled;
	addres = findAShip(x, y);
	shipKilled = arrayOfShips[addres];
	return shipKilled.getHeadXofShip();
}

int shipArray::getHeadYofShip(int x, int y) const
{
	int addres;
	ship shipKilled;
	addres = findAShip(x, y);
	shipKilled = arrayOfShips[addres];
	return shipKilled.getHeadYofShip();
}

bool shipArray::czyPoziom(int x, int y) const
{
	int addres;
	ship shipKilled;
	addres = findAShip(x, y);
	shipKilled = arrayOfShips[addres];
	return shipKilled.PoziomCzyPion();
}



int shipArray::getMasztyShip(int x, int y) const
{
	int addres;
	ship shipKilled;
	addres = findAShip(x, y);
	shipKilled = arrayOfShips[addres];
	return shipKilled.getMaszt();
}


