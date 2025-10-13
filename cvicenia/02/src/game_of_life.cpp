//
// Created by david on 10/13/2025.
//

#include "game_of_life.hpp"

#include <chrono>
#include <thread>

#include "display.hpp"

namespace gol
{
    GameOfLife::GameOfLife()
    {
        m_new_display = new asciid::Display();
        m_old_display = new asciid::Display();
    }

    GameOfLife::~GameOfLife()
    {
        delete m_new_display;
        delete m_old_display;
    }

    bool GameOfLife::cellExists(int row, int col) const
    {
        return m_old_display->boundCheck(row, col);
    }

    void GameOfLife::setCellAlive(int row, int col)
    {
        if (cellExists(row, col))
        {
            m_new_display->turnPixelOn(row, col);
        }
    }

    void GameOfLife::setCellDead(int row, int col)
    {
        if (cellExists(row, col))
        {
            m_new_display->turnPixelOff(row, col);
        }
    }

    void GameOfLife::tick()
    {
        for (int col = 0; col < asciid::Display::getColumnCount(); ++col)
        {
            for (int row = 0; row < asciid::Display::getRowCount(); ++row)
            {
                const int livingNeighbours = calculateLivingNeighbours(row, col);
                if (isCellAlive(row, col))
                {
                    if (livingNeighbours < 2) // ma menej ako 2 susedov, umiera
                    {
                        setCellDead(row, col);
                    }
                    else if (livingNeighbours == 2 || livingNeighbours == 3) // ma prave 2 susedov, zije
                    {
                        setCellAlive(row, col);
                    }
                    else if (livingNeighbours > 3) // ma viac ako 3 susedov, zomiera
                    {
                        setCellDead(row, col);
                    }
                }
                else // she dead
                {
                    if (livingNeighbours == 3)
                    {
                        setCellAlive(row, col);
                    }
                }
            }
        }
        copyToBuffer();
    }

    void GameOfLife::copyToBuffer()
    {
        // Copy active to buffer
        for (int col = 0; col < asciid::Display::getColumnCount(); col++)
        {
            for (int row = 0; row < asciid::Display::getRowCount(); row++)
            {
                if (m_new_display->isPixelOn(row, col))
                {
                    m_old_display->turnPixelOn(row, col);
                }
                else
                {
                    m_old_display->turnPixelOff(row, col);
                }
            }
        }
    }


    void GameOfLife::run(int tickCount)
    {
        for (int i = 0; i < tickCount; ++i)
        {
            tick();
            prinState();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }

    int GameOfLife::calculateLivingNeighbours(int row, int col) const
    {
        int count = 0;
        for (int x = row - 1; x <= row + 1; ++x)
        {
            for (int y = col - 1; y <= col + 1; ++y)
            {
                if (x == row && y == col)
                {
                    continue;
                }
                if (cellExists(x, y) && isCellAlive(x, y))
                {
                    count++;
                }
            }
        }
        return count;
    }

    bool GameOfLife::isCellAlive(int row, int col) const
    {
        return m_old_display->isPixelOn(row, col);
    }

    GameOfLife *GameOfLife::createDieHard()
    {
        GameOfLife *game = new GameOfLife();
        game->setCellAlive(1, 1);
        game->setCellAlive(1, 0);
        game->setCellAlive(2, 1);
        game->setCellAlive(0, 6);
        game->setCellAlive(2, 5);
        game->setCellAlive(2, 6);
        game->setCellAlive(2, 7);
        game->copyToBuffer();
        return game;
    }

    GameOfLife *GameOfLife::createToad()
    {
        GameOfLife *game = new GameOfLife();
        game->setCellAlive(0, 1);
        game->setCellAlive(0, 2);
        game->setCellAlive(0, 3);
        game->setCellAlive(1, 0);
        game->setCellAlive(1, 1);
        game->setCellAlive(1, 2);
        game->copyToBuffer();
        return game;
    }

    void GameOfLife::prinState() const
    {
        asciid::Terminal::clear();
        m_old_display->printLn();
    }

}
