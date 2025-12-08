add_executable(pokemons)

target_sources(pokemons PRIVATE main.c pokedex.c pokemon.c)

target_compile_options(pokemons PRIVATE -std=c11 -Wall -Wextra -Wpedantic)
