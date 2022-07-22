#include "basic_games.h" // Library for the BASIC games
#include "menu.h"        // Menu class
#include "play.h"        // Processing functions for the menu items

#include <iostream>
#include <string>

int main()
{
    // add games here
    std::vector<Menu_Item> games = {{1, "Acey Ducey", play_acey_ducey}};

    // The menu execution is here
    Menu game(games);
    while (game.get_state() == Menu::ON) {
        std::cout << "Welcome to Vintage BASIC Games!\n";
        if (!game.menu_engine()) {
            game.exit();
        }
        else {
            std::cin.sync(); // guards against something left in cin buffer
            system("cls");
        }
    }
    std::cout << "Bye!\n";

    return 0;
}

void play_acey_ducey() { BASIC_GAMES::Acey_Ducey x; }