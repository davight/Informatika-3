//
// Created by david on 10/25/2025.
//

#ifndef SETVIS_SET_VISUALIZER_HPP
#define SETVIS_SET_VISUALIZER_HPP
#include <cstdint>

#include "matrix.hpp"

namespace setvis
{
    using namespace std;

    class SetVisualizer {
        public:
            SetVisualizer() = default;
            ~SetVisualizer() = default;
            uint64_t calcIntersection(uint64_t a, uint64_t b);
            uint64_t calcUnion(uint64_t a, uint64_t b);
            uint64_t calcDifference(uint64_t a, uint64_t b);
            uint64_t calcComplement(uint64_t a);
            void showIntersection(uint64_t a, uint64_t b);
            void showUnion(uint64_t a, uint64_t b);
            void showDifference(uint64_t a, uint64_t b);
            void showComplement(uint64_t a);
        private:
            void show(set_vis::Matrix mA, set_vis::Matrix mB, set_vis::Matrix mC);
    };
}

#endif //SETVIS_SET_VISUALIZER_HPP