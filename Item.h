#ifndef ITEM_H
#define ITEM_H

#include <map>

enum class ItemType {
  WEAPON,
  ARMOR,
  OTHER
};

enum class StatType {
  HEALTH,
  DAMAGE,
  RESISTANCE,
  CRITICAL_CHANCE
};

class Item {
public:
  ItemType type;
  std::map<StatType, int> stats;

  // Constructor
  Item(ItemType type);

  // Methods
  int getStat(StatType stat);
};

#endif