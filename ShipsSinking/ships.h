#pragma once
#include "shipArray.h"


class ships
{
	int positions[10][10]{};

public:
	void addShipToGame(shipArray &shipTab,int maszty);
	void clearPositions();
	void addShip(int x, int y,ship& ship);
	bool hit(int x,int y);///returns true if ship was hitted
	void playerScreen() const;
	void addLongShip(int x, int y, int maszty, ship& shipToAdd);
	bool canIPlaceShip(int x, int y, int kwadrat,int miejsca) const;

};