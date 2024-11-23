#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include <string>

class Enemy : public Entity {
private:
    std::string name;    // Enemy name
    int experiencePoints; // Experience points granted when defeated

public:
    Enemy();

    // Getters and Setters
    void setName(const std::string& name);
    std::string getName() const;

    void setExperiencePoints(int exp);
    int getExperiencePoints() const;

    // New method to get plain ASCII art (no color), before I was defining the ASCII directly inside of the main file, now I jsut apply color there.
    std::string getAsciiArt() const;
};

#endif // ENEMY_H
