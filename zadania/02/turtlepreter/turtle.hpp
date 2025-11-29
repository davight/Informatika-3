#ifndef TURTLEPRETER_TURTLE_HPP
#define TURTLEPRETER_TURTLE_HPP

#include <libfriimgui/image.hpp>
#include <libfriimgui/types.hpp>

#include <vector>

#include "controllable.hpp"
#include "perk.hpp"

namespace turtlepreter
{
    struct Segment;

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

            size_t getPathSegmentCount() const;
            ImVec4 getPathSegmentPoints(size_t i) const;
            ImColor getPathSegmentColor(size_t i) const;
            void setColor(ImColor color);

            // default farba
            inline static const ImColor DEFAULT_COLOR = ImColor(0, 255, 0);

        private:
            void internalMovement(ImVec2 start, ImVec2 end);

            ImColor m_currentColor;
            //std::vector<ImVec4> m_path; replaced s advanced pathom
            std::vector<Segment> m_dataPath;
    };

    struct Segment {
        ImVec2 start;
        ImVec2 end;
        ImColor color;

        ImVec2 getStartWithOffset(const ImVec2 offset) const
        {
            return ImVec2(start.x + offset.x, start.y + offset.y);
        }

        ImVec2 getEndWithOffset(const ImVec2 offset) const
        {
            return ImVec2(end.x + offset.x, end.y + offset.y);
        }

        ImVec4 getStartToEndVec() const
        {
            return ImVec4(start.x, start.y, end.x, end.y);
        }
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
            void log(std::ostream &ost) const override;
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
            void log(std::ostream &ost) const override;
        private:
            float m_angleRad;
    };

    // ==================================================

    class CommandSetColor : public TurtleCommand {
        public:
            CommandSetColor(ImColor color);

            void executeOnTurtle(Turtle &turtle) override;
            std::string toString() override;
            void log(std::ostream &ost) const override;
        private:
            ImColor m_color;
    };
}

#endif