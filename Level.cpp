#include "Level.h"
#include <iostream>

using namespace std;

Level::Level()
{
    
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
    Room* room = player.currentRoom;
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
                "a. Move Left",
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