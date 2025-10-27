
#ifndef SETVIS_MATRIX_HPP
#define SETVIS_MATRIX_HPP
#include <cstdint>


namespace set_vis
{
    class Matrix {
        public:
            explicit Matrix(std::uint64_t value);
            explicit Matrix(); // makes empty matrix
            ~Matrix() = default;
            static const int SIZE = 64;
            bool getValue(std::uint8_t row, std::uint8_t column) const;
            void setValue(std::uint8_t row, std::uint8_t column, bool value); // 0 or 1
            void flipValue(std::uint8_t row, std::uint8_t column);
            std::uint64_t getMatrix() const;
            void print() const;
        private:
            bool internalGetValue(std::uint8_t row, std::uint8_t col) const;
            static void boundCheckExcept(std::uint8_t row, std::uint8_t column);
            std::uint64_t m_matrix;
            static const std::uint64_t m_mask = 1ULL;
    };
}

#endif //INFORMATIKA3_MATRIX_HPP
