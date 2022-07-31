#include <input_validator.h>

Input_Validator::Input_Validator(const std::string &s) { input = s; }

bool Input_Validator::is_num(int &n)
{
    // checking that input is all digits
    bool negative_sign = (input[0] == '-');
    int start = (negative_sign) ? 1 : 0;
    for (int i = start; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }

    // attempt to store the number into n
    try
    {
        n = stoi(input);
    }
    catch (const std::exception &e)
    {
        return false;
    }
    return true;
}

bool Input_Validator::is_pos_num(int &n)
{
    // checking if input is a positive number
    for (char c : input)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    // attempt to store the number into n
    try
    {
        n = stoi(input);
    }
    catch (const std::exception &e)
    {
        return false;
    }

    return true;
}

bool Input_Validator::is_neg_num(int &n)
{
    // checking if input is a negative number
    if (input[0] != '-')
    {
        return false;
    }
    for (int i = 1; i < input.size(); i++)
    {
        if (!isdigit(input[i]))
        {
            return false;
        }
    }

    // attempt to convert
    try
    {
        n = stoi(input);
    }
    catch (const std::exception &e)
    {
        return false;
    }

    return true;
}

bool Input_Validator::is_quit(const std::string &quit_command) const
{
    return input == quit_command;
}

Input_Validator::~Input_Validator() {}