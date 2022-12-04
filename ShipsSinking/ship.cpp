#include "ship.h"

ship::ship()
{
	maszt = 0;
	lives = 0;
}

void ship::setMasztAndLives(int maszty)
{
	maszt = maszty;
	lives = maszty;
}

void ship::setWhere(int x, int y)
{
	where[x][y] = 1;
}

bool ship::isThisShipHere(int x, int y) const
{
	if(where[x][y]==1)return true;
	return false;
}

void ship::oneLiveDown()
{
	lives--;
}

bool ship::wasItKillShot() const
{
	if(lives==0)return true;
	
	return false;
}

int ship::getLive() const
{
	return lives;
}
