//character data

let billy = JSON.parse(characters/billy.json);

let wengine_starlight_engine_replica = {
    name: "Starlight Engine Replica",
    baseAttack: 624,
    bonusAttack: .25
}

function calculateAttack(character, wengine) {
    return character.stats.ATK * (1 + wengine.bonusAttack) + wengine.baseAttack;
}

