#pragma once
class FlipACoin
{
public:
	FlipACoin();
	void Play();

private:
	int myBetInGame;
	bool myPlayTheGame = false;
	bool myValidGuess;
	int myCoinFlipTotalWin = 0;
	int myCoinFlipTotalLoss = 0;
	
};

