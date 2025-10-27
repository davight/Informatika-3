//
// Created by david on 10/25/2025.
//

#include "matrix.hpp"

#include <iostream>
#include <stdexcept>

namespace set_vis
{
    Matrix::Matrix() : m_matrix(0)
    {
    }

    Matrix::Matrix(std::uint64_t value) : m_matrix(value)
    {
    }

    bool Matrix::getValue(std::uint8_t row, std::uint8_t column) const
    {
        boundCheckExcept(row, column);
        return internalGetValue(row, column);
    }

    void Matrix::flipValue(std::uint8_t row, std::uint8_t column)
    {
        boundCheckExcept(row, column);
        m_matrix ^= (m_mask << (row * 8 + column));
    }


    void Matrix::setValue(std::uint8_t row, std::uint8_t column, bool value)
    {
        boundCheckExcept(row, column);
        if (value)
        {
            m_matrix |= (m_mask << (row * 8 + column));
        }
        else
        {
            m_matrix &= ~(m_mask << (row * 8 + column));
        }
    }

    std::uint64_t Matrix::getMatrix() const
    {
        return m_matrix;
    }


    void Matrix::print() const
    {
        for (std::uint8_t i = 0; i < 8; i++)
        {
            for (std::uint8_t j = 0; j < 8; j++)
            {
                std::cout << getValue(i, j) << " ";
            }
            std::cout << "\n";
        }
    }

    bool Matrix::internalGetValue(std::uint8_t row, std::uint8_t col) const
    {
        return m_matrix & (m_mask << (row * 8 + col));
    }


    void Matrix::boundCheckExcept(std::uint8_t row, std::uint8_t column)
    {
        if (row > 8 || column > 8) // theyre unsigned so no need to check for negative numbers
        {
            throw std::out_of_range("Index out of range");
        }
    }

}
