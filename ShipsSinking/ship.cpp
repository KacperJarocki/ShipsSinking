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
