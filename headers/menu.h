#ifndef MENU_H_
#define MENU_H_

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

typedef void (*Menu_Processing_Function)();

/**
 * @param number Numerical value of the option
 * @param text A text that describes what the option would do
 * @param processing_function What the option will do if selected
 *
 */
struct Menu_Option {
    unsigned int number;
    std::string text;
    Menu_Processing_Function processing_function;
};

class Menu {
  public:
    // You won't be able to use menu functions unless the menu is OPEN
    enum State { CLOSED = 0, OPEN = 1 };

  private:
    std::vector<Menu_Option> options; // All of the menu options
    State state;                      // OPEN or CLOSED

    /**
     * @brief Menu cannot be used when state is set to closed.
     *
     */
    void invariant();

  public:
    /**
     * @brief Construct a new Menu from a given list of menu options.
     *
     * @throw Vector of menu options cannot be empty.
     * @param menu A list containing menu options.
     */
    Menu(const std::vector<Menu_Option> &menu);

    /**
     * @brief Displays all of the menu options.
     *
     */
    void display_menu();

    /**
     * @brief Finds menu option corresponding to selection and calls the
     * processing function of that menu option.
     *
     * @throw Menu option given doesn't exist.
     * @param selection A numerical value attributed to a menu option.
     */
    void process_menu_option(const unsigned int selection);

    /**
     * @brief Closes the menu and sets the state to CLOSED.
     *
     */
    void close();

    /**
     * @brief Checks if the menu is still open.
     *
     * @return true Menu is open. Otherwise the menu is closed.
     */
    bool is_open();
};

#endif