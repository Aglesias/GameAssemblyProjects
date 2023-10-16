#pragma once
#include <string>
#include <array>
class Enemies
{
public:
	Enemies();
	void SetEnemyName(std::string aEnemyName);
	std::string GetEnemyName() const;
	void SetEnemyAttackValue();
	int GetEnemyAttackValue() const;
	void SetEnemyHealth();
	int GetEnemyHealth() const;
	void SetDefenceValue();
	int GetDefenceValue() const;
	void SetEnemyStats();
	void SetEnemyMaxHealth();
	int GetEnemyMaxHealth() const;
	void Init();
	void LooseLifeEnemy(int aNumberOfAttack);
	bool IsAlive();
private:
	
	std::string myEnemyName;
	bool myEnemyLives;
	int myEnemyHealth;
	int myEnemyAttack;
	int myEnemyCarryCapacaty;
	int myEnemyDefence;
	int myEnemyStrength;
	int myEnemyDexterity;
	int myEnemyPhysics;
	int myEnemyMaxHealth;
};

