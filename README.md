# Minecraft-classic-RPG
A Minecraft RPG interacted inside the terminal that includes Minecraft's well know gameplay chracteristics such as crafting, mining, trading, monster and boss fighting.

As for the implementation of the game logic oriented towards objects, due to the nature of an RPG requiring the repetition of certain instances.

Events:
In this case events such as combat, mining, trading, other types of events such as sleep, day night, a parent class can be devised that contains the main code for the events from which the different cases branch out.

Enemies:
Also, since there are different types of enemies, a parent class must be created from which each enemy is displayed with its distinctive characteristics.

Villagers:
Villagers and enemies could be thought of as possible children of a class called Entity, but due to the differences in the types of interaction with the player I will consider them as different

Crafting:
Throughout the game, objects/items will be obtained through trading with villagers, defeating enemies and mining, with these items you can craft improvements for the character, armor and weapons. With this class you can properly handle the large amount of crafting recipes that need to be implemented.

With these classes and mainly the event class, the goal of 5 classes is far exceeded, considering that I am considering at least 10 events of which villagers participate and at least 5 types of enemies and a boss, multiple crafts and trading possibilities.
