#include "Player.h"
#include "Room.h"

Player::Player()
{
	myStrength = 2;
	myDexterity = 10;
	myPhysics = 10;
	myMaxHealth = myDexterity * myPhysics;
	Init();
}
void Player::Init()
{
	SetDefenceValue();
	SetAttackValue();
	SetHealth();
}

void Player::SetPlayerName(std::string aPlayersName)
{
	myPlayerName = aPlayersName;
}

std::string Player::GetPlayerName() const
{
	return myPlayerName;
}

void Player::SetCurrentRoom(int &aCurrrentRoom)
{
	std::cout << "Choose a room" << std::endl;

	std::cin >> RoomChoice;

	switch (RoomChoice)
	{
	case 1:
		aCurrrentRoom -= 1; 
		if (aCurrrentRoom < 0)
		{
			aCurrrentRoom = 3;
		}
		break;
	case 2:
		aCurrrentRoom += 1;
		if (aCurrrentRoom > 4)
		{
			aCurrrentRoom = 0;
		}
		break;
	default:
		break;
	}

}

int Player::GetCurrentRoom() const
{
	return RoomChoice;
}

void Player::SetAttackValue()
{
	myAttack = myStrength * myDexterity;
}

int Player::GetAttackValue() const
{
	return myAttack;
}

void Player::SetHealth()
{
	myHealth = myDexterity * myPhysics;
}

int Player::GetHeath() const
{
	return myHealth;
}
int Player::GetMaxHealth() const
{
	return myMaxHealth;
}
void Player::SetDefenceValue()
{
	myDefence = myPhysics * myStrength;
}
int Player::GetDefenceValue() const
{
	return myDefence;
}
bool Player::IsAlive()
{
	if(GetHeath() <= 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void Player::LooseLife(int aNumberOfAttack)
{
	myHealth -= aNumberOfAttack;
	if (myHealth <= 0)
	{
		myHealth = 0;
		
	}
}



