#ifndef ASCIID_TERMINAL_HPP
#define ASCIID_TERMINAL_HPP

namespace asciid
{

    enum class Color {
        Black = 30,
        Red = 31,
        Green = 32,
        Yellow = 33,
        Blue = 34,
        Magenta = 35,
        Cyan = 36,
        White = 37,
    };

    class Terminal {
        public:
            static void clear();
            static void setTextColor(Color color);
            static void resetTextColor();
    };
}

#endif