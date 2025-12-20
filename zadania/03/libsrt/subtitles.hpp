//
// Created by david on 12/17/2025.
//

#ifndef DATA_PROCESSOR_SUBTITLES_HPP
#define DATA_PROCESSOR_SUBTITLES_HPP
#include <chrono>
#include <string>

namespace srt
{
    struct Subtitles {
        int id;
        std::chrono::milliseconds from;
        std::chrono::milliseconds to;
        std::string text;
    };
}

#endif //DATA_PROCESSOR_SUBTITLES_HPP