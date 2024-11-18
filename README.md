# Turn-Based RPG Game in C++
This project is a simple turn-based RPG game implemented in C++. The game is played in the terminal and involves a player navigating through a dungeon with multiple levels, fighting enemies on each level, and ultimately facing a boss on the final level. The player gains experience and levels up by defeating enemies, increasing their stats to prepare for tougher challenges ahead.

## Game Mechanics
Dungeon Levels:

The game consists of 10 dungeon levels. Each level contains a set of enemies that the player must defeat to progress.

Combat:

Combat is turn-based. The player and enemies take turns attacking each other until one is defeated.

Experience and Leveling Up:

The player gains experience points (XP) by defeating enemies. Upon accumulating enough XP, the player levels up, increasing their stats such as health and damage.

Boss Battle:

On the 10th level, the player faces a boss. Defeating the boss completes the game.

Game Over:

If the player's health drops to zero, the game ends.

# Class Structure
The game's functionality is organized using several classes, each responsible for different aspects of the game.

### Entity
Purpose: Serves as the base class for all characters in the game, including the player and enemies.

Key Features:

Attributes:

Health

Damage

Critical Hit Chance

Resistance

Methods: Common functions shared by all entities, such as taking damage or checking if alive.

### Player
Purpose: Represents the player's character in the game.

Inherits From: Entity

Key Features:

Attributes:

Name

Experience Points

Level

Methods:

Leveling up

Gaining experience

### Enemy
Purpose: Represents enemy characters encountered in the dungeon.

Inherits From: Entity

Key Features:

Methods:

Attacking the player

### Dungeon

Purpose: Manages the dungeon levels and controls the progression through the game.

Key Features:

Attributes:

Current Level

List of Enemies

Methods:

Generating levels

Advancing to the next level

### Combat
Purpose: Handles the combat interactions between the player and enemies.

Key Features:

Methods:

Initiating combat

Managing turns

Calculating damage

# UML Class Diagram

![UML 2](https://github.com/user-attachments/assets/d88f2a32-46d5-4f67-91b9-76dc68f7d570)

