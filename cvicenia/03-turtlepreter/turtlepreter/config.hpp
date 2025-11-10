//
// Created by david on 11/10/2025.
//

#ifndef INFORMATIKA3_CONFIG_HPP
#define INFORMATIKA3_CONFIG_HPP
#include <filesystem>
#include <nlohmann/json.hpp>

namespace turtlepreter
{
    class Config {
        public:
            static Config createFromJsonNode(const nlohmann::json &json);
            static Config createFromJsonFile(const std::filesystem::path &path);
            static Config createDefault();
            static Config createFromArgs(int argc, char* argv[]);

            const std::string& getImageTurtle() const;
            const std::string& getImageRunner() const;
            const std::string& getImageSwimmer() const;
            const std::string& getImageTortoise() const;
            int getWidth() const;
            int getHeight() const;
            void print(std::ostream &ost) const;
        private:
            Config() = default;
            std::string m_imageTurtle;
            std::string m_imageRunner;
            std::string m_imageSwimmer;
            std::string m_imageTortoise;
            int m_width;
            int m_height;

    };
}

#endif //INFORMATIKA3_CONFIG_HPP