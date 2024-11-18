#include "Player.h"

Player::Player(const std::string& name)
    : Entity(), experienceLevel(0), experiencePoints(0), name(name) {}

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

std::string Player::getName() const {
    return name;
}

void Player::setName(const std::string& name) {
    this->name = name;
}

void Player::levelUp() {
    experienceLevel++;
    // Logic to increase a base stat upon leveling up
    damage += 5; // Example: Increase damage by 5
    health += 10; // Example: Increase health by 10
}

void Player::gainExperience(int points) {
    experiencePoints += points;
    while (experiencePoints >= 10) {
        experiencePoints -= 10;
        levelUp();
    }
}
