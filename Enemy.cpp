#include "Enemy.h"

Enemy::Enemy() : Entity(), experiencePoints(0) {
    setMaxHealth(100); // Default max health for enemies
    setHealth(100);    // Initialize current health
}

void Enemy::setName(const std::string& name) {
    this->name = name;
}

std::string Enemy::getName() const {
    return name;
}

void Enemy::setExperiencePoints(int exp) {
    experiencePoints = exp;
}

int Enemy::getExperiencePoints() const {
    return experiencePoints;
}

//Method to return plain ASCII art based on the enemy name
std::string Enemy::getAsciiArt() const {
    if (name == "Creeper") {
        return R"(

    %%%((##########%%%//
    %%%((###########%%//
    (((.....##(((..   &&
    ///     ((***     %%
    (((,,***,,...*****##
    ###//***     //(((##
    %%%//          (((##
    %%%((   ..,,,  %%%//

    )";
    } else if (name == "Skeleton") {
        return R"(

    ########(((((((#####
    ##########%%%%%###((
    ###%%&&&&&&&&&&%%%##
    %%%%%%%%%%###%%#####
    %%%,,,,,%%%%%,,,,,%%
    ###%%&&&/////&&###((
    ###,,,,,,,,,,,,,,,((
    ((((((((((((((((((((

    )";
    } else if (name == "Zombie") {
        return R"(

    /****///************
    **********/////*****
    ***((((((((((((/////
    /////////////((***//
    (//     //(((     //
    /**(((((,,,,,((///**
    *************,,*****
    ,,,,,,,,,,***,,***,,

    )";
    } else if (name == "Spider") {
        return R"(

    .....***,,,,,**   ..
    ***,,.  *****  ,,,**
    ...**,,,*****,,***,,
    .  ,,,,,  ,,,..,,,..
    ,,,**...  ...  ***..
    ,,,,,,*****,,**,,,,,
    ,,,((.  ,,,,,  (((,,
    ...((   ,,,,,  (((..

    )";
    } else if (name == "Enderman") {
        return R"(

       ..          ...  

    .                   

    %##**%##     ##***##


    .                   

    )";
    } else if (name == "Witch") {
        return R"(

    ***************  
    **//**//////*//  
    **//**//////*//  
    **//////////*//  
    //&&&&&&&&&&&//  
    **  ((////(# **  
    ((////((((///((  
    ((////(##(///((  

    )";
    }
    return "";
}
