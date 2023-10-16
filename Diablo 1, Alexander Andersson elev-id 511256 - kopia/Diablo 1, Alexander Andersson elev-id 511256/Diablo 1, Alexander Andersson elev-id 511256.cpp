// Diablo 1, Alexander Andersson elev-id 511256.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <array>
#include "Enemies.h"
#include "Player.h"
#include "Room.h"
#include "Doors.h"


int main() 
{
    int currentRoom = 0;
    Doors rayManzerek(0, 1);
    Doors jimMorrison(1, 2);
    Doors robbieKreiger(2, 3);
    Doors johnDensmore(3, 0); 
    bool playingTheGame = true;
    
    std::string playerName;
    Player playerOne;

    

    std::string messageOne = "A door that says: This is the way";
    std::string messageTwo = "A door that says: This is the other way";
    std::string messageThree = "A door that says: This is the third way";
    std::string messageFour = "A door that says: This is the mandalorian way";

   

    Room firstRoom;
    Room secondRoom;
    Room thirdRoom;
    Room fourthRoom;

    playerOne.SetPlayerName(playerName);
    playerOne.GetPlayerName();
    rayManzerek.SetDoor(messageOne);
    jimMorrison.SetDoor(messageTwo); 
    robbieKreiger.SetDoor(messageThree); 
    johnDensmore.SetDoor(messageFour);

    std::vector<Doors*> myDoors;

    Doors* door1 = &rayManzerek;
    Doors* door2 = &jimMorrison;
    Doors* door3 = &robbieKreiger;
    Doors* door4 = &johnDensmore;

    std::vector<Room> theRoomVector = { firstRoom, secondRoom, thirdRoom, fourthRoom };
    theRoomVector[0].AddDoor(door1, door2);
    theRoomVector[1].AddDoor(door2, door3);
    theRoomVector[2].AddDoor(door3, door4);
    theRoomVector[3].AddDoor(door4, door1);
    theRoomVector[0].ShowDoorsInRoom();

    std::cout << "Welcome brave warrior! please enter your name!" << std::endl;
    std::cin >> playerName;
    
    
    while (playerOne.IsAlive() == true && playingTheGame)
    {
        theRoomVector[currentRoom].EnterRoom(playerOne);
        playerOne.SetCurrentRoom(currentRoom);
        /*if (currentRoom != theRoomVector.size() - 1)
        {
            currentRoom++;
        }
        else
        {
            playingTheGame = false;
        }*/
        
    }
    if(playerOne.IsAlive() == true)
    {
        std::cout << "All enemies in the dungeon defeated!" << std::endl;
    }
    else
    {
        std::cout << "You dead!" << std::endl;
    }
   
    

   
    
    
    
    
    
    
    
}

