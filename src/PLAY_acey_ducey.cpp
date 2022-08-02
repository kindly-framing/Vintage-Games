#include "BASIC_acey_ducey.h"
#include "PLAY_game.h"
#include "input_validator.h"

void play_acey_ducey()
{
    // setting up player for game
    Acey_Ducey game;
    std::cout << "\nACEY-DUCEY IS PLAYED IN THE FOLLOWING MANNER\n"
                 "THE DEALER (COMPUTER) DEALS TWO CARDS FACE UP\n"
                 "YOU HAVE AN OPTION TO BET OR NOT BET DEPENDING\n"
                 "ON WHETHER OR NOT YOU FEEL THE CARD WILL HAVE\n"
                 "A VALUE BETWEEN THE FIRST TWO.\n"
                 "IF YOU DO NOT WANT TO BET, INPUT A 0 to quit\n";
    Input_Validator user_input;
    int starting_balance =
        user_input.input_number("not valid entry! try again: ");
    Acey_Ducey::Player user(starting_balance);
    std::cout << "YOU NOW HAVE " << starting_balance << " DOLLARS!\n\n";

    // game logic
    while (user.balance != 0)
    {
        game.deal_initial_cards();
        std::cout << "\nEnter your bet: ";
        int bet = user_input.input_number("not valid entry! try again: ");
        bool zero_bet = (bet == 0);

        while (!game.play_round(user, bet) && !zero_bet)
        {
            std::cout << "SORRY MY FRIEND BUT YOU BET TOO MUCH\n";
            std::cout << "YOU HAVE ONLY " << user.balance
                      << " DOLLARS TO BET\n";
            std::cout << "Enter your bet: ";
            bet = user_input.input_number("not valid entry! try again: ");
            zero_bet = (bet == 0);
        }

        if (zero_bet)
        {
            std::cout << "CHICKEN!!\n\n";
        }
        else
        {
            std::string result_message =
                (user.round_result) ? "YOU WIN!!!\n" : "SORRY, YOU LOSE\n";
            std::cout << result_message << "YOU NOW HAVE " << user.balance
                      << " DOLLARS\n\n";
        }
    }
    // TODO: Implement Line 1010 from Basic website
    std::cout << "OK HOPE YOU HAD FUN\n";
    system("pause");
}
