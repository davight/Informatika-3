#include "interpreter.hpp"
#include "turtle.hpp"
#include "turtle_gui.hpp"

#include <libfriimgui/window.hpp>

#include <imgui/imgui.h>

#include <numbers>
#include <string>

#include "heap_monitor.hpp"

int main(int argc, char *argv[]) {
    namespace tp = turtlepreter;

    (void)argc;
    (void)argv;

    const std::string cTurtleImg = ".\\turtlepreter\\resources\\turtle.png";
    const int cWidth = 1280;
    const int cHeight = 720;
    const int cCenterX = cWidth / 2;
    const int cCenterY = cHeight / 2;

    // Create window, make OpenGL available.
    friimgui::Window *window
        = friimgui::Window::initializeWindow(cWidth, cHeight);

    // Create the turtle.
    tp::Turtle turtle(cTurtleImg, cCenterX, cCenterY);

    // TODO
    //tp::CommandJump *jump = new tp::CommandJump(100, 100);
    //tp::CommandMove *move = new tp::CommandMove(100);
    tp::CommandRotate *rotate = new tp::CommandRotate(std::numbers::pi_v<float> / 2);
    tp::Node *otec = new tp::Node();
    //tp::Node *syn1 = new tp::Node(jump);
    tp::Node *syn2 = new tp::Node(rotate);
    //otec->addSubnode(syn1);
    otec->addSubnode(syn2);

    // Interpret the tree from the root.
    tp::Interpreter interpreter(otec);

    // Create GUI.
    tp::TurtleGUI turtleGUI(&turtle, &interpreter);

    // Render GUI.
    window->setGUI(&turtleGUI);
    window->run();
    friimgui::Window::releaseWindow();
    delete otec;
}
