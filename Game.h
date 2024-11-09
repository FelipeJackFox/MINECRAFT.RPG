#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Dungeon.h"

class Game {
public:
  Player player;
  Dungeon dungeon;
  Combat combat;
  UI ui;

  // Methods
  void start();
  void gameLoop();
  void endGame();
};

#endif