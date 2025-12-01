//
// Created by david on 12/1/2025.
//
#ifndef LIBDF_JSON_LOADER_HPP
#define LIBDF_JSON_LOADER_HPP

#include <fstream>
#include <nlohmann/json.hpp>
#include "loader.hpp"

namespace df
{
    template <typename T>
    class JSONLoader : public Loader<T> {
        public:
            DataFrame<T> load(const std::filesystem::path &path) override;
            virtual T createData(const nlohmann::json &node) = 0;
    };

    template<typename T>
    DataFrame<T> JSONLoader<T>::load(const std::filesystem::path &path)
    {
        std::ifstream ifst(path);
        if (!ifst.is_open())
        {
            throw std::runtime_error("Failed to open: " + path.string());
        }
        auto json = nlohmann::json::parse(ifst);
        std::vector<T> result;
        for (auto &node : json)
        {
            result.push_back(createData(node));
        }
        return DataFrame<T>(std::move(result));
    }



}



#endif //LIBDF_JSON_LOADER_HPP
