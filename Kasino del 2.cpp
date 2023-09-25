// Kasino del 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <random>
#include <array>
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
bool LikeToPlay(bool &aPlayerWantsToPlay, std::string aCheckForFirstTimeOrNot, int aPlayersCredits)
{
    char yes;
    if (aCheckForFirstTimeOrNot == "Play the game" && aPlayersCredits > 0)
    {
        
        do
        {
            std::cout << "Would you like to sit at this table to play the game? (y/n): ";
            std::cin >> yes;
            
            int check = static_cast<int>(yes);
            std::cout << check << std::endl;
            
            
            if (check == 121 || check == 89 || check == 78 || check == 110) // Checks if the character input is "y", "Y", "N" or "n" using the ascii numbers. Works pretty bad, need to check how to do better.
            {
                aPlayerWantsToPlay = true;
            }
            else
            {
                std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
            }
        }

        while (!aPlayerWantsToPlay);
        {
            if (yes != 121 && yes != 89)
            {
                aPlayerWantsToPlay = false;
            }
          
        }
        
    } 
    else if (aCheckForFirstTimeOrNot == "something else" && aPlayersCredits > 0)
    {
        do
        {
            std::cout << "Play again? (y/n): ";
            std::cin >> yes;
            int check = static_cast<int>(yes);
            std::cout << check << std::endl;
            if (check == 121 || check == 89 || check == 78 || check == 110) // Checks if the character input is "y", "Y", "N" or "n" using the ascii numbers. Works pretty bad, need to check how to do better.
            {
                aPlayerWantsToPlay = true;
            }
            else
            {
                aPlayerWantsToPlay = false;
                std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
            }
        }

        while (!aPlayerWantsToPlay);
        {
            if (yes != 121 && yes != 89)
            {
                aPlayerWantsToPlay = false;
            }
        }
    }    
    return aPlayerWantsToPlay;
}
bool ReturnToLobby(bool &aBoolForPlaying) 
{
    std::string yes;
    do
    {
        std::cout << "Return to lobby? (y/n): ";
        std::cin >> yes;
        if (yes == "y" || yes == "n")
        {
            aBoolForPlaying = true;
        }
        else
        {
            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
    }

    while (!aBoolForPlaying);
    {
        if (yes != "y")
        {
           aBoolForPlaying = false;

        }
    }
    return aBoolForPlaying;
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
        return aBoolForPlaying = false;

    }
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
    int totalWinnings = 0;
    int totalLosses = 0;
    bool playTheGame = true;
    bool commenceGambling = true;
    bool validGuess = false;
    bool validInput = false;
    std::string wantToPlay = "Play the game";
    std::string other = "something else";    
    std::array<int, 7> statistic = {0,0,0,0,0, totalWinnings, totalLosses};
    
   

    while (commenceGambling)
    {
        std::string yes[2] = { "hejsan" , "Hello"};
        std::cout << yes[0] << yes[1] << std::endl;

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
            case 1:
            {


                std::cout << "Hello you old gambler! We will throw two dice and your job is to guess the number of the dice roll!" << std::endl;
            
                std::cout << "The odds on this game is 10.0." << std::endl;
                playTheGame = LikeToPlay(validInput, wantToPlay, credits);
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
                            statistic[gameNr % 5] = bet;
                            totalWinnings += bet;
                            gameNr++;
                            credits += bet;
                            std::cout << gameNr % 5;

                        }
                        else
                        {
                            statistic[gameNr % 5] -= bet;
                            totalLosses -= bet;
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
               // system("cls");
                break;
            }

            case 2:
            {
                std::string oddOrEven;
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

                    int oddEvenRoll = rolling % 2;
                    do
                    {
                        std::cin >> oddOrEven;
                        if (oddOrEven == "odd" || oddOrEven == "even")
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

                        if (oddEvenRoll == 0 && oddOrEven == "even")
                        {
                            std::cout << "You guessed " << oddOrEven << " which was correct!! Your bet is now twice what it was and will be added to your total credits!!" << std::endl;
                            bet *= 2;
                            credits += bet;
                        }

                        else if (oddEvenRoll == 1 && oddOrEven == "odd")
                        {
                            std::cout << "You guessed " << oddOrEven << " which was correct!! Your bet is now twice what it was and will be added to your total credits!!" << std::endl;
                            bet *= 2;
                            credits += bet;
                        }

                        else
                        {
                            std::cout << "You guessed " << oddOrEven << " but your guess was wrong. Too bad, try again later!" << std::endl;
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

            case 3:

                for (size_t winLossStatistics = 0; winLossStatistics < 7; winLossStatistics++)
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
