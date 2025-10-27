#include "interpreter.hpp"
#include <stdexcept>

#include "heap_monitor.hpp"

namespace turtlepreter {

    Node::Node()
    {
        this->m_command = nullptr;
    }

    Node::Node(ICommand *command)
    {
        this->m_command = command;
    }

    Node::~Node()
    {
        for (auto *subnode : m_subnodes)
        {
            delete subnode;
        }
        delete m_parent;
        delete m_command;
    }

    std::string Node::toString() const
    {
        return m_command == nullptr ? "No Command" : m_command->toString();
    }

    void Node::addSubnode(Node *subNode)
    {
        m_subnodes.push_back(subNode);
        subNode->m_parent = this;
    }

    ICommand* Node::getCommand() const
    {
        return m_command;
    }

    Node* Node::getParent() const
    {
        return m_parent;
    }

    const std::vector<Node *>& Node::getSubnodes() const
    {
        return m_subnodes;
    }

    CommandMove::CommandMove(float d)
    {
        this->m_d = d;
    }

    void CommandMove::execute(Turtle &turtle)
    {
        turtle.move(this->m_d);
    }

    std::string CommandMove::toString()
    {
        return "Prikaz pre chodenie";
    }

    CommandJump::CommandJump(float x, float y)
    {
        this->m_x = x;
        this->m_y = y;
    }

    void CommandJump::execute(Turtle &turtle)
    {
        turtle.jump(this->m_x, this->m_y);
    }

    std::string CommandJump::toString()
    {
        return "Prikaz pre skok";
    }

    CommandRotate::CommandRotate(float ang)
    {
        this->m_angleRad = ang;
    }

    void CommandRotate::execute(Turtle &turtle)
    {
        turtle.rotate(m_angleRad);
    }

    std::string CommandRotate::toString()
    {
        return "Prikaz pre rotate";
    }

    Interpreter::Interpreter(Node *root) : m_root(root) {
    }

    void Interpreter::interpretAll(Turtle &turtle) {
        this->interpterSubtreeNodes(m_root, turtle);
    }

    Node *Interpreter::getRoot() const {
        return m_root;
    }

    void Interpreter::interpterSubtreeNodes(Node *node, Turtle &turtle) {
        for (auto *subnode : node->getSubnodes())
        {
            subnode->getCommand()->execute(turtle);
            this->interpterSubtreeNodes(subnode, turtle);
        }
    }

} // namespace turtlepreter
