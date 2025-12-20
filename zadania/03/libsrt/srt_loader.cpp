//
// Created by david on 12/17/2025.
//

#include "srt_loader.hpp"

#include <fstream>

#include "utils.hpp"
#include "nlohmann/json.hpp"

namespace srt
{

    df::DataFrame<Subtitles> SrtLoader::load(const std::filesystem::path &path)
    {
        std::ifstream ifst(path);
        if (!ifst.is_open())
        {
            throw std::runtime_error("File does not exist");
        }
        std::vector<Subtitles> subs;
        std::string line;
        std::vector<std::string> segment = {};
        while (std::getline(ifst, line))
        {
            if (line.empty()) // dalsi titulok ci jak to nazvat
            {
                subs.push_back(parseSubtitles(segment));
                segment.clear();
            }
            else
            {
                segment.push_back(line);
            }
        }
        return df::DataFrame<Subtitles>(std::move(subs));
    }

    Subtitles SrtLoader::parseSubtitles(const std::vector<std::string> &segment)
    {
        Subtitles subs;
        subs.id = std::stoi(segment[0]);
        const int pos = segment[1].find(" --> ");
        subs.from = utils::strToMs(segment[1].substr(0, pos));
        subs.to = utils::strToMs(segment[1].substr(pos + 5));
        if (segment.size() > 2)
        {
            for (size_t i = 2; i < segment.size(); i++)
            {
                subs.text += segment[i] + "\n";
            }
        } else
        {
            subs.text = segment[2];
        }
        return subs;
    }


}
