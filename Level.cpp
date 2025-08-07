#include "Level.h"
#include <iostream>

using namespace std;

Level::Level()
{
    
}

void Level::setUpLevel1(string name)
{
    this->name = name;
    this->levelNumber = 1;
    // Set up the first room
    Room* firstRoom = new Room(0, false, vector<Item>(), vector<GameCharacter*>());

    // Set up the second room
    Item ironSword = Item("Iron Sword", 0, 15, 0, ItemType::WEAPON);
    Item leatherHelmet = Item("Leather Helmet", 0, 0, 10, ItemType::HELMET);
    vector<Item> secondRoomItems;
    secondRoomItems.push_back(ironSword);
    secondRoomItems.push_back(leatherHelmet);
    vector<GameCharacter*> noEnemeies;
    Room* secondRoom = new Room(1, false, secondRoomItems, noEnemeies);

    // Set up the third room
    Item firstEnemyDrop= Item("Leather Boots", 0, 0, 10, ItemType::BOOTS);
    GameCharacter* firstEnemy = new GameCharacter(
        "Goblin Soldier",
        "It is a small green creature. It scowls and shows its sharp teeth. It readies its jagged metal sword.",
         65, 35, 10,
        firstEnemyDrop);
    vector<GameCharacter*> thirdRoomEnemies;
    thirdRoomEnemies.push_back(firstEnemy);
    Room* thirdRoom = new Room(2, false, vector<Item>(), thirdRoomEnemies);

    // Set up the fourth room
    Item secondEnemyDrop = Item("Iron Chestplate", 0, 0, 15, ItemType::CHESTPLATE);
    GameCharacter* secondEnemy = new GameCharacter(
        "Goblin Chief",
        "A larger green creature clad in heavy armor. There is a large scar across its face and appears meaner than the last enemy. It readies its long battle-worn spear.",
         110, 57, 20,
        secondEnemyDrop);
    vector<GameCharacter*> fourthRoomEnemies;
    fourthRoomEnemies.push_back(secondEnemy);
    Room* fourthRoom = new Room(3, true, vector<Item>(), fourthRoomEnemies);

    rooms = {firstRoom, secondRoom, thirdRoom, fourthRoom};
}

void Level::setUpLevel2(string name)
{
    this->name = name;
    this->levelNumber = 1;
    cout << "Level 2 setup not yet implemented\n";

    // Set up the first room
    Room* firstRoom = new Room(0, false, vector<Item>(), vector<GameCharacter*>());

    // Set up the second room
    Item firstEnemyDrop= Item("Shield", 0, 0, 15, ItemType::SHIELD);
    GameCharacter* firstEnemy = new GameCharacter(
        "Skeleton Warrior",
        "It is a dirty skeleton. Its bones appear worn and cracked. It raises its spiked mace and shield.",
         100, 95, 25,
        firstEnemyDrop);
    vector<GameCharacter*> secondRoomEnemies;
    secondRoomEnemies.push_back(firstEnemy);
    Room* secondRoom = new Room(1, false, vector<Item>(), secondRoomEnemies);

    // Set up the third room
    Item secondEnemyDrop= Item("Ring of Vigor", 10, 0, 0, ItemType::RING);
    GameCharacter* secondEnemy = new GameCharacter(
        "Skeleton Archer",
        "Another dirty skeleton. It pulls back the drawstring of its bow.",
         110, 100, 10,
        secondEnemyDrop);
    vector<GameCharacter*> thirdRoomEnemies;
    thirdRoomEnemies.push_back(secondEnemy);
    Room* thirdRoom = new Room(2, false, vector<Item>(), thirdRoomEnemies);

    // Set up the fourth room
    Item hardLeatherLeggings = Item("Hard Leather Leggings", 0, 0, 13, ItemType::WEAPON);
    vector<Item> fourthRoomItems;
    fourthRoomItems.push_back(hardLeatherLeggings);
    vector<GameCharacter*> noEnemeies;
    Room* fourthRoom = new Room(3, false, fourthRoomItems, noEnemeies);

    // Set up the fifth room

    // Set up the sixth room
}

