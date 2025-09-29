#include "display_row.hpp"

namespace asciid
{

    DisplayRow::DisplayRow() : m_pixels(0)
    {
    }

    int DisplayRow::getDisplayCount() const
    {
        return 8;
    }

    void DisplayRow::turnPixelOn(int index)
    {
        (void)index;
    }


}