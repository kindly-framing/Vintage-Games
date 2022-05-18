#include "menu.h"
#include "acey_ducey.h"

#include <iostream>

Menu::Menu() {}

Menu::~Menu() {}

void Menu::executeOption(int input)
{
    switch (input)
    {
    case 1:
        playAceyDucey();
        break;
    default:
        break;
    }
}

/**
 * @brief Checks if the program should still be running.
 *
 * @return true The program is running.
 * @return false The program has stopped.
 */
bool Menu::isRunning() { return programRunning; }

/**
 * @brief Checks the input from the user and ensures that is it either the quit
 * command or a valid option. Checks the out of range exception if the user
 * tries to enter a number that can't be stored in an int.
 *
 * @param x The input from the user
 * @return true Either a valid option or the quit command (q)
 * @return false Can't be used in for the menu.
 */
bool Menu::validInput(std::string x)
{
    // 'q' is the only non-numeric valid input
    if (x == "q" || x == "Q")
    {
        return true;
    }
    // If not 'q', input has to be numeric
    for (int i = 0; i < x.length(); i++)
    {
        if (!isdigit(x[i]))
        {
            return false;
        }
    }
    // Number is too big to store
    try
    {
        int y;
        y = stoi(x);
    }
    catch (const std::out_of_range &e)
    {
        return false;
    }

    return true;
}

/**
 * @brief Will turn the menu off.
 *
 */
void Menu::quitMenu() { programRunning = false; }

/**
 * @brief Asks the user to enter an input for the menu options.
 *
 */
void Menu::displayMenu()
{
    // Feel free to add more games options, but add the game as a function
    std::cout
        << "Please enter the corresponding number to play the game or 'q' "
           "to quit.\n";
    std::cout << "1. Acey Ducey\n";
    std::cout << "'q' to quit\n";
}

void Menu::printGreeting()
{
    std::cout << "Hello, welcome to Vintage Games!\n";
}

void Menu::printFarewell() { std::cout << "Thank you for playing!\n"; }
