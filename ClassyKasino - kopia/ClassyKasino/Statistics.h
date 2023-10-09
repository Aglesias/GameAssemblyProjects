#pragma once
#include <array>
class Statistics
{
public:
	Statistics();
	void SetStatistics(int aWinOrLoss, int aNumberOfGamesPlayed);
	int GetStatistics(int aNumberInTheArray) const; 
	
	
private:
	std::array<int, 5> myStatisticsArray = { 0,0,0,0,0 };
};

