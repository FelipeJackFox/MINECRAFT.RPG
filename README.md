# Minecraft-classic-RPG
This document outlines the class structure for a text-based Minecraft RPG running in the terminal. The game will incorporate core Minecraft mechanics such as crafting, mining, trading, and combat with monsters.

## Object-Oriented Design

Due to the repetitive nature of RPG elements, an object-oriented approach is ideal. This allows us to define classes and create multiple instances (objects) with specific properties and behaviors.

## Class Structure

### Entity

* Attributes: health, attack, defense.
* Methods: take_damage(), is_alive().

### Player (inherits from Entity)

* Represents the player character.
* Attributes: inventory, equipment, level, experience.
* Methods: mine(), craft(), trade(), attack(), sleep(), gain_experience(), level_up().

### Villager (inherits from Entity)

* Represents the various types of villagers (farmers, blacksmiths, etc.).
* Attributes: trade_inventory, trade_level.
* Methods: offer_trade().

### Enemy (inherits from Entity)

* Represents hostile creatures.
* Attributes: loot_table.
* Methods: attack_player().
* Examples: Zombie, Skeleton, Spider, Creeper, Enderman, etc., each with unique attributes and attack values.

### Item

* Represents in-game items.
* Attributes: name, type (weapon, tool, material, etc.).

### Tools (inherits from Item)

* Represents in-game tools.
* Attributes: atack_augmntation, haste_stone_augmentation, haste_sand_augmentation, haste_wood_augmentation.

### Inventory

* Manages a collection of items the player owns.
* Methods: add_item(), remove_item(), get_item_count().

### CraftingRecipe

* Defines the requirements and results of crafting.
* Attributes: ingredients, resulting_item.

### Location

* A base class for handling various in-game location.

* Subclasses: Mine, Village, PlayerBase.
