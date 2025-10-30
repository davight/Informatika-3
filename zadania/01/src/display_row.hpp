#ifndef ASCIID_DISPLAY_ROW_HPP
#define ASCIID_DISPLAY_ROW_HPP

#include <cstdint>

#include "terminal.hpp"

namespace asciid
{

    class DisplayRow
    {
        public:
            DisplayRow();
            static int getDisplayCount();
            void turnPixelOn(int index);
            void turnPixelOff(int index);
            void flipPixel(int index);
            bool isPixelOn(int index);
            void clearPixels();
            Color getPixelColor(int index) const;
            void setPixelColor(int index, Color color);
            void print() const;
            void printLn() const;
        private:
            std::uint8_t m_pixels;
            Color m_colors[8];
            bool boundCheck(int index) const;
            void boundCheckExcept(int index) const;
            bool isPixelOnUnsafe(int index) const;
    };

};

#endif