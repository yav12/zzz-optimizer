#include "calc.h"
#include "../data/character.h"
#include "../data/wengine.h"
#include "../data/disc.h"
#include <map>
#include <QDebug>

namespace calc {
    std::map<stats, double> calculateDiscStats(const std::vector<disc> & discs, const std::map<stats, double> & bonus) {
        // the holder of all stats to be returned
        std::map<stats, double> discStats = bonus;

        // go through each disc and add its stats to the total
        for (const disc & thisDisc : discs) {
            // get the main stat for this disc
            discStats[thisDisc.getMainStat()] += thisDisc.getMainStatValue();
            // get the substats for this disc
            discStats[thisDisc.getSubStat1()] += thisDisc.getSub1Value();
            discStats[thisDisc.getSubStat2()] += thisDisc.getSub2Value();
            discStats[thisDisc.getSubStat3()] += thisDisc.getSub3Value();
            discStats[thisDisc.getSubStat4()] += thisDisc.getSub4Value();
        }

        //apply 2p set bonuses
        std::map<calc::discSet, int> setCounts;
        for (const disc & thisDisc : discs) {
            setCounts[thisDisc.getSet()]++;
        }

        for (const auto & pair : setCounts) {
            if (pair.second >= 2) {
                // skip empty sets
                if (pair.first == calc::discSet::None)
                  continue;

                // apply 2pc bonus
                const disc::DiscInfo & info = disc::discMap.at(pair.first);
                discStats[info.bonus2pc] += info.bonus2pcValue;
            }
        }
        
        return discStats;
    }

    std::map<stats, double> calculateWengineBonus(const wengine::wengine & baseWengine, const std::map<stats, double> & bonus) {
        // set the bonus based on the wengine's stat and percentage (the rest are zero)
        std::map<stats, double> wengineBonus = bonus;
        wengineBonus[baseWengine.stat] = static_cast<double>(baseWengine.statPercent);
        return wengineBonus;
    }

    std::map<stats, double> calculateWengineEffect(const character::character & baseCharacter, const wengine::wengine & baseWengine) {
        std::map<stats, double> effect;
        // for now, no additional effects implemented
        return effect;
    }
    double calculateATK(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // character attack
        int baseATK = baseCharacter.stats.atk;
        
        // apply stat bonuses
        double unconditionalPercent = sb.at(stats::ATKPercent);
        double unconditionalFlat = sb.at(stats::ATKFlat);

        // wengine bonuses
        if (wb.find(stats::ATKFlat) != wb.end()) {
            unconditionalFlat += wb.at(stats::ATKFlat);
        } else if (wb.find(stats::ATKPercent) != wb.end()) {
            unconditionalPercent += wb.at(stats::ATKPercent);
        }

        // total
        double totalATK = (baseATK * (1 + unconditionalPercent / 100.0)) + unconditionalFlat;

        return totalATK;
    }

    double calculateDEF(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // character defense
        int baseDEF = baseCharacter.stats.def;

        // stat bonuses to do math with
        double unconditionalPercent = sb.at(stats::DEFPercent);
        double unconditionalFlat = sb.at(stats::DEFFlat);

        // wengine bonuses
        if (wb.find(stats::DEFFlat) != wb.end()) {
            unconditionalFlat += wb.at(stats::DEFFlat);
        } else if (wb.find(stats::DEFPercent) != wb.end()) {
            unconditionalPercent += wb.at(stats::DEFPercent);
        }

        // apply stat bonuses
        double totalDEF = (baseDEF * (1 + unconditionalPercent / 100.0)) + unconditionalFlat;

        return totalDEF;
    }

    double calculateHP(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // character HP
        double baseHP = baseCharacter.stats.hp;

        // stat bonuses to do math with
        double unconditionalPercent = sb.at(stats::HPPercent);
        double unconditionalFlat = sb.at(stats::HPFlat);

        // wengine bonuses
        if (wb.find(stats::HPPercent) != wb.end()) {
            unconditionalPercent += wb.at(stats::HPPercent);
        } else if (wb.find(stats::HPFlat) != wb.end()) {
            unconditionalFlat += wb.at(stats::HPFlat);
        }

        // total
        double totalHP = (baseHP * (1 + unconditionalPercent / 100.0)) + unconditionalFlat;

        return totalHP;
    }

    double calculateCritRate(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // apply stat bonuses (crit rate is additive, as its already a percentage)
        double totalCR = baseCharacter.stats.cr + sb.at(stats::CritRate) + wb.at(stats::CritRate);

        return totalCR;
    }

    double calculateCritDamage(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // apply stat bonuses (crit damage is additive, as its already a percentage)
        double totalCD = baseCharacter.stats.cd + sb.at(stats::CritDamage) + wb.at(stats::CritDamage);

        return totalCD;
    }

    double calculateAnomalyProficiency(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // apply stat bonuses (anomaly proficiency is flat, and since its damage calculation takes 1% of it, there is no percentage increase)
        double totalAP = baseCharacter.stats.ap + wb.at(stats::AnomalyProficiency) + sb.at(stats::AnomalyProficiency);

        return totalAP;
    }

    double calculateAnomalyMastery(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // apply stat bonuses
        double totalAM = baseCharacter.stats.am + sb.at(stats::AnomalyMastery);

        return totalAM;
    }

