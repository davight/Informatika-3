#include "terminal.hpp"
#include <iostream>

namespace asciid
{

    void Terminal::clear()
    {
        std::cout << "\033c";
    }

    void Terminal::resetTextColor()
    {
        std::cout << "\033[0m";
    }

    void Terminal::setTextColor(Color color)
    {
        std::cout << "\033[" << static_cast<int>(color) << "m";
    }

}
