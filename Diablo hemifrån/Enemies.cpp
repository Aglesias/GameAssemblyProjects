#include "Enemies.h"
#include "Enums.h"
Enemies::Enemies()
{
    myStrengthEnemy = 0;
    myDexterityEnemy = 0;
    myPhysicsEnemy = 0;
    Init();
}

void Enemies::Init()
{
    SetStats(myStrengthEnemy, myDexterityEnemy, myPhysicsEnemy, GetChoiceOfEnemy());
    SetAttackValue();
    SetDefenceValue();
    SetHealthValue();
}

void Enemies::SetEnemyName(std::string &aNameForAnEnemy)
{
    myEnemyName = aNameForAnEnemy;
}

std::string Enemies::GetEnemyName() const
{
    return myEnemyName;
}

void Enemies::SetCoiceOfEnemy(int &anEnemyType)
{
    myEnemyInt = anEnemyType; 
}

int Enemies::GetChoiceOfEnemy() const
{
    return myEnemyInt;
}



void Enemies::SetAttackValue()
{
    myAttackValueEnemy = myStrengthEnemy * myDexterityEnemy;
}

int Enemies::GetAttackValue() const
{
    return myAttackValueEnemy;
}

void Enemies::SetDefenceValue()
{
    myDefenceValueEnemy = myStrengthEnemy * myPhysicsEnemy;
}

int Enemies::GetDefenceValue() const
{
    return myDefenceValueEnemy;
}

std::string Enemies::EnemyType(std::string anEnemyType)
{
    myEnemyName = anEnemyType;
    return myEnemyName;
}

void Enemies::SetHealthValue()
{
    myHealthValueEnemy = myDexterityEnemy * myPhysicsEnemy;
}

int Enemies::GetHealthValue() const
{
    return myHealthValueEnemy;
}

void Enemies::EnemyTakeDamage(int anAttackValue)
{
    myHealthValueEnemy -= anAttackValue;
}

void Enemies::SetStats(int& anAmountOfStrength, int &anAmountOfDexterity, int &anAmountOfPhysiscs, int aChoiceOfEnemy)
{
    int earwigStrength = 3;
    int earwigDex = 5;
    int earwigPhys = 2;
    int ladybugStrength = 4;
    int ladybugDex = 4;
    int ladybugPhys = 5;
    int stagbeetleStrength = 7;
    int stagbeetleDex = 8;
    int stagbeetlePhys = 8;
    
    EnemyName theNameOfAnEnemy;
    theNameOfAnEnemy = static_cast<EnemyName>(aChoiceOfEnemy);
    switch (theNameOfAnEnemy)
    {
       
    case EnemyName::Earwig:
        anAmountOfStrength += earwigStrength;
        anAmountOfDexterity += earwigDex;
        anAmountOfPhysiscs += earwigPhys; 
        break;
    case EnemyName::Ladybug:
        anAmountOfStrength += ladybugStrength;
        anAmountOfDexterity += ladybugDex;
        anAmountOfPhysiscs += ladybugPhys;
        break;
    case EnemyName::StagBeetle: 
        anAmountOfStrength += stagbeetleStrength;
        anAmountOfDexterity += stagbeetleDex;
        anAmountOfPhysiscs += stagbeetlePhys;
        break;
          
    default:
        break;
    }
}


bool Enemies::isAlive()
{
    if (GetHealthValue() <= 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
