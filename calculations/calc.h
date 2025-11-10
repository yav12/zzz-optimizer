#pragma once

#include <vector>
#include <string>
#include "types.h"

// forward declarations to avoid pulling in data headers here and creating include cycles (ai told me to do this)
namespace character { struct character; }
namespace wengine { struct wengine; }
class disc;

namespace calc {
    
    // struct to hold calculated stat bonuses
    struct statBonuses {
        int flatAtk;
        double percentAtk;
        int flatDef;
        double percentDef;
        int flatHP;
        double percentHP;
        double critRate;
        double critDamage;
        double anomalyProficiency;
        double flatAnomalyMastery;
        double percentAnomalyMastery;
        double penRatio;
        double PEN;
        double fireDamage;
        double physicalDamage;
        double etherDamage;
        double iceDamage;
        double electricDamage;
        double flatImpact;
        double percentImpact;
        double flatEnergyRegen;
        double percentEnergyRegen;
    };
    // struct for the wengine bonus
    struct wengineBonus {
        stats stat;
        double value;
    };
    // calculation of disc stats to be used in overall calculations
    statBonuses calculateDiscStats(const std::vector<disc> & discs);

    //calculate the wengine bonuses
    wengineBonus calculateWengineBonus(const wengine::wengine & baseWengine);
    statBonuses calculateWengineEffect(const character::character & baseCharacter, const wengine::wengine & baseWengine);

    //calculate out of combat stats
    double calculateATK(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateDEF(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateHP(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateImpact(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateAnomalyProficiency(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateAnomalyMastery(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateFireDamage(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculatePhysicalDamage(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateEtherDamage(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateIceDamage(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateElectricDamage(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateCritRate(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateCritDamage(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateDamagePercent(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculatePEN(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);
    double calculateER(const character::character & baseCharacter, const wengineBonus & wb, const statBonuses & ds);

    // the calculate everything function
    character::character calculateAll(const character::character & baseCharacter, const wengine::wengine & baseWengine, const std::vector<disc> & discs);
}