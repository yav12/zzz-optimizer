
function calculateAttack(character, wengine) {
    return character.stats.ATK * (1 + wengine.bonusAttack) + wengine.baseAttack;
}

