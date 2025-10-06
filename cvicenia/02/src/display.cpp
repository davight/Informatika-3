#include "display.hpp"

#include <stdexcept>

namespace asciid
{
    Display::Display()
    {
        for (int i = 0; i < N_ROWS; i++)
        {
            m_rows[i] = new DisplayRow();
        }
    }

    Display::~Display()
    {
        for (int i = 0; i < N_ROWS; i++)
        {
            delete m_rows[i];
        }
    }

    int Display::getRowCount()
    {
        return N_ROWS;
    }

    int Display::getColumnCount()
    {
        return DisplayRow::getDisplayCount();
    }

    void Display::turnPixelOn(int row, int column)
    {
        boundCheckExcept(row, column);
        m_rows[row]->turnPixelOn(column);
    }

    void Display::turnPixelOff(int row, int column)
    {
        boundCheckExcept(row, column);
        m_rows[row]->turnPixelOff(column);
    }

    void Display::flipPixel(int row, int column)
    {
        boundCheckExcept(row, column);
        m_rows[row]->flipPixel(column);
    }

    bool Display::isPixelOn(int row, int column) const
    {
        boundCheckExcept(row, column);
        return m_rows[row]->isPixelOn(column);
    }

    void Display::clearPixels()
    {
        for (int i = 0; i < N_ROWS; i++)
        {
            m_rows[i]->clearPixels();
        }
    }

    Color Display::getPixelColor(int row, int column) const
    {
        boundCheckExcept(row, column);
        return m_rows[row]->getPixelColor(column);
    }

    void Display::setPixelColor(int row, int column, Color color)
    {
        boundCheckExcept(row, column);
        m_rows[row]->setPixelColor(column, color);
    }

    void Display::print() const
    {
        for (int i = 0; i < N_ROWS; i++)
        {
            m_rows[i]->print();
        }
    }

    void Display::printLn() const
    {
        for (int i = 0; i < N_ROWS; i++)
        {
            m_rows[i]->printLn();
        }
    }

    bool Display::boundCheck(int row, int column) const
    {
        return (row >= 0 && row < DisplayRow::getDisplayCount()) &&
            (column >= 0 && column < N_ROWS); // alebo naopak idk stale je to 8
    }

    void Display::boundCheckExcept(int row, int column) const
    {
        if (!boundCheck(row, column))
        {
            throw std::out_of_range("Index out of range");
        }
    }

}
