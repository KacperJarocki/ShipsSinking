#pragma once
#include "shipArray.h"


class ships
{
	int positions[10][10]{};

public:
	void addShipToGame();
	void clearPositions();
	void addShip(int x, int y,ship& ship);
	void hit(int x,int y);
	void playerScreen() const;
	void addLongShip(int x, int y, int maszty, ship& shipToAdd);
	bool canIPlaceShip(int x, int y, int kwadrat,int miejsca) const;

};