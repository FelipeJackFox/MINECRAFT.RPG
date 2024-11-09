#ifndef DUNGEON_H
#define DUNGEON_H

#include <list>
#include "Enemy.h"
#include "Item.h"

class Exit {
 public:
  //Attributes
};

class Dungeon {
public:
  int level;
  std::list<Enemy*> enemies;
  Enemy* boss;
  std::list<Item*> items;
  Exit* exit;

  // Constructor
  Dungeon(int level);

  // ... (Potential methods for the Dungeon class)
};

#endif