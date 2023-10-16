#include "Enemies.h"
#include <iostream>

Enemies::Enemies()
{
	myEnemyName = "Flea";
	myEnemyAttack = 0;
	myEnemyDefence = 0;
	myEnemyCarryCapacaty = 0;
	myEnemyLives = true;
	Init();
}

void Enemies::Init()
{
	SetEnemyStats();
	SetEnemyHealth();
	SetEnemyAttackValue();
	SetDefenceValue();
	SetEnemyMaxHealth();
}
void Enemies::SetEnemyName(std::string anEnemyName)
{
	myEnemyName = anEnemyName;	
}

std::string Enemies::GetEnemyName() const
{
	return myEnemyName;
}

void Enemies::SetEnemyAttackValue()
{
	myEnemyAttack = myEnemyStrength * myEnemyDexterity;
}

int Enemies::GetEnemyAttackValue() const
{
	return myEnemyAttack;
}

void Enemies::SetEnemyHealth()
{
	myEnemyHealth = myEnemyPhysics * myEnemyDexterity;
}

int Enemies::GetEnemyHealth() const
{
	return myEnemyHealth;
}

void Enemies::SetDefenceValue()
{
	myEnemyDefence = myEnemyStrength * myEnemyPhysics;
}

int Enemies::GetDefenceValue() const
{
	return myEnemyDefence;
}

void Enemies::SetEnemyStats()
{
	if (myEnemyName == "Earwig")
	{
		myEnemyStrength = 2;
		myEnemyDexterity = 2;
		myEnemyPhysics = 5;
	}
	else if (myEnemyName == "Ladybug")
	{
		myEnemyStrength = 2;
		myEnemyDexterity = 15;
		myEnemyPhysics = 2;
	}
	else
	{
		myEnemyStrength = 2;
		myEnemyDexterity = 2;
		myEnemyPhysics = 2;
	}
}

void Enemies::SetEnemyMaxHealth()
{
	myEnemyMaxHealth = myEnemyPhysics * myEnemyDexterity;
}

int Enemies::GetEnemyMaxHealth() const
{
	return myEnemyMaxHealth;
}



void Enemies::LooseLifeEnemy(int aNumberOfAttack)
{
	myEnemyHealth -= aNumberOfAttack;
}

bool Enemies::IsAlive()
{
	if (GetEnemyHealth() <= 0) 
	{
		std::cout << "The " << GetEnemyName() << " is dead." << std::endl;
		return myEnemyLives = false;
	}
	else
	{
		
		return myEnemyLives = true;
	}
}
