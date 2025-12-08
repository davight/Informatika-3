#include "pokedex.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[]) {

    SetConsoleOutputCP(CP_UTF8);
    //PokemonType types2[] = {Bug, Dragon};
    //Pokemon pokemon2 = {"aaa", 12.32, 1.22, 2, types2};

    Pokemon pokemon;
    pokemonInit(&pokemon);
    pokemonSetName(&pokemon, "kkt");
    pokemonSetWeight(&pokemon, 100.123);
    pokemonSetHeight(&pokemon, 20.05);
    PokemonType types[] = {Bug};
    pokemonSetTypes(&pokemon, 1, types);

    pokemonPrint(&pokemon, stdout);
    //pokemonPrint(&pokemon2, stdout);

    pokemonDestroy(&pokemon);
    //pokemonDestroy(&pokemon2);


    if (argc < 2) {
        fputs("Provide path to pokedex.txt", stderr);
        return EXIT_FAILURE;
    }
    Pokedex pokedex;
    pokedexInit(&pokedex);
    pokedexLoad(&pokedex, argv[1]);
    pokedexPrintAll(&pokedex, stdout);
    pokedexPrintByType(&pokedex, stdout);
    pokedexDestroy(&pokedex);
    return EXIT_SUCCESS;
}
