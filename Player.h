#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <string>

class Player : public Entity {
private:
    int experienceLevel;
    int experiencePoints;
    std::string name;

public:
    Player(const std::string& name);

    // Getters and Setters
    int getExperienceLevel() const;
    void setExperienceLevel(int level);

    int getExperiencePoints() const;
    void setExperiencePoints(int points);

    std::string getName() const;
    void setName(const std::string& name);

    // Methods
    void levelUp();
    void gainExperience(int experiencePoints);
};

#endif // PLAYER_H
