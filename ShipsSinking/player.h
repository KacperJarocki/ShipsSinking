#pragma once
#include "user.h"
class player :public user
{
	int score;
	bool win; // if true then player won
public:
	void addingPoints();
	player();
	

};

