#pragma once
class Blackjack
{
public:
	Blackjack();
	void Play();
private:
	int myMaxBet;
	int myMinBet;
	int myBlackjackTotalWin;
	int myBlackjackTotalLoss;
	int myBetInGame;
	bool myPlayTheGame = false;
	bool myValidGuess = false;

};

