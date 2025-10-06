#ifndef ASCIID_DISPLAY_HPP
#define ASCIID_DISPLAY_HPP
#include "display_row.hpp"
#include "terminal.hpp"

namespace asciid
{

    class Display
    {
        public:
            Display();
            ~Display();
            static int getRowCount();
            static int getColumnCount();
            void turnPixelOn(int row, int column);
            void turnPixelOff(int row, int column);
            void flipPixel(int row, int column);
            bool isPixelOn(int row, int column) const;
            void clearPixels();
            Color getPixelColor(int row, int column) const;
            void setPixelColor(int row, int column, Color color);
            void print() const;
            void printLn() const;
        private:
            static const int N_ROWS = 8;
            DisplayRow *m_rows[N_ROWS];
            bool boundCheck(int row, int column) const;
            void boundCheckExcept(int row, int column) const;
    };

}

#endif