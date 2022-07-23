#ifndef INPUT_VALIDATION_H_
#define INPUT_VALIDATION_H_

#include <algorithm>
#include <string>

namespace input_validation {
/**
 * @brief Checks the input and returns if input is a number.
 *
 * @param s An input
 * @return true The input is a valid number.
 */
bool is_num(const std::string &s);

} // namespace input_validation

#endif