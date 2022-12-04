#pragma once



class ships
{
	int positions[10][10]{};
	int lives;
///	int sum;

	
public:
	void addShipToGame();
	void addLives(int n);
	void liveCheck() const;
	void clearPositions();
	void addShip(int x, int y);
	void hit(int x,int y);
	void playerScreen() const;
	void addLongShip(int x, int y, int maszty);
	bool canIPlaceShip(int x, int y, int kwadrat,int miejsca) const;

};