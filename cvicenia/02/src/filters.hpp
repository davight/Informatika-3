#ifndef ASCIID_FILTERS_HPP
#define ASCIID_FILTERS_HPP
#include "terminal.hpp"
#include "display.hpp"

namespace asciid::filters
{
    void flip(Display *d);
    void repaint(Display *d, Color from, Color to);
    void transpose(Display *d);
    void fill(Display *d, int row, int col, Color color);


}

#endif