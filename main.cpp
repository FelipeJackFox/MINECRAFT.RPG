#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

#include <cstdlib> // For rand()

//For decimal number display manipulation :)
#include <sstream>  // Include for std::ostringstream
#include <iomanip>  // Include for std::setprecision

#include "Player.h"
#include "Enemy.h"
#include "Dungeon.h"
#include "Combat.h"

// Function to add delay between lines for cleaner output
void addDelay() {
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
}

// Function to apply colors for gameplay contrast
std::string applyColor(const std::string& text, const std::string& colorCode) {
    return "\033[" + colorCode + "m" + text + "\033[0m";
}

// Clear the last terminal output for a cleaner display
void clearLastLines(int numLines) {
    for (int i = 0; i < numLines; ++i) {
        std::cout << "\033[F" // Move cursor up one line
                  << "\033[2K"; // Clear the entire line
    }
}

// Function to generate a fixed-length health bar
std::string createHealthBar(int currentHealth, int maxHealth, int barLength = 20) {
    if (maxHealth <= 0) return std::string(barLength, '.');
    int filledLength = (currentHealth * barLength) / maxHealth;
    return std::string(filledLength, '|') + std::string(barLength - filledLength, '.');
}

// Display the health of the player and the enemy
void displayHealth(const Player& player, const Enemy& enemy) {
    std::cout << applyColor("Player Health: [", "1;32") 
              << applyColor(createHealthBar(player.getHealth(), player.getMaxHealth()), "1;32") 
              << applyColor("] ", "1;32") 
              << "(" << player.getHealth() << "/" << player.getMaxHealth() << ")\n";

    std::cout << applyColor(enemy.getName() + " Health: [", "1;31") 
              << applyColor(createHealthBar(enemy.getHealth(), enemy.getMaxHealth()), "1;31") 
              << applyColor("] ", "1;31") 
              << "(" << enemy.getHealth() << "/" << enemy.getMaxHealth() << ")\n";
}

// Function to allocate stat points after leveling up
void allocateLevelUpPoints(Player& player) {
    while (player.getPointsToAllocate() > 0) {
        std::cout << "\n" 
                  << applyColor("You have " + std::to_string(player.getPointsToAllocate()) + " points to allocate. Choose a stat:\n", "1;33");
        addDelay();
        std::cout << applyColor("1. Increase Health (+20)\n", "1;32");
        std::cout << applyColor("2. Increase Damage (+4)\n", "1;32");
        std::cout << applyColor("3. Increase Resistance (+3)\n", "1;32");
        std::cout << applyColor("4. Increase Critical Hit Chance (+2%)\n", "1;32");
        std::cout << applyColor("5. Increase Critical Damage Multiplier (+0.15)\n", "1;32");
        std::cout << applyColor("Enter your choice: ", "1;33");

        int choice;
        std::cin >> choice;

        if (choice >= 1 && choice <= 5) {
            player.allocatePointsToStat(choice);
            std::cout << applyColor("Stat successfully updated!\n", "1;32");
            addDelay();
        } else {
            std::cout << applyColor("Invalid choice. Try again.\n", "1;31");
            addDelay();
        }
    }
}

// Function to display player stats
void displayPlayerStats(const Player& player) {
    std::cout << "\n" << applyColor("Player Stats:\n", "1;36");
    addDelay();
    std::cout << applyColor("Name: ", "1;33") << applyColor(player.getName(), "1;32") << "\n";
    std::cout << applyColor("Health: ", "1;33") << applyColor(std::to_string(player.getHealth()), "1;31") 
              << " / " << player.getMaxHealth() << "\n";
    std::cout << applyColor("Damage: ", "1;33") << applyColor(std::to_string(player.getDamage()), "1;34") << "\n";

    // Format Critical Hit Chance with 2 decimal places
    std::ostringstream critChanceStream;
    critChanceStream << std::fixed << std::setprecision(2) << player.getCriticalDamagePercent() * 100;
    std::cout << applyColor("Critical Hit Chance: ", "1;33") 
              << applyColor(critChanceStream.str() + "%", "1;33") << "\n";

    // Format Critical Damage Multiplier with 2 decimal places
    std::ostringstream critDamageStream;
    critDamageStream << std::fixed << std::setprecision(2) << player.getCriticalDamageMultiplier();
    std::cout << applyColor("Critical Damage Multiplier: ", "1;33") 
              << applyColor(critDamageStream.str(), "1;33") << "\n";
    
    std::cout << applyColor("Resistance: ", "1;33") << applyColor(std::to_string(player.getResistance()), "1;34") << "\n";
    std::cout << applyColor("Experience Level: ", "1;33") 
              << applyColor(std::to_string(player.getExperienceLevel()), "1;36") 
              << " (" << player.getExperiencePoints() << "/" << player.getExperienceThreshold() << ")\n";
    std::cout << applyColor("Points Available to Allocate: ", "1;33") 
              << applyColor(std::to_string(player.getPointsToAllocate()), "1;35") << "\n";
}

