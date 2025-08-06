#include "Item.h"

Item::Item()
{

}

Item::Item(string n, int h, int a, int d, ItemType t)
{
    name = n;
    health = h;
    attack = a;
    defence = d;
    type = t;
}