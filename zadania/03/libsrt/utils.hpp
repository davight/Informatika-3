//
// Created by david on 12/17/2025.
//

#ifndef DATA_PROCESSOR_UTILS_HPP
#define DATA_PROCESSOR_UTILS_HPP
#include <chrono>
#include <string_view>

namespace srt
{
    namespace utils
    {
        class Utils {
            public:
                static std::chrono::milliseconds strToMs(std::string_view str);
                static std::string msToStr(std::chrono::milliseconds ms);
        };
    }
}

#endif //DATA_PROCESSOR_UTILS_HPP