#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "Player.h"

class Enemy : public Entity {
public:
  // Constructor
  Enemy(int health, int damage, float critical_damage_prob, 
        float critical_damage_multiplier, int resistance);

  // Methods
  void attackPlayer(Player& player);
};

#endif