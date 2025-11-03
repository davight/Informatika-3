#include "turtle.hpp"

#include <iostream>
#include <imgui/imgui.h>
#include <cmath>

#include "interpreter.hpp"
#include "heap_monitor.hpp"

namespace turtlepreter {


    Turtle::Turtle(const std::string &imgPath) : Controllable(imgPath)
    {
    }

    Turtle::Turtle(const std::string &imgPath, float centerX, float centerY) : Controllable(imgPath, centerX, centerY)
    {
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
            drawList->AddLine({vec.x + p0.x, vec.y + p0.y}, {vec.z + p0.x, vec.w + p0.y}, color, thickness);
        }
        Controllable::draw(region);
    }

    void Turtle::reset() {
        Controllable::reset();
        m_path.clear();
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
        ImVec2 currentPosition = m_transformation.translation.getValueOrDef();
        m_path.push_back({currentPosition.x, currentPosition.y, x, y});
        m_transformation.translation.setValue({x, y});
    }

    void Turtle::rotate(float angleRad) {
        m_transformation.rotation.setValue(m_transformation.rotation.getValueOrDef() + angleRad); // asi staci lol
    }


    ///
    /// Turtle Command
    ///

    bool TurtleCommand::canBeExecuted(Controllable &controllable)
    {
        return dynamic_cast<Turtle*>(&controllable) != nullptr;
    }

    void TurtleCommand::execute(Controllable &controllable)
    {
        Turtle *turtle = dynamic_cast<Turtle*>(&controllable);
        if (turtle != nullptr)
        {
            executeOnTurtle(*turtle);
        }
    }

    ///
    /// CommandMove
    ///

    CommandMove::CommandMove(float d)
    {
        this->m_d = d;
    }

    void CommandMove::executeOnTurtle(Turtle &turtle)
    {
        turtle.move(this->m_d);
    }

    std::string CommandMove::toString()
    {
        return "Command: Move " + std::to_string(m_d);
    }

    ///
    /// CommandJump
    ///

    CommandJump::CommandJump(float x, float y)
    {
        this->m_x = x;
        this->m_y = y;
    }

    void CommandJump::executeOnTurtle(Turtle &turtle)
    {
        turtle.jump(this->m_x, this->m_y);
    }

    std::string CommandJump::toString()
    {
        return "Command: Jump " + std::to_string(m_x) + " " + std::to_string(m_y);
    }

    ///
    /// CommandRotate
    ///

    CommandRotate::CommandRotate(float ang)
    {
        this->m_angleRad = ang;
    }

    void CommandRotate::executeOnTurtle(Turtle &turtle)
    {
        turtle.rotate(m_angleRad);
    }

    std::string CommandRotate::toString()
    {
        return "Command Rotate " + std::to_string(m_angleRad) + "rad";
    }

} // namespace turtlepreter
