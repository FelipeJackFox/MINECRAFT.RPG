# Minecraft-classic-RPG
This document outlines the class structure for a text-based Minecraft RPG running in the terminal.

## Object-Oriented Design

Due to the repetitive nature of RPG elements, an object-oriented approach is ideal. This allows us to define classes and create multiple instances (objects) with specific properties and behaviors.

### Entity

* Represents a living entity in the game, with attributes like health, damage, resistance, and inventory, and methods for taking damage and attacking.

### Player

* Inherits from Entity, representing the player character, with additional attributes like experience level and name, and methods for leveling up and increasing stats.

### Enemy

* Inherits from Entity, representing an enemy in the game, with methods for attacking the player.

### Inventory

* Represents the player's inventory, including equipped weapons and armor, items, and methods for adding, removing, and equipping items.

### Dungeon

* Represents a dungeon level, with attributes like level, enemies, boss, items, and exit, and methods for generating content and handling player progress.

### Item

* Represents an item in the game, with attributes like type, stats, and methods for getting stats.

### Weapon

* Inherits from Item, representing a weapon, with attributes like damage and critical chance.

### Armor

* Inherits from Item, representing armor, with an attribute for resistance.

### Game

* Represents the main game, with attributes like the player, dungeon, combat, and UI, and methods for starting the game, running the game loop, and ending the game.

### Combat

* Handles the combat mechanics of the game, with methods for handling turns, calculating damage, applying status effects, checking for death, and handling input.

#UML Class Diagram


![UML Class diagram](https://github.com/user-attachments/assets/e61f6dcc-53fd-4318-8832-d4de7bca9e00)
