/**
 * @file input_validator.h
 * @author Steven Aquino
 * @brief This is the header file for the Input Validator class. This class can
 * be used to validate input and ensure data is initialized properly in
 * variables.
 * @version 0.1
 * @date 2022-07-29
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef INPUT_VALIDATOR_H
#define INPUT_VALIDATOR_H

#include <iostream>
#include <string>

class Input_Validator
{
  public:
    Input_Validator(const std::string &s = "");

    int input_number(const std::string error_msg = "");

    void set_input(const std::string &s) { input = s; }

    // checks if input is a number and attempts to save input into destination
    bool is_num(int &n);

    // checks if input is a positive number
    bool is_pos_num(int &n);

    // checks if input is a negative number
    bool is_neg_num(int &n);

    // checks if input is a quit command
    bool is_quit(const std::string &quit_command) const;

    ~Input_Validator();

  private:
    std::string input;
};

#endif