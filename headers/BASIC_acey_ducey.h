#ifndef BASIC_ACEY_DUCEY_H
#define BASIC_ACEY_DUCEY_H

#include <BASIC_game.h>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

class Acey_Ducey : Basic_Game
{
  public:
    //   a player object that contains their balance, and their total profits
    struct Player
    {
        int balance;
        int profits;

        Player(int balance_, int profits_)
        {
            balance = balance_;
            profits = profits_;
        }
    };

    // prints the title of the game and turns on the game
    Acey_Ducey();

    // deals the three initial cards to start the round
    void deal_initial_cards();

    // plays a round of Acey Ducey with the player and applies their bet to
    // their balance.
    // returns true if the round was played successfully
    // otherwise false if bet is greater than the player's balance.
    bool play_round(Player &a, const int &bet);

  private:
    //   a dealer object that deals a random card from a deck
    struct Dealer
    {
        // Generate a random card from A (1) to KING (13)
        int deal_card() const
        {
            srand(time(0));
            return 1 + (rand() % 13);
        }
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