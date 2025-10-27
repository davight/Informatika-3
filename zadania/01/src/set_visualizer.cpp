//
// Created by david on 10/25/2025.
//

#include "set_visualizer.hpp"

#include "matrix.hpp"
#include "../../../cvicenia/02/src/display.hpp"

namespace setvis
{
    SetVisualizer::SetVisualizer()
    {
    }

    SetVisualizer::~SetVisualizer()
    {
    }

    uint64_t SetVisualizer::calcIntersection(uint64_t a, uint64_t b)
    {
        const auto mA = new set_vis::Matrix(a);
        const auto mB = new set_vis::Matrix(b);
        const auto mC = new set_vis::Matrix();

        for (std::uint8_t i = 0; i < 8; i++)
        {
            for (std::uint8_t j = 0; j < 8; j++)
            {
                if (mA->getValue(i, j) && mB->getValue(i, j))
                {
                    mC->setValue(i, j, true);
                }
            }
        }

        return mC->getMatrix();
    }

    uint64_t SetVisualizer::calcUnion(uint64_t a, uint64_t b)
    {
        const auto mA = new set_vis::Matrix(a);
        const auto mB = new set_vis::Matrix(b);
        const auto mC = new set_vis::Matrix();

        for (std::uint8_t i = 0; i < 8; i++)
        {
            for (std::uint8_t j = 0; j < 8; j++)
            {
                if (mA->getValue(i, j) || mB->getValue(i, j))
                {
                    mC->setValue(i, j, true);
                }
            }
        }

        return mC->getMatrix();
    }

    uint64_t SetVisualizer::calcDifference(uint64_t a, uint64_t b)
    {
        const auto mA = new set_vis::Matrix(a);
        const auto mB = new set_vis::Matrix(b);
        const auto mC = new set_vis::Matrix();

        for (std::uint8_t i = 0; i < 8; i++)
        {
            for (std::uint8_t j = 0; j < 8; j++)
            {
                const bool mAval = mA->getValue(i, j);
                const bool mBval = mB->getValue(i, j);
                mC->setValue(i, j, mAval && !mBval);
            }
        }

        return mC->getMatrix();
    }

    uint64_t SetVisualizer::calcComplement(uint64_t a)
    {
        const auto mA = new set_vis::Matrix(a);
        const auto mC = new set_vis::Matrix();

        for (std::uint8_t i = 0; i < 8; i++)
        {
            for (std::uint8_t j = 0; j < 8; j++)
            {
                mC->setValue(i, j, !mA->getValue(i, j));
            }
        }

        return mC->getMatrix();
    }

    void SetVisualizer::showIntersection(uint64_t a, uint64_t b)
    {
        show(new set_vis::Matrix(a),
            new set_vis::Matrix(b),
            new set_vis::Matrix(calcIntersection(a, b)));
    }

    void SetVisualizer::showUnion(uint64_t a, uint64_t b)
    {
        show(new set_vis::Matrix(a),
            new set_vis::Matrix(b),
            new set_vis::Matrix(calcUnion(a, b)));
    }

    void SetVisualizer::showDifference(uint64_t a, uint64_t b)
    {
        show(new set_vis::Matrix(a),
            new set_vis::Matrix(b),
            new set_vis::Matrix(calcDifference(a, b)));
    }

    void SetVisualizer::showComplement(uint64_t a)
    {
        // need different logic
        auto *mA = new set_vis::Matrix(a);
        auto *display = new asciid::Display();

        for (std::uint8_t i = 0; i < 8; i++)
        {
            for (std::uint8_t j = 0; j < 8; j++)
            {
                display->turnPixelOn(i, j);
                display->setPixelColor(i, j, mA->getValue(i, j) ? asciid::Color::White : asciid::Color::Red);
            }
        }
        display->printLn();
    }

    void SetVisualizer::show(set_vis::Matrix *mA, set_vis::Matrix *mB, set_vis::Matrix *mC)
    {
        auto *display = new asciid::Display();

        for (std::uint8_t i = 0; i < 8; i++)
        {
            for (std::uint8_t j = 0; j < 8; j++)
            {
                if (mC->getValue(i, j))
                {
                    display->turnPixelOn(i, j);
                    display->setPixelColor(i, j, asciid::Color::Red);
                }
                else if (mA->getValue(i, j) || mB->getValue(i, j))
                {
                    display->turnPixelOn(i, j);
                    display->setPixelColor(i, j, asciid::Color::White);
                }
            }
        }
        display->printLn();
    }

}
