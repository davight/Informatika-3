#include "turtle.hpp"

#include <iostream>
#include <imgui/imgui.h>
#include <cmath>
#include <stdexcept>

#include "heap_monitor.hpp"

namespace turtlepreter {

    Turtle::Turtle(const std::string &imgPath) :
        m_transformation(),
        m_image(friimgui::Image::createImage(imgPath)) {
    }

    Turtle::Turtle(const std::string &imgPath, float centerX, float centerY) :
        Turtle(imgPath) {
        m_transformation.translation.setValue({centerX, centerY});
    }

    void Turtle::draw(const friimgui::Region &region) {
        const float thickness = 1;
        const ImColor color = ImColor(ImVec4({0, 1, 0, 1}));
        ImDrawList *drawList = ImGui::GetWindowDrawList();
        const ImVec2 p0 = region.getP0();
        // TODO
        (void)thickness; // SHE THICC
        (void)color;
        (void)drawList;
        (void)p0;
        // TODO
        for (auto &vec : m_path)
        {
            //std::cout << "Drawing line from " << vec.x << ", " << vec.y << " to " << vec.z << ", " << vec.w << std::endl;
            drawList->AddLine({vec.x + p0.x, vec.y + p0.y}, {vec.z + p0.x, vec.w + p0.y}, color, thickness);
        }
        m_image.draw(region, m_transformation);
    }

    void Turtle::reset() {
        //throw std::logic_error("Not implemented yet!");
    }

    void Turtle::move(float distance) {
        const ImVec2 currentPosition = m_transformation.translation.getValueOrDef();
        float rotation = m_transformation.rotation.getValueOrDef();
        float newX = currentPosition.x + distance * cos(rotation);
        float newY = currentPosition.y + distance * sin(rotation);

        m_path.push_back({currentPosition.x, currentPosition.y, newX, newY});
        m_transformation.translation.setValue({newX, newY});
    }

    void Turtle::jump(float x, float y) {
        // Potrebujeme Vec2 od aktualnej polohy po novu polohu
        ImVec2 currentPosition = m_transformation.translation.getValueOrDef();
        m_path.push_back({currentPosition.x, currentPosition.y, x, y});
        // najprv x pohyb
        /*
        for (float xM = std::min(currentPosition.x, x); xM <= std::max(currentPosition.x, x); ++xM)
        {
            m_transformation.translation.setValue({xM, y});
        }
        // pak y pohyb
        for (float yM = std::min(currentPosition.y, y); yM <= std::max(currentPosition.y, y); ++yM)
        {
            m_transformation.translation.setValue({x, yM});
        }
        */
        m_transformation.translation.setValue({x, y});
        currentPosition = m_transformation.translation.getValueOrDef();
        std::cout << "New position: " << currentPosition.x << currentPosition.y << std::endl;
        //m_transformation.translation.setValue({x, y});
    }

    void Turtle::rotate(float angleRad) {
        m_transformation.rotation.setValue(m_transformation.rotation.getValueOrDef() + angleRad); // asi staci lol
    }

} // namespace turtlepreter
