#ifndef BASIC_GAMES_H_
#define BASIC_GAMES_H_

#include <iostream>
#include <string>
namespace basic_games {

class Acey_Ducey {
  public:
    typedef int Card;
    const Card ranks[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

    const std::string greeting =
        "\tACEY DUCEY CARD GAME\n"
        "Creative Computing Morristown, New Jersey\n\n"
        "ACEY-DUCEY IS PLAYED IN THE FOLLOWING MANNER\n"
        "THE DEALER (COMPUTER) DEALS TWO CARDS FACE UP\n"
        "YOU HAVE AN OPTION TO BET OR NOT BET DEPENDING\n"
        "ON WHETHER OR NOT YOU FEEL THE CARD WILL HAVE\n"
        "A VALUE BETWEEN THE FIRST TWO.\n"
        "IF YOU DO NOT WANT TO BET, INPUT A 0\n";

  private:
    double balance; // User's balance

  public:
    // displays greeting and gets starting balance from user for game
    Acey_Ducey();

    // deals a random card
    Card deal_card();

    // game engine
    bool engine();
};
} // namespace basic_games

#endif