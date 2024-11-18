#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
public:
    Enemy();

    // Methods
    void attackPlayer(Player& player);
};

#endif // ENEMY_H
