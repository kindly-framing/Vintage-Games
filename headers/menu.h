#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

typedef void (*Menu_Processing_Function)();
struct Menu_Option
{
    int number;
    std::string text;
    Menu_Processing_Function function;
};

enum State
{
    CLOSED = 0,
    OPEN = 1
};

class Menu
{
  public:
    Menu(std::vector<Menu_Option> menu_);

    void process(int option);

    void close();

    bool is_open();

    bool option_exists(int option);

    friend std::ostream &operator<<(std::ostream &output, const Menu &m)
    {
        for (Menu_Option a : m.menu)
        {
            output << a.number << " " << a.text << "\n";
        }
        return output;
    }

  private:
    std::vector<Menu_Option> menu;
    State state;
};

#endif