    double calculateImpact(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // character impact
        double baseImpact = baseCharacter.stats.impact;

        // stat bonuses to do math with
        double unconditionalPercent = sb.at(stats::ImpactPercent);
        double unconditionalFlat = sb.at(stats::ImpactFlat);

        // wengine bonuses
        if (wb.find(stats::ImpactFlat) != wb.end()) {
            unconditionalFlat += wb.at(stats::ImpactFlat);
        } else if (wb.find(stats::ImpactPercent) != wb.end()) {
            unconditionalPercent += wb.at(stats::ImpactPercent);
        }

        // total
        double totalImpact = (baseImpact * (1 + unconditionalPercent / 100.0)) + unconditionalFlat;

        return totalImpact;
    }

    double calculatePEN(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // pen is flat, so there is no percentage to calculate 
        double totalPEN = baseCharacter.stats.pen + sb.at(stats::PEN);

        return totalPEN;
    }

    double calculatePENRatio(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // pen ratio is only additive (its a percentage to begin with) so no fancy math
        double totalPENRatio = baseCharacter.stats.penr + wb.at(stats::PenRatio) + sb.at(stats::PenRatio);

        return totalPENRatio;
    }

    double calculateDamagePercent(const character::character & baseCharacter, const std::map<stats, double> & wb, const std::map<stats, double> & sb) {
        // a switch to check character attribute and add corresponding damage bonus
        switch (baseCharacter.attribute) {
            case attribute::Fire:
                return sb.at(stats::FireDamage);
            case attribute::Physical:
                return sb.at(stats::PhysicalDamage);
            case attribute::Ether:
                return sb.at(stats::EtherDamage);
            case attribute::Ice:
                return sb.at(stats::IceDamage);
            case attribute::Electric:
                return sb.at(stats::ElectricDamage);
            default:
                return 0.0;
        }
    }

    double calculateER(const character::character &baseCharacter, const std::map<stats, double> &wb, const std::map<stats, double> &sb) {
        // character energy regen
        double baseER = baseCharacter.stats.er;

        // apply stat bonuses
        double unconditionalPercent = sb.at(stats::EnergyRegenPercent);
        double unconditionalFlat = sb.at(stats::EnergyRegenFlat);

        double totalER = (baseER * (1 + unconditionalPercent / 100.0)) + unconditionalFlat;

        return totalER;
    }
    double calculateSF(const character::character &baseCharacter, const std::map<stats, double> &wb, const std::map<stats, double> &sb) {
        // sheer force is special, calculated as 30% of attack stat (game mechanic) + 10% of hp (all rupture agent core passive) + any additional sources
        return baseCharacter.stats.atk * 0.3 + baseCharacter.stats.hp * 0.1;
    }

    character::character calculateAll(const character::character & baseCharacter, const wengine::wengine & baseWengine, const std::vector<disc> & discs) {

      for (size_t i = 0; i < discs.size(); ++i) {
        qDebug() << "disc" << i << "mainStat"
                 << static_cast<int>(discs[i].getMainStat()) << "mainVal"
                 << discs[i].getMainStatValue() << "sub1"
                 << static_cast<int>(discs[i].getSubStat1()) << "v"
                 << discs[i].getSub1Value();
      }
        character::character calculatedCharacter = baseCharacter;

        // maps for stat bonuses
        std::map<stats, double> statBonuses = { 
            {stats::ATKFlat, 0},
            {stats::ATKPercent, 0},
            {stats::DEFFlat, 0},
            {stats::DEFPercent, 0},
            {stats::HPFlat, 0},
            {stats::HPPercent, 0},
            {stats::CritRate, 0},
            {stats::CritDamage, 0},
            {stats::AnomalyProficiency, 0},
            {stats::AnomalyMastery, 0},
            {stats::AnomalyProficiency, 0},
            {stats::PenRatio, 0},
            {stats::PEN, 0},
            {stats::FireDamage, 0},
            {stats::PhysicalDamage, 0},
            {stats::EtherDamage, 0},
            {stats::IceDamage, 0},
            {stats::ElectricDamage, 0},
            {stats::ImpactFlat, 0},
            {stats::ImpactPercent, 0},
            {stats::EnergyRegenFlat, 0},
            {stats::EnergyRegenPercent, 0},
            {stats::SheerForce, 0},
            {stats::AdrenalineRegen, 0}
        };

        std::map<stats, double> wengineBonus = statBonuses;

        // statBonuses = calculateDiscStats(discs); <- to be implemented later
        wengineBonus = calculateWengineBonus(baseWengine, wengineBonus);

        // calculate disc bonuses
        statBonuses = calculateDiscStats(discs, statBonuses);

        
        //add base attack from wengines
        statBonuses[stats::ATKFlat] += baseWengine.baseAtk;

        calculatedCharacter.stats.atk = calculateATK(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.def = calculateDEF(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.hp = calculateHP(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.cr = calculateCritRate(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.cd = calculateCritDamage(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.am = calculateAnomalyMastery(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.ap = calculateAnomalyProficiency(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.penr = calculatePENRatio(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.impact = calculateImpact(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.er = calculateER(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.aaa = calculateDamagePercent(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.pen = calculatePEN(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.damagePercent = calculateDamagePercent(calculatedCharacter, wengineBonus, statBonuses);
        calculatedCharacter.stats.sf = calculateSF(calculatedCharacter, wengineBonus, statBonuses);

        return calculatedCharacter;
    }
}