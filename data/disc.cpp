#include "disc.h"

disc::disc() {

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