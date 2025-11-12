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
        double unconditionalPercent = ds.percentAtk;
        double unconditionalFlat = ds.flatAtk ;
        
        // total
        double totalATK = (baseATK * (1 + unconditionalPercent / 100.0)) + unconditionalFlat;

        return totalATK;
    }

    double calculateDEF(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // character defense
        int baseDEF = baseCharacter.stats.def;
        
        // apply stat bonuses
        double totalDEF = (baseDEF * (1 + ds.percentDef / 100.0)) + ds.flatDef;

        return totalDEF;
    }

    double calculateHP(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // character HP
        double baseHP = baseCharacter.stats.hp;

        // apply stat bonuses
        double unconditionalPercent = ds.percentHP;
        double unconditionalFlat = ds.flatHP;

        if (wb.stat == stats::HPPercent) {
            unconditionalPercent += wb.value;
        } else if (wb.stat == stats::HP) {
            unconditionalFlat += wb.value;
        }

        // total
        double totalHP = (baseHP * (1 + unconditionalPercent / 100.0)) + unconditionalFlat;

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

    double calculateAnomalyProficiency(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // apply stat bonuses
        double totalAP = baseCharacter.stats.ap + ds.anomalyProficiency;

        return totalAP;
    }

    double calculateAnomalyMastery(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // apply stat bonuses
        double totalAM = baseCharacter.stats.am + ds.percentAnomalyMastery;

        return totalAM;
    }

    double calculateImpact(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // apply stat bonuses
        double totalImpact = baseCharacter.stats.impact + ds.percentImpact;

        return totalImpact;
    }

    double calculatePEN(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // apply stat bonuses
        double totalPEN = baseCharacter.stats.pen + ds.penRatio;

        return totalPEN;
    }

    double calculatePENRatio(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        
        // apply stat bonuses
        double totalPENRatio = baseCharacter.stats.penr + ds.penRatio;
        //pen ratio is only additive (its a percentage to begin with) so nothing else to be done
        return totalPENRatio;
    }

    double calculateDamagePercent(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses& ds) {
        // a switch to check character attribute and add corresponding damage bonus
        switch (baseCharacter.attribute) {
            case attribute::Fire:
                return ds.fireDamage;
            case attribute::Physical:
                return ds.physicalDamage;
            case attribute::Ether:
                return ds.etherDamage;
            case attribute::Ice:
                return ds.iceDamage;
            case attribute::Electric:
                return ds.electricDamage;
            default:
                return 0.0;
        }
    }

    double calculateER(const character::character &baseCharacter, const wengineBonus &wb, const statBonuses &ds) {
        // apply stat bonuses
        double totalER = baseCharacter.stats.er + ds.percentEnergyRegen;

        return totalER;
    }
    double calculateSF(const character::character &baseCharacter, const wengineBonus &wb, const statBonuses &ds) {
        // sheer force is special, calculated as 30% of attack stat (game mechanic) + 10% of hp (all rupture agent core passive) + any additional sources
        return baseCharacter.stats.atk * 0.3 + baseCharacter.stats.hp * 0.1;
    }

    character::character calculateAll(const character::character & baseCharacter, const wengine::wengine & baseWengine, const std::vector<disc> & discs) {
        character::character calculatedCharacter = baseCharacter;

        statBonuses ds = calculateDiscStats(discs);
        wengineBonus wb = calculateWengineBonus(baseWengine);

        //add base attack from wengines
        ds.flatAtk += baseWengine.baseAtk;

        calculatedCharacter.stats.atk = calculateATK(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.def = calculateDEF(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.hp = calculateHP(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.cr = calculateCritRate(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.cd = calculateCritDamage(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.am = calculateAnomalyMastery(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.ap = calculateAnomalyProficiency(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.penr = calculatePENRatio(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.impact = calculateImpact(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.er = calculateER(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.aaa = calculateDamagePercent(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.pen = calculatePEN(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.damagePercent = calculateDamagePercent(calculatedCharacter, wb, ds);
        calculatedCharacter.stats.sf = calculateSF(calculatedCharacter, wb, ds);

        return calculatedCharacter;
    }
}