#include "../headers/menu.h"

Menu::Menu(const std::vector<Menu_Option> &menu)
{
    if (menu.empty()) {
        throw std::invalid_argument(
            "Context: Creating a new Menu object.\n"
            "Problem: The menu parameter given is empty.\n"
            "Solution: Provide a menu with at least one option.\n");
    }

    options = menu;
    state = OPEN;
}

void Menu::display_menu()
{
    invariant();
    for (Menu_Option x : options) {
        std::cout << x.number << ": " << x.text << std::endl;
    }
}

void Menu::process_menu_option(const unsigned int selection)
{
    invariant();

    bool found = false;
    for (Menu_Option x : options) {
        if (selection == x.number) {
            found = !found;
            (x.processing_function)();
            break;
        }
    }
    if (!found) {
        throw std::invalid_argument(
            "Context: Processing option in the menu.\n"
            "Problem: Option selected doesn't exist in the menu.\n"
            "Solution: Ensure the option exists in the menu.\n");
    }
}

void Menu::close() { state = CLOSED; }

void Menu::invariant() { assert(state == OPEN); }

bool Menu::is_open() { return state; }