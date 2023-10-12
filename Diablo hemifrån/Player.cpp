#include "Player.h"


Player::Player()
{
    myStrength = 3;
    myDexterity = 5;
    myPhysics = 8;
}

void Player::Init()
{
    SetAttackValue();
    SetDefenceValue();
    SetHealthValue();
    SetStats(myStrength, myDexterity, myPhysics);
}

void Player::SetAttackValue()
{
    myAttackValue = myStrength * myDexterity;
}

int Player::GetAttackValue() const
{
    return myAttackValue;
}

void Player::SetDefenceValue()
{
    myDefenceValue = myStrength * myPhysics;
}

int Player::GetDefenceValue() const
{
    return myDefenceValue;
}

void Player::SetHealthValue()
{
    myHealthValue = myDexterity * myPhysics;
}

int Player::GetHealthValue() const
{
    return myHealthValue;
}

void Player::SetStats(int &anAmountOfStrength, int anAmountOfDexterity, int anAmountOfPhysiscs)
{
    myStrength = anAmountOfStrength;
    myDexterity = anAmountOfDexterity;
    myPhysics = anAmountOfPhysiscs;
}

bool Player::isAlive()
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
