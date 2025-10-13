#include <iostream>

#include "terminal.hpp"

#include "display.hpp"
#include "game_of_life.hpp"

int main()
{
    gol::GameOfLife *game = gol::GameOfLife::createToad();
    game->run(100);
    return 0;
}
