add_executable(zadanie1)

target_sources(zadanie1 PUBLIC set_visualizer.cpp display.cpp display_row.cpp main.cpp terminal.cpp matrix.cpp)

target_compile_options(zadanie1 PUBLIC -Wall -Wextra -Wpedantic -std=c++20 -g)