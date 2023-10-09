#include "GuessNumberGame.h"
#include "CasinoFunctions.h"
#include "Statistics.h"


GuessNumberGame::GuessNumberGame(int aMinBet, int aMaxBet)
{
    dice1 = 0;
    dice2 = 0;
    rolling = dice1 + dice2;
    myBetInGame = 0;
    myValidGuess = false;
    myPlayTheGame = false;
    checkWantToPlay = "Play the game";
    checkOther = "Play the game again";
    myGuessNumberTotalWin = 0;
    myGuessNumberTotalLoss = 0;
    myMinBet = aMinBet; 
    myMaxBet = aMaxBet;
    
}

int GuessNumberGame::BettingInMinMax(int aPlayersCredit, int& aPlayersBet, int aMinimumBet, int aMaximumBet)
{
    std::cout << "You currently have " << aPlayersCredit << " credits availible." << std::endl;
    std::cout << "How many of your credits would you like to bet?" << std::endl;

    const int resetPlayerBet = 0;
    bool betOk = false;

    do
    {
        std::cin >> aPlayersBet;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << "Please enter a valid bet." << std::endl;
        }
        else if (aPlayersBet <= aPlayersCredit && aPlayersBet > resetPlayerBet && aPlayersBet >= aMinimumBet && aPlayersBet <= aMaximumBet)
        {
            betOk = true;
        }
        else
        {
            aPlayersBet = resetPlayerBet;
            std::cout << "Your bet cannot bet more than "<< aMinimumBet << " and not less than " << aMaximumBet << "." << std::endl;
            std::cout << "You currently have" << aPlayersCredit << "credits." << std::endl;
            std::cout << "Please enter a valid bet:" << std::endl;

        }
    }

    while (!betOk);
    {
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "Your bet is " << aPlayersBet << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;


    }

    if (aPlayersBet == aPlayersCredit)
    {

        std::cout << "ALL IN!! THIS IS EXCITING!!" << std::endl;
        std::cout << "-------------------------------------------------------------" << std::endl;
    }
    return aPlayersBet;
}





void GuessNumberGame::Play(int& aTotalOfCreditsWon, int & aNumberOfCreditsAvailable, int& aNumberOfGamesPlayed, Statistics &aStatisticClass, bool &aBoolForTheWholeGame)
{
    std::cout << "Hello you old gambler! We will throw two dice and your job is to guess the number of the dice roll!" << std::endl;
    std::cout << "The odds on this game is 10.0." << std::endl;

    CasinoFunctions::LikeToPlay(myPlayTheGame, checkWantToPlay, aNumberOfCreditsAvailable);
    
    while (myPlayTheGame)
    {
        dice1 = CasinoFunctions::Randomizer(1, 6);
        dice2 = CasinoFunctions::Randomizer(1, 6);
        rolling = dice1 + dice2;
        CasinoFunctions::TotalWinnings(aTotalOfCreditsWon, myGuessNumberTotalWin, myGuessNumberTotalLoss, myPlayTheGame);
        std::cout << aNumberOfCreditsAvailable << std::endl;
        if (myPlayTheGame == false)
        {
            break;
        }
    
        myBetInGame = BettingInMinMax(aNumberOfCreditsAvailable, myBetInGame, myMinBet, myMaxBet);
        

        int guess;
        aNumberOfCreditsAvailable -= myBetInGame;
        std::cout << "---------------------------------------------------------------------" << std::endl;
        std::cout << aNumberOfCreditsAvailable << std::endl;
        std::cout << rolling << std::endl;

        do
        {
            int maxGuess = 12;
            int minGuess = 2;

            std::cout << "Please enter your guess:";
            std::cin >> guess;
            if (guess >= minGuess && guess <= maxGuess)
            {
                myValidGuess = true;

            }

            else if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(100, '\n');
            }

            else
            {
                std::cout << "You have to enter a number between 2 and 12" << std::endl;
            }
        }

        while (myValidGuess == false);
        {

            
            std::cout << "The first dice rolled was: " << dice1 << std::endl;
            std::cout << "The second dice rolled was: " << dice2 << std::endl;
            std::cout << "The sum of the dice rolls was: " << rolling << std::endl;

            if (guess == rolling)
            {

                std::cout << "You guessed the right number!! Your bet is now tenfold what it was and will be added to your total credits!!" << std::endl;
                myBetInGame *= 10;
                aStatisticClass.SetStatistics(myBetInGame, aNumberOfGamesPlayed);
                myGuessNumberTotalWin += myBetInGame; 
                aNumberOfGamesPlayed++;
                aNumberOfCreditsAvailable += myBetInGame;
                std::cout << "---------------------------------------------------------------------" << std::endl;
                std::cout << aNumberOfCreditsAvailable << std::endl;
                std::cout << myGuessNumberTotalWin << std::endl;

            }
            else
            {
                myGuessNumberTotalLoss -= myBetInGame;                
                aStatisticClass.SetStatistics(-myBetInGame, aNumberOfGamesPlayed);
                aNumberOfGamesPlayed++;                
                std::cout << "---------------------------------------------------------------------" << std::endl;
                std::cout << aNumberOfCreditsAvailable << std::endl;
                std::cout << myGuessNumberTotalLoss << std::endl;

            }
            myValidGuess = false;

        }

        CasinoFunctions::LikeToPlay(myPlayTheGame, checkWantToPlay, aNumberOfCreditsAvailable);
        system("cls");
        CasinoFunctions::ThrownOut(aNumberOfCreditsAvailable, aBoolForTheWholeGame);

   

        const int suspiciousWinnings = 10000;

        if (!aBoolForTheWholeGame)
        {
            break;
        }

       
    }
}
