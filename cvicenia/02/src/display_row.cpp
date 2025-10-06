#include "display_row.hpp"

#include <iostream>
#include <stdexcept>

namespace asciid
{

    DisplayRow::DisplayRow() : m_pixels(0)
    {
        for (int  i = 0; i < getDisplayCount(); ++i)
        {
            m_colors[i] = Color::White;
        }
    }

    int DisplayRow::getDisplayCount()
    {
        return 8;
    }

    void DisplayRow::turnPixelOn(int index)
    {
        boundCheckExcept(index);
        m_pixels |= 1 << index;
    }

    void DisplayRow::turnPixelOff(int index)
    {
        boundCheckExcept(index);
        m_pixels &= ~ (0 << index);
    }

    void DisplayRow::flipPixel(int index)
    {
        boundCheckExcept(index);
        m_pixels ^= 1 << index;
    }

    bool DisplayRow::isPixelOn(int index)
    {
        boundCheckExcept(index);
        return isPixelOnUnsafe(index);
    }

    bool DisplayRow::isPixelOnUnsafe(int index) const
    {
        return m_pixels & 1 << index;
    }

    void DisplayRow::clearPixels()
    {
        m_pixels = 0;
    }

    Color DisplayRow::getPixelColor(int index) const {
        boundCheckExcept(index);
        return Color::Black;
    }

    void DisplayRow::setPixelColor(int index, Color color)
    {
        boundCheckExcept(index);
        this->m_colors[index] = color;
    }

    void DisplayRow::print() const
    {
        for (int i = 0; i < getDisplayCount(); ++i)
        {
            Terminal::setTextColor(m_colors[i]);
            std::cout << (isPixelOnUnsafe(i) ? "*" : " ");
            if (isPixelOnUnsafe(i))
            Terminal::resetTextColor();
        }
    }

    void DisplayRow::printLn() const
    {
        print();
        std::cout << "\n";
    }

    void DisplayRow::boundCheckExcept(int index) const
    {
        if (index < 0 || index >= getDisplayCount())
        {
            throw std::out_of_range("Index out of range");
        }
    }

}
