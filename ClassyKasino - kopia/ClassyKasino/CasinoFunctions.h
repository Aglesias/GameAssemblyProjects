#pragma once
#include <iostream>
#include <cstdlib>
#include <random>
#include <array>
namespace CasinoFunctions
{
	int  BettingOK(int aPlayersCredit, int& aPlayersBet);
	void DeckOfCards(std::array<int, 52>& aDeckOfBlackJack);
	void DrawCards(std::array<int, 52>& aDeckOfBlackJack, int& aSumOfCardsDrawn, std::array<int, 10>& someDrawnCards, std::string aCheckForDealerOrNot);
	int  Randomizer(int aMinNumber, int aMaxNumber);
	void DrawCardsBlackJack(int& aNumberLessThan21, std::array<int, 10>& someCardsDrawn, std::array<int, 52>& aDeckOfBlackJack, std::string aCheckForDealerOrNot);
	bool LikeToPlay(bool& aPlayerWantsToPlay, std::string aCheckForFirstTimeOrNot, int aPlayersCredits);
	bool ReturnToLobby(bool& aPlayerWantsToPlay);
	void StatisticsForLast5Games(std::array<int, 5>& aStatisticsArray, int& aBetthatismade, int aNumberOfGamesPlayed);
	void TheTableOfRoulette(bool normalTable);
	void ThrownOut(int aPlayersCredits, bool& aBoolForPlaying);
	void TotalWinnings(int& aTotalWinLoss, int aWinTotal, int aLossTotal, bool& playing);
}
