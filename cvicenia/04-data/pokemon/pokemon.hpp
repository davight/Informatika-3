//
// Created by david on 12/1/2025.
//

#ifndef DATA_PROCESSOR_POKEMON_HPP
#define DATA_PROCESSOR_POKEMON_HPP
#include <string>
#include <vector>

#include "../libdf/data_frame.hpp"
#include "../libdf/json_loader.hpp"

namespace pokemon
{
    enum class PokemonType {
        Bug, Dragon, Electric, Fighting, Fire,
        Flying, Ghost, Grass, Ground, Ice,
        Normal, Poison, Psychic, Rock, Water
    };

    struct Pokemon {
        std::pmr::string num;
        std::pmr::string name;
        float height;
        float weight;
        std::vector<PokemonType> type;
        std::vector<std::string> nextEvolution;

        static PokemonType parseType(const std::string& type)
        {
            if (type == "Bug") return PokemonType::Bug;
            if (type == "Dragon") return PokemonType::Dragon;
            if (type == "Electric") return PokemonType::Electric;
            if (type == "Fighting") return PokemonType::Fighting;
            if (type == "Fire") return PokemonType::Fire;
            if (type == "Flying") return PokemonType::Flying;
            if (type == "Ghost") return PokemonType::Ghost;
            if (type == "Grass") return PokemonType::Grass;
            if (type == "Ground") return PokemonType::Ground;
            if (type == "Ice") return PokemonType::Ice;
            if (type == "Normal") return PokemonType::Normal;
            if (type == "Poison") return PokemonType::Poison;
            if (type == "Psychic") return PokemonType::Psychic;
            if (type == "Rock") return PokemonType::Rock;
            if (type == "Water") return PokemonType::Water;
            throw std::runtime_error("Unknown pokemon type: " + type); // nemalo by nastat
        }
    };

    class Pokedex {
        public:
            Pokedex(df::DataFrame<Pokemon> pokemons);
            void printNames() const;
            void printEvolutions() const;
            float calculateAverageHeight();
            float calculateAverageWeight();
            std::vector<const Pokemon *> getByType(PokemonType type);
        private:
            df::DataFrame<Pokemon> m_pokemons;
    };

    class PokemonLoader : public df::JSONLoader<Pokemon> {
        public:
            using BaseClass = df::JSONLoader<Pokemon>;
            Pokemon createData(const nlohmann::json &node) override;
    };

}


#endif //DATA_PROCESSOR_POKEMON_HPP
