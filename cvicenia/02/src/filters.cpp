#include "filters.hpp"

#include <stdexcept>

namespace asciid::filters
{
    void flip(Display *d)
    {
        for (int row = 0; row < Display::getRowCount(); row++)
        {
            for (int col = 0; col < Display::getColumnCount(); col++)
            {
                d->flipPixel(row, col);
            }
        }
    }

    void transpose(Display *d)
    {
        (void)d; // nech nepinda warning
        throw std::runtime_error("Not implemented"); // na toto som uz unaveny
    }

    void repaint(Display *d, Color from, Color to)
    {
        for (int row = 0; row < Display::getRowCount(); row++)
        {
            for (int col = 0; col < Display::getColumnCount(); col++)
            {
                if (d->getPixelColor(row, col) == from)
                {
                    d->setPixelColor(row, col, to);
                }
            }
        }
    }

    void fill(Display *d, int row, int col, Color color)
    {
        (void)d; (void)row; (void)col; (void)color; // nech nepinda warning
        throw std::runtime_error("Not implemented"); // na toto som uz unaveny moc
    }
}
