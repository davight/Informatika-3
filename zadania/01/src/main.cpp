#include <cstdint>
#include <iostream>

#include "matrix.hpp"
#include "set_visualizer.hpp"

int main()
{
    const std::uint64_t a = 0x0F0F0F0F0F0F0F0F;
    const std::uint64_t b = 0xFFFFFFFF00000000;

    setvis::SetVisualizer *sv = new setvis::SetVisualizer();

    auto *intersection = new set_vis::Matrix(sv->calcIntersection(a, b));
    auto *union_ = new set_vis::Matrix(sv->calcUnion(a, b));
    auto *difference = new set_vis::Matrix(sv->calcDifference(a, b));
    auto *complement = new set_vis::Matrix(sv->calcComplement(a));

    std::cout << "Intersection: \n" << std::endl;
    sv->showIntersection(a, b);
    std::cout << "Union: \n" << std::endl;
    sv->showUnion(a, b);
    std::cout << "Difference: \n" << std::endl;
    sv->showDifference(a, b);
    std::cout << "Complement: \n" << std::endl;
    sv->showComplement(a);

    return 0;

    std::cout << "intersection: \n" << std::endl;
    intersection->print();
    std::cout << "\n";
    std::cout << "union: \n" << std::endl;
    union_->print();
    std::cout << "\n";
    std::cout << "difference: \n" << std::endl;
    difference->print();
    std::cout << "\n";
    std::cout << "complement: \n" << std::endl;
    complement->print();
}
