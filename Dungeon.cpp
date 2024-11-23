#include "Dungeon.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <random>

Dungeon::Dungeon() : level(1) {
    initializeEnemyDictionary();
    generateLevel();
}

void Dungeon::initializeEnemyDictionary() { //health, damage, resistance, critchance, critmult, experience, rarity
    enemyDictionary = {
        {"Creeper", {10, 7, 2, 0.009f, 1.5f, 15, 7}},
        {"Zombie", {10, 5, 0, 0.005f, 1.2f, 8, 10}},
        {"Skeleton", {10, 5, 0, 0.005f, 1.2f, 10, 10}},
        {"Spider", {15, 6, 1, 0.01f, 1.5f, 20, 5}},
        {"Enderman", {20, 10, 5, 0.01f, 2.0f, 30, 2}},
        {"Witch", {17, 1, 1, 0.01f, 1.7f, 25, 4}},
    };
}

std::string Dungeon::selectEnemyByRarity() {
    std::vector<std::string> enemyPool;
    for (const auto& [name, data] : enemyDictionary) {
        for (int i = 0; i < data.rarity; ++i) {
            enemyPool.push_back(name);
        }
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, enemyPool.size() - 1);

    int randomIndex = dist(gen);
    return enemyPool[randomIndex];
}

Enemy Dungeon::createEnemy(const std::string& name) {
    const EnemyData& data = enemyDictionary[name];
    Enemy enemy;
    enemy.setName(name);

    int scaledHealth = data.baseHealth + level;
    enemy.setMaxHealth(scaledHealth);
    enemy.setHealth(scaledHealth);
    enemy.setDamage(data.baseDamage + level);
    enemy.setResistance(data.baseResistance);
    enemy.setCriticalDamagePercent(data.baseCritChance);
    enemy.setCriticalDamageMultiplier(data.baseCritMultiplier);
    enemy.setExperiencePoints((data.baseExperience + level) * 1.2);

    return enemy;
}

//Minimo tres enemigos al inicio
void Dungeon::generateLevel() {
    enemies.clear();
    int numEnemies = std::max(3, level);

    for (int i = 0; i < numEnemies; ++i) {
        std::string enemyName = selectEnemyByRarity();
        enemies.push_back(createEnemy(enemyName));
    }
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

void Dungeon::progressToNextLevel() {
    level++;
    generateLevel();
}

