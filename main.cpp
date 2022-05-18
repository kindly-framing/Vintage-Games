#include <iostream>
#include <string>

#include "menu.h"

int main()
{
    Menu vintageGameMenu;
    vintageGameMenu.printGreeting();

    while (vintageGameMenu.isRunning())
    {
        vintageGameMenu.displayMenu();
        std::string userInput;
        std::cin >> userInput;

        if (vintageGameMenu.validInput(userInput))
        {
            if (userInput == "q")
            {
                vintageGameMenu.quitMenu();
            }
            else
            {
                int in = stoi(userInput);
                vintageGameMenu.executeOption(in);
            }
        }
        else
        {
            std::cout << "Input can't be processed. Try again!\n";
        }
    }

    vintageGameMenu.printFarewell();
}