//
// Created by david on 12/17/2025.
//

#ifndef DATA_PROCESSOR_JSON_WRITER_HPP
#define DATA_PROCESSOR_JSON_WRITER_HPP
#include "writer.hpp"
#include <nlohmann/json.hpp>

namespace df
{
    template<typename T>
    class JSONWriter : public Writer<T> {
        protected:
            void writeImpl(const DataFrame<T> &df, std::ostream &ost) override;
            virtual nlohmann::json toJSON(const T &record) = 0;
    };

    template<typename T>
    void JSONWriter<T>::writeImpl(const DataFrame<T> &df, std::ostream &ost)
    {
        auto json = nlohmann::json::array();

        df.apply([&json, this](const T &t) -> void
        {
            json.push_back(toJSON(t));
        });

        ost << json;
    }

}

#endif //DATA_PROCESSOR_JSON_WRITER_HPP
