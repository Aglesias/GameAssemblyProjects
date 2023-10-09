#pragma once
class Roulette
{
public:
	Roulette();
	void Play();
private:
	int betingame;
	bool playthegame = false;
	bool validguess = false;
	int myRouletteTotalWin;
	int myRouletteTotalLoss;
};

