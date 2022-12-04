#include "ship.h"

void ship::setMasztAndLives(int maszty)
{
	maszt = maszty;
	lives = maszty;
}

void ship::setWhere(int x, int y)
{
	where[x][y] = 1;
}
