#include "disc.h"

disc::disc() {
    // Default constructor
    rank = "S";
    set = calc::discSet::None;
}
void disc::setSet(calc::discSet discSet) {
    // Implementation for setting the name of the disc
    set = discSet;
}

void disc::setSlot(int slotNumber) {
    // Implementation for setting the slot of the disc (1-6)
    slot = slotNumber;
}

void disc::setMainStat(calc::stats stat) {
    // set what the main stat should be based on string (or slot if 1-3)
    if (slot == 1) {
        mainStat = calc::stats::ATKFlat;
    } else if (slot == 2) {
        mainStat = calc::stats::ATKPercent;
    } else if (slot == 3) {
        mainStat = calc::stats::DEFFlat;
    } else {
        mainStat = stat;
    }

    // set the main stat value (assume s rank and level 15 for now)
    baseValues::s s;
    switch (mainStat) {
        case calc::stats::HPFlat:
            mainStatValue = s.mainHP[14];
            break;
        case calc::stats::ATKFlat:
            mainStatValue = s.mainATK[14];
            break;
        case calc::stats::DEFFlat:
            mainStatValue = s.mainDEF[14];
            break;
        case calc::stats::HPPercent:
            mainStatValue = s.mainHPPercent[14];
            break;
        case calc::stats::ATKPercent:
            mainStatValue = s.mainATKPercent[14];
            break;
        case calc::stats::DEFPercent:
            mainStatValue = s.mainDEFPercent[14];
            break;
        case calc::stats::CritRate:
            mainStatValue = s.mainCritRate[14];
            break;
        case calc::stats::CritDamage:
            mainStatValue = s.mainCritDmg[14];
            break;
        case calc::stats::AnomalyProficiency:
            mainStatValue = s.mainAP[14];
            break;
        case calc::stats::AnomalyMastery:
            mainStatValue = s.mainAM[14];
            break;
        case calc::stats::PenRatio:
            mainStatValue = s.mainPENR[14];
            break;
        case calc::stats::ImpactPercent:
            mainStatValue = s.mainImpact[14];
            break;
        case calc::stats::EnergyRegenPercent:
            mainStatValue = s.mainER[14];
            break;
        default:
            mainStatValue = 0;
            break;
    }

}

void disc::setSub1(calc::stats stat, int level) {
    // Implementation for setting the first substat of the disc
    subStat1 = stat;
    sub1Level = level;
    calculateSubValue(sub1Level, subStat1, subStat1Value);
}

void disc::setSub2(calc::stats stat, int level) {
    // Implementation for setting the second substat of the disc
    subStat2 = stat;
    sub2Level = level;
    calculateSubValue(sub2Level, subStat2, subStat2Value);
}

void disc::setSub3(calc::stats stat, int level) {
    // Implementation for setting the third substat of the disc
    subStat3 = stat;
    sub3Level = level;
    calculateSubValue(sub3Level, subStat3, subStat3Value);
}

void disc::setSub4(calc::stats stat, int level) {
    // Implementation for setting the fourth substat of the disc
    subStat4 = stat;
    sub4Level = level;
    calculateSubValue(sub4Level, subStat4, subStat4Value);
}

void disc::calculateSubValue(int level, calc::stats stat, double& value) {
    level = level + 1; // zero roll is technically 1 roll in that substat, and aditional rolls add to that
    auto apply = [&](auto &base){
        switch (stat) {
            case calc::stats::HPFlat:
                value = base.hp * level;
                break;
            case calc::stats::ATKFlat:
                value = base.atk * level;
                break;
            case calc::stats::DEFFlat:
                value = base.def * level;
                break;
            case calc::stats::HPPercent:
                value = base.hpPercent * level;
                break;
            case calc::stats::ATKPercent:
                value = base.atkPercent * level;
                break;
            case calc::stats::DEFPercent:
                value = base.defPercent * level;
                break;
            case calc::stats::CritRate:
                value = base.critRate * level;
                break;
            case calc::stats::CritDamage:
                value = base.critDmg * level;
                break;
            case calc::stats::AnomalyProficiency:
                value = base.AP * level;
                break;
            case calc::stats::PEN:
                value = base.PEN * level;
                break;
            default:
                value = 0;
                break;
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

calc::discSet disc::getSet() const {
    return set;
}

calc::stats disc::getMainStat() const {
    return mainStat;
}
double disc::getMainStatValue() const {
    return mainStatValue;
}
calc::stats disc::getSubStat1() const {
    return subStat1;
}
double disc::getSub1Value() const {
    return subStat1Value;
}
calc::stats disc::getSubStat2() const {
    return subStat2;
}
double disc::getSub2Value() const {
    return subStat2Value;
}
calc::stats disc::getSubStat3() const {
    return subStat3;
}
double disc::getSub3Value() const {
    return subStat3Value;
}
calc::stats disc::getSubStat4() const {
    return subStat4;
}
double disc::getSub4Value() const {
    return subStat4Value;
}