// Resting Logic
void playerResting(Player& player) {
    std::cout << "\n" << applyColor("You choose to rest. You regain 20% of your max health.\n", "1;32");
    int healAmount = 0.30 * player.getMaxHealth();  // 20% health regen
    player.setHealth(player.getHealth() + healAmount);
    if (player.getHealth() > player.getMaxHealth()) {
        player.setHealth(player.getMaxHealth());  // Cap health at maxHealth
    }

    //Chance to get out of shape if resting (30% chance to lose a stat)
    int randChance = rand() % 100;
    if (randChance < 30) {  // 30% chance to get out of shape
        std::cout << applyColor("You have rested too much and feel out of shape! One stat has decreased.\n", "1;31");

        // Randomly decrease one stat
        int statChoice = rand() % 3; // Randomly pick a stat to decrease (0 = damage, 1 = critical chance, 2 = critical multiplier)
        switch (statChoice) {
            case 0:
                player.setDamage(player.getDamage() - 2);
                std::cout << applyColor("Your damage has decreased by 2.\n", "1;33");
                break;
            case 1:
                player.setCriticalDamagePercent(player.getCriticalDamagePercent() - 0.005f);
                std::cout << applyColor("Your critical hit chance has decreased by 0.5%.\n", "1;33");
                break;
            case 2:
                player.setCriticalDamageMultiplier(player.getCriticalDamageMultiplier() - 0.1f);
                std::cout << applyColor("Your critical damage multiplier has decreased by 0.1.\n", "1;33");
                break;
        }
    }
}

// Function to display the enemy ASCII art but with color depending on its name
void displayEnemyAsciiArt(Enemy& enemy) {
    std::string enemyAsciiArt = enemy.getAsciiArt(); // Get the plain ASCII art

    // Apply color based on the enemy name
    std::string coloredAsciiArt;
    if (enemy.getName() == "Creeper") {
        coloredAsciiArt = applyColor(enemyAsciiArt, "1;92");  // Green for Creeper
    } else if (enemy.getName() == "Skeleton") {
        coloredAsciiArt = applyColor(enemyAsciiArt, "1;97");  // White for Skeleton
    } else if (enemy.getName() == "Zombie") {
        coloredAsciiArt = applyColor(enemyAsciiArt, "1;96");  // Cyan for Zombie
    } else if (enemy.getName() == "Spider") {
        coloredAsciiArt = applyColor(enemyAsciiArt, "1;90");  // Grey for Spider
    } else if (enemy.getName() == "Enderman") {
        coloredAsciiArt = applyColor(enemyAsciiArt, "1;95");  // Magenta for Enderman
    } else if (enemy.getName() == "Witch") {
        coloredAsciiArt = applyColor(enemyAsciiArt, "1;35");  // Purple for Witch
    } else {
        coloredAsciiArt = enemyAsciiArt;  // Default if no match
    }

    std::cout << coloredAsciiArt;
}

void combatDisplay(Player& player, Enemy& enemy, Dungeon& dungeon) {
    Combat combat(player, enemy, dungeon);

    // Combat loop, turn by turn
    while (player.getIsAlive() && enemy.getIsAlive()) {
        // Player turn
        std::string playerActionLog = combat.playerTurn();
        std::cout << applyColor(playerActionLog, "1;33") << "\n";
        addDelay();

        // Clear previous health bars and display updated health
        clearLastLines(3);
        displayHealth(player, enemy);

        if (!enemy.getIsAlive()) {
            break; // Stop combat if the enemy is defeated
        }

        // Enemy turn
        std::string enemyActionLog = combat.enemyTurn();
        std::cout << applyColor(enemyActionLog, "1;31") << "\n";
        addDelay();

        // Clear previous health bars and display updated health
        clearLastLines(3);
        displayHealth(player, enemy);
    }

    // Final result
    std::string resultLog = combat.checkForDeaths();
    std::cout << applyColor(resultLog, "1;32") << "\n";

    // If the enemy is defeated, award experience and level up
    if (!enemy.getIsAlive()) {
        player.gainExperience(enemy.getExperiencePoints());
        if (player.getPointsToAllocate() > 0) {
            std::cout << applyColor("Congratulations! You leveled up to Level " + std::to_string(player.getExperienceLevel()) + "!\n", "1;32");
            allocateLevelUpPoints(player);
        }
    }
}



