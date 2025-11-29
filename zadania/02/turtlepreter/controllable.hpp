//
// Created by david on 11/3/2025.
//

#ifndef INFORMATIKA3_CONTROLLABLE_HPP
#define INFORMATIKA3_CONTROLLABLE_HPP
#include <string>

#include "../lib/external/imgui/imgui.h"
#include "../lib/libfriimgui/image.hpp"
#include "../lib/libfriimgui/types.hpp"

namespace turtlepreter
{

    class Controllable {
        public:
            Controllable(const std::string &path);
            Controllable(const std::string &path, float centerX, float centerY);

            virtual ~Controllable() = default;
            virtual void draw(const friimgui::Region &region);
            virtual void reset();
            friimgui::Transformation& getTransformation();
        private:
            friimgui::Image m_image;
            ImVec2 m_initialTranslation;
        protected:
            friimgui::Transformation m_transformation;
    };

}


#endif //INFORMATIKA3_CONTROLLABLE_HPP
