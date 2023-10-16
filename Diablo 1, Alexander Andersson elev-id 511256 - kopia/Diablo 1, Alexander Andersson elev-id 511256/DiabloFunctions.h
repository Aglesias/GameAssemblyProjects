#pragma once
#include <vector>
#include <iostream>
#include "Enemies.h"
#include "Room.h"
namespace DiabloFunctions
{
    void DisplayEnemiesWithHealth(std::vector<Enemies*>& anEnemyVector)
    {
        for (int enemyIndex = 0; enemyIndex < anEnemyVector.size(); enemyIndex++)
        {
            std::cout << "[" << enemyIndex + 1 << "] You see " << anEnemyVector[enemyIndex]->GetEnemyName() << " it has " << anEnemyVector[enemyIndex]->GetEnemyHealth() << " / " << anEnemyVector[enemyIndex]->GetEnemyMaxHealth() << " HP" << std::endl;
        }

    }
    int SelectEnemyToAttack(std::vector<Enemies*>& anEnemyVector)
    {
        bool enemyIsOk = false;
        int selectedEnemy;
        if (anEnemyVector.size() > 0)
        {
            do
            {
                std::cout << "---------------------------------------------------------------------" << std::endl;
                std::cout << "Who vould you like to attack?" << std::endl;
                std::cin >> selectedEnemy;
                std::cout << "---------------------------------------------------------------------" << std::endl;


                if (selectedEnemy <= anEnemyVector.size() && selectedEnemy > 0)
                {
                    enemyIsOk = true;
                }
                else if (std::cin.fail())
                {
                    std::cin.clear();
                    std::cin.ignore(100, '\n');

                    std::cout << "Please select an enemy to attack." << std::endl;
                }
                else
                {
                    std::cout << "Please select an enemy to attack." << std::endl;
                }

            } while (enemyIsOk == false);
            {
                return selectedEnemy;
            }
        }
        return 0;

    }
    void CreateEnemies(std::vector<Enemies*>& anEnemyVector, Enemies*& anEnemy, Enemies*& aSecondEnemy)
    {
       
        anEnemy->SetEnemyName("Earwig");
        anEnemy->Init();
        aSecondEnemy->SetEnemyName("Ladybug");
        aSecondEnemy->Init();
        anEnemyVector.push_back(anEnemy);
        anEnemyVector.push_back(aSecondEnemy);
        
    }
    /*void RoomMessage(Room &aCurrentRoom)
    {
        std::cout << "You see two doors in the room, which door would you like to use?" << std::endl;
       
    }*/
}
