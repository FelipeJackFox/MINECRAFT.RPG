#ifndef INVENTORY_H
#define INVENTORY_H

#include <list>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"

class Inventory {
public:
  Weapon* equippedWeapon;
  Armor* equippedArmor;
  std::list<Item*> items;

  // Methods
  void addItem(Item* item);
  void removeItem(Item* item);
  void equipItem(Item* item);
};

#endif 