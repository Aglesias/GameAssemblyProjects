#pragma once
#include <array>
#include "Blackjack.h"
#include "FlipACoin.h"
#include "GuessNumberGame.h"
#include "OddOrEven.h"
#include "Roulette.h"
#include "Statistics.h"


#include <iostream>
enum class Games
{
    GuessNumber = 1,
    OddOrEven,
    Blackjack,
    FlipACoin,
    Roulette,
    Statistics,
}; 
class GameManager
{
public:
    GameManager();
    void Play();
    void PlayerName();    
    void HighOrLow();
    
    
private:
    Blackjack myBlackjack;
    FlipACoin myFlipACoin;
    GuessNumberGame myGuessNumberGameLow;
    GuessNumberGame myGuessNumberGameHigh;
    OddOrEven myOddOrEven;
    Roulette myRoulette;
    Statistics myStatistics;
    int choiceofgame;
    int myNumberOfGamesPlayed;
    int myCreditsAvalible;
    int myWinLossTotal;
    bool myCommenceGambling;
    std::string myPlayerName;
    bool myBoolForName = true;
};

