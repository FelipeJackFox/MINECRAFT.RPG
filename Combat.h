#ifndef COMBAT_H
#define COMBAT_H

#include "Player.h"
#include "Enemy.h"

class Combat {
private:
    Player& player;
    Enemy& enemy;

    // Private Methods
    void playerTurn();
    void enemyTurn();
    void calculateDamage(Entity& attacker, Entity& defender);
    void applyStatusEffects(Entity& entity);
    void checkForDeaths();

public:
    Combat(Player& player, Enemy& enemy);

    // Methods
    void startCombat();
};

#endif // COMBAT_H
