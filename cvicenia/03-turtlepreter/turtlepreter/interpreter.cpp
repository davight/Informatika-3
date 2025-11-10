#include "interpreter.hpp"

#include <iostream>

#include "heap_monitor.hpp"

namespace turtlepreter {

    ///
    /// Node
    ///

    Node* Node::createLeafNode(ICommand *command)
    {
        return createNode(command, new CursorUp());
    }

    Node* Node::createSequentialNode()
    {
        return createNode(nullptr, new SequentialCursor());
    }

    Node* Node::createNode(ICommand *command, Cursor *cursor)
    {
        Node *node = new Node(command, cursor);
        cursor->setNode(node);
        return node;
    }

    Node::Node(ICommand *command, Cursor *cursor) :  m_parent(nullptr), m_command(command), m_cursor(cursor)
    {
    }

    Node::~Node()
    {
        for (auto *subnode : m_subnodes)
        {
            delete subnode;
        }
        delete m_parent;
        delete m_command;
        delete m_cursor;
    }

    std::string Node::toString() const
    {
        return (m_command == nullptr ? "No Command" : m_command->toString()) + "|" +m_cursor->toString();
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

    Cursor* Node::getCursor() const
    {
        return m_cursor;
    }

    const std::vector<Node *>& Node::getSubnodes() const
    {
        return m_subnodes;
    }

    ///
    /// Interpreter
    ///

    Interpreter::Interpreter(Node *root) : m_root(root), m_current(root) {
    }

    void Interpreter::interpretAll(Controllable &controllable) {
        while (m_current != nullptr)
        {
            interpretStep(controllable);
        }
        //this->interpterSubtreeNodes(m_root, turtle);
    }

    void Interpreter::interpretStep(Controllable &controllable)
    {
        if (m_current != nullptr)
        {
            if (m_current->getCommand() != nullptr)
            {
                if (!m_current->getCommand()->canBeExecuted(controllable)) // if if if if if chain ahh
                {
                    throw std::runtime_error("Command cannot be executed");
                }
                m_current->getCommand()->execute(controllable);
            }
            moveCurrent();
        }
    }

    void Interpreter::reset()
    {
        m_current = m_root;
        m_root->getCursor()->reset();
        for (auto *subnode : m_root->getSubnodes())
        {
            subnode->getCursor()->reset();
        }
    }

    bool Interpreter::wasSomethingExecuted()
    {
        return false;
    }

    bool Interpreter::isFinished()
    {
        return false;
    }

    Node *Interpreter::getCurrent()
    {
        return nullptr;
    }

    bool Interpreter::stopOnNoveWithoutCommand()
    {
        return false;
    }

    void Interpreter::setStopOnNodeWithoutCommand(bool value)
    {
        (void)value;
    }

    void Interpreter::moveCurrent()
    {
        m_current = m_current->getCursor()->next();
    }

    Node *Interpreter::getRoot() const {
        return m_root;
    }

    void Interpreter::interpterSubtreeNodes(Node *node, Controllable &controllable) {
        for (auto *subnode : node->getSubnodes())
        {
            subnode->getCommand()->execute(controllable);
            this->interpterSubtreeNodes(subnode, controllable);
        }
    }

    ///
    /// Cursor
    ///

    Cursor::Cursor()
    {
        m_node = nullptr;
    }


    void Cursor::setNode(Node *node)
    {
        m_node = node;
    }

    ///
    /// CursorUp
    ///

    Node *CursorUp::next()
    {
        return m_node->getParent();
    }

    void CursorUp::reset()
    {
        // nic vraj
    }

    std::string CursorUp::toString()
    {
        return "Cursor: Up";
    }

    ///
    /// SequentialCursor
    ///

    Node *SequentialCursor::next()
    {
        m_current++;
        std::vector<Node *> subnodes = m_node->getSubnodes();
        if (static_cast<size_t>(m_current) >= subnodes.size())
        {
            return m_node->getParent();
        }
        return m_node->getSubnodes()[m_current];
    }

    void SequentialCursor::reset()
    {
        m_current = -1;
    }

    std::string SequentialCursor::toString()
    {
        std::vector<Node *> subnodes = m_node->getSubnodes();
        size_t next = static_cast<size_t>(m_current) + 1;
        if (next >= subnodes.size())
        {
            return "Cursor: Up";
        }
        return "Cursor: Child " + std::to_string(next + 1) + "/" + std::to_string(subnodes.size());
    }

} // namespace turtlepreter
