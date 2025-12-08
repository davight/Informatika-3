#include "pokedex.h"
#include "pokemon.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void pokemonNodeInit(PokemonNode *self) {
    memset(self, 0, sizeof(PokemonNode));
}

void pokemonNodeSetNext(PokemonNode *self, PokemonNode *next) {
    self->next = next;
}

void pokemonNodeSetPokemon(PokemonNode *self, Pokemon *pokemon) {
    self->pokemon = pokemon;
}

void pokemonNodeDestroy(PokemonNode *self) {
    if (self->next) {
        pokemonNodeDestroy(self->next);
    }
    free(self);
}

static void loadPokemons(Pokedex *self, FILE *f) {
    fscanf(f, "%d\n", &self->pokemonCount);
    self->pokemons =  malloc(self->pokemonCount * sizeof(Pokemon));
    for (Pokemon* i = self->pokemons; i < self->pokemons + self->pokemonCount; ++i)
    {
        pokemonInit(i);

        char buffer[1024];
        fscanf(f, "%s", buffer);
        pokemonSetName(i, buffer);
        float weight;
        float height;
        fscanf(f, "%f %f", &weight, &height);
        pokemonSetWeight(i, weight);
        pokemonSetHeight(i, height);

        int typeCount;
        fscanf(f, "%d", &typeCount);
        PokemonType* types = malloc(typeCount * sizeof(PokemonType));

        for (int j = 0; j < typeCount; j++)
        {
            fscanf(f, "%s", buffer);
            types[j] = strToPokemonType(buffer);
        }
        pokemonSetTypes(i, typeCount, types);
        free(types);
        // nazov
        // hmotnost a vyska
        // typy

    }
}


static void buildTypeIndex(Pokedex *self) {
    for (Pokemon *pokemon = self->pokemons; pokemon < self->pokemons + self->pokemonCount; ++pokemon)
    {
        for (PokemonType *type = pokemon->types; type < pokemon->types + pokemon->typeCount; ++type)
        {
            PokemonNode *node = malloc(sizeof(PokemonNode));
            pokemonNodeInit(node);
            pokemonNodeSetPokemon(node, pokemon);
            pokemonNodeSetNext(node, self->types[*type]);
            self->types[*type] = node;
        }
    }
}


void pokedexInit(Pokedex *self) {
    memset(self, 0, sizeof(Pokedex));
}


void pokedexLoad(Pokedex *self, const char *path) {
    FILE *f = fopen(path, "r");
    if (f == NULL)
    {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    loadPokemons(self, f);
    buildTypeIndex(self);
    fclose(f);
}


void pokedexPrintAll(Pokedex *self, FILE *out) {
    fprintf(out, "Pokedex has %d pokemon! \n ", self->pokemonCount);
    for (Pokemon* i = self->pokemons; i < self->pokemons + self->pokemonCount; ++i)
    {
        pokemonPrint(i, out);
    }
}


void pokedexPrintByType(Pokedex *self, FILE *out) {
    for (int i = 0; i < PokemonTypeCount; ++i)
    {
        fprintf(out, "%s: \n", pokemonTypeToStr(i));
        PokemonNode *node = self->types[i];
        while (node != NULL)
        {
            fprintf(out, "%s%s", node->pokemon->name, node->next != NULL ? "," : "\n");
            node = node->next;
        }
        fputs("\n", out);
    }
}


void pokedexDestroy(Pokedex *self) {
    for (Pokemon* i = self->pokemons; i < self->pokemons + self->pokemonCount; ++i)
    {
        pokemonDestroy(i);
    }
    free(self->pokemons);
    for (PokemonNode** node = self->types; node < self->types + PokemonTypeCount; ++node)
    {
        pokemonNodeDestroy(*node);
    }
}
