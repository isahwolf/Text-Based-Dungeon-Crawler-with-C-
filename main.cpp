#include <iostream>
#include "Dungeon.cpp"
#include "Player.cpp"
#include "GameCharacter.cpp"
#include "Item.cpp"
#include "Room.cpp"

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
    Room firstRoom = Room(0, false, vector<Item>(), vector<GameCharacter>());

    // Set up the second room
    Item ironSword = Item("Iron Sword", 0, 10, 0);
    Item leatherHelmet = Item("Leather Helmet", 0, 0, 10);
    vector<Item> secondRoomItems;
    secondRoomItems.push_back(ironSword);
    secondRoomItems.push_back(leatherHelmet);
    Room secondRoom = Room(1, false, secondRoomItems, vector<GameCharacter>());

    // Set up the third room
    Item firstEnemyDrop= Item("Leather Boots", 0, 0, 10);
    GameCharacter firstEnemy = GameCharacter(
        "Goblin Soldier",
        "It is a small green creature. It scowls and shows its sharp teeth. It readies its jagged metal sword.",
         65, 25, 10,
        firstEnemyDrop);
    vector<GameCharacter> thirdRoomEnemies;
    thirdRoomEnemies.push_back(firstEnemy);
    Room thirdRoom = Room(2, false, vector<Item>(), thirdRoomEnemies);

    // Set up the fourth room
    Item secondEnemyDrop = Item("Iron Chestplate", 0, 0, 15);
    GameCharacter secondEnemy = GameCharacter(
        "Goblin Chief",
        "A larger green creature clad in heavy armor. There is a large scar across its face and appears meaner than the last enemy. It readies its long battle-worn spear.",
         115, 45, 20,
        secondEnemyDrop);
    vector<GameCharacter> fourthRoomEnemies;
    fourthRoomEnemies.push_back(secondEnemy);
    Room fourthRoom = Room(3, true, vector<Item>(), fourthRoomEnemies);

    Dungeon dungeon = Dungeon(player);
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