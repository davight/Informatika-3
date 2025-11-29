//
// Created by david on 11/10/2025.
//

#include "config.hpp"

#include <fstream>

namespace turtlepreter
{
    Config Config::createDefault()
    {
        Config config;
        std::string path = "turtlepreter\\resource\\";
        config.m_imageRunner = path + "runner.png";
        config.m_imageSwimmer = path + "swimmer.png";
        config.m_imageTortoise = path + "tortoise.png";
        config.m_imageTurtle = path + "turtle.png";
        config.m_width = 800;
        config.m_height = 600;
        return config;
    }

    Config Config::createFromArgs(int argc, char* argv[])
    {
        // idk jak
        return createDefault();
    }

    Config Config::createFromJsonFile(const std::filesystem::path &path)
    {
        std::ifstream ifst(path);
        if (!ifst.is_open())
        {
            throw std::runtime_error("Failed to open: " + path.string());
        }
        return createFromJsonNode(nlohmann::json::parse(ifst));
    }

    Config Config::createFromJsonNode(const nlohmann::json &json)
    {
        Config config;
        config.m_imageTurtle = json["imageTurtle"];
        config.m_imageRunner = json["imageRunner"];
        config.m_imageSwimmer = json["imageSwimmer"];
        config.m_imageTortoise = json["imageTortoise"];
        config.m_width = json["width"];
        config.m_height = json["height"];
        return config;
    }

    int Config::getHeight() const
    {
        return m_height;
    }

    int Config::getWidth() const
    {
        return m_width;
    }

    const std::string &Config::getImageRunner() const
    {
        return m_imageRunner;
    }

    const std::string &Config::getImageSwimmer() const
    {
        return m_imageSwimmer;
    }

    const std::string &Config::getImageTortoise() const
    {
        return m_imageTortoise;
    }

    const std::string &Config::getImageTurtle() const
    {
        return m_imageTurtle;
    }

    void Config::print(std::ostream &ost) const
    {
        ost << "ImageTurtle path: " << m_imageTurtle << "\n"
            << "ImageRunner path: " << m_imageRunner << "\n"
            << "ImageSwimmer path: " << m_imageSwimmer << "\n"
            << "ImageTortoise path: " << m_imageTortoise << "\n"
            << "Width: " << m_width << "\n"
            << "Height: " << m_height << "\n";
    }

}
