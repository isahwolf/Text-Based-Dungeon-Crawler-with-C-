#include <string>
#include "EquipmentSlot.h"

#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item
{
public:    
    string name;
    int health, attack, defence;
    ItemType type;
    Item();
    Item(string, int, int, int, ItemType);
};

#endif