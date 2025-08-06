#include <string>
#include "Item.h"

#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

using namespace std;

class GameCharacter
{
public:
    string name;
    string description;
    int maxHealth, currentHealth, attack, defence;
    Item dropItem;
    GameCharacter(string, string, int, int, int, Item = Item());
    int takeDamage(int);
    bool checkIsDead();
};

#endif