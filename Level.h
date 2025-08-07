#include "Player.h"
#include <vector>

#ifndef LEVEL_H
#define LEVEL_H

class Level
{
public:
    vector<Room*> rooms;
    Level();
    string name;
    int levelNumber;

    void setUpLevel1(string);
    void setUpLevel2(string);
    void handleMovementRoom1(Player& player, vector<Room*>& rooms);
    void handleMovementRoom2(Player& player, vector<Room*>& rooms);
    void handleMovementActions(Player& player, vector<Room*>& rooms);
    void printActions(int, string[]);
};

#endif