#include "Combat.h"

Combat::Combat(Player& player, Enemy& enemy, Dungeon& dungeon)
    : player(player), enemy(enemy), dungeon(dungeon) {}

std::string Combat::playerTurn() {
    return calculateDamage(player.getName(), player, enemy.getName(), enemy);
}

std::string Combat::enemyTurn() {
    return calculateDamage(enemy.getName(), enemy, player.getName(), player);
}

std::string Combat::calculateDamage(const std::string& attackerName, Entity& attacker, const std::string& defenderName, Entity& defender) {
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

    // Return attack information as a string
    return attackerName + " dealt " + std::to_string(damageDealt) + " damage to " + defenderName + "!";
}

std::string Combat::checkForDeaths() {
    if (!player.getIsAlive()) {
        return "Player has been defeated!";
    }
    if (!enemy.getIsAlive()) {
        int expGained = 5 + (dungeon.getLevel() * 2);
        player.gainExperience(expGained);
        return "Enemy " + enemy.getName() + " has been defeated! You gained " + std::to_string(expGained) + " experience points!";
    }
    return "";
}

