//
// Created by david on 12/1/2025.
//

#include "pokemon.hpp"

#include <iostream>

namespace pokemon
{

    Pokemon PokemonLoader::createData(const nlohmann::json &node)
    {
        Pokemon pokemon = Pokemon();
        pokemon.name = node["name"].get<std::string>();
        pokemon.num = node["num"].get<std::string>();

        std::string height = node["height"].get<std::string>();
        height = height.substr(0, height.size() - 2);
        pokemon.height = std::stof(height);

        std::string weight = node["weight"].get<std::string>();
        weight = weight.substr(0, weight.size() - 2);
        pokemon.weight = std::stof(weight);

        if (node.contains("type"))
        {
            for (auto type : node["type"])
            {
                pokemon.type.push_back(Pokemon::parseType(type.get<std::string>()));
            }
        }
        if (node.contains("next_evolution"))
        {
            for (auto evolution : node["next_evolution"])
            {
                pokemon.nextEvolution.push_back(evolution["name"].get<std::string>());
            }
        }

        return pokemon;
    }

    Pokedex::Pokedex(df::DataFrame<Pokemon> pokemons) : m_pokemons(pokemons)
    {
    }

    float Pokedex::calculateAverageHeight()
    {
        return m_pokemons.mean<float>([](const Pokemon &pokemon) -> float
        {
            return pokemon.height;
        });
    }

    std::vector<const Pokemon *> Pokedex::getByType(PokemonType type)
    {
        return m_pokemons.filter([type](const Pokemon &pokemon) -> bool
        {
            for (auto &t : pokemon.type)
            {
                if (type == t)
                {
                    return true;
                }
            }
            return false;
        });
    }

    float Pokedex::calculateAverageWeight()
    {
        return m_pokemons.mean<float>([](const Pokemon &pokemon) -> float
        {
            return pokemon.weight;
        });
    }

    void Pokedex::printEvolutions() const
    {
        return;
    }

    void Pokedex::printNames() const
    {
        m_pokemons.apply([](const Pokemon &pokemon) -> void
        {
            std::cout << pokemon.name << "\n";
        });
    }

}
