#pragma once
#include "ships.h"
#include  <iostream>

class user
{
protected:
	bool deadlyHit;
	bool RUCOmputer;
	bool LastShotHit;//true if last shot was succesful false otherwise
	shipArray shipTab;
	ships myBoard;
	int  userLives;
	int  quantityShips[4]{};// quantity of ships of each index is another 
	bool automaticShips;// if true your ships would be placed randomly on board, always true for comp
	bool automaticSpotsAroundShip;// if true when you will destroy enemy's ship it will surrounded by dots, always true for comp
	friend class computer;
public:
	user();
	bool didHitKill() const { return deadlyHit; }
	bool ifAutomaticShips() const{return automaticShips;}
	bool ifAutomaticSpotsAroundShip() const { return automaticSpotsAroundShip;}
	bool wasLastShotHit() const { return LastShotHit; }
	bool wasItDeadly() const { return deadlyHit; }
	void setLives();///count lives of all of user ships
	void liveCheck() const;/// game ender
	void addShips();/// user adds all ships to the game bas
	bool hit(int x,int y);///user hit a ship,true if coordinates are good
	void testing();
	int getLives() const;
	void spotsAroundShip(int x, int y);
	bool AutomaticAddShips();
	void showTheBoard()const;
	bool didHit(int x, int y)const;
	void setAutomaticShip(const char m);
	void setAutomaticSpotting(const char m);
	void setShips(const char m);
	
	

};

