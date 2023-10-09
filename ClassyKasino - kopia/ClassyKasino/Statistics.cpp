#include "Statistics.h"

Statistics::Statistics()
{
	
}

void Statistics::SetStatistics(int aWinOrLoss, int aNumberOfGamesPlayed)
{
	const int numberOfGamesInTheStatistics = 5;
	myStatisticsArray[aNumberOfGamesPlayed % numberOfGamesInTheStatistics] = aWinOrLoss;
}

int Statistics::GetStatistics(int aNumberInTheArray) const
{
	
	return myStatisticsArray[aNumberInTheArray];
	
}






