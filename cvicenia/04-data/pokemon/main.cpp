//
// Created by david on 12/1/2025.
//

#include "pokemon.hpp"

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    auto pokemonLoader = pokemon::PokemonLoader();

    auto pokemonDataFrame = df::DataFrame<pokemon::Pokemon>(pokemonLoader.load("C:\\Users\\david\\Documents\\GitHub\\informatika3\\cvicenia\\04-data\\data\\pokedex.json"));


    pokemon::Pokedex pokedex = pokemon::Pokedex(pokemonDataFrame);

    pokedex.printNames();
    return 0;
}
