#include "pokemon.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *pokemonTypeToStr(PokemonType type) {
    static const char *NAMES[] = {
        "Bug",
        "Dragon",
        "Electric",
        "Fighting",
        "Fire",
        "Flying",
        "Ghost",
        "Grass",
        "Ground",
        "Ice",
        "Normal",
        "Poison",
        "Psychic",
        "Rock",
        "Water"
    };
    return NAMES[type];
}


PokemonType strToPokemonType(const char *str) {
    static const struct {
        const char *str;
        PokemonType type;
    } MAPPING[] = {
        {"Bug", Bug},
        {"Dragon", Dragon},
        {"Electric", Electric},
        {"Fighting", Fighting},
        {"Fire", Fire},
        {"Flying", Flying},
        {"Ghost", Ghost},
        {"Grass", Grass},
        {"Ground", Ground},
        {"Ice", Ice},
        {"Normal", Normal},
        {"Poison", Poison},
        {"Psychic", Psychic},
        {"Rock", Rock},
        {"Water", Water}
    };
    for (int i = 0; i < PokemonTypeCount; ++i) {
        if (strcmp(str, MAPPING[i].str) == 0) {
            return MAPPING[i].type;
        }
    }
    fputs("Invalid pokemon type: ", stderr);
    fputs(str, stderr);
    fputs("\n", stderr);
    exit(EXIT_FAILURE);
}


void pokemonInit(Pokemon *self) {
    memset(self, 0, sizeof(Pokemon));
}


void pokemonSetName(Pokemon *self, const char *name) {
    self->name = realloc(self->name, strlen(name) + 1);
    strcpy(self->name, name);
}


void pokemonSetWeight(Pokemon *self, float weight) {
    self->weight = weight;
}


void pokemonSetHeight(Pokemon *self, float height) {
    self->height = height;
}


void pokemonSetTypes(Pokemon *self, int typeCount, PokemonType *types) {
    self->typeCount = typeCount;
    self->types = realloc(self->types, self->typeCount * sizeof(PokemonType));
    for (int i = 0; i < typeCount; ++i)
    {
        self->types[i] = types[i];
    }
}


void pokemonPrint(Pokemon *self, FILE *out) {
    fputs("Pokemon{ \n", out);
    fprintf(out, " name  %s\n", self->name);
    fprintf(out, " weight %.2lf ", self->weight);
    fprintf(out, " height %.2lf ", self->height);
    printf("types: ");
    for (int i = 0; i < self->typeCount; ++i)
    {
        fprintf(out, " %s", pokemonTypeToStr(self->types[i]));
        if (i != self->typeCount - 1) {
            fputc(',', out);
        }
    }
    fputs("\n}\n", out);
}


void pokemonDestroy(Pokemon *self) {
    free(self->name);
    free(self->types);
}
