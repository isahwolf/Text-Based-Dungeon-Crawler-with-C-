#include "Player.h"
#include <vector>

#ifndef LEVEL_H
#define LEVEL_H

class Level
{
public:
    Level();
    void handleMovementActions(Player& player, vector<Room*>& rooms);
    void printActions(int, string[]);
};

#endif