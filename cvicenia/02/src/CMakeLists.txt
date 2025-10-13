add_executable(asciid)

target_sources(asciid PUBLIC display_row.cpp main.cpp terminal.cpp heap_monitor.cpp display.cpp filters.cpp game_of_life.cpp)

target_compile_options(asciid PUBLIC -Wall -Wextra -Wpedantic -std=c++20 -g)
