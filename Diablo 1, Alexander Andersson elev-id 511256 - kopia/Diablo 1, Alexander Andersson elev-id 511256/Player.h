#pragma once
#include <string>
class Room;
class Doors;

class Player
{
public:
	Player();
	void SetPlayerName(std::string aPlayersName);
	std::string GetPlayerName() const;
	void SetCurrentRoom(int& aCurrrentRoom);
	int GetCurrentRoom() const;
	void SetAttackValue();
	int GetAttackValue() const;
	void SetHealth();
	int GetHeath() const;
	int GetMaxHealth() const;
	void SetDefenceValue();
	int GetDefenceValue() const;
	void Init();
	void LooseLife(int aNumberOfAttack);
	bool IsAlive();
private:
	std::string myPlayerName;
	bool myPlayerLives;
	int myHealth;
	int myMaxHealth;
	int myAttack;
	int myCarryCapacaty;
	int myDefence;
	int myStrength;
	int myDexterity;
	int myPhysics;
	int RoomChoice;

};

