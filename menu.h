#include <string>
#ifndef MENU_H
#define MENU_H

class Menu {
  private:
    bool programRunning = true;

  public:
    Menu();
    ~Menu();
    void printGreeting();
    void printFarewell();
    bool isRunning();
    void displayMenu();
    bool validInput(std::string x);
    void quitMenu();
    void executeOption(int input);
};

#endif