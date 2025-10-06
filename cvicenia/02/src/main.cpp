#include "terminal.hpp"

#include "display.hpp"

int main()
{
    using namespace asciid;
    Display *display = new Display();
    display->turnPixelOn(1, 1);
    display->turnPixelOn(2, 2);
    display->turnPixelOn(3, 3);
    display->flipPixel(3, 3);
    display->turnPixelOn(4, 4);
    display->setPixelColor(4, 4, Color::Red);
    display->flipPixel(5, 5);
    display -> printLn();
    delete display;
    return 0;
}
