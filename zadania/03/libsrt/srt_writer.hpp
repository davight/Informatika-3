//
// Created by david on 12/17/2025.
//

#ifndef DATA_PROCESSOR_SRT_WRITER_HPP
#define DATA_PROCESSOR_SRT_WRITER_HPP
#include "subtitles.hpp"
#include "../libdf/json_writer.hpp"
#include "../libdf/writer.hpp"


namespace srt
{
    class NativeSrtWriter : public df::Writer<Subtitles> {
        protected:
            void writeImpl(const df::DataFrame<Subtitles> &df, std::ostream &ost) override;
    };

    class JSONSrtWriter : public df::JSONWriter<Subtitles> {
        protected:
            nlohmann::json toJSON(const Subtitles &record) override;
    };
}

#endif //DATA_PROCESSOR_SRT_WRITER_HPP