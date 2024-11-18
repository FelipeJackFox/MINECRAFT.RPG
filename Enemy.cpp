#include "Enemy.h"
#include <cstdlib>

Enemy::Enemy() {
    // Customize enemy stats if needed
    health = 50;
    damage = 8;
    criticalDamagePercent = 0.05f;
    criticalDamageMultiplier = 1.2f;
}

void Enemy::attackPlayer(Player& player) {
    int actualDamage = damage;

    // Check for critical hit
    float randValue = static_cast<float>(rand()) / RAND_MAX;
    if (randValue < criticalDamagePercent) {
        actualDamage = static_cast<int>(damage * criticalDamageMultiplier);
    }

    // Calculate damage after resistance
    int damageDealt = actualDamage - player.getResistance();
    if (damageDealt < 0) damageDealt = 0;

    // Apply damage to player
    int newHealth = player.getHealth() - damageDealt;
    player.setHealth(newHealth);
}
