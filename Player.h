#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include <string>

class Player : public Entity {
private:
    int experienceLevel;
    int experiencePoints; // Tracks current experience progress
    int experienceThreshold; // Dynamic threshold for leveling up
    int pointsToAllocate; // Tracks points available for stat allocation
    std::string name;

public:
    Player(const std::string& name);

    // Getters and Setters
    int getExperienceLevel() const;
    void setExperienceLevel(int level);

    int getExperiencePoints() const;
    void setExperiencePoints(int points);

    int getExperienceThreshold() const;
    int getPointsToAllocate() const;

    std::string getName() const;
    void setName(const std::string& name);

    void setResistance(int resistance);
    void setCriticalDamagePercent(float percent);
    void setCriticalDamageMultiplier(float multiplier);

    // Methods
    void levelUp();
    void gainExperience(int points);
    void allocatePointsToStat(int choice);
};

#endif // PLAYER_H
