#ifndef SRC_POKEMON_H
#define SRC_POKEMON_H

#include <stdio.h>

typedef enum {
    Bug,
    Dragon,
    Electric,
    Fighting,
    Fire,
    Flying,
    Ghost,
    Grass,
    Ground,
    Ice,
    Normal,
    Poison,
    Psychic,
    Rock,
    Water,
    PokemonTypeCount
} PokemonType;

const char *pokemonTypeToStr(PokemonType type);

PokemonType strToPokemonType(const char *str);


typedef struct {
    char *name;
    float weight;
    float height;
    int typeCount;
    PokemonType *types;
} Pokemon;

void pokemonInit(Pokemon *self);

void pokemonSetName(Pokemon *self, const char *name);

void pokemonSetWeight(Pokemon *self, float weight);

void pokemonSetHeight(Pokemon *self, float height);

void pokemonSetTypes(Pokemon *self, int typeCount, PokemonType *types);

void pokemonPrint(Pokemon *self, FILE *out);

void pokemonDestroy(Pokemon *self);

#endif
