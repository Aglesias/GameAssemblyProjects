#pragma once
#include <string>

class Enemies
{
public:
	Enemies();
	void Init();
	void SetEnemyName(std::string& aNameForAnEnemy);
	std::string GetEnemyName() const;
	void SetCoiceOfEnemy(int& anEnemyType);
	int GetChoiceOfEnemy() const;
	void SetAttackValue();
	int GetAttackValue() const;
	void SetDefenceValue();
	int GetDefenceValue() const;
	std::string EnemyType(std::string anEnemyType);
	void SetHealthValue();
	int GetHealthValue() const;
	void EnemyTakeDamage(int anAttackValue);
	void SetStats(int& anAmountOfStrength, int &anAmountOfDexterity, int &anAmountOfPhysiscs, int aChoiceOfEnemy);
	bool isAlive();
private:
	int myHealthValueEnemy;
	int myDefenceValueEnemy;
	int myStrengthEnemy;
	int myDexterityEnemy;
	int myPhysicsEnemy;
	int myAttackValueEnemy;
	std::string myEnemyName;
	int myEnemyInt;
};

