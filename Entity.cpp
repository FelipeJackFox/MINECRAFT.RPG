#include "Entity.h"

Entity::Entity()
    : health(100), maxHealth(100), isAlive(true), damage(10),
      criticalDamagePercent(0.1f), criticalDamageMultiplier(1.5f), resistance(0) {}

int Entity::getHealth() const {
    return health;
}

void Entity::setHealth(int health) {
    this->health = health;
    if (health <= 0) {
        this->health = 0;
        isAlive = false;
    } else if (health > maxHealth) {
        this->health = maxHealth; // Cap health at maxHealth
    }
}

int Entity::getMaxHealth() const {
    return maxHealth;
}

void Entity::setMaxHealth(int maxHealth) {
    this->maxHealth = maxHealth;
    if (health > maxHealth) {
        health = maxHealth; // Adjust current health if maxHealth decreases
    }
}

bool Entity::getIsAlive() const {
    return isAlive;
}

int Entity::getDamage() const {
    return damage;
}

void Entity::setDamage(int damage) {
    this->damage = damage;
}

float Entity::getCriticalDamagePercent() const {
    return criticalDamagePercent;
}

void Entity::setCriticalDamagePercent(float percent) {
    criticalDamagePercent = percent;
}

float Entity::getCriticalDamageMultiplier() const {
    return criticalDamageMultiplier;
}

void Entity::setCriticalDamageMultiplier(float multiplier) {
    criticalDamageMultiplier = multiplier;
}

int Entity::getResistance() const {
    return resistance;
}

void Entity::setResistance(int resistance) {
    this->resistance = resistance;
}
