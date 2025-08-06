#include "Dungeon.h"
#include "Player.h"
#include <iostream>

using namespace std;

Dungeon::Dungeon(Player p)
{
    player = p;
}

void Dungeon::printActions(int numActions, string actions[])
{
    cout << "Choose an action:\n";
    for (int i = 0; i < numActions; i++)
    {
        cout << actions[i] << "\n";
    }
}

void Dungeon::handleFightActions(GameCharacter * enemy)
{
    string actions[] = 
    {
        "a. Attack",
        "b. View Stats",
        "c. Retreat",
    };
    while(true)
    {
        printActions(3, actions);
        string input;
        cin >> input;
        // handle player actions
        if (input == "a" || input == "A")
        {
            // attack
            int damage = enemy->takeDamage(player.attack);
            cout << "Your attack does " << damage << " damage.\n";
            cout << enemy->name << " now has " << enemy->currentHealth << " health.\n";
        }
        else if (input == "b" || input == "B")
        {
            //View Stats
            cout << "Your stats are currently: \n";
            cout << player.currentHealth << " health, " << player.attack << " attack, and " << player.defence << " defence.\n";
            continue;
        }
        else if (input == "c" || input == "C")
        {
            //retreat
            player.changeRooms(player.previousRoom);
            enterRoom(player.currentRoom);
            return;
        }
        else
        {
            cout << "Incorrect choice\n";
        }
        //check if enemy is dead
        if (enemy->checkIsDead())
        {
            cout << "You win! You have defeated the " << enemy->name << "\n";
            cout << "\n";
            player.increaseStats(10, 5, 5);
            cout << "Your stats increased!\n";
            cout << "Your health is now " << player.currentHealth << ", your attack is now " << player.attack << ", and your defence is now " << player.defence << "\n";
            cout << "\n";
            cout << "The " << enemy->name << " dropped " << enemy->dropItem.name << "!\n";
            cout << "\n";
            player.currentRoom->items.push_back(enemy->dropItem);
            player.currentRoom->clearEnemies();

            if (!player.currentRoom->items.empty())
            {
                cout << "Do you want to loot the room?\n";
                string actions[] = 
                {
                    "a. Yes",
                    "b. No",
                };
                while(true)
                {
                    printActions(2, actions);
                    string input;
                    cin >> input;
                    if (input == "a" || input == "A")
                    {
                        // loot the current room
                        handleLootActions(player.currentRoom);
                        return;
                    }
                    else if (input == "b" || input == "B")
                    {
                        return;
                    }
                    else
                    {
                        cout << "Incorrect choice\n";
                    }
                }
            }
            return;
        }
        // handle enemy actions
        int damage = player.takeDamage(enemy->attack);
        cout << enemy->name << "'s attack does " << damage << " damage.\n";
        cout << "You now have " << player.currentHealth << " health.\n";
        if (player.checkIsDead())
        {
            return;
        }

    }

}

void Dungeon::handleRoomWithEnemy(Room * room)
{
    cout << "\n";
    GameCharacter enemy = room->enemies.front();
    cout << "You enter the room and see a " << enemy.name << "\n";
    cout << enemy.description << "\n";
    cout << enemy.name << " has " << enemy.currentHealth << " health, " << enemy.attack << " attack, and " << enemy.defence << " defence.\n";;
    string actions[] = 
    {
        "a. Fight the " + enemy.name,
        "b. Go back to previous room",
    };
    while(true)
    {
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "a" || input == "A")
        {
            // fight
            handleFightActions(&enemy);
            return;
        }
        else if (input == "b" || input == "B")
        {
            //move to previous room
            player.changeRooms(player.previousRoom);
            enterRoom(player.currentRoom);
            return;
        }
        else
        {
            cout << "Incorrect choice\n";
        }
    }
}

void Dungeon::handleLootActions(Room * room)
{
    for (Item item : room->items)
    {
        string removedItem = player.addItem(item);

        cout << "You picked up the " << item.name;

        if (removedItem != "")
        {
            cout << " and you dropped the " << removedItem;
        }

        cout << ".\n" << item.name << " has " << item.attack << " attack, " << item.health << " health, and " << item.defence << " defence.\n";
    }
    player.lootRoom(room);

    cout << "Your health is now " << player.currentHealth << ", your attack is now " << player.attack << ", and your defence is now " << player.defence << "\n";

    room->clearLoot();
}

