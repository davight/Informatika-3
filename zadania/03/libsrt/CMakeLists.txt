add_library(srt STATIC)

target_include_directories(srt PUBLIC ..)

target_sources(srt PRIVATE srt_loader.cpp srt_writer.cpp utils.cpp)

target_compile_options(srt PRIVATE -Wall -Wextra -Wpedantic)
target_compile_options(srt PUBLIC -std=c++20)

target_link_libraries(srt PUBLIC nlohmann_json::nlohmann_json df uiutils)
