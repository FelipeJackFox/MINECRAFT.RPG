#ifndef DUNGEON_H
#define DUNGEON_H

#include "Enemy.h"
#include "Exit.h"
#include <vector>

class Dungeon {
private:
    int level;
    std::vector<Enemy> enemies;
    Enemy boss;
    Exit exit;

public:
    Dungeon();

    // Getters and Setters
    int getLevel() const;
    void setLevel(int level);

    std::vector<Enemy>& getEnemies();
    void setEnemies(const std::vector<Enemy>& enemies);

    Enemy& getBoss();
    void setBoss(const Enemy& boss);

    Exit& getExit();
    void setExit(const Exit& exit);

    // Methods
    void progressToNextLevel();
    void generateLevel();
};

#endif // DUNGEON_H
