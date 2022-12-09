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
	int countOfLives() const;
	int findAShip(int x,int y) const;
	void minusOneLive(int x, int y);
	int specificLives(int index) const;
	bool wasItDeadlyShot(int x, int y) ;
	void clearArray();
	int getHeadXofShip(int x,int y)const;
	int getHeadYofShip(int x, int y)const;  
	bool czyPoziom(int x, int y) const;
	int getMasztyShip(int x, int y)const;
	

};

