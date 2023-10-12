
#include <iostream>
#include "Doors.h"
#include "Enemies.h"
#include "Player.h"
#include "Room.h"
#include "Enums.h"
int main()
{
    std::string earwig = "Earwig";
    std::string ladybug = "Ladybug";
    std::string stagBeetle = "Stag beetle";
    
    EnemyName enemyEnum;
    Player player;
    Enemies enemy;
    Enemies enemy2;
    int earwigInt= 0;
    
    enemy.SetCoiceOfEnemy(earwigInt);
    enemy.SetEnemyName(earwig);
    enemy.Init();
    player.Init();

    while (enemy.isAlive() == true && player.isAlive() == true)
    {
        std::cout << "You are fighting an " << enemy.GetEnemyName() << " it looks menacing." << std::endl
                  << "The " << enemy.GetEnemyName() << " has " << enemy.GetHealthValue() << " HP" << std::endl
                  << "Press Enter to attack" << std::endl;
        system("pause"); 
        enemy.EnemyTakeDamage((player.GetAttackValue() - enemy.GetDefenceValue()));
        std::cout << "You smack the enemy for " << (player.GetAttackValue() - enemy.GetDefenceValue()) << " damage." << std::endl;
        if (enemy.isAlive()== false)
        {
            std::cout << "You defeated the enemy." << std::endl;
        }
    }
}

