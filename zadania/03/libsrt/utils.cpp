//
// Created by david on 12/17/2025.
//

#include "utils.hpp"

#include <cstdio>
#include <string>

namespace srt
{
    namespace utils
    {
        std::string msToStr(std::chrono::milliseconds chronoms)
        {
            long long count = chronoms.count();

            int ms = count % 1000; // sekunda = 1000ms
            count /= 1000;
            int sec = count % 60; // minuta = 60s
            count /= 60;
            int min = count % 60; // hodina = 60m
            count /= 60;
            int hod = static_cast<int>(count);


            char buffer[16]; // hh:mm:ss,ms
            snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d,%03d", hod, min, sec, ms);
            return buffer;
        }

        std::chrono::milliseconds strToMs(std::string_view str)
        {
            int hod = std::stoi(std::string(str.substr(0, 2)));
            int min = std::stoi(std::string(str.substr(3, 2)));
            int sec = std::stoi(std::string(str.substr(6, 2)));
            int ms = std::stoi(std::string(str.substr(9, 3)));
            return std::chrono::milliseconds(((hod * 60 + min) * 60 + sec) * 1000 + ms);
        }

    }
} // srt