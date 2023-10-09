#include "GameManager.h"


GameManager::GameManager():
    myGuessNumberGameLow(50, 100), myGuessNumberGameHigh(100,200)
{
    myBlackjack = Blackjack();
    myFlipACoin = FlipACoin();
    myOddOrEven = OddOrEven();
    myRoulette = Roulette();
    myStatistics = Statistics(); 
    myCreditsAvalible = 200;
    myNumberOfGamesPlayed = 0;
    myWinLossTotal = 0;
    myCommenceGambling = true;
    choiceofgame = 0;
}

void GameManager::Play()
{
    Games currentgame;
    
    std::string checkwanttoplay = "play the game";
    std::string checkother = "play the game again";

    std::array<int, 5> statistic = { 0,0,0,0,0 };
    std::array<int, 52> cards{ 0 };

    const int firstgame = 1;    
    
    int maxnumberofchoices = static_cast<int>(Games::Statistics);

    PlayerName();

    while (myCommenceGambling)
    {


        std::cout << "---------------------------------------------------------------------" << std::endl;
        std::cout << "Welcome " << myPlayerName << " to the tga-casino lobby! you have " << myCreditsAvalible << " credits to gamble with." << std::endl;
        std::cout << "please choose a table to play a game:" << std::endl;
        std::cout << "1. guess the number" << std::endl;
        std::cout << "2. odd or even." << std::endl;
        std::cout << "3. blackjack." << std::endl;
        std::cout << "4. coin flip." << std::endl;
        std::cout << "5. roulette." << std::endl;
        std::cout << "6. win/loss statistics" << std::endl;
        std::cout << "---------------------------------------------------------------------" << std::endl;

        std::cin >> choiceofgame;
        currentgame = static_cast<Games>(choiceofgame);
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << "please pick 1 for 'guess the number', 2 for 'odd or even', 3 for blackjack, 4 for coin toss, 5 for roulette and 6 for statistics " << std::endl;

        }
        else if (choiceofgame > maxnumberofchoices || choiceofgame < firstgame)
        {
            std::cout << "please pick 1 for 'guess the number', 2 for 'odd or even', 3 for blackjack, 4 for coin toss, 5 for roulette and 6 for statistics " << std::endl;
        }

        switch (currentgame)
        {

            default:
            {
                break;
            }

            case Games::GuessNumber:
            {
                
                
                HighOrLow();
                if (myCommenceGambling == false)
                {
                    break;
                }
                break;

            }

            case Games::OddOrEven:
            {

                myOddOrEven.Play();
                if (myCommenceGambling == false)
                {
                    break;
                }
                break;
            }

            case Games::Blackjack:
            {
                myBlackjack.Play();
                break;
            }

            case Games::FlipACoin:
            {
                myFlipACoin.Play();
                if (myCommenceGambling == false)
                {
                    break;
                }
                break;
            }

            case Games::Roulette:
            {
                myRoulette.Play();
                break;
                if (myCommenceGambling == false)
                {
                    break;
                }
                break;
            }

            case Games::Statistics:
            {
                for (int statisticSize = 0; statisticSize < 5; statisticSize++)
                {
                    std::cout << myStatistics.GetStatistics(statisticSize) << std::endl;
                }
                break;
            }
        }
    }
    std::cout << "you leave the casino with " << myCreditsAvalible << " credits.";
	
}

void GameManager::PlayerName()
{
    std::cout << "Please enter your name: " << std::endl;

    while (true)
    {
        myBoolForName = true;
        std::cin >> myPlayerName;
        for (char charInString : myPlayerName)
        {

            if ((charInString < 'a' || charInString > 'z') && (charInString < 'A' || charInString > 'Z'))
            {
                myBoolForName = false;
            }

        }
        if (myPlayerName.length() > 1 && myBoolForName == true)
        {
            break;
        }
        std::cout << "Please make use of only characters between a to z. Numbers and special characters not allowed." << std::endl;

    }
    
}

void GameManager::HighOrLow()
{
    bool checkPlay = false;
    int HighOrLow;
    enum YesOrNo
    {
        Low = 1,
        High,
    };
    
    do
    {
        std::cout << "---------------------------------------------------------------------" << std::endl;
        std::cout << "Would you like to play low stakesor ?: " << std::endl;
        std::cout << "[1] Low stakes. Min bet 50 max bet 100." << std::endl;
        std::cout << "[2] High stakes. Min bet 100 max bet 200." << std::endl;
        std::cin >> HighOrLow;
        std::cout << "---------------------------------------------------------------------" << std::endl;


        if (HighOrLow == High || HighOrLow == Low)
        {
            checkPlay = true;
        }
        else if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << "Invalid input. Please enter [1] for yes or [2] for No." << std::endl;
        }

    }

    while (checkPlay == false);
    {
        
        if (HighOrLow == High)
        {
            myGuessNumberGameHigh.Play(myWinLossTotal, myCreditsAvalible, myNumberOfGamesPlayed, myStatistics, myCommenceGambling);
                        
        }
        else
        {
            myGuessNumberGameLow.Play(myWinLossTotal, myCreditsAvalible, myNumberOfGamesPlayed, myStatistics, myCommenceGambling);
        }
    }

   
}
