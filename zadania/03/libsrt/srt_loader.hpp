//
// Created by david on 12/17/2025.
//

#ifndef DATA_PROCESSOR_SRT_LOADER_HPP
#define DATA_PROCESSOR_SRT_LOADER_HPP
#include "subtitles.hpp"
#include "../libdf/loader.hpp"

namespace srt
{
    class SrtLoader : public df::Loader<Subtitles> {
        public:
            df::DataFrame<Subtitles> load(const std::filesystem::path &path) override;
        private:
            static Subtitles parseSubtitles(const std::vector<std::string> &segment);
    };
}

#endif //DATA_PROCESSOR_SRT_LOADER_HPP