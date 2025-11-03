//
// Created by david on 11/3/2025.
//

#include "controllable.hpp"

#include <iostream>

namespace turtlepreter
{
    Controllable::Controllable(const std::string &path) : m_image(friimgui::Image::createImage(path))
    {
    }

    Controllable::Controllable(const std::string &path, float centerX, float centerY) : Controllable(path)
    {
        m_initialTranslation = {centerX, centerY};
        m_transformation.translation.setValue({centerX, centerY});
    }

    friimgui::Transformation &Controllable::getTransformation()
    {
        return m_transformation;
    }

    void Controllable::reset()
    {
        m_transformation.reset();
        m_transformation.translation.setValue(m_initialTranslation);
    }

    void Controllable::draw(const friimgui::Region &region)
    {
        m_image.draw(region, m_transformation);
    }

}
