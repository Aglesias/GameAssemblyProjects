#pragma once
#include "Doors.h"
#include <string>
#include <vector>
#include "Enemies.h"
class Player;
class Enemies;

class Room
{
public:
    Room();
    void EnterRoom(Player& aPlayer);
    void FightEnemies(Player& aPlayer);
    void AddDoor(Doors*& aDoor, Doors* aSecondDoor);
    void ShowDoorsInRoom();
    void UseDoor(Player& aPlayer);
private:
    Enemies myEnemy;
    Enemies myEnemy2;
    Enemies* ptr1 = &myEnemy;
    Enemies* ptr2 = &myEnemy2;
    int currentRoom = 0;
    std::vector<Enemies*> myEnemies;
    std::vector<Enemies*>::iterator it = myEnemies.begin();
    std::vector<Doors*> myDoorsInRoom;
};