void Dungeon::handleRoomWithChest(Room * room)
{
    cout << "\n";
    cout << "You enter the room and see a large wooden chest in the middle. It appears that you can open it.\n";
    string actions[] = 
    {
        "a. Loot the chest",
        "b. Move to another room",
    };
    while(true)
    {
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "a" || input == "A")
        {
            // loot chest
            handleLootActions(room);
            return;
        }
        else if (input == "b" || input == "B")
        {
            //move to another room
            return;
        }
        else
        {
            cout << "Incorrect choice\n";
        }
    }
}

void Dungeon::handleEmptyRoom(Room * room)
{
    cout << "\n";
    cout << "You enter the room but it is empty.\n";
    string actions[] = {"a. Move to another room"};
    while(true)
    {
        printActions(1, actions);
        string input;
        cin >> input;
        if (input == "a" || input == "A")
        {
            //move actions
            return;
        }
        else
        {
            cout << "Incorrect choice\n";
        }
    }
}

void Dungeon::enterRoom(Room * room)
{
    if (room->enemies.size() != 0)
    {
        // handle room with enemy
        handleRoomWithEnemy(room);
    }
    else if (room->items.size() != 0)
    {
        // handle room with chest
        handleRoomWithChest(room);
    }
    else
    {
        // handle empty room
        handleEmptyRoom(room);
    }
}

void Dungeon::handleMovementActions(Room * room)
{
    while(true)
    {
        if (room->pos == 0)
        {
            cout << "\n";
            cout << "There is a room to your right and behind you.\n";
            string actions[] = 
            {
                "a. Move Right",
                "b. Move Down",
            };
            printActions(2, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(&rooms[1]);
                return;
            }
            else if (input == "b" || input == "B")
            {
                player.changeRooms(&rooms[2]);
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
                "a. Move Left",
            };
            printActions(1, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(&rooms[0]);
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
                player.changeRooms(&rooms[0]);
                return;
            }
            else if (input == "b" || input == "B")
            {
                player.changeRooms(&rooms[3]);
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
            cout << "There is a room to your left.\n";
            string actions[] = 
            {
                "a. Move Left",
            };
            printActions(1, actions);
            string input;
            cin >> input;
            if (input == "a" || input == "A")
            {
                player.changeRooms(&rooms[2]);
                return;
            }
            else
            {
                cout << "Incorrect choice\n";
            }
        }
    }
}

int Dungeon::performEndGameLogic()
{
    string actions[] = 
    {
        "a. Yes",
        "b. No",
    };
    while(true)
    {
        printActions(2, actions);
        string input;
        cin >> input;
        if (input == "a" || input == "A")
        {
            return 1;
        }
        else if (input == "b" || input == "B")
        {
            return 0;
        }
        else
        {
            cout << "Incorrect choice\n";
        }
    }
}

int Dungeon::runDungeon()
{
    cout << "\n";
    cout << "Welcome to the dungeon, " << player.name << "! Inside you will find treasures but also enemies. Enter at your peril!\n";
    cout << "\n";
    cout << "You enter the dungeon with nothing but a small dagger.\n";
    cout << "Your stats are currently: \n";
    cout << player.currentHealth << " health, " << player.attack << " attack, and " << player.defence << " defence.\n";
    player.currentRoom = &rooms[0];
    player.previousRoom = &rooms[0];
    while(true)
    {
        // enter room
        enterRoom(player.currentRoom);
        // check if dead
        if (player.checkIsDead())
        {
            // Lose the game
            cout << "Game Over! Try Again?\n";
            return performEndGameLogic();
        }
        else
        {
            if (player.currentRoom->isExit)
            {
                if (player.currentRoom->enemies.size() == 0)
                {
                    //win the game
                    cout << "You Win! Play Again?\n";
                    return performEndGameLogic();
                }
            }
        }
        // movement options
        handleMovementActions(player.currentRoom);
    }
}