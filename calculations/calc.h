#pragma once

#include "../data/character.h"
#include "../data/wengine.h"
#include "../data/disc.h"

namespace calc {
    //enum for different main stats
    enum class mainStat {
        ATK,
        ATKPercent,
        DEF,
        DEFPercent,
        HP,
        HPPercent,
        CritRate,
        CritDamage,
        AnomalyProficiency,
        AnomalyMastery,
        PenRatio,
        FireDamage,
        PhysicalDamage,
        EtherDamage,
        IceDamage,
        ElectricDamage,
        Impact,
        EnergyRegen
    };
    
    // struct to hold calculated disc stats
    struct discStats {
        int flatAtk;
        double percentAtk;
        int flatDef;
        double percentDef;
        int flatHP;
        double percentHP;
    };
    
    // calculation of disc stats to be used in overall calculations
    discStats calculateDiscStats(const std::vector<disc> & discs);


    double calculateATK(const character::character & baseCharacter, const wengine::wengine & baseWengine, const discStats & ds);
    double calculateDEF(const character::character & baseCharacter, const wengine::wengine & baseWengine, const discStats & ds);
    double calculateHP(const character::character & baseCharacter, const wengine::wengine & baseWengine, const discStats & ds);

    //  the calculate everything function
    character::character calculateAll(const character::character & baseCharacter, const wengine::wengine & baseWengine, const std::vector<disc> & discs);
}