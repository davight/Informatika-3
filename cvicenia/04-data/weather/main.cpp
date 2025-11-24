#include "weather_data.hpp"
#include <iostream>
#include <windows.h>

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;
    SetConsoleOutputCP(CP_UTF8);

    auto cfg = df::CSVConfig::createFromParams(';');
    auto weatherLoader = weather::WeatherLoader(cfg);
    auto weatherDataFrame = df::DataFrame<weather::WeatherRecord>(weatherLoader.load("../data/shmu-may-2025.csv"));

    weatherDataFrame.print(std::cout);

    const weather::WeatherRecord *tempMinR = weatherDataFrame.min(weather::WRTempMinExtractor());
    std::cout << "Min temp: " << tempMinR->tempMin << " " << tempMinR->city << std::endl;

    const weather::WeatherRecord *tempMaxR = weatherDataFrame.max(weather::WRTempMinExtractor());
    std::cout << "Max temp: " << tempMaxR->tempMin << " " << tempMaxR->city << std::endl;

    auto filterFreezing = weatherDataFrame.filter(weather::FreezingFilter());
    std::cout << "Freezing temperatures: " << filterFreezing.size() << std::endl;

    auto filterBlbosti = weatherDataFrame.filter([](const weather::WeatherRecord &record)
    {
        return record.tempMax < 0;
    });

    for (auto &record : filterBlbosti)
    {
        std::cout << record->city << " " << record->tempMax << "°C " << record->elevation << "mnm." << std::endl;
    }


    auto mean = weatherDataFrame.mean<float>(weather::WRElevationExtractor());
    std::cout << "Mean: " << mean << std::endl;
    return 0;
}
