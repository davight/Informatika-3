#include "display_row.hpp"
#include "terminal.hpp"
#include <iostream>

#include "terminal.hpp"

int main()
{
    using namespace asciid;
    Terminal::setTextColor(Color::Black);
    std::cout << "asjlkdsalkdaksdjksa";

    DisplayRow *displayRow = new DisplayRow();
    //int rowCount = displayRow -> getDisplayCount();
    //std::cout << rowCount << std::endl;
    displayRow -> turnPixelOn(0);
    displayRow -> turnPixelOn(1);
    displayRow -> turnPixelOn(2);
    displayRow -> setPixelColor(1, Color::Red);
    displayRow -> setPixelColor(2, Color::Green);
    displayRow -> printLn();
    delete displayRow;
    return 0;
}
