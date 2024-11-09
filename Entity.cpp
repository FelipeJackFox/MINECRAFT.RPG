#include "Enemy.h"

// Constructor implementation
Enemy::Enemy(int health, int damage, float critical_damage_prob, 
             float critical_damage_multiplier, int resistance) : 
             Entity(health, damage, critical_damage_prob, 
             critical_damage_multiplier, resistance) {}

// Method implementations