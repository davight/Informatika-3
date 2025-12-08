#ifndef SRC_POKEDEX_H
#define SRC_POKEDEX_H

#include "pokemon.h"


typedef struct PokemonNode {
    struct PokemonNode *next;
    Pokemon *pokemon;
} PokemonNode;

void pokemonNodeInit(PokemonNode *self);

void pokemonNodeSetNext(PokemonNode *self, PokemonNode *next);

void pokemonNodeSetPokemon(PokemonNode *self, Pokemon *pokemon);

void pokemonNodeDestroy(PokemonNode *self);


typedef struct {
    int pokemonCount;
    Pokemon *pokemons;
    PokemonNode *types[PokemonTypeCount];
} Pokedex;

void pokedexInit(Pokedex *self);

void pokedexLoad(Pokedex *self, const char *path);

void pokedexPrintAll(Pokedex *self, FILE *out);

void pokedexPrintByType(Pokedex *self, FILE *out);

void pokedexDestroy(Pokedex *self);

#endif
