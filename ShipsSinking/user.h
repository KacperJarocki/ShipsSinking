#pragma once
#include "ships.h"
#include  <iostream>

class user
{
protected:
	bool LastShotHit;//true if last shot was succesful false otherwise
	shipArray shipTab;
	ships myBoard;
	int  userLives;
	int  quantity5ships;// quantity of ships made of 5 blocks
	int  quantity4ships;
	int  quantity3ships;
	int  quantity2ships;
	int  quantity1ships;
	bool automaticShips;// if true your ships would be placed randomly on board, always true for comp
	bool automaticSpotsAroundShip;// if true when you will destroy enemy's ship it will surrounded by dots, always true for comp
public:
	//todo: napisac metody: odejmowanie zycia shiptab, zastanowic sie czego brakuje.
	bool ifAutomaticShips() const{return automaticShips;}
	bool ifAutomaticSpotsAroundShip() const { return automaticSpotsAroundShip;}\
	bool wasLastShotHit() const { return LastShotHit; }
	void setLives()const;
	void liveCheck() const;/// game ender

};

