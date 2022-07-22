#ifndef MENU_H_
#define MENU_H_

#include <string>
#include <vector>

// Zero is reserved for terminating menu
const unsigned int TERMINATING_INT = 0;

typedef void (*Menu_Processing_Function)();
struct Menu_Item {
    unsigned int number;
    std::string text;
    Menu_Processing_Function processing_function;
};

class Menu {
  public:
    // ON means the menu is running, while OFF means to exit from the menu
    enum State { ON = 1, OFF = 0 };

  private:
    State state;                      // ON or OFF
    std::vector<Menu_Item> main_menu; // Menu to display and process

    void set_state(State a) { state = a; } // changes the state of the menu

  public:
    // construct an object from a custom menu
    Menu(std::vector<Menu_Item> menu);

    // processes the array of menu items and executes the process function
    // returns true if menu item was found
    bool menu_engine();

    // helper for menu_engine() to check if the user input is valid and places
    // the valid input into destination
    bool valid(const std::string input, unsigned int &destination);

    // returns the state of the menu if it is turned on or off.
    bool get_state() { return state; }

    // sets the state of the menu as OFF
    void exit() { state = OFF; }
};

#endif