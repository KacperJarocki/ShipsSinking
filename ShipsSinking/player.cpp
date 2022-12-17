#include "player.h"

//tem sol
player::player()
{
	RUCOmputer = false;
	deadlyHit = false;
	automaticShips = true;
		quantityShips[0] = 3;
		quantityShips[1] = 2;
		quantityShips[2] = 2;
		quantityShips[3] = 1;



}

player::player(const player& copy)
{
	deadlyHit = copy.deadlyHit;
	RUCOmputer = copy.RUCOmputer;
	LastShotHit = copy.LastShotHit;
	shipTab.copy(copy.shipTab);
	myBoard.copy(copy.myBoard);
	

}
