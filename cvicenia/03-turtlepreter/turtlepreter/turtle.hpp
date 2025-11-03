#ifndef TURTLEPRETER_TURTLE_HPP
#define TURTLEPRETER_TURTLE_HPP

#include <libfriimgui/image.hpp>
#include <libfriimgui/types.hpp>

#include <vector>

#include "controllable.hpp"

namespace turtlepreter {

class Turtle : public Controllable {
public:
    Turtle(const std::string &imgPath);
    Turtle(const std::string &imgPath, float centerX, float centerY);

    void draw(const friimgui::Region &region) override;

    /**
     * Odstráni históriu pohybu a vráti korytnačku na pôvodné miesto
     * s pôvodným natočením.
     */
    void reset() override;

    /**
     * Posunie korytnačku o @p distance v smere jej natočenia.
     */
    void move(float distance);

    /**
     * Presunie korytnačku na súradnice @p x @p y
     */
    void jump(float x, float y);

    /**
     * Zmení natočenie korytnačky na @p angleRad
     */
    void rotate(float angleRad);

private:
    std::vector<ImVec4> m_path;
};

} // namespace turtlepreter

#endif