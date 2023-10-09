#include "CasinoFunctions.h"

int  CasinoFunctions::BettingOK(int aPlayersCredit, int& aPlayersBet)
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
        else if (aPlayersBet <= aPlayersCredit && aPlayersBet > resetPlayerBet)
        {
            betOk = true;
        }
        else
        {
            aPlayersBet = resetPlayerBet;
            std::cout << "Your bet cannot bet more than your total number of credits or zero." << std::endl;
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
void CasinoFunctions::DeckOfCards(std::array<int, 52>& aDeckOfBlackJack)
{
    int card = 2;
    int incrementIncreaseForCards = 4;
    int oneThroughNineIncrementOfCards = 4;
    int tenToKingIncrementOfCards = 16;
    int lastIncrementOfTheCardsOfACertainValue = 0;
    int incrementOfCardsOfACertainValue = 4;
    int numberOfCardsInADeckIfYouStartCountingAtZero = 51;

    for (size_t aCardsNumberInDeck = lastIncrementOfTheCardsOfACertainValue; aCardsNumberInDeck < incrementOfCardsOfACertainValue; aCardsNumberInDeck++)
    {

        aDeckOfBlackJack[aCardsNumberInDeck] = card;

        // std::cout << aDeckOfBlackjack[aCardsNumberInDeck] << std::endl;
        if (aCardsNumberInDeck >= numberOfCardsInADeckIfYouStartCountingAtZero)
        {
            break;
        }

        else if (aCardsNumberInDeck == 31)
        {
            card++;
            incrementOfCardsOfACertainValue += tenToKingIncrementOfCards;
            lastIncrementOfTheCardsOfACertainValue = incrementOfCardsOfACertainValue - tenToKingIncrementOfCards;
        }

        else if (aCardsNumberInDeck == incrementOfCardsOfACertainValue - 1)
        {
            card++;
            incrementOfCardsOfACertainValue += incrementIncreaseForCards;
            lastIncrementOfTheCardsOfACertainValue = incrementOfCardsOfACertainValue - incrementIncreaseForCards;
        }


    }
}
int  CasinoFunctions::Randomizer(int aMinNumber, int aMaxNumber)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> numberRandom(aMinNumber, aMaxNumber);
    
    int randomNumber = numberRandom(gen);
    return randomNumber;

}
void CasinoFunctions::DrawCards(std::array<int, 52>& aDeckOfBlackJack, int& aSumOfCardsDrawn, std::array<int, 10>& someDrawnCards, std::string aCheckForDealerOrNot)
{
    std::random_device rd;
    std::uniform_int_distribution<int> cardRandom(0, 51);
    std::mt19937 gen(rd());

    int firstRandom = cardRandom(gen);
    int secondRandom = cardRandom(gen);

    const int antiDrawTwoOfSame = 0;
    const int noValuePrecentAtAnArraySlot = 0;

    while (firstRandom == secondRandom)
    {
        firstRandom = cardRandom(gen);
        secondRandom = cardRandom(gen);
    }

    while (aDeckOfBlackJack[firstRandom] == noValuePrecentAtAnArraySlot)
    {
        firstRandom = cardRandom(gen);
    }

    int firstCard = aDeckOfBlackJack[firstRandom];
    aDeckOfBlackJack[firstRandom] = antiDrawTwoOfSame;

    while (aDeckOfBlackJack[secondRandom] == noValuePrecentAtAnArraySlot)
    {
        secondRandom = cardRandom(gen);
    }

    int secondCard = aDeckOfBlackJack[secondRandom];
    aDeckOfBlackJack[secondRandom] = antiDrawTwoOfSame;

    someDrawnCards[0] = firstCard;
    someDrawnCards[1] = secondCard;

    if (aCheckForDealerOrNot == "Play the game")
    {
        std::cout << "You draw " << firstCard << " and " << secondCard << std::endl;
        std::cout << "---------------------------------------------------------- " << std::endl;
    }

    else
    {

        std::cout << "The dealer draws " << firstCard << " and " << secondCard << std::endl;
        std::cout << "---------------------------------------------------------- " << std::endl;
    }

    aSumOfCardsDrawn = firstCard + secondCard;
}
void CasinoFunctions::DrawCardsBlackJack(int& aNumberLessThan21, std::array<int, 10>& someCardsDrawn, std::array<int, 52>& aDeckOfBlackJack, std::string aCheckForDealerOrNot)
{
    std::random_device rd;
    std::uniform_int_distribution<int> cardRandom(0, 51);
    std::mt19937 gen(rd());

    bool hitAgain = true;
    bool hitting = false;

    int cardThatIsDrawn = 2;
    int yesOrNo;
    enum YesOrNo
    {

        Yes = 1,
        No,
    };




    if (aCheckForDealerOrNot == "Play the game")
    {
        while (hitAgain)
        {
            do
            {
                std::cout << "Your card total is " << aNumberLessThan21 << " do you want to draw a card?" << std::endl;
                std::cout << "[1] Hit me!(It's a frase draw another card in blackjack)." << std::endl;
                std::cout << "[2] Stand.(You don't draw another card)" << std::endl;
                std::cin >> yesOrNo;

                if (yesOrNo == Yes || yesOrNo == No)
                {
                    hitting = true;
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

            while (!hitting);
            {

                if (yesOrNo != Yes)
                {
                    std::cout << "Leaving table" << std::endl;
                    break;
                }

                const int noValuePrecentAtAnArraySlot = 0;
                const int resetHandTotalSum = 0;

                aNumberLessThan21 = resetHandTotalSum;
                int randomCard = cardRandom(gen);

                while (aDeckOfBlackJack[randomCard] == noValuePrecentAtAnArraySlot)
                {
                    randomCard = cardRandom(gen);
                }

                int takeACard = aDeckOfBlackJack[randomCard];
                someCardsDrawn[cardThatIsDrawn] = takeACard;
                std::cout << "You got " << takeACard << std::endl;

                cardThatIsDrawn++;
                const int checkForBust = 21;

                for (size_t drawnCards = 0; drawnCards < cardThatIsDrawn; drawnCards++)
                {
                    std::cout << "You've drawn " << someCardsDrawn[drawnCards] << std::endl;
                    aNumberLessThan21 = aNumberLessThan21 + someCardsDrawn[drawnCards];

                    if (aNumberLessThan21 > checkForBust)
                    {
                        int aceEleven = 11;
                        int aceOne = 1;
                        int firstCardInHand = 0;
                        aNumberLessThan21 = resetHandTotalSum;
                        std::cout << "loppiloop" << std::endl;
                        for (size_t drawnCards = firstCardInHand; drawnCards < cardThatIsDrawn; drawnCards++)
                        {

                            if (someCardsDrawn[drawnCards] == aceEleven)
                            {
                                someCardsDrawn[drawnCards] = aceOne;
                            }
                            aNumberLessThan21 = aNumberLessThan21 + someCardsDrawn[drawnCards];
                        }
                    }
                }

                if (aNumberLessThan21 > checkForBust)
                {
                    std::cout << "Your total is over 21, you lose." << std::endl;
                    std::cout << "Ending round" << std::endl;

                    break;
                }
            }

            hitting = false;
        }
    }
    if (aCheckForDealerOrNot == "Play the game again")
    {
        const int dealerDrawOrStand = 17;
        while (aNumberLessThan21 < dealerDrawOrStand)
        {
            const int resetHandTotalSum = 0;
            const int noValuePrecent = 0;
            aNumberLessThan21 = resetHandTotalSum;
            int randomCard = cardRandom(gen);
            while (aDeckOfBlackJack[randomCard] == noValuePrecent)
            {
                randomCard = cardRandom(gen);

            }
            int takeACard = aDeckOfBlackJack[randomCard];
            someCardsDrawn[cardThatIsDrawn] = takeACard;
            std::cout << "The dealer got " << takeACard << std::endl;

            cardThatIsDrawn++;

            for (size_t drawnCards = 0; drawnCards < cardThatIsDrawn; drawnCards++)
            {
                std::cout << "The dealer has drawn " << someCardsDrawn[drawnCards] << std::endl;
                aNumberLessThan21 = aNumberLessThan21 + someCardsDrawn[drawnCards];

            }

            int checkForBust = 21;

            if (aNumberLessThan21 > checkForBust)
            {
                const int aceEleven = 11;
                const int aceOne = 1;
                int firstCardInHand = 0;
                aNumberLessThan21 = resetHandTotalSum;
                for (size_t drawnCards = firstCardInHand; drawnCards < cardThatIsDrawn; drawnCards++)
                {
                    if (someCardsDrawn[drawnCards] == aceEleven)
                    {
                        someCardsDrawn[drawnCards] = aceOne;
                    }
                    aNumberLessThan21 = aNumberLessThan21 + someCardsDrawn[drawnCards];
                }

            }

            if (aNumberLessThan21 > checkForBust)
            {
                std::cout << "Your total is over 21, you lose." << std::endl;
                std::cout << "Ending round" << std::endl;

                break;
            }
        }

    }
}
bool CasinoFunctions::LikeToPlay(bool& aPlayerWantsToPlay, std::string aCheckForFirstTimeOrNot, int aPlayersCredits)
{
    int yesOrNo;
    enum YesOrNo
    {
        Yes = 1,
        No,
    };

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


            if (yesOrNo == Yes || yesOrNo == No)
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
            if (yesOrNo != Yes)
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

            if (yesOrNo == Yes || yesOrNo == No)
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
            if (yesOrNo != Yes)
            {
                aPlayerWantsToPlay = false;
            }
        }
    }
    return aPlayerWantsToPlay;
}
bool CasinoFunctions::ReturnToLobby(bool& aPlayerWantsToPlay)
{
    enum YesOrNo
    {
        Yes = 1,
        No,
    };
    int yesOrNo;
    do
    {
        std::cout << "---------------------------------------------------------------------" << std::endl;
        std::cout << "Return to lobby?: " << std::endl;
        std::cout << "[1] Yes." << std::endl;
        std::cout << "[2] Exit casino." << std::endl;
        std::cin >> yesOrNo;
        std::cout << "---------------------------------------------------------------------" << std::endl;
        if (yesOrNo == Yes || yesOrNo == No)
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
        if (yesOrNo != Yes)
        {
            aPlayerWantsToPlay = false;
        }
    }
    return aPlayerWantsToPlay;
}
void CasinoFunctions::StatisticsForLast5Games(std::array<int, 5>& aStatisticsArray, int& aBetthatismade, int aNumberOfGamesPlayed)
{
    const int numberOfGamesInTheStatistics = 5;
    aStatisticsArray[aNumberOfGamesPlayed % numberOfGamesInTheStatistics] = aBetthatismade;

}
void CasinoFunctions::TheTableOfRoulette(bool normalTable)
{
    if (normalTable == true)
    {
        std::cout << " #########################  " << std::endl;
        std::cout << "/              0          \\" << std::endl;
        std::cout << " -------------------------- " << std::endl;
        std::cout << "|   1R   |   2B   |   3R   |" << std::endl;
        std::cout << " -------------------------- " << std::endl;
        std::cout << "|   4B   |   5R   |   6B   |" << std::endl;
        std::cout << " ---------------------------------- " << std::endl;
        std::cout << "|   7R   |   8B   |   9R   |       |" << std::endl;
        std::cout << " --------------------------  Even  |" << std::endl;
        std::cout << "|  10B   |  11B   |  12R   |       |" << std::endl;
        std::cout << " ---------------------------------- " << std::endl;
        std::cout << "|  13B   |  14R   |  15B   |       |" << std::endl;
        std::cout << " --------------------------   Red  |" << std::endl;
        std::cout << "|  16R   |  17B   |  18R   |       |" << std::endl;
        std::cout << " ---------------------------------- " << std::endl;
        std::cout << "|  19R   |  20B   |  21R   |       |" << std::endl;
        std::cout << " --------------------------  Black |" << std::endl;
        std::cout << "|  22B   |  23R   |  24B   |       |" << std::endl;
        std::cout << " ---------------------------------- " << std::endl;
        std::cout << "|  25R   |  26B   |  27R   |       |" << std::endl;
        std::cout << " --------------------------   Odd  |" << std::endl;
        std::cout << "|  28B   |  29B   |  30R   |       |" << std::endl;
        std::cout << " ---------------------------------- " << std::endl;
        std::cout << "|  31B   |  32R   |  33B   |" << std::endl;
        std::cout << " -------------------------- " << std::endl;
        std::cout << "|  34R   |  35B   |  36R   |" << std::endl;
        std::cout << " -------------------------- " << std::endl;
        std::cout << "\\ col1  |  col2  |  col3  /" << std::endl;
        std::cout << " #########################  " << std::endl;
    }
    else
    {
        std::cout << " #########################  " << std::endl;
        std::cout << "/              0          \\" << std::endl;
        std::cout << " -------------------------- " << std::endl;
        std::cout << "|   1R   |   2B   |   3R   |" << std::endl;
        std::cout << " -------(1)------(2)------- " << std::endl;
        std::cout << "|   4B   |   5R   |   6B   |" << std::endl;
        std::cout << " -------(3)------(4)--------------- " << std::endl;
        std::cout << "|   7R   |   8B   |   9R   |       |" << std::endl;
        std::cout << " -------(5)------(6)-------  Even  |" << std::endl;
        std::cout << "|  10B   |  11B   |  12R   |       |" << std::endl;
        std::cout << " -------(7)------(8)--------------- " << std::endl;
        std::cout << "|  13B   |  14R   |  15B   |       |" << std::endl;
        std::cout << " -------(9)------(10)------   Red  |" << std::endl;
        std::cout << "|  16R   |  17B   |  18R   |       |" << std::endl;
        std::cout << " -------(11)-----(12)------------- " << std::endl;
        std::cout << "|  19R   |  20B   |  21R   |       |" << std::endl;
        std::cout << " -------(13)-----(14)------  Black |" << std::endl;
        std::cout << "|  22B   |  23R   |  24B   |       |" << std::endl;
        std::cout << " -------(15)-----(16)-------------- " << std::endl;
        std::cout << "|  25R   |  26B   |  27R   |       |" << std::endl;
        std::cout << " -------(17)-----(18)------   Odd  |" << std::endl;
        std::cout << "|  28B   |  29B   |  30R   |       |" << std::endl;
        std::cout << " -------(19)-----(20)-------------- " << std::endl;
        std::cout << "|  31B   |  32R   |  33B   |" << std::endl;
        std::cout << " -------(21)-----(22)------ " << std::endl;
        std::cout << "|  34R   |  35B   |  36R   |" << std::endl;
        std::cout << " -------------------------- " << std::endl;
        std::cout << "\\ col1  |  col2  |  col3  /" << std::endl;
        std::cout << " #########################  " << std::endl;
    }
}
void CasinoFunctions::ThrownOut(int aPlayersCredits, bool& aBoolForPlaying)
{
    const int outOfCredits = 0;
    if (aPlayersCredits == outOfCredits)
    {

        std::cout << "You see two strong men in suits walkning towards you. The men grabs you by your hands and feet and says:" << std::endl;
        std::cout << "'People without credits are not welcome in this establishment.'" << std::endl;
        std::cout << "While they carry you towards the exit a chill runs down your spine as you realise you gambled away this months rent..." << std::endl;
        aBoolForPlaying = false;

    }

}
void CasinoFunctions::TotalWinnings(int& aTotalWinLoss, int aWinTotal, int aLossTotal, bool& playing)
{
    const int suspiciousWinnings = 10000;
    const int greatWinnings = 1000;
    const int greatLosses = -1000;
    aTotalWinLoss = aWinTotal + aLossTotal;
    if (aTotalWinLoss > suspiciousWinnings)
    {
        std::cout << "---------------------------------------------------------------------" << std::endl;
        std::cout << "The guards escort you from the table because you have had to much luck, they don't think this is a coincidence!" << std::endl;
        playing = false;
    }
    else if (aTotalWinLoss > greatWinnings)
    {
        std::cout << "---------------------------------------------------------------------" << std::endl;
        std::cout << "Your have won a total of " << aTotalWinLoss << " credits at this table! NICE!" << std::endl;
        std::cout << "---------------------------------------------------------------------" << std::endl;

    }
    else if (aTotalWinLoss < greatLosses)
    {
        std::cout << "Your have lost a total of " << aTotalWinLoss << " credits at this table... too bad." << std::endl;
    }
    else
    {
        std::wcout << "Your have won/lost a total of " << aTotalWinLoss << " credits at this table so far." << std::endl;
    }

}


