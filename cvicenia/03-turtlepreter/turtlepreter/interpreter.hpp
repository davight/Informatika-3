#ifndef TURTLEPRETER_INTERPRETER_HPP
#define TURTLEPRETER_INTERPRETER_HPP

#include "turtle.hpp"

#include <string>
#include <vector>

namespace turtlepreter {

class ICommand;
class Cursor;

class Node {
public:

    static Node* createLeafeNode(ICommand *command);
    static Node* createSequentialNode();

    /**
     * Odstráni synov vrcholu.
     */
    ~Node();

    /*
     * Vráti reťazec reprezentujúci vrchol.
     * Ak vrchol nemá priradený command, vráti "No command".
     * Inak vráti reťazec reprezentujúci command.
     */
    std::string toString() const;

    /**
     * Uloží @p subnode do zoznamu synov.
     * Nastaví sa ako otec @p subnode
     * Preberá zodpovednosť za životný cyklus @p subnode
     */
    void addSubnode(Node *subnode);

    Cursor* getCursor() const;

    Node *getParent() const;
    const std::vector<Node *> &getSubnodes() const;

    ICommand *getCommand() const;

private:
    static Node *createNode(ICommand *command, Cursor *cursor);
    Node(ICommand *command, Cursor *cursor);
    Node *m_parent;
    std::vector<Node *> m_subnodes;

    ICommand *m_command;
    Cursor *m_cursor;
};

// ==================================================

class ICommand {
public:
    virtual ~ICommand() = default;

    /**
     * Vykoná akciu s korytnačkou @p turtle
     */
    virtual void execute(Turtle &turtle) = 0;

    /**
     * Vráti reťazec popisujúci príkaz.
     */
    virtual std::string toString() = 0;
};

// --------------------------------------------------

/**
 * Posunie korytnačku o zadanú vzdialenosť v smere jej natočenia.
 */
class CommandMove : public ICommand {
public:
    CommandMove(float d);

    void execute(Turtle &turtle) override;
    std::string toString() override;

private:
    float m_d;
};

// --------------------------------------------------

/**
 * Presunie korytnačku na zadané súradnice.
 */
class CommandJump : public ICommand {
public:
    CommandJump(float x, float y);

    void execute(Turtle &turtle) override;
    std::string toString() override;

private:
    float m_x;
    float m_y;
};

// --------------------------------------------------

/**
 * Zmení natočenie korytnačky.
 */
class CommandRotate : public ICommand {
public:
    CommandRotate(float angleRad);

    void execute(Turtle &turtle) override;
    std::string toString() override;

private:
    float m_angleRad;
};

// ==================================================

class Interpreter {
public:
    Interpreter(Node *root);

    void interpretStep(Turtle &turtle);
    void reset();
    bool wasSomethingExecuted();
    bool isFinished();
    Node* getCurrent();
    bool stopOnNoveWithoutCommand();
    void setStopOnNodeWithoutCommand(bool value); // boolean parameter :side_eye:
    /**
     * Rekurzívnou prehliadkou interpretuje príkazy
     * vo všetkých vrcholoch.
     */
    void interpretAll(Turtle &turtle);

    Node *getRoot() const;

private:
    Node *m_root;
    Node *m_current;

    void interpterSubtreeNodes(Node *node, Turtle &turtle);
    void moveCurrent();
};

    class Cursor {
        public:
            Cursor();
            virtual ~Cursor() = default;
            virtual Node* next() = 0;
            virtual void reset() = 0;
            virtual std::string toString() = 0;
            void setNode(Node *node);
        protected:
            Node *m_node;
    };

    class CursorUp : public Cursor {
        public:
            Node* next() override;
            void reset() override;
            std::string toString() override;
    };

    class SequentialCursor : public Cursor {
        public:
            Node* next() override;
            void reset() override;
            std::string toString() override;
        private:
            int m_current = -1;
    };

} // namespace turtlepreter

#endif
