#ifndef ENTITY_H
#define ENTITY_H

#include "Inventory.h"

class Entity {
public:
  int health;
  bool isAlive;
  int damage;
  float critical_damage_prob;
  float critical_damage_multiplier;
  int resistance;
  Inventory inventory;

  // Constructor
  Entity(int health, int damage, float critical_damage_prob, 
         float critical_damage_multiplier, int resistance);

  // Methods
  void takeDamage(int damage);
  void attack(Entity& target);
};

#endif