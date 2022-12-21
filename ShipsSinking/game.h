#pragma once
#include "player.h"
#include "computer.h"
class game
{
	player gamer;
	computer enemy;
public:
	void intro() const;

		void phaseOne();
		void phaseTwo();
		void phaseThree();
		

};

