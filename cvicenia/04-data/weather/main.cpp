#include "weather_data.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
    (void)argc;
    (void)argv;

    auto cfg = df::CSVConfig::createFromParams(';');
    auto weatherLoader = weather::WeatherLoader(cfg);
    auto weatherDataFrame = df::DataFrame<weather::WeatherRecord>(weatherLoader.load("../data/shmu-may-2025.csv"));

    weatherDataFrame.print(std::cout);

    return 0;
}
