add_executable(weather)

target_sources(weather PRIVATE main.cpp weather_data.cpp)

target_compile_options(weather PRIVATE -Wall -Wextra -Wpedantic)

target_link_libraries(weather PRIVATE df uiutils)