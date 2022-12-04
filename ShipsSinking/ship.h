#pragma once
class ship
{
	int maszt;
	int lives;
	int where[10][10]{};
public:
	void setMasztAndLives(int maszty);
	void setWhere(int x, int y);


};

