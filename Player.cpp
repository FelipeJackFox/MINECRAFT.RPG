#include "Player.h"

Player::Player(const std::string& name)
    : Entity(), experienceLevel(0), experiencePoints(0), experienceThreshold(40), pointsToAllocate(0), name(name) {}

int Player::getExperienceLevel() const {
    return experienceLevel;
}

void Player::setExperienceLevel(int level) {
    experienceLevel = level;
}

int Player::getExperiencePoints() const {
    return experiencePoints;
}

void Player::setExperiencePoints(int points) {
    experiencePoints = points;
}

int Player::getExperienceThreshold() const {
    return experienceThreshold;
}

int Player::getPointsToAllocate() const {
    return pointsToAllocate;
}

std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string& name) {
    this->name = name;
}

void Player::setResistance(int resistance) {
    this->resistance = resistance;
}

void Player::setCriticalDamagePercent(float percent) {
    criticalDamagePercent = percent;
}

void Player::setCriticalDamageMultiplier(float multiplier) {
    criticalDamageMultiplier = multiplier;
}

void Player::levelUp() {
    experienceLevel++;
    experiencePoints = 0; // Reset experience points upon level-up
    pointsToAllocate += 3;
    experienceThreshold += (experienceLevel * 10); // Increase thresholdsssss
}

void Player::gainExperience(int points) {
    experiencePoints += points;
    while (experiencePoints >= experienceThreshold) {
        experiencePoints -= experienceThreshold;
        levelUp();
    }
}

void Player::allocatePointsToStat(int choice) {
    if (pointsToAllocate <= 0) {
        return; // No points available to allocate
    }

    switch (choice) {
        case 1: // Increase Health
            setMaxHealth(getMaxHealth() + 20); // Increase max health
            setHealth(getHealth() + 20);       // Increase current health proportionally
            break;
        case 2: // Increase Damage
            setDamage(getDamage() + 4);
            break;
        case 3: // Increase Resistance
            setResistance(getResistance() + 3);
            break;
        case 4: // Increase Critical Hit Chance
            setCriticalDamagePercent(getCriticalDamagePercent() + 0.02f);
            break;
        case 5: // Increase Critical Damage Multiplier
            setCriticalDamageMultiplier(getCriticalDamageMultiplier() + 0.15f);
            break;
        default:
            // Invalid choice
            return;
    }

    pointsToAllocate--; // Decrease the points available for allocation and repeat until no points to allocate
}
