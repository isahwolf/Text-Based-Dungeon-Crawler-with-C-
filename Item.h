#include <string>

#ifndef ITEM_H
#define ITEM_H

using namespace std;

class Item
{
public:    
    string name;
    int health, attack, defence;
    Item();
    Item(string, int, int, int);
};

#endif