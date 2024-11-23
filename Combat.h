#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"
#include "Enemy.h"
#include "Dungeon.h"
#include "Entity.h"
#include <vector>
#include <string>

class Combat {
private:
    Player& player;
    Enemy& enemy;
    Dungeon& dungeon;
    
    std::string calculateDamage(const std::string& attackerName, Entity& attacker, const std::string& defenderName, Entity& defender);

public:
    Combat(Player& player, Enemy& enemy, Dungeon& dungeon);

    std::string playerTurn();
    std::string enemyTurn();
    std::string checkForDeaths();
};

#endif // COMBAT_H
