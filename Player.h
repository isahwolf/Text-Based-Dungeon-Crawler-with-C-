//Room.h includes GameCharacter, Item, and vector
#include "Room.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player: public GameCharacter
{
public:
    Room * currentRoom;
    Room * previousRoom;
    vector<Item> inventory;
    Player(string="", int=0, int=0, int=0);
    string addItem(Item);
    void increaseStats(int, int, int);
    //* references specific room
    void lootRoom(Room *);
    void changeRooms(Room *);
};

#endif