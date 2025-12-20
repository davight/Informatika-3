//
// Created by david on 12/17/2025.
//

#ifndef DATA_PROCESSOR_SRT_PROCESSOR_HPP
#define DATA_PROCESSOR_SRT_PROCESSOR_HPP
#include <filesystem>

#include "subtitles.hpp"
#include "../libdf/data_frame.hpp"

namespace srt
{
    class SrtProcessor {
        public:
            SrtProcessor();

            template<typename Loader>
            void load(Loader &loader, const std::filesystem::path &path);

            template<typename Writer>
            void write(Writer &writer, const std::filesystem::path &path);

            template<typename Duration>
            void offset(Duration offset);
        private:
            df::DataFrame<Subtitles> m_subtitles;
    };

    SrtProcessor::SrtProcessor() : m_subtitles(std::vector<Subtitles>())
    {
    }


    template<typename Loader>
    void SrtProcessor::load(Loader &loader, const std::filesystem::path &path)
    {
        m_subtitles = loader.load(path);
    }

    template<typename Writer>
    void SrtProcessor::write(Writer &writer, const std::filesystem::path &path)
    {
        writer.write(m_subtitles, path);
    }

    template<typename Duration>
    void SrtProcessor::offset(Duration offset)
    {
        m_subtitles.transform([&offset](Subtitles &sub)
        {
            sub.from += offset;
            sub.to += offset;
        });
    }


}

#endif //DATA_PROCESSOR_SRT_PROCESSOR_HPP