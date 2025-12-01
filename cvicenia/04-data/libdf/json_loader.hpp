//
// Created by david on 12/1/2025.
//
#ifndef LIBDF_JSON_LOADER_HPP
#define LIBDF_JSON_LOADER_HPP

#include <nlohmann/json.hpp>
#include "loader.hpp"

namespace df
{
    template <typename T>
    class JSONLoader : public Loader<T> {
        DataFrame<T> load(const std::filesystem::path &path) override;
        virtual T createData(const nlohmann::json &node) = 0;
    };

    template<typename T>
    DataFrame<T> JSONLoader<T>::load(const std::filesystem::path &path)
    {
        return nullptr;
    }



}



#endif //LIBDF_JSON_LOADER_HPP
