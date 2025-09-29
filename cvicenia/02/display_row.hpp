#ifndef ASCIID_DISPLAY_ROW_HPP
#define ASCIID_DISPLAY_ROW_HPP

#include <cstdint>

namespace asciid
{

    class DisplayRow
    {
        public:
            DisplayRow();
            int getDisplayCount() const;
            void turnPixelOn(int index);

        private:
            std::uint8_t m_pixels;
    };

};

#endif