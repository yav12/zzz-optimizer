// define bonuses for disks

const woodpecker = {
    bonusCritRate: 8 //percent
}
const puffer = {
    bonusPENRatio: 8 //percent
}
const shockstar = {
    bonusImpact: 6 //percent
}
const freedom = {
    bonusAP: 30  //flat
}
const hormone = {
    bonusAttack: 10 //percent
}
const soul = {
    bonusDefense: 16 //percent
}
const swingJazz = {
    bonusEnergyRegen: 20 //percent
}
const chaosJazz = {
    bonusAP: 30 //flat
}
const protoPunk = {
    bonusShield: 15 //percent
}
const moonlightLullaby = {
    bonusEnergyRegen: 20 // percent
};
const dawnsBloom = {
    bonusBasicAttackDMG: 15 // percent
};
const kingOfTheSummit = {
    bonusDaze: 6 // percent
};
const yunkuiTales = {
    bonusHP: 10 // percent
};
const phaethonsMelody = {
    bonusAnomalyMastery: 8 // percent
};
const shadowHarmony = {
    bonusAftershockDashDMG: 15 // percent
};
const astralVoice = {
    bonusAttack: 10 // percent
};
const branchAndBladeSong = {
    bonusCritDMG: 16 // percent
};
const fangedMetal = {
    bonusPhysicalDMG: 10 // percent
}
const polarMetal = {
    bonusIceDMG: 10 // percent
};
const thunderMetal = {
    bonusElectricDMG: 10 // percent
};
const chaoticMetal = {
    bonusEtherDMG: 10 // percent
};
const infernoMetal = {
    bonusFireDMG: 10 // percent
};



// calculate before combat frozen stats

function calculateFrozenAttack(character, wengine, twoPieceBonus) {
    return character.stats.ATK * (1 + wengine.bonusAttack + twoPieceBonus) + wengine.baseAttack;
}

function calculateFrozenDefense(character, wengine, twoPieceBonus) {
    return character.stats.DEF * (1 + wengine.bonusDefense + twoPieceBonus) + wengine.baseDefense;
}

function calculateFrozenHP(character, wengine, twoPieceBonus) {
    return character.stats.HP * (1 + wengine.bonusHP + twoPieceBonus) + wengine.baseHP;
}

function calculateFrozenCritRate(character, wengine, twoPieceBonus) {
    return character.stats.critRate + wengine.bonusCritRate + wengine.baseCritRate + twoPieceBonus;
}

