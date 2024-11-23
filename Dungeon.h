#ifndef DUNGEON_H
#define DUNGEON_H

#include "Enemy.h"
#include <vector>
#include <unordered_map>
#include <string>

class Dungeon {
private:
    int level;
    std::vector<Enemy> enemies;  // Storing enemies by value (no pointers)

    struct EnemyData {
        int baseHealth;
        int baseDamage;
        int baseResistance;
        float baseCritChance;
        float baseCritMultiplier;
        int baseExperience;
        int rarity;
    };

    std::unordered_map<std::string, EnemyData> enemyDictionary;

    void initializeEnemyDictionary();
    Enemy createEnemy(const std::string& name);
    std::string selectEnemyByRarity();

public:
    Dungeon();

    // Getters and Setters
    int getLevel() const;
    void setLevel(int level);

    std::vector<Enemy>& getEnemies();
    void setEnemies(const std::vector<Enemy>& enemies);

    void progressToNextLevel();
    void generateLevel();
};

#endif // DUNGEON_H
