#include "user.h"


void user::setLives()
{
 userLives = shipTab.countOfLives();
}

void user::liveCheck() const
{
	if (userLives < 1)
	{
		std::cout << "u lost :(";
		exit(0);
	}
}
