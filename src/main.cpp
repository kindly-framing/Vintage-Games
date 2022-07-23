// #include "basic_games.h" // Library for the BASIC games
#include "../headers/main.h"             // Game menu and play functions
#include "../headers/input_validation.h" // Validators for input
#include "../headers/menu.h"             // Header file for Menu class

int main()
{
    Menu game(games);
    std::cout << "Welcome to Vintage BASIC Games!\n";
    game.display_menu();
    std::cout << "Enter game to play or q to quit: ";

    std::string input;
    unsigned int selection;
    while (game.is_open()) {
        std::getline(std::cin, input);
        if (input == "q" || input == "Q") {
            break;
        }

        if (input_validation::is_num(input)) {
            selection = std::stoul(input);
            try {
                game.process_menu_option(selection);
                system("cls");
                std::cout << "Welcome to Vintage BASIC Games!\n";
                game.display_menu();
                std::cout << "Enter game to play or q to quit: ";
            }
            catch (const std::invalid_argument &e) {
                std::cout << "Not a valid entry! Try again: ";
            }
        }
        else {
            std::cout << "Not valid entry! Try again: ";
        }

        std::cin.sync();
    }
    std::cout << "Bye!\n";

    return 0;
}

void play_acey_ducey() { std::cout << "execute option 1\n"; }