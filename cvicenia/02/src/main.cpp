#include <iostream>

#include "terminal.hpp"

#include "display.hpp"
#include "game_of_life.hpp"

int main()
{
    gol::GameOfLife *game = gol::GameOfLife::createToad();
    game->run(100);
    //game->prinState();
    //std::cout << game->isCellAlive(1, 1) << std::endl;
    //std::cout << game->isCellAlive(1, 2) << std::endl;
    //std::cout << game->isCellAlive(1, 0) << std::endl;
    return 0;
    game->prinState();
    game->tick();
    game->prinState();
    game->tick();
    return 0;
}
