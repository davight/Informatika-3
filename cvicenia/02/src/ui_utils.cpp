#include "ui_utils.hpp"

#include <charconv>
#include <iostream>
#include <limits>
#include <string>
#include <stdexcept>

namespace uiutils {

bool promptYesNo(const std::string &prompt) {
    throw std::logic_error("Not implemented yet!");
}

int chooseOption(
    const std::string &prompt,
    const std::vector<std::string> &options
) {
    throw std::logic_error("Not implemented yet!");
}

std::optional<int> chooseOptionOpt(
    const std::string &prompt,
    const std::vector<std::string> &options,
    int maxTries
) {
    throw std::logic_error("Not implemented yet!");
}

int readInt(const std::string &prompt) {
    throw std::logic_error("Not implemented yet!");
}

std::optional<int> readIntOpt(const std::string &prompt, int maxTries) {
    throw std::logic_error("Not implemented yet!");
}

std::string readString(const std::string &prompt) {
    std::cout << prompt;
    std::string input;
    std::cin >> input;
    return input;
}

std::optional<int> parseInt(const std::string &s) {
    int result;

    const char *first = s.data();
    const char *last = s.data() + s.size();
    const std::from_chars_result fcResult
        = std::from_chars(first, last, result);

    return fcResult.ec == std::errc() && fcResult.ptr == last
             ? std::optional<int>(result)
             : std::nullopt;
}

} // namespace uiutils
