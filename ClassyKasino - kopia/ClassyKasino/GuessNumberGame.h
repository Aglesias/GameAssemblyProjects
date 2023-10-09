#pragma once
#include <string>
class Statistics; // forward declaration

class GuessNumberGame
{
	
public:	
	GuessNumberGame(int aMinBet, int aMaxBet);
	int BettingInMinMax(int aPlayersCredit, int& aPlayersBet, int aMinimumBet, int aMaximumBet);
	void Play(int& aTotalOfCreditsWon, int& aNumberOfCreditsAvailable,int &aNumberOfGamesPlayed, Statistics &aStatisticClass, bool& aBoolForTheWholeGame);
	
private:
	int dice1;
	int dice2;
	int rolling;
	int myBetInGame;
	bool myPlayTheGame;
	bool myValidGuess;
	int myMinBet;
	int myMaxBet;	
	int myGuessNumberTotalWin;
	int myGuessNumberTotalLoss;
	std::string checkWantToPlay;
	std::string checkOther;
	
};

