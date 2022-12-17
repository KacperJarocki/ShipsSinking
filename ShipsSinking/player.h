#pragma once
#include "user.h"
class player :public user
{
	
public:
	friend void copyTheShips(const player& play);
	player();
	player(const player &copy);
	~player() =default;
};

