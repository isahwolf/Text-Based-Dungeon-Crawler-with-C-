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
    Player player = Player(playerName, 100, 20, 10); // Create a player with default stats
    Dungeon dungeon = Dungeon(player); // Create a dungeon with the player
    int currentLevel = 1; // Start at level 1
    
    while(true)
    {

        Level level1; // Create a new level instance

        if (currentLevel == 1)
        {
            level1.setUpLevel1("Goblin Camp");
        }
        else if (currentLevel == 2)
        {
            level1.setUpLevel2("Skeleton Crypt");
        }
        else
        {
            cout << "Congratulations! You have completed all available levels! More levels coming soon!\n";
            break;
        }
        
        dungeon.rooms = level1.rooms;
        dungeon.level = level1;


        int result = dungeon.runDungeon();
        if (result == 0)
        {
            break; // Exit the game
        }
        else if (result == 1)
        {
            cout << "Starting over...\n";
            currentLevel = 1; // Reset to first level
            player = Player(playerName, 100, 20, 10); // Resets player
            dungeon = Dungeon(player); // Resets dungeon
        }
        else if (result == 2)
        {
            currentLevel++; // Move to the next level
        }
    }
    cout << "Goodbye Dungeon Crawler!";
}