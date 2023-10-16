#include "Room.h"
#include "Doors.h"
#include "Player.h"
#include "DiabloFunctions.h"
Room::Room()
{


}

void Room::EnterRoom(Player& aPlayer)
{
    FightEnemies(aPlayer);
    UseDoor(aPlayer);

}

void Room::FightEnemies(Player& aPlayer)
{
    DiabloFunctions::CreateEnemies(myEnemies, ptr1, ptr2);
    std::cout << " " << std::endl;
    std::cout << "-------- | New Door | --------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << myDoorsInRoom[0]->GetDoor() << std::endl;
    std::cout << myDoorsInRoom[1]->GetDoor() << std::endl;
    std::cout << " " << std::endl;
    while ((!myEnemies.empty() && myEnemies.back()->IsAlive() && aPlayer.IsAlive()))
    {
        std::cout << "-------- | New Round | --------" << std::endl;
        DiabloFunctions::DisplayEnemiesWithHealth(myEnemies);
        int selectedEnemy = DiabloFunctions::SelectEnemyToAttack(myEnemies) - 1;

        if (myEnemies[selectedEnemy]->GetEnemyHealth() <= 0)
        {
            std::cout << "Stop hitting the dead!" << std::endl;

        }
        else
        {
            int playerDamage = (aPlayer.GetAttackValue() - myEnemies[selectedEnemy]->GetDefenceValue());
            std::cout << "You are fighting an " << myEnemies[selectedEnemy]->GetEnemyName() << " it has " << myEnemies[selectedEnemy]->GetEnemyHealth() << " HP" << std::endl;
            std::cout << "You deal " << playerDamage << " damage." << std::endl;
            std::cout << "Press enter to attack enemy!" << std::endl;
            myEnemies[selectedEnemy]->LooseLifeEnemy(playerDamage);
            if (myEnemies[selectedEnemy]->GetEnemyHealth() <= 0)
            {
                it = myEnemies.begin() + selectedEnemy;
                myEnemies.erase(it);

            }
            else if (myEnemies.empty() == true)
            {
                std::cout << "You've killed all the enemies in this room!" << std::endl;
                break;
            }
            for (int enemyIndex = 0; enemyIndex < myEnemies.size(); enemyIndex++)
            {
                if (myEnemies[enemyIndex]->IsAlive() == true)
                {
                    int damage = (myEnemies[enemyIndex]->GetEnemyAttackValue() - aPlayer.GetDefenceValue());
                    if (damage < 0)
                    {
                        damage = 1;

                    }
                    std::cout << "The " << myEnemies[enemyIndex]->GetEnemyName() << " hits you for " << damage << " points of damage, ouch!" << std::endl;
                    aPlayer.LooseLife(damage);
                    std::cout << "You HP is " << aPlayer.GetHeath() << "/" << aPlayer.GetMaxHealth() << std::endl;
                    if (aPlayer.GetHeath() == 0)
                    {
                        std::cout << "You are dead." << std::endl;
                        break;
                    }
                }
            }

        }

        std::cout << "You walk into the another room through: " << myDoorsInRoom[1]->GetDoor() << std::endl;
    }
}

void Room::AddDoor(Doors*& aDoor, Doors* aSecondDoor)
{
    myDoorsInRoom.push_back(aDoor);
    myDoorsInRoom.push_back(aSecondDoor);
}

void Room::ShowDoorsInRoom()
{
    std::cout << myDoorsInRoom[0]->GetDoor() << std::endl;
    std::cout << myDoorsInRoom[1]->GetDoor() << std::endl;
}

void Room::UseDoor(Player& aPlayer)
{
    for (int doorIndex = 0; doorIndex < myDoorsInRoom.size(); doorIndex++)
    {
        std::cout << "[" << doorIndex + 1 << "] " << myDoorsInRoom[doorIndex]->GetDoor() << std::endl;
    }
    system("pause");
   /* switch (switch_on)
    {
    case 1:
        break;
    case 2:
        break;
    default:
        break;
    }*/
}
