#include "Combat.h"
#include <iostream>

Combat::Combat(Player& player, Enemy& enemy)
    : player(player), enemy(enemy) {}

void Combat::startCombat() {
    while (player.getIsAlive() && enemy.getIsAlive()) {
        playerTurn();
        if (enemy.getIsAlive()) {
            enemyTurn();
        }
    }
    checkForDeaths();
}

void Combat::playerTurn() {
    // For simplicity, player always attacks
    calculateDamage(player, enemy);
    applyStatusEffects(enemy);
}

void Combat::enemyTurn() {
    enemy.attackPlayer(player);
    applyStatusEffects(player);
}

void Combat::calculateDamage(Entity& attacker, Entity& defender) {
    int actualDamage = attacker.getDamage();

    // Check for critical hit
    float randValue = static_cast<float>(rand()) / RAND_MAX;
    if (randValue < attacker.getCriticalDamagePercent()) {
        actualDamage = static_cast<int>(actualDamage * attacker.getCriticalDamageMultiplier());
    }

    // Calculate damage after resistance
    int damageDealt = actualDamage - defender.getResistance();
    if (damageDealt < 0) damageDealt = 0;

    // Apply damage to defender
    int newHealth = defender.getHealth() - damageDealt;
    defender.setHealth(newHealth);

    // Output attack information
    std::cout << "Attacker dealt " << damageDealt << " damage.\n";
}

void Combat::applyStatusEffects(Entity& entity) {
    // Implement status effects if any
}

void Combat::checkForDeaths() {
    if (!player.getIsAlive()) {
        std::cout << "Player has been defeated!\n";
    }
    if (!enemy.getIsAlive()) {
        std::cout << "Enemy has been defeated!\n";
        // Grant experience to player
        player.gainExperience(10); // Example experience gain
    }
}
