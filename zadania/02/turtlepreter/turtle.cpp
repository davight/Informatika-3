#include "turtle.hpp"

#include <iostream>
#include <imgui/imgui.h>
#include <cmath>

#include "interpreter.hpp"
#include "heap_monitor.hpp"

namespace turtlepreter {

    Turtle::Turtle(const std::string &imgPath) : Controllable(imgPath), m_currentColor(DEFAULT_COLOR)
    {
    }

    Turtle::Turtle(const std::string &imgPath, float centerX, float centerY) : Controllable(imgPath, centerX, centerY), m_currentColor(DEFAULT_COLOR)
    {
    }

    void Turtle::draw(const friimgui::Region &region) {
        ImDrawList *drawList = ImGui::GetWindowDrawList();
        const ImVec2 p0 = region.getP0();
        for (auto &path : m_dataPath)
        {
            drawList->AddLine(path.getStartWithOffset(p0),  path.getEndWithOffset(p0), path.color, 1);
        }
        Controllable::draw(region);
    }

    void Turtle::reset() {
        Controllable::reset();
        m_dataPath.clear();
    }

    void Turtle::move(float distance)
    {
        const ImVec2 currentPosition = m_transformation.translation.getValueOrDef();
        float rotation = m_transformation.rotation.getValueOrDef();
        float newX = currentPosition.x + distance * cos(rotation);
        float newY = currentPosition.y + distance * sin(rotation);

        internalMovement(currentPosition, {newX, newY});
    }

    void Turtle::jump(float x, float y)
    {
        internalMovement(m_transformation.translation.getValueOrDef(), {x, y});
    }

    void Turtle::rotate(float angleRad)
    {
        m_transformation.rotation.setValue(m_transformation.rotation.getValueOrDef() + angleRad); // asi staci lol
    }

    void Turtle::internalMovement(ImVec2 start, ImVec2 end)
    {
        auto path = Segment();
        path.start = start;
        path.end = end;
        path.color = m_currentColor;
        m_dataPath.push_back(path);

        m_transformation.translation.setValue(end);
    }

    ImColor Turtle::getPathSegmentColor(size_t i) const
    {
        return m_dataPath[i].color;
    }

    size_t Turtle::getPathSegmentCount() const
    {
        return m_dataPath.size();
    }

    ImVec4 Turtle::getPathSegmentPoints(size_t i) const
    {
        return m_dataPath[i].getStartToEndVec();
    }

    void Turtle::setColor(ImColor color)
    {
        m_currentColor = color;
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

    CommandMove::CommandMove(float d) : m_d(d)
    {
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

    CommandJump::CommandJump(float x, float y) : m_x(x), m_y(y)
    {
    }

    void CommandJump::executeOnTurtle(Turtle &turtle)
    {
        turtle.jump(this->m_x, this->m_y);
    }

    std::string CommandJump::toString()
    {
        return "Command: Jump " + std::to_string(m_x) + " " + std::to_string(m_y);
    }

    void CommandJump::log(std::ostream &ost) const
    {
        ost << "jump(" << m_x << "," << m_y << ")\n";
    }

    ///
    /// CommandRotate
    ///

    CommandRotate::CommandRotate(float ang) : m_angleRad(ang)
    {
    }

    void CommandRotate::executeOnTurtle(Turtle &turtle)
    {
        turtle.rotate(m_angleRad);
    }

    std::string CommandRotate::toString()
    {
        return "Command Rotate " + std::to_string(m_angleRad) + "rad";
    }

    void CommandRotate::log(std::ostream &ost) const
    {
        ost << "rotate(" << m_angleRad << ")\n";
    }

    ///
    /// CommandSetColor
    ///

    CommandSetColor::CommandSetColor(ImColor color) : m_color(color)
    {
    }

    void CommandSetColor::executeOnTurtle(Turtle &turtle)
    {
        turtle.setColor(m_color);
    }

    std::string CommandSetColor::toString()
    {
        return "Command Set Color" + std::to_string(m_color.Value.x) + " " + std::to_string(m_color.Value.y) + " " + std::to_string(m_color.Value.z);
    }

    void CommandSetColor::log(std::ostream &ost) const
    {
        ost << "setColor(" << m_color.Value.x << "," << m_color.Value.y << "," << m_color.Value.z << ")\n";
    }

    Tortoise::Tortoise(const std::string &imgPath) : Controllable(imgPath), Turtle(imgPath), Runner(imgPath, 0, 0)
    {
    }

    Tortoise::Tortoise(const std::string &imgPath, float centerX, float centerY) : Controllable(imgPath, centerX, centerY), Turtle(imgPath, centerX, centerY), Runner(imgPath, centerX, centerY)
    {
    }

    void Tortoise::reset()
    {
        Turtle::reset();
        Perk::reset();
    }

} // namespace turtlepreter
