#include <menu.h>

Menu::Menu(std::vector<Menu_Option> menu_)
{
    if (menu_.empty())
    {
        throw std::invalid_argument("Menu is empty!");
    }
    menu = menu_;
    state = OPEN;
}

void Menu::process(int option)
{
    bool found_option = false;
    for (Menu_Option a : menu)
    {
        if (a.number == option)
        {
            found_option = !found_option;
            a.function();
        }
    }
    if (!found_option)
    {
        throw std::invalid_argument("Option doesn't exist!");
    }
}

void Menu::close() { state = CLOSED; }

bool Menu::is_open() { return state == OPEN; }

bool Menu::option_exists(int option)
{
    for (Menu_Option a : menu)
    {
        if (a.number == option)
        {
            return true;
        }
    }
    return false;
}