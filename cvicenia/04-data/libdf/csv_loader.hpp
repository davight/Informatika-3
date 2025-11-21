#ifndef LIBDF_CSV_LOADER_HPP
#define LIBDF_CSV_LOADER_HPP
#include <filesystem>

#include <csv.hpp>

#include "csv_config.hpp"
#include "loader.hpp"

namespace df {

    template<typename T>
    class CSVLoader : public Loader<T> {
        public:
            CSVLoader(CSVConfig config);
            DataFrame<T> load(const std::filesystem::path &path) override;
            virtual T create(const csv::CSVRow &row) = 0;
        private:
            CSVConfig m_config;
    };

    template<typename T>
    CSVLoader<T>::CSVLoader(CSVConfig config) : m_config(config)
    {
    }

    template<typename T>
    DataFrame<T> CSVLoader<T>::load(const std::filesystem::path &path)
    {
        csv::CSVFormat format = csv::CSVFormat();
        format.delimiter(m_config.getDelimiter());
        csv::CSVReader reader = csv::CSVReader(path.string(), format);
        std::vector<T> result;
        result.reserve(reader.n_rows());
        for (const csv::CSVRow &row : reader)
        {
            result.push_back(create(row));
        }
        return DataFrame<T>(std::move(result));
    }


} // namespace df

#endif
