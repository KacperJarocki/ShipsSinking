#include "player.h"

//tem sol
player::player()
{
	RUCOmputer = false;
	deadlyHit = false;
	automaticShips = false;
		quantityShips[0] = 4;
		quantityShips[1] = 3;
		quantityShips[2] = 2;
		quantityShips[3] = 1;
		quantityShips[4] = 0;



}

player::player(const player& copy)
{
	deadlyHit = copy.deadlyHit;
	RUCOmputer = copy.RUCOmputer;
	LastShotHit = copy.LastShotHit;
	shipTab.copy(copy.shipTab);
	myBoard.copy(copy.myBoard);
	

}