int main() {
    std::cout << "\n";
    std::cout << applyColor(R"(

       __  ________  ______________  ___   __________     ___  ___  _____
      /  |/  /  _/ |/ / __/ ___/ _ \/ _ | / __/_  __/    / _ \/ _ \/ ___/
     / /|_/ // //    / _// /__/ , _/ __ |/ _/  / /  __  / , _/ ___/ (_ / 
    /_/  /_/___/_/|_/___/\___/_/|_/_/ |_/_/   /_/  /_/ /_/|_/_/   \___/  
                                                                   

    )", "1;35");
    addDelay();

    // Initialize player and dungeon
    std::cout << "\n" << applyColor("Enter your nametag: ", "1;33");
    std::string playerName;
    std::getline(std::cin, playerName);
    addDelay();

    Player player(playerName);
    Dungeon dungeon;

    std::cout << "\n";
    std::cout << applyColor("Welcome, " + player.getName() + "! Prepare to descend into the mines.\n", "1;32");
    std::cout << "\n";
    addDelay();

    bool gameRunning = true;
    int lastDisplayedLevel = 0; // Track the last displayed level, used to just display the level once when progressing

    while (gameRunning && player.getIsAlive()) {
        if (dungeon.getLevel() != lastDisplayedLevel) {
            std::cout << "\n";
            std::cout << applyColor("--- Mine Level: " + std::to_string(dungeon.getLevel()) + " ---\n", "1;36");
            std::cout << "\n";
            lastDisplayedLevel = dungeon.getLevel();
            addDelay();
        }

        // Check if the player is at level 10 and end the game
        if (dungeon.getLevel() == 10) {
            std::cout << applyColor("Congratulations! You've reached mine level 10!\n", "1;32");
            gameRunning = false;  // End the game
            break;  // Exit the game loop
        }

        // Display menu for the actions
        std::cout << "\n" << applyColor("Choose an action:\n", "1;33");
        std::cout << applyColor("1. Fight\n", "1;32");
        std::cout << applyColor("2. Stats\n", "1;34");
        std::cout << applyColor("3. Next Level\n", "1;35");
        std::cout << applyColor("4. Rest\n", "1;35");
        std::cout << applyColor("Enter your choice: ", "1;33");

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (!dungeon.getEnemies().empty()) {
                    Enemy& enemy = dungeon.getEnemies().back();

                    std::cout << "\n";
                    std::cout << applyColor("You encounter an enemy: " + enemy.getName() + "!\n", "1;31");
                    displayEnemyAsciiArt(enemy); // Display colored ASCII art
                    addDelay();

                    displayHealth(player, enemy); // Show initial health bars
                    combatDisplay(player, enemy, dungeon);

                    if (!player.getIsAlive()) {
                        std::cout << "\n";
                        std::cout << applyColor("Game Over! You have been defeated.\n", "1;31");
                        std::cout << "\n";
                        addDelay();
                        gameRunning = false;
                    }

                    dungeon.getEnemies().pop_back(); // Remove defeated enemy
                } else {
                    std::cout << "\n";
                    std::cout << applyColor("There's no one to fight right now.\n", "1;33");
                    addDelay();
                }
                break;

            case 2:
                std::cout << "\n";
                displayPlayerStats(player);
                std::cout << "\n";
                break;

            case 3:
                if (dungeon.getEnemies().empty()) {
                    std::cout << "\n";
                    std::cout << applyColor("Progressing to the next level...\n", "1;32");
                    std::cout << "\n";
                    addDelay();
                    dungeon.progressToNextLevel();
                } else {
                    std::cout << "\n";
                    std::cout << applyColor("You must defeat all enemies first!\n", "1;31");
                    std::cout << "\n";
                    addDelay();
                }
                break;

            case 4:
                playerResting(player);
                break;

            default://Robustes
                std::cout << "\n";
                std::cout << applyColor("Invalid choice. Try again.\n", "1;31");
                std::cout << "\n";
                addDelay();
        }
    }

    std::cout << "\n";
    std::cout << applyColor("Game Over!\n", "1;36");
    std::cout << "\n";
    return 0;
}