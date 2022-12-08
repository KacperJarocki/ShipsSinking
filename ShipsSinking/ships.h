#pragma once
#include "shipArray.h"


class ships
{
	int positions[10][10]{};

public:
	bool addShipToGame(shipArray &shipTab,int maszty);
	void clearPositions();
	void addShip(int x, int y,ship& ship);
	bool hit(int x,int y);///returns true if ship was hitted
	void playerScreen() const;
	bool addLongShip(int x, int y, int maszty, ship& shipToAdd);
	bool canIPlaceShip(int x, int y, int kwadrat,int miejsca) const;
	void enemyScreen() const;
	bool AutomaticAddShipToGame(shipArray& shipTab, int maszty,int x,int y);
	bool AutomaticAddLongShip(int x, int y, int maszty, ship& shipToAdd);
};