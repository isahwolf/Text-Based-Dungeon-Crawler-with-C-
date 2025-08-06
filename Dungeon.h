#include "Player.h"
#include "Level.h"
#include <vector>

using namespace std;

#ifndef DUNGEON_H
#define DUNGEON_H

class Dungeon
{
public:
    Player player;
    Level level;
    vector<Room*> rooms;
    Dungeon(Player);
    int runDungeon();
    void enterRoom(Room *);
    void handleEmptyRoom(Room *);
    void handleRoomWithChest(Room *);
    void handleRoomWithEnemy(Room *);
    void handleLootActions(Room *);
    void handleFightActions(GameCharacter *);
    int performEndGameLogic();
};

#endif