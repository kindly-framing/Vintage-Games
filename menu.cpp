#include "menu.h"
#include <iostream>
#include <limits>

Menu::Menu(std::vector<Menu_Item> menu)
{
    main_menu = menu;
    set_state(ON);
}

bool Menu::menu_engine()
{
    using namespace std;

    // display the menu
    for (Menu_Item x : main_menu) {
        cout << x.number << ": " << x.text << endl;
    }

    // receive and handle input
    cout << "Enter your selection or zero to quit: ";
    std::string input;
    unsigned int selection;
    std::getline(std::cin, input);
    while (!valid(input, selection)) {
        cout << "Incorrect entry. Try again: ";
        std::getline(std::cin, input);
    }

    // execute the processing function for the menu item
    if (selection == TERMINATING_INT) {
        return false;
    }
    for (Menu_Item x : main_menu) {
        if (selection == x.number) {
            (x.processing_function)();
            break;
        }
    }
    return true;
}

bool Menu::valid(const std::string input, unsigned int &destination)
{
    // stoul() already goes through each character in input and tries to convert
    unsigned int a;
    try {
        a = std::stoul(input);
    }
    catch (const std::invalid_argument &e) {
        return false;
    }

    if (a <= main_menu.size()) {
        destination = a;
        return true;
    }
    return false;
}