void Level::printActions(int numActions, string actions[])
{
    cout << "Choose an action:\n";
    for (int i = 0; i < numActions; i++)
    {
        cout << actions[i] << "\n";
    }
}

void Level::handleMovementActions(Player &player, vector<Room*>& rooms)
{
    if (levelNumber == 1)
    {
        handleMovementRoom1(player, rooms);
    }
    else if (levelNumber == 2)
    {
        handleMovementRoom2(player, rooms);
    }
    else
    {
        cout << "Error: Level not found / created yet\n";
        return;
    }
}

void Level::handleMovementRoom1(Player &player, vector<Room*>& rooms)
{
    Room* room = player.currentRoom;
    while(true)
    {
        if (room->pos == 0)
        {
            cout << "\n";
            cout << "There is a room to your Left and behind you.\n";
            string actions[] = 
            {
                "a. Move Left",
                "b. Move Down",
            };
            printActions(2, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[1]);
                return;
            }
            else if (input == "b" || input == "B")
            {
                player.changeRooms(rooms[2]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
        else if (room->pos == 1)
        {
            cout << "\n";
            cout << "There is a room to your left.\n";
            string actions[] = 
            {
                "a. Move Right",
            };
            printActions(1, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[0]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
        else if (room->pos == 2)
        {
            cout << "\n";
            cout << "There is a room to your right and in front of you.\n";
            string actions[] = 
            {
                "a. Move Up",
                "b. Move Right",
            };
            printActions(2, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[0]);
                return;
            }
            else if (input == "b" || input == "B")
            {
                player.changeRooms(rooms[3]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
        else
        {
            cout << "\n";
            cout << "There is a room to your Left.\n";
            string actions[] = 
            {
                "a. Move Left",
            };
            printActions(1, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[2]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
    }
}

void Level::handleMovementRoom2(Player &player, vector<Room*>& rooms)
{
    Room* room = player.currentRoom;
    while (true)
    {
        if (room->pos == 0)
        {
            cout << "\n";
            cout << "There is a room in front of you.\n";
            string actions[] = 
            {
                "a. Move Up",
            };
            printActions(1, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[1]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
        else if (room->pos == 1)
        {
            cout << "\n";
            cout << "There is a room to your right and in front of you.\n";
            string actions[] = 
            {
                "a. Move Up",
                "b. Move Right",
            };
            printActions(2, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[4]);
                return;
            }
            else if (input == "b" || input == "B")
            {
                player.changeRooms(rooms[2]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
        else if (room->pos == 2)
        {
            cout << "\n";
            cout << "There is a room to your left and in front of you.\n";
            string actions[] = 
            {
                "a. Move Up",
                "b. Move Left",
            };
            printActions(2, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[3]);
                return;
            }
            else if (input == "b" || input == "B")
            {
                player.changeRooms(rooms[1]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
        else if (room->pos == 3)
        {
            cout << "\n";
            cout << "There is a room to your left and behind you.\n";
            string actions[] = 
            {
                "a. Move Down",
                "b. Move Left",
            };
            printActions(2, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[2]);
                return;
            }
            else if (input == "b" || input == "B")
            {
                player.changeRooms(rooms[4]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
        else if (room->pos == 4)
        {
            cout << "\n";
            cout << "There is a room to your left and behind you.\n";
            string actions[] = 
            {
                "a. Move Down",
                "b. Move Left",
            };
            printActions(2, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[1]);
                return;
            }
            else if (input == "b" || input == "B")
            {
                player.changeRooms(rooms[5]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
        else 
        {
            cout << "\n";
            cout << "There is a room to your Right.\n";
            string actions[] = 
            {
                "a. Move Right",
            };
            printActions(1, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(rooms[2]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
    }

}