#include "calc.h"

namespace calc {
    discStats calculateDiscStats(const std::vector<disc> & discs) {
        // the holder of all stats to be returned
        discStats totalStats = {0, 0.0, 0, 0.0, 0, 0.0};

        for (const auto& d : discs) {
            switch (d.getMainStat()) {
                case mainStat::ATK:
                    totalStats.flatAtk += static_cast<int>(d.getMainStatValue());
                    break;
                case mainStat::ATKPercent:
                    totalStats.percentAtk += d.getMainStatValue();
                    break;
                case mainStat::DEF:
                    totalStats.flatDef += static_cast<int>(d.getMainStatValue());
                    break;
                case mainStat::DEFPercent:
                    totalStats.percentDef += d.getMainStatValue();
                    break;
                case mainStat::HP:
                    totalStats.flatHP += static_cast<int>(d.getMainStatValue());
                    break;
                case mainStat::HPPercent:
                    totalStats.percentHP += d.getMainStatValue();
                    break;
                case mainStat::CritRate:
                    totalStats.critRate += d.getMainStatValue();
                    break;
                case mainStat::CritDamage:
                    totalStats.critDamage += d.getMainStatValue();
                    break;
                case mainStat::AnomalyProficiency:
                    totalStats.anomalyProficiency += d.getMainStatValue();
                    break;
                case mainStat::AnomalyMastery:
                    totalStats.anomalyMastery += d.getMainStatValue();
                    break;
                case mainStat::PenRatio:
                    totalStats.penRatio += d.getMainStatValue();
                    break;
                case mainStat::FireDamage:
                    totalStats.fireDamage += d.getMainStatValue();
                    break;
                case mainStat::PhysicalDamage:
                    totalStats.physicalDamage += d.getMainStatValue();
                    break;
                case mainStat::EtherDamage:
                    totalStats.etherDamage += d.getMainStatValue();
                    break;
                case mainStat::IceDamage:
                    totalStats.iceDamage += d.getMainStatValue();
                    break;
                case mainStat::ElectricDamage:
                    totalStats.electricDamage += d.getMainStatValue();
                    break;
                case mainStat::Impact:
                    totalStats.impact += d.getMainStatValue();
                    break;
                case mainStat::EnergyRegen:
                    totalStats.energyRegen += d.getMainStatValue();
                    break;
                default:
                    break; // there are no other main stats, unless i messed up
            }
            
            // substats
        }
    }

    double calculateATK(const character::character & baseCharacter, const wengine::wengine & baseWengine, const std::vector<disc> & discs) {
        // character attack
        int baseATK = baseCharacter.stats.atk;

        // apply wengine bonus
        baseATK += baseWengine.baseAtk;
        
        // apply disc bonuses
        discStats ds = calculateDiscStats(discs);

        return static_cast<double>(baseATK + ds.flatAtk);
    }

    character::character calculateAll(const character::character & baseCharacter, const wengine::wengine & baseWengine, const std::vector<disc> & discs) {
        character::character calculatedCharacter = baseCharacter;

        discStats ds = calculateDiscStats(discs);

        calculatedCharacter.stats.atk = calculateATK(calculatedCharacter, baseWengine, ds);
        calculatedCharacter.stats.def = calculateDEF(calculatedCharacter, baseWengine, ds);
        calculatedCharacter.stats.hp = calculateHP(calculatedCharacter, baseWengine, ds);

        return calculatedCharacter;
    }
}