#include "weather_data.hpp"

#include "uiutils/ui_utils.hpp"

namespace weather {

    WeatherLoader::WeatherLoader(df::CSVConfig config) : BaseClass(config)
    {
    }

    WeatherRecord WeatherLoader::create(const csv::CSVRow &row)
    {
        auto result = WeatherRecord();
        result.city = row["mesto"].get<std::string>();
        result.tempMin= row["t_min"].get<float>();
        result.tempMax = row["t_max"].get<float>();
        result.temp0700 = row["t_0700"].get<float>();
        result.temp1400 = row["t_1400"].get<float>();
        result.temp2100 = row["t_2100"].get<float>();
        result.elevation = row["nadmorska_vyska"].get<int>();
        if (std::optional<std::chrono::year_month_day> dateOpt = uiutils::parseDate(row["datum"].get<std::string>()))
        {
            result.date = *dateOpt;
        }
        return result;
    }



} // namespace weather
