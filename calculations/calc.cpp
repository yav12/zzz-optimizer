#include "calc.h"
#include "../data/character.h"
#include "../data/wengine.h"
#include "../data/disc.h"

namespace calc {
    statBonuses calculateDiscStats(const std::vector<disc> & discs) {
        // the holder of all stats to be returned
        statBonuses totalStats{};

        for (const auto& d : discs) {
            switch (d.getMainStat()) {
                case stats::ATKPercent:
                    totalStats.percentAtk += d.getMainStatValue();
                    break;
                case stats::DEFPercent:
                    totalStats.percentDef += d.getMainStatValue();
                    break;
                case stats::HPPercent:
                    totalStats.percentHP += d.getMainStatValue();
                    break;
                case stats::CritRate:
                    totalStats.critRate += d.getMainStatValue();
                    break;
                case stats::CritDamage:
                    totalStats.critDamage += d.getMainStatValue();
                    break;
                case stats::AnomalyProficiency:
                    totalStats.anomalyProficiency += d.getMainStatValue();
                    break;
                case stats::AnomalyMastery:
                    totalStats.percentAnomalyMastery += d.getMainStatValue();
                    break;
                case stats::PenRatio:
                    totalStats.penRatio += d.getMainStatValue();
                    break;
                case stats::FireDamage:
                    totalStats.fireDamage += d.getMainStatValue();
                    break;
                case stats::PhysicalDamage:
                    totalStats.physicalDamage += d.getMainStatValue();
                    break;
                case stats::EtherDamage:
                    totalStats.etherDamage += d.getMainStatValue();
                    break;
                case stats::IceDamage:
                    totalStats.iceDamage += d.getMainStatValue();
                    break;
                case stats::ElectricDamage:
                    totalStats.electricDamage += d.getMainStatValue();
                    break;
                case stats::Impact:
                    totalStats.percentImpact += d.getMainStatValue();
                    break;
                case stats::EnergyRegen:
                    totalStats.percentEnergyRegen += d.getMainStatValue();
                    break;
                default:
                    break; // there are no other main stats, unless i messed up
            }

            // substats
        }
        return totalStats;
    }

    wengineBonus calculateWengineBonus(const wengine::wengine & baseWengine) {
        wengineBonus bonus;
        // map w-engine stat string to enum; include all enum values from calculations/types.h
        switch (baseWengine.stat) {;
            case stats::ATKPercent:
                bonus.stat = stats::ATKPercent;
                break;
            case stats::DEFPercent:
                bonus.stat = stats::DEFPercent;
                break;
            case stats::HPPercent:
                bonus.stat = stats::HPPercent;
                break;
            case stats::CritRate:
                bonus.stat = stats::CritRate;
                break;
            case stats::CritDamage:
                bonus.stat = stats::CritDamage;
                break;
            case stats::AnomalyProficiency:
                bonus.stat = stats::AnomalyProficiency;
                break;
            case stats::AnomalyMastery:
                bonus.stat = stats::AnomalyMastery;
                break;
            case stats::PenRatio:
                bonus.stat = stats::PenRatio;
                break;
            case stats::Impact:
                bonus.stat = stats::Impact;
                break;
            case stats::EnergyRegen:
                bonus.stat = stats::EnergyRegen;
                break;
            default:
                // handle unknown stat
                break;
        }

        bonus.value = static_cast<double>(baseWengine.statPercent);
        return bonus;
    }

    double calculateATK(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // character attack
        int baseATK = baseCharacter.stats.atk;
        
        // apply stat bonuses
        double totalATK = (baseATK * (1 + ds.percentAtk / 100.0)) + ds.flatAtk;

        return totalATK;
    }

    double calculateDEF(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // character defense
        int baseDEF = baseCharacter.stats.def;
        
        // apply stat bonuses
        double totalDEF = (baseDEF * (1 + ds.percentDef / 100.0)) + ds.flatDef;

        return totalDEF;
    }

    double calculateHP(const character::character & baseCharacter, const wengine::wengine & baseWengine, const statBonuses& ds) {
        // character HP
        double baseHP = baseCharacter.stats.hp;

        // apply stat bonuses
        double totalHP = (baseHP * (1 + ds.percentHP / 100.0)) + ds.flatHP;

        return totalHP;
    }

    double calculateCritRate(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // apply stat bonuses
        double totalCR = baseCharacter.stats.cr + ds.critRate;

        return totalCR;
    }

    double calculateCritDamage(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // apply stat bonuses
        double totalCD = baseCharacter.stats.cd + ds.critDamage;

        return totalCD;
    }
    double calculateDamagePercent(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // a switch to check character attribute and add corresponding damage bonus
        switch (baseCharacter.attribute) {
            case "Fire":
                return ds.fireDamage;
            case "Physical":
                return ds.physicalDamage;
            case "Ether":
                return ds.etherDamage;
            case "Ice":
                return ds.iceDamage;
            case "Electric":
                return ds.electricDamage;
            default:
                return 0.0;
        }
        double totalDP = baseCharacter.stats.ap + ds.fireDamage + ds.physicalDamage + ds.etherDamage + ds.iceDamage + ds.electricDamage;

        return totalDP;
    }

    character::character calculateAll(const character::character & baseCharacter, const wengine::wengine & baseWengine, const std::vector<disc> & discs) {
        character::character calculatedCharacter = baseCharacter;

        statBonuses ds = calculateDiscStats(discs);
        wengineBonus wb = calculateWengineBonus(baseWengine);

        //switch to add wengine advanced stat to stat bonuses
        switch (wb.stat) {
            case stats::ATKPercent:
                ds.percentAtk += wb.value;
                break;
            case stats::DEFPercent:
                ds.percentDef += wb.value;
                break;
            case stats::HPPercent:
                ds.percentHP += wb.value;
                break;
            case stats::CritRate:
                ds.critRate += wb.value;
                break;
            case stats::CritDamage:
                ds.critDamage += wb.value;
                break;
            case stats::AnomalyProficiency:
                ds.anomalyProficiency += wb.value;
                break;
            case stats::AnomalyMastery:
                ds.percentAnomalyMastery += wb.value;
                break;
            case stats::PenRatio:
                ds.penRatio += wb.value;
                break;
            case stats::Impact:
                ds.percentImpact += wb.value;
                break;
            case stats::EnergyRegen:
                ds.percentEnergyRegen += wb.value;
                break;
        }

        calculatedCharacter.stats.atk = calculateATK(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.def = calculateDEF(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.hp = calculateHP(calculatedCharacter, wb, ds);

        return calculatedCharacter;
    }
}