//
// Created by david on 10/25/2025.
//

#include "set_visualizer.hpp"

#include "matrix.hpp"
#include "display.hpp"

namespace setvis
{

    uint64_t SetVisualizer::calcIntersection(uint64_t a, uint64_t b)
    {
        return a & b;
    }

    uint64_t SetVisualizer::calcUnion(uint64_t a, uint64_t b)
    {
        return a | b;
    }

    uint64_t SetVisualizer::calcDifference(uint64_t a, uint64_t b)
    {
        return a & (~b);
    }

    uint64_t SetVisualizer::calcComplement(uint64_t a)
    {
        return ~a;
    }

    void SetVisualizer::showIntersection(uint64_t a, uint64_t b)
    {
        show(set_vis::Matrix(a),
            set_vis::Matrix(b),
            set_vis::Matrix(calcIntersection(a, b)));
    }

    void SetVisualizer::showUnion(uint64_t a, uint64_t b)
    {
        show(set_vis::Matrix(a),
            set_vis::Matrix(b),
            set_vis::Matrix(calcUnion(a, b)));
    }

    void SetVisualizer::showDifference(uint64_t a, uint64_t b)
    {
        show(set_vis::Matrix(a),
            set_vis::Matrix(b),
            set_vis::Matrix(calcDifference(a, b)));
    }

    void SetVisualizer::showComplement(uint64_t a)
    {
        // need different logic
        auto mA = set_vis::Matrix(a);
        auto display = asciid::Display();

        for (std::uint8_t i = 0; i < 8; i++)
        {
            for (std::uint8_t j = 0; j < 8; j++)
            {
                display.turnPixelOn(i, j);
                display.setPixelColor(i, j, mA.getValue(i, j) ? asciid::Color::White : asciid::Color::Red);
            }
        }
        display.printLn();
    }

    void SetVisualizer::show(set_vis::Matrix mA, set_vis::Matrix mB, set_vis::Matrix mC)
    {
        auto display = asciid::Display();

        for (std::uint8_t i = 0; i < 8; i++)
        {
            for (std::uint8_t j = 0; j < 8; j++)
            {
                if (mC.getValue(i, j))
                {
                    display.turnPixelOn(i, j);
                    display.setPixelColor(i, j, asciid::Color::Red);
                }
                else if (mA.getValue(i, j) || mB.getValue(i, j))
                {
                    display.turnPixelOn(i, j);
                    display.setPixelColor(i, j, asciid::Color::White);
                }
            }
        }
        display.printLn();
    }

}
