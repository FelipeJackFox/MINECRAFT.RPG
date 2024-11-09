#ifndef COMBAT_H
#define COMBAT_H

#include "Entity.h"

enum class Input {
  ATTACK,
  DEFEND,
  USE_ITEM,
  RUN
};

enum class Action {
  ATTACK,
  DEFEND,
  USE_ITEM,
  RUN
};

class Combat {
public:
  // Methods
  void handleTurn(Entity* attacker, Entity* defender);
  int calculateDamage(Entity* attacker, Entity* defender);
  void applyStatusEffects(Entity* entity);  
  void checkForDeath(Entity* entity);
  void handleInput();
  Action InputToAction(Input input);
};

#endif