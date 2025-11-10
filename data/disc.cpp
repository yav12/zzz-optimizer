#include "disc.h"

disc::disc() {

}
void disc::setName(std::string discName) {
    // Implementation for setting the name of the disc
    name = discName;
}

void disc::setSlot(int slotNumber) {
    // Implementation for setting the slot of the disc (1-6)
    slot = slotNumber;
}

void disc::setMainStat(std::string stat) {
    // set what the main stat should be based on string (or slot if 1-3)
    if (slot == 1) {
        mainStat = calc::mainStat::ATK;
    } else if (slot == 2) {
        mainStat = calc::mainStat::ATKPercent;
    } else if (slot == 3) {
        mainStat = calc::mainStat::DEF;
    } else {
        if (stat == "HP") {
            mainStat = calc::mainStat::HP;
        } else if (stat == "ATK") {
            mainStat = calc::mainStat::ATK;
        } else if (stat == "DEF") {
            mainStat = calc::mainStat::DEF;
        } else if (stat == "HP%") {
            mainStat = calc::mainStat::HPPercent;
        } else if (stat == "ATK%") {
            mainStat = calc::mainStat::ATKPercent;
        } else if (stat == "DEF%") {
            mainStat = calc::mainStat::DEFPercent;
        } else if (stat == "CRIT Rate") {
            mainStat = calc::mainStat::CritRate;
        } else if (stat == "CRIT Damage") {
            mainStat = calc::mainStat::CritDamage;
        } else if (stat == "Anomaly Proficiency") {
            mainStat = calc::mainStat::AnomalyProficiency;
        } else if (stat == "Anomaly Mastery") {
            mainStat = calc::mainStat::AnomalyMastery;
        } else if (stat == "PEN Ratio") {
            mainStat = calc::mainStat::PenRatio;
        } else if (stat == "Fire Damage") {
            mainStat = calc::mainStat::FireDamage;
        } else if (stat == "Physical Damage") {
            mainStat = calc::mainStat::PhysicalDamage;
        } else if (stat == "Ether Damage") {
            mainStat = calc::mainStat::EtherDamage;
        } else if (stat == "Ice Damage") {
            mainStat = calc::mainStat::IceDamage;
        } else if (stat == "Electric Damage") {
            mainStat = calc::mainStat::ElectricDamage;
        }
    }
}

void disc::setSub1(std::string stat, int level) {
    // Implementation for setting the first substat of the disc
    subStat1 = stat;
    sub1Level = level;
    calculateSubValue(sub1Level, subStat1, subStat1Value);
}

void disc::setSub2(std::string stat, int level) {
    // Implementation for setting the second substat of the disc
    subStat2 = stat;
    sub2Level = level;
    calculateSubValue(sub2Level, subStat2, subStat2Value);
}

void disc::setSub3(std::string stat, int level) {
    // Implementation for setting the third substat of the disc
    subStat3 = stat;
    sub3Level = level;
    calculateSubValue(sub3Level, subStat3, subStat3Value);
}

void disc::setSub4(std::string stat, int level) {
    // Implementation for setting the fourth substat of the disc
    subStat4 = stat;
    sub4Level = level;
    calculateSubValue(sub4Level, subStat4, subStat4Value);
}

void disc::calculateSubValue(int level, std::string stat, double& value) {
    auto apply = [&](auto &base){
        if (stat == "HP") {
            value = base.hp * level;
        } else if (stat == "ATK") {
            value = base.atk * level;
        } else if (stat == "DEF") {
            value = base.def * level;
        } else if (stat == "HP%") {
            value = base.hpPercent * level;
        } else if (stat == "ATK%") {
            value = base.atkPercent * level;
        } else if (stat == "DEF%") {
            value = base.defPercent * level;
        } else if (stat == "CRIT Rate") {
            value = base.critRate * level;
        } else if (stat == "CRIT Damage") {
            value = base.critDmg * level;
        } else if (stat == "Anomaly Proficiency") {
            value = base.AP * level;
        } else if (stat == "PEN") {
            value = base.PEN * level;
        } else {
            value = 0; // how did you get this?
        }
    };

    if (rank == "B") {
        baseValues::b b;
        apply(b);
    } else if (rank == "A") {
        baseValues::a a;
        apply(a);
    } else if (rank == "S") {
        baseValues::s s;
        apply(s);
    } else {
        value = 0; // unknown rank
    }
}

calc::mainStat disc::getMainStat() const {
    return mainStat;
}
double disc::getMainStatValue() const {
    return mainStatValue;
}