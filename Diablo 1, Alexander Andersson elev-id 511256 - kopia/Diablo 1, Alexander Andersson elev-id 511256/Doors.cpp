#include "Doors.h"

Doors::Doors(int aFirstExit, int aSecondExit)
{
	aFirstExit = 0;
	aSecondExit = 0;
	myDurren = "This is a door";
}

void Doors::SetDoor(std::string &aDoorDescription)
{
	myDurren = aDoorDescription;
}

void Doors::ChangeRoom(Room& aRoom, Room& aSecondRoom, Doors& aDoor, Doors aSecondDoor)
{
	
}

std::string Doors::GetDoor() const
{
	
	return myDurren;
}
