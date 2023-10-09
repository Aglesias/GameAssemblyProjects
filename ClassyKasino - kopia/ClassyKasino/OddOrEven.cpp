#include "OddOrEven.h"
#include "CasinoFunctions.h"
#include "Statistics.h"
OddOrEven::OddOrEven()
{
    dice1 = 0;
    dice2 = 0;
    rolling = dice1 + dice2;
    myBetInGame = 0;
    myValidGuess = false;
    myPlayTheGame = false;
    checkWantToPlay = "Play the game";
    checkOther = "Play the game again";
    myOddOrEvenTotalWin = 0;
    myOddOrEvenRotalLoss = 0;
}

void OddOrEven::Play(int& aTotalOfCreditsWon, int& aNumberOfCreditsAvailable, int& aNumberOfGamesPlayed, Statistics& aStatisticClass, bool& aBoolForTheWholeGame)
{
    int oddOrEven;
    std::cout << "Hello you old gambler! We will throw two dice and your job is to guess if the number will be odd or even!" << std::endl;
    std::cout << "You currently have " << aNumberOfCreditsAvailable << " credits availible." << std::endl;
    std::cout << "The odds on this game is 2.0." << std::endl;

    CasinoFunctions::LikeToPlay (myPlayTheGame, checkWantToPlay, aNumberOfCreditsAvailable);

    while (myPlayTheGame)
    {
        CasinoFunctions::TotalWinnings(aTotalOfCreditsWon, myOddOrEvenTotalWin, myOddOrEvenRotalLoss, myPlayTheGame);

        dice1 = CasinoFunctions::Randomizer(1, 6);
        dice2 = CasinoFunctions::Randomizer(1, 6);
        rolling = dice1 + dice2;
        int oddOrEvenCheck = 2;

        enum OddEven
        {
            ModulusEven,
            Odd,
            Even,
        };

        std::cout << "How many of your credits would you like to bet?" << std::endl;

        myBetInGame = CasinoFunctions::BettingOK(aNumberOfCreditsAvailable, myBetInGame);
        
        aNumberOfCreditsAvailable -= myBetInGame;

        std::cout << rolling;
        std::cout << "Please guess either 'odd' or 'even'" << std::endl;
        std::cout << "[1] Odd" << std::endl;
        std::cout << "[2] Even" << std::endl;


        int oddEvenRoll = rolling % oddOrEvenCheck;

        do
        {

            std::cin >> oddOrEven;
            if (oddOrEven == Odd || oddOrEven == Even)
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
                std::cout << "Pleas enter either 'odd' or 'even'." << std::endl;
            }
        }

        while (myValidGuess == false);
        {

            if (oddOrEven == 1)
            {
                std::cout << "Your guess is odd.";
            }

            else
            {
                std::cout << "Your guess is even.";
            }


            if (oddEvenRoll == ModulusEven && oddOrEven == Even)
            {
                std::cout << "You guessed " << oddOrEven << " which was correct!! Your bet is now twice what it was and will be added to your total credits!!" << std::endl;
                myBetInGame *= 2;
                aStatisticClass.SetStatistics(myBetInGame, aNumberOfGamesPlayed);
                myOddOrEvenTotalWin += myBetInGame;
                aNumberOfGamesPlayed++;
                aNumberOfCreditsAvailable += myBetInGame;
                std::cout << aNumberOfGamesPlayed % 5;


            }

            else if (oddEvenRoll == Odd && oddOrEven == Odd)
            {
                std::cout << "You guessed " << oddOrEven << " which was correct!! Your bet is now twice what it was and will be added to your total credits!!" << std::endl;
                myBetInGame *= 2;
                aStatisticClass.SetStatistics(-myBetInGame, aNumberOfGamesPlayed);
                myOddOrEvenRotalLoss += myBetInGame;
                aNumberOfGamesPlayed++;
                aNumberOfCreditsAvailable += myBetInGame;
                std::cout << aNumberOfGamesPlayed % 5;

            }

            else
            {
                std::cout << "You guessed " << oddOrEven << " but your guess was wrong. Too bad, try again later!" << std::endl;
                aTotalOfCreditsLostInGame -= aBetIsMade;
                aBetIsMade = -aBetIsMade;
                CasinoFunctions::StatisticsForLast5Games(aStatisticForGames, aBetIsMade, aNumberOfGamesPlayed);
                aNumberOfGamesPlayed++;
                std::cout << aNumberOfGamesPlayed % 5;
            }
            aValidGuess = false;

        }
        CasinoFunctions::LikeToPlay(aBoolForPlayingGame, aStringForChecking, aNumberOfCreditsAvailable);
        system("cls");
        CasinoFunctions::ThrownOut(aNumberOfCreditsAvailable, aBoolForTheWholeGame);

        const int suspiciousWinnings = 10000;

        if (!aBoolForTheWholeGame)
        {
            break;
        }

        if (!aBoolForPlayingGame && aTotalOfCreditsWon < suspiciousWinnings)
        {
            CasinoFunctions::ReturnToLobby(aBoolForTheWholeGame);
        }
    }
}
