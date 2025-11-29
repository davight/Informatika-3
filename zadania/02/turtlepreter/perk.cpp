//
// Created by david on 11/3/2025.
//

#include "perk.hpp"
#include "interpreter.hpp"

#include "heap_monitor.hpp"

namespace turtlepreter
{

    Perk::Perk(const std::string &imgPath, float centerX, float centerY, int fullStat) : Controllable(imgPath, centerX, centerY), m_stat(fullStat), m_fullStat(fullStat)
    {
    }

    void Perk::reset()
    {
        m_stat = m_fullStat;
    }

    bool Perk::hasStat() const
    {
        return m_stat > 0;
    }

    void Perk::useStat()
    {
        m_stat--;
    }

    Runner::Runner(const std::string &imgPath, float centerX, float centerY) : Controllable(imgPath, centerX, centerY), Perk(imgPath, centerX, centerY, MAX_STAMINA)
    {
    }

    bool Runner::hasStamina() const
    {
        return hasStat();
    }

    void Runner::useStamina()
    {
        useStat();
    }

    CommandRun::CommandRun(ImVec2 vec) : m_vec(vec)
    {
    }

    bool CommandRun::canBeExecuted(Controllable &controllable)
    {
        return dynamic_cast<Runner*>(&controllable) != nullptr;
    }

    void CommandRun::execute(Controllable &controllable)
    {
        Runner *runner = dynamic_cast<Runner*>(&controllable);
        if (runner != nullptr && runner->hasStamina())
        {
            runner->useStamina();
            runner->getTransformation().translation.setValue(m_vec);
        }
    }

    std::string CommandRun::toString()
    {
        return "Command Run";
    }

    Swimmer::Swimmer(const std::string &imgPath, float centerX, float centerY) : Controllable(imgPath, centerX, centerY), Perk(imgPath, centerX, centerY, MAX_OXYGEN)
    {
    }

    bool Swimmer::hasOxygen() const
    {
        return hasStat();
    }

    void Swimmer::useOxygen()
    {
        useStat();
    }

    CommandSwim::CommandSwim(ImVec2 vec) : m_d(vec)
    {
    }

    bool CommandSwim::canBeExecuted(Controllable &controllable)
    {
        return dynamic_cast<Swimmer*>(&controllable) != nullptr;
    }

    void CommandSwim::execute(Controllable &controllable)
    {
        Swimmer *swimmer = dynamic_cast<Swimmer*>(&controllable);
        if (swimmer != nullptr && swimmer->hasOxygen())
        {
            swimmer->useOxygen();
            swimmer->getTransformation().translation.setValue(m_d);
        }
    }

    std::string CommandSwim::toString()
    {
        return "Command Swim";
    }

} // turtlepreter