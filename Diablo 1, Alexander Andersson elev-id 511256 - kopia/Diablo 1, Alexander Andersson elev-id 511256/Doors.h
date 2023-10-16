#pragma once
#include <iostream>
#include <string>
#include <vector>

class Room;

class Doors
{
public:
	Doors(int aFirstExit, int aSecondExit);
	void SetDoor(std::string& aDoorDescription); 
	void ChangeRoom(Room& aRoom, Room& aSecondRoom, Doors& aDoor, Doors aSecondDoor);
	std::string GetDoor() const; 
private:
	std::string myDurren;
	int myFirstExit;
	int mySecondExit;

	
};

