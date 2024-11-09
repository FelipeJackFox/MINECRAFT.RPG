#ifndef PLAYER_H
#define PLAYER_H

#include <string> 
#include "Entity.h"

enum class StatType {
  HEALTH,
  DAMAGE,
  RESISTANCE,
  CRITICAL_CHANCE
};

class Player : public Entity {
public:
  int experienceLevel;
  std::string name;

  // Constructor
  Player(std::string name);

  // Methods
  void levelUp();
  void increaseStat(StatType stat);
};

#endif