#include "display_row.hpp"
#include <iostream>

int main()
{
    asciid::DisplayRow *displayRow = new asciid::DisplayRow();
    int rowCount = displayRow -> getDisplayCount();
    std::cout << rowCount << std::endl;
    delete displayRow;
    return 0;
}