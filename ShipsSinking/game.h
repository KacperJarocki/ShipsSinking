#pragma once
#include "player.h"
#include "computer.h"
class game
{
public:
	void intro() const;

		void phaseOne(player & gamer, computer & enemy);
		void phaseTwo(player & gamer, computer & enemy);
		void phaseThree(player & gamer, computer & enemy);
		

};

