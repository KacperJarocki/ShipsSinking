#pragma once
class ship ///this class exist to help with counting lives and with helping computers choosing
{
	
	int x;//head x
	int y;//head y
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
	void setShip();
	int getHeadXofShip()const { return x; }
	int getHeadYofShip()const { return  y; }
	int getMaszt()const { return maszt; }
	bool PoziomCzyPion();//poziom is trued


};

