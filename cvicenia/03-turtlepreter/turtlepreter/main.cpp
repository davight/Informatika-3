#include <algorithm>
#include <iostream>

#include "interpreter.hpp"
#include "turtle.hpp"
#include "turtle_gui.hpp"

#include <libfriimgui/window.hpp>

#include <imgui/imgui.h>

#include <numbers>
#include <string>

#include "perk.hpp"
#include "heap_monitor.hpp"

int main(int argc, char *argv[]) {
    namespace tp = turtlepreter;

    (void)argc;
    (void)argv;

    const std::string cTurtleImg = ".\\turtlepreter\\resources\\turtle.png";
    const std::string cRunnerImg = ".\\turtlepreter\\resources\\runner.png";
    const int cWidth = 1280;
    const int cHeight = 720;
    const int cCenterX = cWidth / 2;
    const int cCenterY = cHeight / 2;

    // Create window, make OpenGL available.
    friimgui::Window *window
        = friimgui::Window::initializeWindow(cWidth, cHeight);

    // Create the turtle.
    tp::Turtle turtle(cTurtleImg, cCenterX, cCenterY);
    tp::Runner runner(cRunnerImg, cCenterX, cCenterY);

    //tp::CommandJump *jump = new tp::CommandJump(0, 00);
    //tp::CommandMove *move = new tp::CommandMove(100);
    //tp::CommandRotate *rotate = new tp::CommandRotate(std::numbers::pi_v<float> / 3);
    tp::Node *otec = tp::Node::createSequentialNode();
    //tp::Node *turtleOtec = tp::Node::createSequentialNode();
    //tp::Node *syn1 = tp::Node::createLeafeNode(move);
    //tp::Node *syn2 = tp::Node::createLeafeNode(rotate);
    //turtleOtec->addSubnode(syn1);
    //turtleOtec->addSubnode(syn2);
    //turtleOtec->addSubnode(syn1);
    //turtleOtec->addSubnode(syn2);
    //turtleOtec->addSubnode(syn1);
    //turtleOtec->addSubnode(syn2);

    tp::CommandRun *run = new tp::CommandRun({10, 20});
    //tp::Node *runnerOtec = tp::Node::createSequentialNode();
    tp::Node *runNode2 = tp::Node::createLeafeNode(run);
    otec->addSubnode(runNode2);

    //otec->addSubnode(turtleOtec);
    //otec->addSubnode(runnerOtec);

    // Interpret the tree from the root.
    tp::Interpreter interpreter(otec);

    // Create GUI.
    tp::TurtleGUI turtleGUI(&runner, &interpreter);

    // Render GUI.
    window->setGUI(&turtleGUI);
    window->run();
    friimgui::Window::releaseWindow();
    delete otec;
}
