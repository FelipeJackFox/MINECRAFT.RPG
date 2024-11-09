#include "Player.h"
#include <string> 

// Constructor implementation
Player::Player(std::string name) : Entity(100, 10, 5.0f, 1.5f, 0), name(name), experienceLevel(1) {}

// Method implementations