//
// Created by david on 11/3/2025.
//

#ifndef TURTLEPRETER_PERK_HPP
#define TURTLEPRETER_PERK_HPP
#include <string>

#include "controllable.hpp"
#include "interpreter.hpp"

namespace turtlepreter
{

    class Perk : virtual public Controllable {
        public:
            Perk(const std::string &imgPath, float centerX, float centerY, int fullStat);
            void reset() override;
        protected:
            bool hasStat() const;
            void useStat();
        private:
            int m_stat;
            int m_fullStat;
    };

    class Runner : public Perk {
        public:
            Runner(const std::string &imgPath, float centerX, float centerY);
            //void draw(const friimgui::Region &region) override;
            bool hasStamina() const;
            void useStamina();
        private:
            static const int MAX_STAMINA = 3;
    };

    class CommandRun : public ICommand {
        public:
            CommandRun(ImVec2 vec);
            ~CommandRun() override = default;
            void execute(Controllable &controllable) override;
            bool canBeExecuted(Controllable &controllable) override;
            std::string toString() override;
        private:
            ImVec2 m_vec;
    };

    class Swimmer : public Perk {
        public:
            Swimmer(const std::string &imgPath, float centerX, float centerY);
            //void draw(const friimgui::Region &region) override;
            bool hasOxygen() const;
            void useOxygen();
        private:
            static const int MAX_OXYGEN = 3;
    };

    class CommandSwim : public ICommand {
        public:
            CommandSwim(ImVec2 vec);
            ~CommandSwim() override = default;
            void execute(Controllable &controllable) override;
            bool canBeExecuted(Controllable &controllable) override;
            std::string toString() override;
        private:
            ImVec2 m_d;
    };

} // turtlepreter

#endif //TURTLEPRETER_PERK_HPP