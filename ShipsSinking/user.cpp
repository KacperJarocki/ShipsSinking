#include "user.h"

#include <string>

bool is_number(const std::string& s)
{
	return !s.empty() && std::find_if(s.begin(),
		s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}
bool containsOnlyLetters(std::string const& str) {
	return str.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") ==
		std::string::npos;
}


user::user()
{
}

void user::setLives()
{
	userLives = shipTab.countOfLives();
}

void user::addShips()
{
	myBoard.clearPositions();
	shipTab.clearArray();
	for (int i = 0; i < 5; i++)
	{
		system("cls");
		myBoard.playerScreen();
		for (int j = 0; j < quantityShips[4 - i]; j++)
		{
			std::string xS = " ", yS = " ";
			int x, y;
				bool isNumber = false;
				bool isLetter = false;
				char ch2[10];
				std::cout << "podaj numer z zakresu 1 - 10 wcisnij enter nastepnie podaj litere A - J,\n beda one reprezentowaly twoje koordynaty:\n ";

				while (isNumber == false)
				{
					std::getline(std::cin, xS);
					while (xS.length() > 2)
					{
						std::cout << "podaj numer z zakresu 1 - 10 wcisnij enter\n ";
						std::getline(std::cin, xS);
					}
					isNumber = is_number(xS);
				}
				while (isLetter == false)
				{
					std::cout << "podaj litere z zakresu A - J :\n ";
					std::getline(std::cin, yS);
					while (yS.length() != 1)
					{
						std::cout << "podaj JEDNA litere z zakresu A - J :\n ";
						std::getline(std::cin, yS);
					}
					isLetter = containsOnlyLetters(yS);
				}

				strncpy_s(ch2, yS.c_str(), sizeof(ch2));
				x = std::stoi(xS) - 1;
				y = (int)std::toupper(ch2[0]) - 'A';

			
			myBoard.playerScreen();
			while (myBoard.addShipToGame(shipTab, 5-i,x,y) == false);
		}
		
	}
	setLives();
}

bool user::hit(int x, int y)
{
	std::string xS =" ", yS= " ";
	
	
	
	if(RUCOmputer == true)
	{
		bool isNumber = false;
		bool isLetter = false;
		char ch2[10];
		std::cout << "podaj numer z zakresu 1 - 10 wcisnij enter nastepnie podaj litere A - J,\n beda one reprezentowaly twoje koordynaty:\n ";
		
		while (isNumber == false)
		{
			std::getline(std::cin, xS);
			while (xS.length()>2)
			{
				std::cout << "podaj numer z zakresu 1 - 10 wcisnij enter\n ";
				std::getline(std::cin, xS);
			}
			isNumber = is_number(xS);
		}
		while (isLetter == false)
		{
			std::cout << "podaj litere z zakresu A - J :\n ";
			std::getline(std::cin, yS);
			while (yS.length()!= 1)
			{
				std::cout << "podaj JEDNA litere z zakresu A - J :\n ";
				std::getline(std::cin, yS);
			}
			isLetter = containsOnlyLetters(yS);
		}
		
		strncpy_s(ch2, yS.c_str(), sizeof(ch2));
		x = std::stoi(xS) - 1;
		y = (int)std::toupper(ch2[0]) - 'A';

	}
	if (x > -1 && x < 10 && y>-1 && y < 10)
	{

		if (myBoard.canIshotThere(x, y) == true)
		{
		
		LastShotHit = myBoard.hit(x, y);
		if (LastShotHit == true)
		{
			deadlyHit = shipTab.wasItDeadlyShot(x, y);
			if (deadlyHit== true)
			{
				std::cout << "trafiony zatopiony\n";
				if (automaticSpotsAroundShip == true)
				{
					spotsAroundShip(x, y);
				}
			}
		}
		setLives();
		}
		else
		{
			return false;
		}
	}	
	else
	{
		return false;
	}
	if (RUCOmputer == false)
		myBoard.playerScreen();
	else
	{
		myBoard.enemyScreen();
	}
	return true;


}


int user::getLives() const
{
	return userLives;
}

void user::spotsAroundShip(int x,int y)
{
	
	
	int headX, headY,maszty;
	maszty = shipTab.getMasztyShip(x, y);
	headX = shipTab.getHeadXofShip(x,y);
	headY = shipTab.getHeadYofShip(x,y);	
	if(shipTab.czyPoziom(x, y) == false)
	{
		myBoard.spotting(headX - 1, headY - 1, maszty + 2, 3);
		
	}
	else
	{
		myBoard.spotting(headX - 1, headY - 1, 3, maszty + 2);		
	}
	



	
}

bool user::AutomaticAddShips()
{
	int x, y;
	myBoard.clearPositions();
	shipTab.clearArray();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < quantityShips[4 - i]; j++)
		{
			int licznikWstawianiaStatku = 0;
			while (true)
			{

				 x = std::rand() % (10);
				 y = std::rand() % (10);
				if(myBoard.AutomaticAddShipToGame(shipTab,5-i,x,y)==true)
					break;
				licznikWstawianiaStatku++;
				if (licznikWstawianiaStatku > 10000000)
				{
					
					myBoard.clearPositions();
					shipTab.clearArray();
					return false;
				}
			}
		}
	}
	if (RUCOmputer == false)
		myBoard.playerScreen();
	else
	{
		myBoard.enemyScreen();
	}

	setLives();
	return true;
	
	
}

void user::showTheBoard()const
{
	if (RUCOmputer == false)
		myBoard.playerScreen();
	else
	{
		myBoard.enemyScreen();
	}

}

bool user::didHit(int x, int y) const
{
	return myBoard.didIHit(x,y);
}

void user::setAutomaticShip(const char m)
{
	if (m == 'y')
	{
		automaticShips = true;
		
	}
	else
	{
		automaticShips = false;
		
	}
	
}

void user::setAutomaticSpotting(const char m)
{
	if(m == 'y')
	{
		automaticSpotsAroundShip = true;
		
	}
	else
	{
		automaticSpotsAroundShip = false;
		
	}
}

void user::setShips(const char m)
{
	int zabezpiecznie = 0;
	
	if (m == 'y')
	{
		
		for (int i = 0; i < 5; i++)
		{
			std::string ilosc = "A";
			std::cout << "ustawiasz ilosc stakow " << i + 1 << " masztowych\n";
			while (is_number(ilosc) == false)
			{
				std::cout << "podaj numer i wcisnij enter\n ";
				std::getline(std::cin, ilosc);
				while (ilosc.length() > 1)
				{
					std::cout << "podaj numer i wcisnij enter\n ";
					std::getline(std::cin, ilosc);
				}
				 
			}
			quantityShips[i] = std::stoi(ilosc);
			zabezpiecznie = zabezpiecznie + std::stoi(ilosc);
		}
		if (zabezpiecznie > 15)
		{
			std::cout << "statkow jest za duzo zmnien ilosc\n";
			setShips('y');
		}
	}
}


