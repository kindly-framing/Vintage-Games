#ifndef BASIC_ACEY_DUCEY_H
#define BASIC_ACEY_DUCEY_H

#include "BASIC_game.h"
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

class Acey_Ducey : public Basic_Game
{
  public:
    //   a player object that contains their balance, and their total profits
    struct Player
    {
        enum Result
        {
            LOST,
            WON,
        };
        int balance;
        Result round_result;
        Player(int t_balance = 0) { balance = t_balance; }
    };

    // prints the title of the game and turns on the game
    Acey_Ducey();

    // deals the three initial cards to start the round
    void deal_initial_cards();

    // plays a round of Acey Ducey with the player and applies their bet to
    // their balance.
    // returns true if the round was played successfully
    // otherwise false if bet can't be applied to player's balance.
    bool play_round(Player &a, const int &bet);

    // closes the game. Utlize to end game loop.
    void close() { state = OFF; }

  private:
    //   a dealer object that deals a random card from a deck
    struct Dealer
    {
        Dealer() { srand(time(0)); }

        // Generate a random card from A (1) to KING (13)
        int deal_card() const { return 1 + (rand() % 13); }
    };

    int dealt_cards[3]; // the playing cards for the round

    // a player's balance can never be zero
    void player_invariant(const Player &a) const;

    // the game state must be ON to play game
    void game_invariant() const;

    // converts an integer value to the associated rank. ex. KING = 13
    std::string convert_to_rank(const int &n);
};

#endif