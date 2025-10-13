#ifndef GOL_GAME_OF_LIFE_HPP
#define GOL_GAME_OF_LIFE_HPP
#include "display.hpp"

namespace gol
{
    class GameOfLife
    {
        public:
            GameOfLife();
            ~GameOfLife();
            bool cellExists(int row, int col) const;
            void setCellAlive(int row, int col);
            void tick();
            void run(int tickCount);
            void prinState() const;
            static GameOfLife *createToad();
            static GameOfLife *createDieHard();
        private:
            void copyToBuffer();
            int calculateLivingNeighbours(int row, int col) const;
            bool isCellAlive(int row, int col) const;
            void internalSetCellDead(int row, int col);
            void internalSetCellAlive(int row, int col);
            asciid::Display *m_new_display;
            asciid::Display *m_old_display;
    };
}

#endif //INFORMATIKA3_GAME_OF_LIFE_HPP