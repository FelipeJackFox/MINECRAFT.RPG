#include "Dungeon.h"
#include <cstdlib>

Dungeon::Dungeon() : level(1) {
    generateLevel();
}

int Dungeon::getLevel() const {
    return level;
}

void Dungeon::setLevel(int level) {
    this->level = level;
}

std::vector<Enemy>& Dungeon::getEnemies() {
    return enemies;
}

void Dungeon::setEnemies(const std::vector<Enemy>& enemies) {
    this->enemies = enemies;
}

Enemy& Dungeon::getBoss() {
    return boss;
}

void Dungeon::setBoss(const Enemy& boss) {
    this->boss = boss;
}

Exit& Dungeon::getExit() {
    return exit;
}

void Dungeon::setExit(const Exit& exit) {
    this->exit = exit;
}

void Dungeon::progressToNextLevel() {
    level++;
    generateLevel();
}

void Dungeon::generateLevel() {
    enemies.clear();
    exit.setIsOpen(false);

    // Generate enemies based on level
    int numEnemies = level * 2;
    for (int i = 0; i < numEnemies; ++i) {
        Enemy enemy;
        // Customize enemy stats per level if needed
        enemies.push_back(enemy);
    }

    // Set boss on final level
    if (level == 10) {
        boss = Enemy();
        boss.setHealth(200);
        boss.setDamage(25);
    }
}
