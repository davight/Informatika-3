add_library(df INTERFACE)

target_include_directories(df INTERFACE ..)

target_compile_options(df INTERFACE -Wall -Wextra -Wpedantic)
target_compile_options(df INTERFACE -std=c++20)

target_link_libraries(df INTERFACE nlohmann_json::nlohmann_json csv gcov)
