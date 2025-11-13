#pragma once

#include <vector>
#include <map>
#include "types.h"

// forward declarations to avoid pulling in data headers here and creating include cycles (ai told me to do this)
namespace character { struct character; }
namespace wengine { struct wengine; }
class disc;

namespace calc {
    // calculation of disc stats to be used in overall calculations
    std::map<stats, double> calculateDiscStats(const std::vector<disc> & discs);

    //calculate the wengine bonuses
    std::map<stats, double> calculateWengineBonus(const wengine::wengine & baseWengine);
    std::map<stats, double> calculateWengineEffect(const character::character & baseCharacter, const wengine::wengine & baseWengine);

    //calculate out of combat stats
    double calculateATK(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateDEF(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateHP(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateImpact(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateAnomalyProficiency(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateAnomalyMastery(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateFireDamage(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculatePhysicalDamage(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateEtherDamage(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateIceDamage(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateElectricDamage(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateCritRate(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateCritDamage(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateDamagePercent(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculatePENRatio(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateER(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);
    double calculateSF(const character::character & baseCharacter, const std::map<stats, double> & wengineBonus, const std::map<stats, double> & statBonuses);

    // the calculate everything function
    character::character calculateAll(const character::character & baseCharacter, const wengine::wengine & baseWengine, const std::vector<disc> & discs);
}