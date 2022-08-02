#include "PLAY_game.h"
#include "input_validator.h"
#include "menu.h"

std::vector<Menu_Option> games = {{1, "Acey Ducey", play_acey_ducey},
                                  {2, "Another game", holder}};

int main()
{
    const std::string option_request =
        "Please select an option from the menu or q to quit: ";
    const std::string invalid_entry = "Not a valid entry! Try again: ";

    Menu main_menu(games);
    std::cout << main_menu << option_request;
    std::string input;
    int option;
    while (main_menu.is_open())
    {
        std::getline(std::cin, input);
        Input_Validator user(input);
        if (user.is_quit("q"))
        {
            main_menu.close();
        }
        else if (user.is_num(option) && main_menu.option_exists(option))
        {
            system("cls");
            main_menu.process(option);
            std::cin.sync();
            system("cls");
            std::cout << main_menu << option_request;
        }
        else
        {
            std::cout << invalid_entry;
        }
    }

    std::cout << "Bye!\n";
    return 0;
}

void holder() { std::cout << "Running option...\n"; }