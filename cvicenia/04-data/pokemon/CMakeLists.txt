add_executable(pokemon)

target_sources(pokemon PRIVATE main.cpp pokemon.cpp)

target_compile_options(pokemon PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(pokemon PRIVATE df uiutils)