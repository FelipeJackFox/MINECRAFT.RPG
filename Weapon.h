#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
public:
  int damage;
  float critical_chance;

  // Constructor
  Weapon(int damage, float critical_chance);
};

#endif