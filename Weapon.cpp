#include "Weapon.h"

// Constructor implementation
Weapon::Weapon(int damage, float critical_chance) : 
  Item(ItemType::WEAPON), damage(damage), critical_chance(critical_chance) {}