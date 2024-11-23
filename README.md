# Turn-Based RPG Game in C++ "MINECRAFT.RPG"
Designing a text-based RPG game with visual inspiration on the game Minecraft, this project addresses the creation of a terminal-based RPG where players delve into a mine, battling enemies, allocating stats, and progressing through levels.

## Game Mechanics
Dungeon Levels:

The game consists of 10 dungeon levels. Each level contains a set of enemies that the player must defeat to progress.

* Combat:

Combat is turn-based. The player and enemies take turns attacking each other until one is defeated.

* Experience and Leveling Up:

The player gains experience points (XP) by defeating enemies. Upon accumulating enough XP, the player levels up, increasing their stats such as health and damage.

* Winner:

On the 10th level, the player wins the game.

* Game Over:

If the player's health drops to zero, the game ends.

# UML Class Diagram

![UML_final](https://github.com/user-attachments/assets/47dabbc6-58e4-4c51-ad75-2f8d86bd3232)

# Class Structure
The game's functionality is organized using several classes, each responsible for different aspects of the game.

### Player:
Represents the user, containing attributes like health, damage, resistance, and experience points. It includes methods for stat allocation (allocatePointsToStat), experience gain (gainExperience), and leveling up (levelUp), allowing for dynamic player progression.
* Key Features:
Flexible stat allocation system where players can customize health, damage, resistance, and critical hit capabilities.
Automatically adjusts health values to remain within defined limits, ensuring no overflow or underflow errors.
### Enemy:
Represents adversaries encountered in the dungeon. Inherits from the Entity class and includes additional features like ASCII art representation and experience point rewards.
* Key Features:
Procedurally generated stats tailored to the dungeon level.
Distinct ASCII art for better visual engagement.
### Dungeon:
Manages dungeon levels and enemy populations, aggregating a vector of Enemy objects. The class includes methods for generating levels and selecting enemies by rarity, ensuring procedural variety and challenge scaling.
* Key Features:
Implements rarity-based enemy selection to diversify gameplay.
Ensures consistent level progression with increasing difficulty.
### Combat:
Manages turn-based combat interactions between Player and Enemy. Uses references for efficient data handling and real-time updates.
* Key Features:
Calculates damage, critical hits, and resistance effects dynamically.
Supports seamless transitions between player and enemy turns.
### Entity:
Base class for Player and Enemy, encapsulating shared attributes like health, damage, critical hit properties, and resistance.
* Key Features:
Provides reusable methods for health and damage management.
Reduces redundancy by centralizing common functionality.



