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
                case mainStat::CritDamage:
                case mainStat::AnomalyProficiency:
                case mainStat::AnomalyMastery:
                case mainStat::PenRatio:
                case mainStat::FireDamage:
                case mainStat::PhysicalDamage:
                case mainStat::EtherDamage:
                case mainStat::IceDamage:
                case mainStat::ElectricDamage:
                case mainStat::Impact:
                case mainStat::EnergyRegen:
                default:
                    break; // ignore other stats for now
            }

            // similarly handle substats if needed
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