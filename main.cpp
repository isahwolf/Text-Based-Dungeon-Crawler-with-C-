#include <iostream>
#include "Dungeon.h"
#include "Player.h"
#include "GameCharacter.h" 
#include "Item.h"
#include "Room.h"
#include "Level.h"

int main ()
{
    system("color 0A");
    cout << R"(
__________________________________________________________________________________________________
|    ___    __ __  ____    ____    ___   ___   ____          __  ____    ____  __    __  _       |
|   |   \  |  |  ||    \  /    |  /  _] /   \ |    \        /  ]|    \  /    ||  |__|  || |      |
|   |    \ |  |  ||  _  ||   __| /  [_ |     ||  _  |      /  / |  D  )|  o  ||  |  |  || |      |
|   |  D  ||  |  ||  |  ||  |  ||    _]|  O  ||  |  |     /  /  |    / |     ||  |  |  || |___   |
|   |     ||  :  ||  |  ||  |_ ||   [_ |     ||  |  |    /   \_ |    \ |  _  ||  `  '  ||     |  |
|   |     ||     ||  |  ||     ||     ||     ||  |  |    \     ||  .  \|  |  | \      / |     |  |
|   |_____| \__,_||__|__||___,_||_____| \___/ |__|__|     \____||__|\_||__|__|  \_/\_/  |_____|  |
|________________________________________________________________________________________________|
    )";
    // Set up the player
    cout << "Welcome dungeon crawler! What is your name?\n";
    string playerName;
    cin >> playerName;
    Player player = Player(playerName, 100, 20, 10);
    
    // Set up the first room
    Room* firstRoom = new Room(0, false, vector<Item>(), vector<GameCharacter*>());

    // Set up the second room
    Item ironSword = Item("Iron Sword", 0, 10, 0, ItemType::WEAPON);
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
         65, 25, 10,
        firstEnemyDrop);
    vector<GameCharacter*> thirdRoomEnemies;
    thirdRoomEnemies.push_back(firstEnemy);
    Room* thirdRoom = new Room(2, false, vector<Item>(), thirdRoomEnemies);

    // Set up the fourth room
    Item secondEnemyDrop = Item("Iron Chestplate", 0, 0, 15, ItemType::BOOTS);
    GameCharacter* secondEnemy = new GameCharacter(
        "Goblin Chief",
        "A larger green creature clad in heavy armor. There is a large scar across its face and appears meaner than the last enemy. It readies its long battle-worn spear.",
         115, 45, 20,
        secondEnemyDrop);
    vector<GameCharacter*> fourthRoomEnemies;
    fourthRoomEnemies.push_back(secondEnemy);
    Room* fourthRoom = new Room(3, true, vector<Item>(), fourthRoomEnemies);

    Dungeon dungeon = Dungeon(player);
    dungeon.rooms.resize(4);
    dungeon.rooms[0] = firstRoom;
    dungeon.rooms[1] = secondRoom;
    dungeon.rooms[2] = thirdRoom;
    dungeon.rooms[3] = fourthRoom;

    while(true)
    {
        int result = dungeon.runDungeon();
        if (result == 0)
        {
            break;
        }
    }
    cout << "Goodbye Dungeon Crawler!";
}