#pragma once
class ship ///this class exist to help with counting lives and with helping computers choosing
{
	int maszt;
	int lives;
	int where[10][10]{};
public:
	ship();
	void setMasztAndLives(int maszty);// to count how many lives in total
	void setWhere(int x, int y); ///todo: dodac w odpowiednie miejscie
	bool isThisShipHere(int x,int y) const;
	void oneLiveDown();// after getting hit deletes live
	bool wasItKillShot() const;/// checks if shot destroy ship
	int getLive() const; 


};

