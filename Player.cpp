#include "Player.h"

Player::Player(string n, int h, int a, int d)
    : GameCharacter(n, "", h, a, d)
{
    Item dagger = Item("Dagger", 0, 5, 0, ItemType::WEAPON);
    addItem(dagger);
}

string Player::addItem(Item item)
{
    string removedItem = "";

    if (item.type == ItemType::WEAPON)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].type == ItemType::WEAPON)
            {
                increaseStats(-inventory[i].health, -inventory[i].attack, -inventory[i].defence);

                removedItem = inventory[i].name;

                inventory.erase(inventory.begin() + i );
                break;
            }
        }
    }

    inventory.push_back(item);
    increaseStats(item.health, item.attack, item.defence);
    return removedItem;
}

void Player::increaseStats(int h, int a, int d)
{
    currentHealth += h;
    maxHealth += h;
    attack += a;
    defence += d;
}

void Player::lootRoom(Room * room)
{
    vector<Item> items = room->items;
    for (int i = 0; i < items.size(); i++)
    {
        addItem(items[i]);
    }
}

void Player::changeRooms(Room * newRoom)
{
    previousRoom = currentRoom;
    currentRoom = newRoom;
}