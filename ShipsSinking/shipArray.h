#pragma once
#include "ship.h"
class shipArray
{
	ship arrayOfShips[20]{};
	int countOfShips;
public:
	//todo: dodac metode zliczajaca zycia, szukajaca staku  o danych koordynatach, odejmujaca zycie statkowi o danych koordynatach dodac do meitd
	shipArray();
	void addShipToArray(ship& ship);
	int countOfLives();
	ship findAShip(int x,int y);
};

