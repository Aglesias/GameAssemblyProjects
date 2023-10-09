#pragma once
#include <string>
class Statistics; // forward declaration
class OddOrEven
{
public:
	OddOrEven();
	void Play(int& aTotalOfCreditsWon, int& aNumberOfCreditsAvailable, int& aNumberOfGamesPlayed, Statistics& aStatisticClass, bool& aBoolForTheWholeGame);
private:
	
	bool playthegame = false;
	bool validguess = false;
	int myOddOrEvenTotalWin = 0;
	int myOddOrEvenRotalLoss = 0;
	int dice1;
	int dice2;
	int rolling;
	int myBetInGame;
	bool myPlayTheGame;
	bool myValidGuess;
	std::string checkWantToPlay;
	std::string checkOther;
};

