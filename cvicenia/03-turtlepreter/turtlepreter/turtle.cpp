#include "turtle.hpp"

#include <imgui/imgui.h>

#include <stdexcept>

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
    (void)thickness;
    (void)color;
    (void)drawList;
    (void)p0;
    // TODO
    m_image.draw(region, m_transformation);
}

void Turtle::reset() {
    throw std::logic_error("Not implemented yet!");
}

void Turtle::move(float distance) {
    (void)distance;
    // Dobrovoľná úloha na doma.
    throw std::logic_error("Not implemented yet!");
}

void Turtle::jump(float x, float y) {
    (void)x;
    (void)y;
    throw std::logic_error("Not implemented yet!");
}

void Turtle::rotate(float angleRad) {
    (void)angleRad;
    throw std::logic_error("Not implemented yet!");
}

} // namespace turtlepreter
