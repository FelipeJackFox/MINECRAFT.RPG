#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
    int health;
    int maxHealth;
    bool isAlive;
    int damage;
    float criticalDamagePercent;
    float criticalDamageMultiplier;
    int resistance;

public:
    Entity();

    // Getters and Setters
    int getHealth() const;
    void setHealth(int health);

    int getMaxHealth() const;
    void setMaxHealth(int maxHealth);

    bool getIsAlive() const;

    int getDamage() const;
    void setDamage(int damage);

    float getCriticalDamagePercent() const;
    void setCriticalDamagePercent(float percent);

    float getCriticalDamageMultiplier() const;
    void setCriticalDamageMultiplier(float multiplier);

    int getResistance() const;
    void setResistance(int resistance);
};

#endif // ENTITY_H
