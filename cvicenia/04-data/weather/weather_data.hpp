#ifndef WEATHER_WEATHER_DATA_HPP
#define WEATHER_WEATHER_DATA_HPP
#include <chrono>
#include <string>

#include "libdf/csv_loader.hpp"

namespace weather {

    struct WeatherRecord {
        std::string city;
        std::chrono::year_month_day date;
        float tempMin;
        float tempMax;
        float temp0700;
        float temp1400;
        float temp2100;
        int elevation;
    };

    class WeatherLoader : public df::CSVLoader<WeatherRecord> {
        public:
            using BaseClass = df::CSVLoader<WeatherRecord>;
            WeatherLoader(df::CSVConfig config);
            WeatherRecord create(const csv::CSVRow &row) override;
    };

} // namespace weather

#endif
