#ifndef TURTLEPRETER_TURTLE_HPP
#define TURTLEPRETER_TURTLE_HPP

#include <libfriimgui/image.hpp>
#include <libfriimgui/types.hpp>

#include <vector>

#include "controllable.hpp"
#include "perk.hpp"

namespace turtlepreter
{
    class Turtle : virtual public Controllable {
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


    class Tortoise : public Turtle, public Runner
    {
        public:
            Tortoise(const std::string &imgPath);
            Tortoise(const std::string &imgPath, float centerX, float centerY);
            void reset() override;
    };

    class TurtleCommand : public ICommand
    {
        protected:
            void execute(Controllable &controllable) final;
            bool canBeExecuted(Controllable &controllable) override;
            virtual void executeOnTurtle(Turtle &turtle) = 0;
    };

    /**
     * Posunie korytnačku o zadanú vzdialenosť v smere jej natočenia.
     */
    class CommandMove : public TurtleCommand {
        public:
            CommandMove(float d);

            void executeOnTurtle(Turtle &turtle) override;
            std::string toString() override;

        private:
            float m_d;
    };

    // --------------------------------------------------

    /**
     * Presunie korytnačku na zadané súradnice.
     */
    class CommandJump : public TurtleCommand {
        public:
            CommandJump(float x, float y);

            void executeOnTurtle(Turtle &turtle) override;
            std::string toString() override;

        private:
            float m_x;
            float m_y;
    };

    // --------------------------------------------------

    /**
     * Zmení natočenie korytnačky.
     */
    class CommandRotate : public TurtleCommand {
        public:
            CommandRotate(float angleRad);

            void executeOnTurtle(Turtle &turtle) override;
            std::string toString() override;

        private:
            float m_angleRad;
    };

    // ==================================================
}

#endif