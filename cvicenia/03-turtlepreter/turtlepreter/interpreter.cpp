#include "interpreter.hpp"
#include <stdexcept>

#include "heap_monitor.hpp"

namespace turtlepreter {

// TODO Node definitions

// ==================================================

// TODO CommandMove definitions

// ==================================================

// TODO CommandJump definitions

// ==================================================

// TODO CommandRotate definitions

// ==================================================

Interpreter::Interpreter(Node *root) : m_root(root) {
}

void Interpreter::interpretAll(Turtle &turtle) {
    this->interpterSubtreeNodes(m_root, turtle);
}

Node *Interpreter::getRoot() const {
    return m_root;
}

void Interpreter::interpterSubtreeNodes(Node *node, Turtle &turtle) {
    (void)node;
    (void)turtle;
    throw std::logic_error("Not implemented yet!");
}

} // namespace turtlepreter
