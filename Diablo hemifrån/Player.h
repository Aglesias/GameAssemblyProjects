#pragma once
#include <iostream>
#include <string>
class Player
{
public:
	Player();
	void Init();
	void SetAttackValue();
	int GetAttackValue() const;
	void SetDefenceValue();
	int GetDefenceValue() const;
	void SetHealthValue();
	int GetHealthValue() const;
	void SetStats(int& anAmountOfStrength, int anAmountOfDexterity, int anAmountOfPhysiscs);
	bool isAlive();
private:
	int myHealthValue;
	int myAttackValue;
	int myDefenceValue;
	int myStrength;
	int myDexterity;
	int myPhysics;
	
};

