#include "BASIC_acey_ducey.h"

Acey_Ducey::Acey_Ducey()
{
    state = ON;
    std::cout << "\t\tACEY DUCEY CARD GAME\n"
                 "CREATIVE COMPUTING MORRISTOWN, NEW JERSEY\n";
}

void Acey_Ducey::deal_initial_cards()
{
    // dealing cards from the dealer
    Dealer x;
    for (int i = 0; i < 3; i++)
    {
        dealt_cards[i] = x.deal_card();
    }

    // sorting the first two cards to be in order to be displayed
    if (dealt_cards[0] > dealt_cards[1])
    {
        std::swap(dealt_cards[0], dealt_cards[1]);
    }
    std::cout << "HERE ARE YOUR NEXT TWO CARDS\n";
    std::cout << convert_to_rank(dealt_cards[0]) << "\n"
              << convert_to_rank(dealt_cards[1]) << "\n";
}

bool Acey_Ducey::play_round(Player &a, const int &bet)
{
    // pre-conditions
    game_invariant();
    player_invariant(a);
    if (bet > a.balance || bet == 0)
    {
        return false;
    }

    // play a round of Acey Ducey
    std::cout << "Final card: " << convert_to_rank(dealt_cards[2]) << "\n";
    if (dealt_cards[2] > dealt_cards[0] && dealt_cards[2] < dealt_cards[1])
    {
        a.round_result = Player::WON;
        a.balance += bet;
    }
    else
    {
        a.round_result = Player::LOST;
        a.balance -= bet;
    }
    return true;
}

void Acey_Ducey::player_invariant(const Player &a) const
{
    assert(a.balance >= 0);
}

void Acey_Ducey::game_invariant() const { assert(state == ON); }

std::string Acey_Ducey::convert_to_rank(const int &n)
{
    std::string rank;
    switch (n)
    {
    case 1:
        rank = "ACE";
        break;
    case 11:
        rank = "JACK";
        break;
    case 12:
        rank = "QUEEN";
        break;
    case 13:
        rank = "KING";
        break;
    default:
        rank = std::to_string(n);
        break;
    }
    return rank;
}