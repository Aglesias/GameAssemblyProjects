// Kasino del 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <random>
#include <array>
void ArrayTest(std::array<int, 5>& aStatisticsArray, int& aBetthatismade, int aNumberOfGamesPlayed)
{
    aStatisticsArray[aNumberOfGamesPlayed % 5] = aBetthatismade;

}
int BettingOK(int aPlayersCredit, int &aPlayersBet)
{
    
    bool betOk = false;
    do
    {
        std::cin >> aPlayersBet;
        if (aPlayersBet <= aPlayersCredit)
        {
            betOk = true;
        }
        else
        {
            aPlayersBet = 0;
            std::cout << "Your bet cannot bet more than your total number of credits." << std::endl;
            std::cout << "You currently have" << aPlayersCredit << "credits." << std::endl;
            std::cout << "Please enter a valid bet:" << std::endl;
            
        }
    } 
    while (!betOk);
    {
        std::cout << "Your bet is" << aPlayersBet << std::endl;
       

    }
    if (aPlayersBet == aPlayersCredit)
    {
        std::cout << "ALL IN!! THIS IS EXITING!!" << std::endl;
    }
    return aPlayersBet;
}
int Diceroll(int aFirstDice, int aSecondDice) 
{
    return aFirstDice + aSecondDice;
    

}
 int TotalWinnings(int& aTotalWinLoss, int aWinTotal, int aLossTotal)
{
    aTotalWinLoss = aWinTotal + aLossTotal;
    return aTotalWinLoss;
}
bool LikeToPlay(bool &aPlayerWantsToPlay, std::string aCheckForFirstTimeOrNot, int aPlayersCredits)
{
    int yesOrNo;
    if (aCheckForFirstTimeOrNot == "Play the game" && aPlayersCredits > 0)
    {
        
        do
        {
            std::cout << "---------------------------------------------------------------------" << std::endl;
            std::cout << "Would you like to sit at this table to play the game?: " << std::endl;
            std::cout << "[1] Yes." << std::endl;
            std::cout << "[2] No." << std::endl;
            std::cin >> yesOrNo;
            std::cout << "---------------------------------------------------------------------" << std::endl;

            
            if (yesOrNo == 1 || yesOrNo == 2)
            {
                aPlayerWantsToPlay = true;
            }
            else if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(100, '\n');

                std::cout << "Invalid input. Please enter [1] for yes or [2] for No." << std::endl;
            }
            
        }

        while (!aPlayerWantsToPlay);
        {
            if (yesOrNo != 1)
            {
                aPlayerWantsToPlay = false;
            }
          
        }
        
    } 
    else if (aCheckForFirstTimeOrNot == "Play the game again" && aPlayersCredits > 0)
    {
        do
        {
            std::cout << "---------------------------------------------------------------------" << std::endl;
            std::cout << "Play again?: " << std::endl;
            std::cout << "[1] Yes." << std::endl;
            std::cout << "[2] No." << std::endl;
            std::cin >> yesOrNo;
            std::cout << "---------------------------------------------------------------------" << std::endl;

            if (yesOrNo == 1 || yesOrNo == 2)
            {
                aPlayerWantsToPlay = true;
            }
            else if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(100, '\n');

                std::cout << "Invalid input. Please enter [1] for yes or [2] for No." << std::endl;
            }
            else
            {
                std::cout << "Invalid input. Please enter [1] for yes or [2] for No." << std::endl;

            } 
        }

        while (!aPlayerWantsToPlay);
        {
            if (yesOrNo != 1)
            {
                aPlayerWantsToPlay = false;
            }
        }
    }    
    return aPlayerWantsToPlay;
}
bool ReturnToLobby(bool &aPlayerWantsToPlay) 
{
    int yesOrNo;
    do
    {
        std::cout << "---------------------------------------------------------------------" << std::endl;
        std::cout << "Return to lobby?: " << std::endl;
        std::cout << "[1] Yes." << std::endl;
        std::cout << "[2] Exit casino." << std::endl;
        std::cin >> yesOrNo;
        std::cout << "---------------------------------------------------------------------" << std::endl;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << "Invalid input. Please enter [1] for yes or [2] for No." << std::endl;
        }
        else if (yesOrNo == 1 || yesOrNo == 2)
        {
            aPlayerWantsToPlay = true;
        }
        else
        {
            std::cout << "Invalid input. Please enter [1] for yes or [2] for No." << std::endl;

        }
    }

    while (!aPlayerWantsToPlay);
    {
        if (yesOrNo != 1)
        {
            aPlayerWantsToPlay = false;
        }
    }
    return aPlayerWantsToPlay;
}
bool ThrownOut(int aPlayersCredits, bool &aBoolForPlaying)
{
    if (aPlayersCredits == 0)
    {
        char throwOutStop;
        std::cout << "You see two strong men in suits walkning towards you. The men grabs you by your hands and feet and says:" << std::endl;
        std::cout << "'People without credits are not welcome in this establishment.'" << std::endl;
        std::cout << "While they carry you towards the exit a chill runs down your spine as you realise you gambled away this months rent..." << std::endl;
        std::cin >> throwOutStop;
        aBoolForPlaying = false;

    }
    return aBoolForPlaying;
}
int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 6);


    int credits = 200;
    int choice;
    int bet = 0;
    int gameNr = 0;
    int guessNumberTotalWin = 0;
    int guessNumberTotalLoss = 0;
    int oddOrEvenTotalWin = 0;  
    int oddOrEvenTotalLoss = 0; 
    int totalWinningsInGame;
    bool playTheGame = false;
    bool commenceGambling = true;
    bool validGuess = false;
    std::string wantToPlay = "Play the game";
    std::string other = "Play the game again";    
    std::array<int, 5> statistic = {0,0,0,0,0};
    enum games
    {
        HowToDo,
        GuessNumber,
        OddOrEven,

        Statistics,
    };
   

    while (commenceGambling)
    {
        
        

        std::cout << "Welcome to the TGA-casino lobby! You have " << credits << " credits to gamble with." << std::endl;
        std::cout << "Please choose a table to play a game:" << std::endl;
        std::cout << "1. Guess the number" << std::endl;
        std::cout << "2. Odd or even" << std::endl;
        std::cout << "3. Win/loss statistics" << std::endl;

        std::cin >> choice;
        if (choice > 3 || choice < 1)
        {
            std::cout << "Please pick 1 for 'Guess the number' or 2 for 'Odd or Even' or 3 to show wins/losses";
        }
        switch (choice)
        {

        default:

            break;
            case GuessNumber:
            {

                TotalWinnings(totalWinningsInGame, guessNumberTotalWin, guessNumberTotalLoss );

                if (totalWinningsInGame > 1000) 
                {
                    std::cout << "Your have won a total of " << totalWinningsInGame << " at this table! NICE!" << std::endl;
                }
                else if (totalWinningsInGame < -1000)
                {
                    std::cout << "Your have lost a total of " << totalWinningsInGame << " at this table... too bad." << std::endl;
                }
                else
                {
                    std::wcout << "Your have won/lost a total of " << totalWinningsInGame << " at this table so far." << std::endl;
                }
                
                std::cout << "Hello you old gambler! We will throw two dice and your job is to guess the number of the dice roll!" << std::endl;
            
                std::cout << "The odds on this game is 10.0." << std::endl;
                LikeToPlay(playTheGame, wantToPlay, credits);
                while (playTheGame)
                {
                    int dice1 = dist(gen);
                    int dice2 = dist(gen);
                    int rolling = Diceroll(dice1, dice2);

                    std::cout << "You currently have " << credits << " credits availible." << std::endl;
                    std::cout << "How many of your credits would you like to bet?" << std::endl;

                    int currentBet = BettingOK(credits, bet);
                    bet = currentBet;

                    std::cout << rolling << std::endl;

                    int guess;
                    credits -= bet;

                    do
                    {
                        std::cout << "Please enter your guess:";
                        std::cin >> guess;
                        if (guess > 1 && guess < 13)
                        {
                            validGuess = true;

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

                    while (!validGuess);
                    {
                        std::cout << "The first dice rolled was: " << dice1 << std::endl;
                        std::cout << "The second dice rolled was: " << dice2 << std::endl;
                        std::cout << "The sum of the dice rolls was: " << rolling << std::endl;
                        if (guess == rolling)
                        {

                            std::cout << "You guessed the right number!! Your bet is now tenfold what it was and will be added to your total credits!!" << std::endl;
                            bet *= 10;
                            ArrayTest(statistic, bet, gameNr);                             
                            guessNumberTotalWin += bet;
                            gameNr++;
                            credits += bet;
                            std::cout << gameNr % 5;

                        }
                        else
                        {
                            bet = -bet;
                            ArrayTest(statistic, bet, gameNr);
                            guessNumberTotalLoss -= bet;
                            gameNr++;
                            std::cout << gameNr % 5;
                        }
                    }
                    LikeToPlay(playTheGame, other, credits);
                    ThrownOut(credits, commenceGambling); 
                    if (!commenceGambling)
                    {
                        break;
                    }
                }
                
                if (!playTheGame) 
                {
                    ReturnToLobby(commenceGambling);
                }
                system("cls");
                break;
            }

            case OddOrEven:
            {
                int totalWinningsInGame = oddOrEvenTotalWin + oddOrEvenTotalLoss; 
                if (totalWinningsInGame > 1000)
                {
                    std::cout << "Your have won a total of " << totalWinningsInGame << " at this table! NICE!" << std::endl;
                }
                else if (totalWinningsInGame < -1000)
                {
                    std::cout << "Your have lost a total of " << totalWinningsInGame << " at this table... too bad." << std::endl;
                }
                else
                {
                    std::wcout << "Your have won/lost a total of " << totalWinningsInGame << " at this table." << std::endl;
                }
                int oddOrEven;
                std::cout << "Hello you old gambler! We will throw two dice and your job is to guess if the number will be odd or even!" << std::endl;
                std::cout << "You currently have " << credits << " credits availible." << std::endl;
                std::cout << "The odds on this game is 2.0." << std::endl;
                LikeToPlay(playTheGame, wantToPlay, credits);
                while (playTheGame)
                {
                    int dice1 = dist(gen);
                    int dice2 = dist(gen);
                    int rolling = Diceroll(dice1, dice2);
                    std::cout << "How many of your credits would you like to bet?" << std::endl;

                    int betting = BettingOK(credits, bet);
                    bet = betting;
                    credits -= bet;

                    std::cout << rolling;
                    std::cout << "Please guess either 'odd' or 'even'" << std::endl;
                    std::cout << "[1] Odd" << std::endl;
                    std::cout << "[2] Even" << std::endl;
                    

                    int oddEvenRoll = rolling % 2;
                    do
                    {
                        std::cin >> oddOrEven;
                        if (oddOrEven == 1 || oddOrEven == 2)
                        {
                            validGuess = true;
                        }
                        else
                        {
                            std::cout << "Pleas enter either 'odd' or 'even'." << std::endl;
                        }
                    }

                    while (!validGuess);
                    {
                        std::cout << "Your guess is " << oddOrEven << ".";

                        if (oddEvenRoll == 0 && oddOrEven == 2)
                        {
                            std::cout << "You guessed " << oddOrEven << " which was correct!! Your bet is now twice what it was and will be added to your total credits!!" << std::endl;
                            bet *= 2;
                            ArrayTest(statistic, bet, gameNr);
                            oddOrEvenTotalWin += bet;
                            gameNr++;
                            credits += bet;
                            std::cout << gameNr % 5;

                        } 

                        else if (oddEvenRoll == 1 && oddOrEven == 1)
                        {
                            std::cout << "You guessed " << oddOrEven << " which was correct!! Your bet is now twice what it was and will be added to your total credits!!" << std::endl;
                            bet *= 2;
                            ArrayTest(statistic, bet, gameNr);
                            oddOrEvenTotalWin += bet;
                            gameNr++;
                            credits += bet;
                            std::cout << gameNr % 5;

                        } 

                        else
                        {
                            std::cout << "You guessed " << oddOrEven << " but your guess was wrong. Too bad, try again later!" << std::endl;
                            oddOrEvenTotalLoss -= bet;
                            bet = -bet;
                            ArrayTest(statistic, bet, gameNr);
                            gameNr++;
                            std::cout << gameNr % 5;
                        }

                    }
                    LikeToPlay(playTheGame, other, credits);
                    system("cls");
                    ThrownOut(credits, commenceGambling);

                }

                if (!commenceGambling)
                {
                    break;
                }

                if (!playTheGame)
                {
                    ReturnToLobby(commenceGambling);
                }            
                
                break;
            }

            case Statistics:

                for (size_t winLossStatistics = 0; winLossStatistics < 5; winLossStatistics++)
                {
                    std::cout << statistic[winLossStatistics] << std::endl;
                    
                }
                break;
        }
    }
    std::cout << "You leave the casino with " << credits << " credits.";
}
 


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
