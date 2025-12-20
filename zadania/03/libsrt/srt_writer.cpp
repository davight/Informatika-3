//
// Created by david on 12/17/2025.
//

#include "srt_writer.hpp"

#include "utils.hpp"
#include "nlohmann/json.hpp"
#include "nlohmann/json_fwd.hpp"

namespace srt
{
    nlohmann::json JSONSrtWriter::toJSON(const Subtitles &record)
    {
        nlohmann::json json;
        json["id"] = record.id;
        json["text"] = record.text;
        json["from"] = utils::msToStr(record.from);
        json["to"] = utils::msToStr(record.to);
        return json;
    }

    void NativeSrtWriter::writeImpl(const df::DataFrame<Subtitles> &df, std::ostream &ost)
    {
        df.apply([&ost](const Subtitles &sub) -> void
        {
            ost << std::to_string(sub.id) << "\n";
            ost << utils::msToStr(sub.from) << " --> " << utils::msToStr(sub.to) << "\n";
            ost << sub.text;

            ost << "\n";
        });
    }


}
