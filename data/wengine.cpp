#include "wengine.h"

void wengine::setWengineData() {
    bashfulDemon.name = "Bashful Demon";
    bashfulDemon.rarity = "A";
    bashfulDemon.specialty = "Support";
    bashfulDemon.baseAtk = 624;
    bashfulDemon.stat = calc::stats::ATKPercent;
    bashfulDemon.statPercent = 25;
    bashfulDemon.effect = R"(Increases Ice DMG by 15%/17.5%/20%/22%/24%. When launching an EX Special Attack, all squad members ' ATK increases by 2%/2.3%/2.6%/2.9%/3.2% for 12s, stacking up to 4 times. Repeated triggers reset the duration. Passive effects of the same name do not stack.)";
    bashfulDemon.image = ":/wengines/support/BashfulDemon.jxl";

    bellicoseBlaze.name = "Bellicose Blaze";
    bellicoseBlaze.rarity = "S";
    bellicoseBlaze.specialty = "Attack";
    bellicoseBlaze.baseAtk = 713;
    bellicoseBlaze.stat = calc::stats::EnergyRegen;
    bellicoseBlaze.statPercent = 60;
    bellicoseBlaze.effect = R"(Increases CRIT Rate by 20%/23%/26%/29%/32%. When the equipper triggers an Aftershock that deals Fire DMG, their attacks ignore 15%/17.2%/19.5%/21.7%/24% of the target's DEF for 8s. Can stack once every 3s, up to 2 stacks. Repeated triggers reset the duration.)";
    bellicoseBlaze.image = ":/wengines/attack/BellicoseBlaze.jxl";

    bigCylinder.name = "Big Cylinder";
    bigCylinder.rarity = "A";
    bigCylinder.specialty = "Defense";
    bigCylinder.baseAtk = 624;
    bigCylinder.stat = calc::stats::DEFPercent;
    bigCylinder.statPercent = 40;
    bigCylinder.effect = R"(Reduces DMG taken by 7.5%/8.5%/9.5%/10.5%/12%. After being attacked, the next attack to hit an enemy will trigger a critical hit and deal 600%/690%/780%/870%/960% of the equipper's DEF as additional DMG. This effect can be triggered once every 7.5s.)";
    bigCylinder.image = ":/wengines/defense/BigCylinder.jxl";

    blazingLaurel.name = "Blazing Laurel";
    blazingLaurel.rarity = "S";
    blazingLaurel.specialty = "Stun";
    blazingLaurel.baseAtk = 713;
    blazingLaurel.stat = calc::stats::Impact;
    blazingLaurel.statPercent = 18;
    blazingLaurel.effect = R"(Upon launching a Quick Assist or Perfect Assist, the equipper's Impact increases by 25%/28.75%/32.5%/36.25%/40% for 8s. When the equipper launches and hits an enemy with a Basic Attack, apply Wilt to the target for 30s, stacking up to 20 times, repeated triggers reset the duration. When any squad member hits an enemy, for every stack of Wilt applied to the target, the CRIT DMG of the Ice DMG and Fire DMG dealt by that attack increases by 1.5%/1.72%/1.95%/2.17%/2.4%. Only one instance of this effect can exist in the same squad.)";
    blazingLaurel.image = ":/wengines/stun/BlazingLaurel.jxl";

    boxCutter.name = "Box Cutter";
    boxCutter.rarity = "A";
    boxCutter.specialty = "Stun";
    boxCutter.baseAtk = 624;
    boxCutter.stat = calc::stats::Impact;
    boxCutter.statPercent = 15;
    boxCutter.effect = R"(Upon launching an Aftershock, the equipper's Physical DMG increases by 15%/17.3%/19.5%/21.8%/24%, and Daze increases by 10%/11.5%/13%/14.5%/16%, lasting 10s.)";
    boxCutter.image = ":/wengines/stun/BoxCutter.jxl";

    bunnyBand.name = "Bunny Band";
    bunnyBand.rarity = "A";
    bunnyBand.specialty = "Defense";
    bunnyBand.baseAtk = 594;
    bunnyBand.stat = calc::stats::DEFPercent;
    bunnyBand.statPercent = 40;
    bunnyBand.effect = R"(Increases Max HP by 8%/9.2%/10.4%/11.6%/12.8%. Increases the equipper's ATK by 10%/11.5%/13%/14.5%/16% when they are shielded.)";
    bunnyBand.image = ":/wengines/defense/BunnyBand.jxl";

    cannonRotor.name = "Cannon Rotor";
    cannonRotor.rarity = "A";
    cannonRotor.specialty = "Attack";
    cannonRotor.baseAtk = 594;
    cannonRotor.stat = calc::stats::CritRate;
    cannonRotor.statPercent = 20;
    cannonRotor.effect = R"(Increases ATK by 7.5%/8.6%/9.7%/10.8%/12%. Landing a critical hit on an enemy will inflict an additional 200% of ATK as DMG. This effect can trigger once every 8s/7.5s/7s/6.5s/6s.)";
    cannonRotor.image = ":/wengines/attack/CannonRotor.jxl";

    cinderCobalt.name = "[Cinder] Cobalt";
    cinderCobalt.rarity = "B";
    cinderCobalt.specialty = "Rupture";
    cinderCobalt.baseAtk = 475;
    cinderCobalt.stat = calc::stats::HPPercent;
    cinderCobalt.statPercent = 20;
    cinderCobalt.effect = R"(Upon entering combat or switching in, the equipper's ATK increases by 7.2%/8.2%/9.3%/10.4%/11.5% for 10s. This effect can trigger once every 20s.)";
    cinderCobalt.image = ":/wengines/rupture/CinderCobalt.jxl";

    cordisGermina.name = "Cordis Germina";
    cordisGermina.rarity = "S";
    cordisGermina.specialty = "Attack";
    cordisGermina.baseAtk = 713;
    cordisGermina.stat = calc::stats::CritRate;
    cordisGermina.statPercent = 24;
    cordisGermina.effect = R"(Increases CRIT Rate by 15%/17%/19%/21%/23%. When the equipper deals DMG with a Basic Attack or EX Special Attack, they gain 1 stack of a buff. Each stack increases the equipper's Electric DMG by 12.5%/14.5%/16.5%/18.5%/20%, up to 2 stacks. Each stack lasts 40s. At 2 stacks, the wearer's Basic Attack and Ultimate DMG ignore 20%/23%/26%/29%/32% of enemy DEF.)";
    cordisGermina.image = ":/wengines/attack/CordisGermina.jxl";

    deepSeaVisitor.name = "Deep Sea Visitor";
    deepSeaVisitor.rarity = "S";
    deepSeaVisitor.specialty = "Attack";
    deepSeaVisitor.baseAtk = 713;
    deepSeaVisitor.stat = calc::stats::CritRate;
    deepSeaVisitor.statPercent = 24;
    deepSeaVisitor.effect = R"(Increases Ice DMG by 25%/31.5%/38%/44.5%/50%. Upon hitting an enemy with a Basic Attack, the equipper's CRIT Rate increases by 10%/12.5%/15%/17.5%/20% for 8s. When dealing Ice DMG with a Dash Attack, the equipper's CRIT Rate increases by an additional 10%/12.5%/15%/17.5%/20% for 15s.)";
    deepSeaVisitor.image = ":/wengines/attack/DeepSeaVisitor.jxl";

    demaraBatteryMarkII.name = "Demara Battery Mark II";
    demaraBatteryMarkII.rarity = "A";
    demaraBatteryMarkII.specialty = "Stun";
    demaraBatteryMarkII.baseAtk = 624;
    demaraBatteryMarkII.stat = calc::stats::Impact;
    demaraBatteryMarkII.statPercent = 15;
    demaraBatteryMarkII.effect = R"(Increases Electric DMG by 15%/17.5%/20%/22%/24%. When the equipper hits an enemy with a Dodge Counter or Assist Attack, their Energy Generation Rate increases by 18%/20.5%/23%/25%/27.5% for 8s.)";
    demaraBatteryMarkII.image = ":/wengines/stun/DemaraBatteryMarkII.jxl";

    dreamlitHearth.name = "Dreamlit Hearth";
    dreamlitHearth.rarity = "S";
    dreamlitHearth.specialty = "Support";
    dreamlitHearth.baseAtk = 713;
    dreamlitHearth.stat = calc::stats::HPPercent;
    dreamlitHearth.statPercent = 30;
    dreamlitHearth.effect = R"(The equipper's Energy Regen increases by 0.4/0.46/0.52/0.58/0.64/s. When the equipper activates Ether Veil or extends its duration, all squad members gain 25%/28.8%/32.5%/36.3%/40% increased DMG and 15%/17.3%/19.5%/21.8%/24% increased Max HP for 45s. Only one instance of this effect can exist in the same squad.)";
    dreamlitHearth.image = ":/wengines/support/DreamlitHearth.jxl";

    drillRigRedAxis.name = "Drill Rig - Red Axis";
    drillRigRedAxis.rarity = "A";
    drillRigRedAxis.specialty = "Attack";
    drillRigRedAxis.baseAtk = 624;
    drillRigRedAxis.stat = calc::stats::EnergyRegen;
    drillRigRedAxis.statPercent = 50;
    drillRigRedAxis.effect = R"(When launching an EX Special Attack or Chain Attack, Electric DMG from Basic Attacks and Dash Attacks increases by 50%/57.5%/65%/72.5%/80% for 10s. This effect can trigger once every 15s.)";
    drillRigRedAxis.image = ":/wengines/attack/DrillRig-RedAxis.jxl";

    elegantVanity.name = "Elegant Vanity";
    elegantVanity.rarity = "S";
    elegantVanity.specialty = "Support";
    elegantVanity.baseAtk = 713;
    elegantVanity.stat = calc::stats::ATKPercent;
    elegantVanity.statPercent = 30;
    elegantVanity.effect = R"(When any squad member enters the field through a Quick Assist, Chain Attack, Defensive Assist, or Evasive Assist, the equipper gains 5/5.5/6/6.5/7 Energy. When the equipper consumes 25 or more Energy, the DMG dealt by all squad members increases by 10%/11.5%/13%/14.5%/16%, stacking up to 2 times, and lasting 20s.)";
    elegantVanity.image = ":/wengines/support/ElegantVanity.jxl";

    electroLipGloss.name = "Electro-Lip Gloss";
    electroLipGloss.rarity = "A";
    electroLipGloss.specialty = "Anomaly";
    electroLipGloss.baseAtk = 594;
    electroLipGloss.stat = calc::stats::AnomalyProficiency;
    electroLipGloss.statPercent = 75;
    electroLipGloss.effect = R"(When there are enemies inflicted with Attribute Anomaly on the field, the equipper's ATK increases by 10%/11.5%/13%/14.5%/16% and they deal an additional 15%/17.5%/20%/22.5%/25% more DMG to the target.)";
    electroLipGloss.image = ":/wengines/anomaly/ElectroLipGloss.jxl";

    gildedBlossom.name = "Gilded Blossom";
    gildedBlossom.rarity = "A";
    gildedBlossom.specialty = "Attack";
    gildedBlossom.baseAtk = 594;
    gildedBlossom.stat = calc::stats::ATKPercent;
    gildedBlossom.statPercent = 25;
    gildedBlossom.effect = R"(ATK increases by 6%/6.9%/7.8%/8.7%/9.6%, and DMG dealt by EX Special Attacks increases by 15%/17.2%/19.5%/21.8%/24%.)";
    gildedBlossom.image = ":/wengines/attack/GildedBlossom.jxl";

    grillOWisp.name = "Grill O'Wisp";
    grillOWisp.rarity = "A";
    grillOWisp.specialty = "Rupture";
    grillOWisp.baseAtk = 624;
    grillOWisp.stat = calc::stats::HPPercent;
    grillOWisp.statPercent = 25;
    grillOWisp.effect = R"(The equipper's Fire DMG increases by 15%/17.25%/19.5%/21.75%/24%. When the equipper's HP decreases, their CRIT Rate increases by 15%/17.25%/19.5%/21.75%/24% for 5s.)";
    grillOWisp.image = ":/wengines/rupture/GrillOWisp.jxl";

    hailstormShrine.name = "Hailstorm Shrine";
    hailstormShrine.rarity = "S";
    hailstormShrine.specialty = "Anomaly";
    hailstormShrine.baseAtk = 743;
    hailstormShrine.stat = calc::stats::CritRate;
    hailstormShrine.statPercent = 24;
    hailstormShrine.effect = R"(CRIT DMG increases by 50%/57%/65%/72%/80%. When using an EX Special Attack or when any squad member applies an Attribute Anomaly to an enemy, the equipper's Ice DMG increases by 20%/23%/26%/29%/32%, stacking up to 2 times and lasting 15s.)";
    hailstormShrine.image = ":/wengines/anomaly/HailstormShrine.jxl";

    heartstringNocturne.name = "Heartstring Nocturne";
    heartstringNocturne.rarity = "S";
    heartstringNocturne.specialty = "Attack";
    heartstringNocturne.baseAtk = 713;
    heartstringNocturne.stat = calc::stats::CritRate;
    heartstringNocturne.statPercent = 24;
    heartstringNocturne.effect = R"(CRIT DMG increases by 50%/57.5%/65%/72.5%/80%. When the equipper enters combat, or activates a Chain Attack or Ultimate, they gain 1 stack of Heartstring. Each stack allows Chain Attack and Ultimate to ignore 12.5%/14.5%/16.5%/18.5%/20% of target Fire RES, stacking up to 2 times and lasting 30s.)";
    heartstringNocturne.image = ":/wengines/attack/HeartstringNocturne.jxl";

    hellfireGears.name = "Hellfire Gears";
    hellfireGears.rarity = "S";
    hellfireGears.specialty = "Stun";
    hellfireGears.baseAtk = 684;
    hellfireGears.stat = calc::stats::Impact;
    hellfireGears.statPercent = 18;
    hellfireGears.effect = R"(While off-field, the equipper's Energy Regen increases by 0.6/0.75/0.9/1.05/1.2/s. When using an EX Special Attack, the equipper's Impact is increased by 10%/12.5%/15%/17.5%/20% for 10s, stacking up to 2 times.)";
    hellfireGears.image = ":/wengines/stun/HellfireGears.jxl";

    housekeeper.name = "Housekeeper";
    housekeeper.rarity = "A";
    housekeeper.specialty = "Attack";
    housekeeper.baseAtk = 624;
    housekeeper.stat = calc::stats::ATKPercent;
    housekeeper.statPercent = 25;
    housekeeper.effect = R"(While off-field, the equipper's Energy Regen increases by 0.45/0.52/0.58/0.65/0.72 /s. When an EX Special Attack hits an enemy, the equipper's Physical DMG increases by 3%/3.5%/4%/4.4%/4.8%, stacking up to 15 times and lasting 1s.)";
    housekeeper.image = ":/wengines/attack/Housekeeper.jxl";

    iceJadeTeapot.name = "Ice-Jade Teapot";
    iceJadeTeapot.rarity = "S";
    iceJadeTeapot.specialty = "Stun";
    iceJadeTeapot.baseAtk = 713;
    iceJadeTeapot.stat = calc::stats::Impact;
    iceJadeTeapot.statPercent = 18;
    iceJadeTeapot.effect = R"(When a Basic Attack hits an enemy, gain 1 stack of Tea-riffic. Each stack increases Impact and can lead to a squad-wide DMG buff when ≥15 stacks.)";
    iceJadeTeapot.image = ":/wengines/stun/Ice-JadeTeapot.jxl";

    identityBase.name = "[Identity] Base";
    identityBase.rarity = "B";
    identityBase.specialty = "Defense";
    identityBase.baseAtk = 475;
    identityBase.stat = calc::stats::HPPercent;
    identityBase.statPercent = 20;
    identityBase.effect = R"(When attacked, the equipper's DEF increases by 20%/23%/26%/29%/32% for 8s.)";
    identityBase.image = ":/wengines/defense/IdentityBase.jxl";

    identityInflection.name = "[Identity] Inflection";
    identityInflection.rarity = "B";
    identityInflection.specialty = "Defense";
    identityInflection.baseAtk = 475;
    identityInflection.stat = calc::stats::DEFPercent;
    identityInflection.statPercent = 32;
    identityInflection.effect = R"(When attacked, reduces the attacker's DMG by 6%/7%/8%/9%/10% for 12s.)";
    identityInflection.image = ":/wengines/defense/IdentityInflection.jxl";

    kaboomTheCannon.name = "Kaboom the Cannon";
    kaboomTheCannon.rarity = "A";
    kaboomTheCannon.specialty = "Support";
    kaboomTheCannon.baseAtk = 624;
    kaboomTheCannon.stat = calc::stats::EnergyRegen;
    kaboomTheCannon.statPercent = 50;
    kaboomTheCannon.effect = R"(When any friendly unit in the squad attacks and hits an enemy, all friendly units' ATK increases by 2.5%/2.8%/3.2%/3.6%/4% for 8s, stacking up to 4 times. Passive effects of the same name do not stack.)";
    kaboomTheCannon.image = ":/wengines/support/KaboomtheCannon.jxl";

    lunarDecrescent.name = "[Lunar] Decrescent";
    lunarDecrescent.rarity = "B";
    lunarDecrescent.specialty = "Attack";
    lunarDecrescent.baseAtk = 475;
    lunarDecrescent.stat = calc::stats::ATKPercent;
    lunarDecrescent.statPercent = 20;
    lunarDecrescent.effect = R"(Launching a Chain Attack or Ultimate increases the equipper's DMG by 15%/17.5%/20%/22.5%/25% for 6s.)";
    lunarDecrescent.image = ":/wengines/attack/LunarDecrescent.jxl";

    lunarNoviluna.name = "[Lunar] Noviluna";
    lunarNoviluna.rarity = "B";
    lunarNoviluna.specialty = "Attack";
    lunarNoviluna.baseAtk = 475;
    lunarNoviluna.stat = calc::stats::CritRate;
    lunarNoviluna.statPercent = 16;
    lunarNoviluna.effect = R"(Launching an EX Special Attack generates 3/3.5/4/4.5/5 Energy for the equipper. This effect can trigger once every 12s.)";
    lunarNoviluna.image = ":/wengines/attack/LunarNoviluna.jxl";

    lunarPleniluna.name = "[Lunar] Pleniluna";
    lunarPleniluna.rarity = "B";
    lunarPleniluna.specialty = "Attack";
    lunarPleniluna.baseAtk = 475;
    lunarPleniluna.stat = calc::stats::ATKPercent;
    lunarPleniluna.statPercent = 20;
    lunarPleniluna.effect = R"(Basic Attack, Dash Attack, and Dodge Counter DMG increases by 12%/14%/16%/18%/20%.)";
    lunarPleniluna.image = ":/wengines/attack/LunarPleniluna.jxl";

    marcatoDesire.name = "Marcato Desire";
    marcatoDesire.rarity = "A";
    marcatoDesire.specialty = "Attack";
    marcatoDesire.baseAtk = 594;
    marcatoDesire.stat = calc::stats::CritRate;
    marcatoDesire.statPercent = 20;
    marcatoDesire.effect = R"(When an EX Special Attack or Chain Attack hits an enemy, the equipper's ATK increases by 6%/6.9%/7.8%/8.7%/9.6% for 8s. While the target is under an Attribute Anomaly, this effect is increased by an additional 6%/6.9%/7.8%/8.7%/9.6%.)";
    marcatoDesire.image = ":/wengines/attack/MarcatoDesire.jxl";

    metanukimorphosis.name = "Metanukimorphosis";
    metanukimorphosis.rarity = "S";
    metanukimorphosis.specialty = "Support";
    metanukimorphosis.baseAtk = 713;
    metanukimorphosis.stat = calc::stats::EnergyRegen;
    metanukimorphosis.statPercent = 60;
    metanukimorphosis.effect = R"(When the equipper's EX Special Attack or Ultimate deals Physical DMG, their Anomaly Mastery increases by 30/34/39/43/48 for 40s. When the equipper's Aftershock hits an enemy, all squad members' Anomaly Proficiency increases by 60 for 40s.)";
    metanukimorphosis.image = ":/wengines/support/Metanukimorphosis.jxl";

    myriadEclipse.name = "Myriad Eclipse";
    myriadEclipse.rarity = "S";
    myriadEclipse.specialty = "Attack";
    myriadEclipse.baseAtk = 713;
    myriadEclipse.stat = calc::stats::CritRate;
    myriadEclipse.statPercent = 24;
    myriadEclipse.effect = R"(Increases CRIT DMG by 45%/51.75%/58.5%/65.25%/72%. When using an EX Special Attack, Chain Attack, or Ultimate to deal Ice DMG, the equipper gains the Absolute Zero Death Sentence effect for 3s, which ignores a portion of enemy DEF.)";
    myriadEclipse.image = ":/wengines/attack/MyriadEclipse.jxl";

    originalTransmorpher.name = "Original Transmorpher";
    originalTransmorpher.rarity = "A";
    originalTransmorpher.specialty = "Defense";
    originalTransmorpher.baseAtk = 594;
    originalTransmorpher.stat = calc::stats::HPPercent;
    originalTransmorpher.statPercent = 25;
    originalTransmorpher.effect = R"(Increases Max HP by 8%/9%/10%/11%/12.5%. When attacked, the equipper's Impact is increased by 10%/11.5%/13%/14.5%/16% for 12s.)";
    originalTransmorpher.image = ":/wengines/defense/OriginalTransmorpher.jxl";

    peacekeeperSpecialized.name = "Peacekeeper - Specialized";
    peacekeeperSpecialized.rarity = "A";
    peacekeeperSpecialized.specialty = "Defense";
    peacekeeperSpecialized.baseAtk = 624;
    peacekeeperSpecialized.stat = calc::stats::ATKPercent;
    peacekeeperSpecialized.statPercent = 25;
    peacekeeperSpecialized.effect = R"(While Shielded, the equipper's Energy Regen increases by 0.4/0.46/0.52/0.58/0.64 /s. The Anomaly Buildup of EX Special Attacks and Assist Follow-Ups increase by 36%/40%/45%/50%/55%.)";
    peacekeeperSpecialized.image = ":/wengines/defense/Peacekeeper-Specialized.jxl";

    practicedPerfection.name = "Practiced Perfection";
    practicedPerfection.rarity = "S";
    practicedPerfection.specialty = "Anomaly";
    practicedPerfection.baseAtk = 713;
    practicedPerfection.stat = calc::stats::ATKPercent;
    practicedPerfection.statPercent = 30;
    practicedPerfection.effect = R"(The equipper's Anomaly Mastery increases by 60/69/78/87/96. When inflicting Assault, the equipper's Physical DMG increases by 20%/23%/26%/29%/32% for 20s, stacking up to 2 times.)";
    practicedPerfection.image = ":/wengines/anomaly/PracticedPerfection.jxl";

    preciousFossilizedCore.name = "Precious Fossilized Core";
    preciousFossilizedCore.rarity = "A";
    preciousFossilizedCore.specialty = "Stun";
    preciousFossilizedCore.baseAtk = 594;
    preciousFossilizedCore.stat = calc::stats::Impact;
    preciousFossilizedCore.statPercent = 15;
    preciousFossilizedCore.effect = R"(When the target's HP is no lower than 50%, the equipper inflicts 10%/11.5%/13%/14.5%/16% more Daze to the target. When the target's HP is no lower than 75%, this bonus is further increased by 10%/11.5%/13%/14.5%/16%.)";
    preciousFossilizedCore.image = ":/wengines/stun/PreciousFossilizedCore.jxl";

    puzzleSphere.name = "Puzzle Sphere";
    puzzleSphere.rarity = "A";
    puzzleSphere.specialty = "Rupture";
    puzzleSphere.baseAtk = 594;
    puzzleSphere.stat = calc::stats::ATKPercent;
    puzzleSphere.statPercent = 25;
    puzzleSphere.effect = R"(Upon launching an EX Special Attack, the equipper's CRIT DMG increases by 16%/18.4%/20.8%/23.2%/25.6% for 12s. Additionally, if the target's current HP is below 50% of their Max HP, EX Special Attack DMG increases by 20%/23%/26%/29%/32%.)";
    puzzleSphere.image = ":/wengines/rupture/PuzzleSphere.jxl";

    qingmingBirdcage.name = "Qingming Birdcage";
    qingmingBirdcage.rarity = "S";
    qingmingBirdcage.specialty = "Rupture";
    qingmingBirdcage.baseAtk = 743;
    qingmingBirdcage.stat = calc::stats::HPPercent;
    qingmingBirdcage.statPercent = 30;
    qingmingBirdcage.effect = R"(CRIT Rate increases by 20%/23%/26%/29%/32%. When launching an EX Special Attack, the character gains Qingming Companion stacks that increase Ether DMG and Ultimate/EX Sheer DMG.)";
    qingmingBirdcage.image = ":/wengines/rupture/QingmingBirdcage.jxl";

    radiowaveJourney.name = "Radiowave Journey";
    radiowaveJourney.rarity = "A";
    radiowaveJourney.specialty = "Rupture";
    radiowaveJourney.baseAtk = 594;
    radiowaveJourney.stat = calc::stats::HPPercent;
    radiowaveJourney.statPercent = 25;
    radiowaveJourney.effect = R"(When launching a Chain Attack or Ultimate, the equipper gains stacks that increase Sheer Force by 80/92/104/116/128, stacking up to 3 times and lasting 12s.)";
    radiowaveJourney.image = ":/wengines/rupture/RadiowaveJourney.jxl";

    rainforestGourmet.name = "Rainforest Gourmet";
    rainforestGourmet.rarity = "A";
    rainforestGourmet.specialty = "Anomaly";
    rainforestGourmet.baseAtk = 594;
    rainforestGourmet.stat = calc::stats::AnomalyProficiency;
    rainforestGourmet.statPercent = 75;
    rainforestGourmet.effect = R"(For every 10 Energy consumed, the equipper gains a buff that increases ATK by 2.5%/2.8%/3.2%/3.6%/4% for 10s, stacking up to 10 times.)";
    rainforestGourmet.image = ":/wengines/anomaly/RainforestGourmet.jxl";

    reelProjector.name = "Reel Projector";
    reelProjector.rarity = "A";
    reelProjector.specialty = "Defense";
    reelProjector.baseAtk = 594;
    reelProjector.stat = calc::stats::Impact;
    reelProjector.statPercent = 15;
    reelProjector.effect = R"(When a squad member's HP is >=50%, they take less DMG and less Miasma Contamination. Only one instance of this effect can exist in the same squad.)";
    reelProjector.image = ":/wengines/defense/ReelProjector.jxl";

    reverbMarkI.name = "[Reverb] Mark I";
    reverbMarkI.rarity = "B";
    reverbMarkI.specialty = "Support";
    reverbMarkI.baseAtk = 475;
    reverbMarkI.stat = calc::stats::ATKPercent;
    reverbMarkI.statPercent = 20;
    reverbMarkI.effect = R"(Launching an EX Special Attack increases all squad members' Impact by 8%/9%/10%/11%/12% for 10s. Passive effects of the same name do not stack.)";
    reverbMarkI.image = ":/wengines/support/ReverbMarkI.jxl";

    reverbMarkII.name = "[Reverb] Mark II";
    reverbMarkII.rarity = "B";
    reverbMarkII.specialty = "Support";
    reverbMarkII.baseAtk = 475;
    reverbMarkII.stat = calc::stats::EnergyRegen;
    reverbMarkII.statPercent = 40;
    reverbMarkII.effect = R"(Launching an EX Special Attack or Chain Attack increases all squad members' Anomaly Mastery and Anomaly Proficiency by 10/12/13/15/16 for 10s.)";
    reverbMarkII.image = ":/wengines/support/ReverbMarkII.jxl";

    reverbMarkIII.name = "[Reverb] Mark III";
    reverbMarkIII.rarity = "B";
    reverbMarkIII.specialty = "Support";
    reverbMarkIII.baseAtk = 475;
    reverbMarkIII.stat = calc::stats::HPPercent;
    reverbMarkIII.statPercent = 20;
    reverbMarkIII.effect = R"(Launching a Chain Attack or Ultimate increases all squad members' ATK by 8%/9%/10%/11%/12% for 10s. Passive effects of the same name do not stack.)";
    reverbMarkIII.image = ":/wengines/support/ReverbMarkIII.jxl";

    riotSuppressorMarkVI.name = "Riot Suppressor Mark VI";
    riotSuppressorMarkVI.rarity = "S";
    riotSuppressorMarkVI.specialty = "Attack";
    riotSuppressorMarkVI.baseAtk = 713;
    riotSuppressorMarkVI.stat = calc::stats::CritDamage;
    riotSuppressorMarkVI.statPercent = 48;
    riotSuppressorMarkVI.effect = R"(Increases CRIT Rate by 15%/18.8%/22.6%/26.4%/30%. Launching an EX Special Attack grants the equipper 8 Charge stacks; consuming stacks increases Basic/Dash Attack Ether DMG.)";
    riotSuppressorMarkVI.image = ":/wengines/attack/RiotSuppressorMarkVI.jxl";

    roaringFurnace.name = "Roaring Fur-nace";
    roaringFurnace.rarity = "S";
    roaringFurnace.specialty = "Stun";
    roaringFurnace.baseAtk = 713;
    roaringFurnace.stat = calc::stats::ATKPercent;
    roaringFurnace.statPercent = 30;
    roaringFurnace.effect = R"(The Daze dealt by EX Special Attack, Chain Attack, and Ultimate increases by 28%/32.2%/36.4%/40.6%/44.8%. Chain Attack/Ultimate Fire DMG increases squad DMG for 30s.)";
    roaringFurnace.image = ":/wengines/stun/RoaringFur-nace.jxl";

    roaringRide.name = "Roaring Ride";
    roaringRide.rarity = "A";
    roaringRide.specialty = "Anomaly";
    roaringRide.baseAtk = 624;
    roaringRide.stat = calc::stats::ATKPercent;
    roaringRide.statPercent = 25;
    roaringRide.effect = R"(When EX Special Attack hits an enemy, one of three possible effects is randomly triggered for 5s: ATK increase, Anomaly Proficiency increase, or Anomaly Buildup Rate increase.)";
    roaringRide.image = ":/wengines/anomaly/RoaringRide.jxl";

    sixShooter.name = "Six Shooter";
    sixShooter.rarity = "A";
    sixShooter.specialty = "Stun";
    sixShooter.baseAtk = 594;
    sixShooter.stat = calc::stats::Impact;
    sixShooter.statPercent = 15;
    sixShooter.effect = R"(The equipper gains 1 Charge stack every 3s, stacking up to 6 times. When launching an EX Special Attack, consumes all Charge stacks and each stack consumed increases the skill's Daze inflicted.)";
    sixShooter.image = ":/wengines/stun/SixShooter.jxl";

    sliceOfTime.name = "Slice of Time";
    sliceOfTime.rarity = "A";
    sliceOfTime.specialty = "Support";
    sliceOfTime.baseAtk = 594;
    sliceOfTime.stat = calc::stats::PenRatio;
    sliceOfTime.statPercent = 20;
    sliceOfTime.effect = R"(Any squad members' key skills generate Decibels and Energy for the equipper. This effect can trigger once every 12s. Passive effects of the same name do not stack.)";
    sliceOfTime.image = ":/wengines/support/SliceofTime.jxl";

    springEmbrace.name = "Spring Embrace";
    springEmbrace.rarity = "A";
    springEmbrace.specialty = "Defense";
    springEmbrace.baseAtk = 594;
    springEmbrace.stat = calc::stats::ATKPercent;
    springEmbrace.statPercent = 25;
    springEmbrace.effect = R"(Reduces DMG taken by 7.5%/8.5%/9.5%/10.5%/12%. When attacked, the equipper's Energy Generation Rate increases by 10%/11.5%/13%/14.5%/16% for 12s. Buff transfers on switch.)";
    springEmbrace.image = ":/wengines/defense/SpringEmbrace.jxl";

    steelCushion.name = "Steel Cushion";
    steelCushion.rarity = "S";
    steelCushion.specialty = "Attack";
    steelCushion.baseAtk = 684;
    steelCushion.stat = calc::stats::CritRate;
    steelCushion.statPercent = 24;
    steelCushion.effect = R"(Increases Physical DMG by 20%/25%/30%/35%/40%. The equipper's DMG increases by 25%/31.5%/38%/44%/50% when hitting the enemy from behind.)";
    steelCushion.image = ":/wengines/attack/SteelCushion.jxl";

    starlightEngine.name = "Starlight Engine";
    starlightEngine.rarity = "A";
    starlightEngine.specialty = "Attack";
    starlightEngine.baseAtk = 594;
    starlightEngine.stat = calc::stats::ATKPercent;
    starlightEngine.statPercent = 25;
    starlightEngine.effect = R"(Launching a Dodge Counter or Quick Assist increases the equipper's ATK by 12%/13.8%/15.6%/17.4%/19.2% for 12s.)";
    starlightEngine.image = ":/wengines/attack/StarlightEngine.jxl";

    starlightEngineReplica.name = "Starlight Engine Replica";
    starlightEngineReplica.rarity = "A";
    starlightEngineReplica.specialty = "Attack";
    starlightEngineReplica.baseAtk = 624;
    starlightEngineReplica.stat = calc::stats::ATKPercent;
    starlightEngineReplica.statPercent = 25;
    starlightEngineReplica.effect = R"(Increases the equipper's Physical DMG against the target by 36%/41%/46.5%/52%/57.5% for 8s upon hitting an enemy at least 6 meters away with a Basic Attack or Dash Attack.)";
    starlightEngineReplica.image = ":/wengines/attack/StarlightEngineReplica.jxl";

    steamOven.name = "Steam Oven";
    steamOven.rarity = "A";
    steamOven.specialty = "Stun";
    steamOven.baseAtk = 594;
    steamOven.stat = calc::stats::EnergyRegen;
    steamOven.statPercent = 50;
    steamOven.effect = R"(For every 10 Energy accumulated, the equipper's Impact is increased by 2%/2.3%/2.6%/2.9%/3.2%, stacking up to 8 times. After Energy is consumed, this bonus remains for 8 more seconds.)";
    steamOven.image = ":/wengines/stun/SteamOven.jxl";

    streetSuperstar.name = "Street Superstar";
    streetSuperstar.rarity = "A";
    streetSuperstar.specialty = "Attack";
    streetSuperstar.baseAtk = 594;
    streetSuperstar.stat = calc::stats::ATKPercent;
    streetSuperstar.statPercent = 25;
    streetSuperstar.effect = R"(Whenever a squad member launches a Chain Attack, the equipper gains 1 Charge stack, stacking up to 3 times. Upon activating their own Ultimate, the equipper consumes all Charge stacks, and each stack increases the skill's DMG by 15%/17.2%/19.5%/21.7%/24%.)";
    streetSuperstar.image = ":/wengines/attack/StreetSuperstar.jxl";

    theVault.name = "The Vault";
    theVault.rarity = "A";
    theVault.specialty = "Support";
    theVault.baseAtk = 624;
    theVault.stat = calc::stats::EnergyRegen;
    theVault.statPercent = 50;
    theVault.effect = R"(Dealing Ether DMG using an EX Special Attack, Chain Attack, or Ultimate increases all units' DMG against the target by 15%/17.5%/20%/22%/24% and increases the equipper's Energy Regen by 0.5/0.58/0.65/0.72/0.8 /s for 2s.)";
    theVault.image = ":/wengines/support/TheVault.jxl";

    tremorTrigramVessel.name = "Tremor Trigram Vessel";
    tremorTrigramVessel.rarity = "A";
    tremorTrigramVessel.specialty = "Defense";
    tremorTrigramVessel.baseAtk = 624;
    tremorTrigramVessel.stat = calc::stats::ATKPercent;
    tremorTrigramVessel.statPercent = 25;
    tremorTrigramVessel.effect = R"(The equipper's EX Special Attack and Ultimate DMG increases by 25%/28.7%/32.5%/36.2%/40%. Whenever any squad member takes DMG or recovers HP, the equipper gains 2/2.3/2.6/2.9/3.2 Energy. This effect can trigger once every 5s.)";
    tremorTrigramVessel.image = ":/wengines/defense/TremorTrigramVessel.jxl";

    unfetteredGameBall.name = "Unfettered Game Ball";
    unfetteredGameBall.rarity = "A";
    unfetteredGameBall.specialty = "Support";
    unfetteredGameBall.baseAtk = 594;
    unfetteredGameBall.stat = calc::stats::EnergyRegen;
    unfetteredGameBall.statPercent = 50;
    unfetteredGameBall.effect = R"(Whenever the equipper's attack triggers an Attribute Counter effect, all units' CRIT Rate against the struck enemy increases by 12%/13.5%/15.5%/17.5%/20% for 12s. Passive effects of the same name do not stack.)";
    unfetteredGameBall.image = ":/wengines/support/UnfetteredGameBall.jxl";

    vortexArrow.name = "[Vortex] Arrow";
    vortexArrow.rarity = "B";
    vortexArrow.specialty = "Stun";
    vortexArrow.baseAtk = 475;
    vortexArrow.stat = calc::stats::Impact;
    vortexArrow.statPercent = 12;
    vortexArrow.effect = R"(The equipper's attacks inflict 8%/9%/10%/11%/12% more Daze on their main target.)";
    vortexArrow.image = ":/wengines/stun/VortexArrow.jxl";

    vortexHatchet.name = "[Vortex] Hatchet";
    vortexHatchet.rarity = "B";
    vortexHatchet.specialty = "Stun";
    vortexHatchet.baseAtk = 475;
    vortexHatchet.stat = calc::stats::EnergyRegen;
    vortexHatchet.statPercent = 40;
    vortexHatchet.effect = R"(Upon entering combat or switching in, the equipper's Impact increases by 9%/10%/11%/12%/13% for 10s. This effect can trigger once every 20s.)";
    vortexHatchet.image = ":/wengines/stun/VortexHatchet.jxl";

    vortexRevolver.name = "[Vortex] Revolver";
    vortexRevolver.rarity = "B";
    vortexRevolver.specialty = "Stun";
    vortexRevolver.baseAtk = 475;
    vortexRevolver.stat = calc::stats::ATKPercent;
    vortexRevolver.statPercent = 20;
    vortexRevolver.effect = R"(EX Special Attacks inflict 10%/11.5%/13%/14.5%/16% more Daze.)";
    vortexRevolver.image = ":/wengines/stun/VortexRevolver.jxl";

    weepingGemini.name = "Weeping Gemini";
    weepingGemini.rarity = "A";
    weepingGemini.specialty = "Anomaly";
    weepingGemini.baseAtk = 594;
    weepingGemini.stat = calc::stats::ATKPercent;
    weepingGemini.statPercent = 25;
    weepingGemini.effect = R"(Whenever a squad member inflicts an Attribute Anomaly on an enemy, the equipper gains a buff that increases Anomaly Proficiency by 30/34/38/42/48, stacking up to 4 times. This effect expires when the target recovers from Stun or is defeated.)";
    weepingGemini.image = ":/wengines/anomaly/WeepingGemini.jxl";

    flamemakerShaker.name = "Flamemaker Shaker";
    flamemakerShaker.rarity = "S";
    flamemakerShaker.specialty = "Anomaly";
    flamemakerShaker.baseAtk = 713;
    flamemakerShaker.stat = calc::stats::ATKPercent;
    flamemakerShaker.statPercent = 30;
    flamemakerShaker.effect = R"(While off - field, the equipper's Energy Regen increases by 0.6/0.75/0.9/1.05/1.2 /s. When hitting an enemy with an EX Special Attack or Assist Attack, the equipper's DMG increases by 3.5%/4.4%/5.2%/6.1%/7%, stacking up to 10 times and lasting for 6s. This effect can trigger once every 0.3s. While off - field, the stack effect is doubled. Repeated triggers reset the duration. Upon obtaining the DMG increase effect, if the number of current stacks is greater than or equal to 5, then the equipper's Anomaly Proficiency increases by 50./62./75./87./100. This Anomaly Proficiency increase does not stack and lasts for 6s.)";
    flamemakerShaker.image = ":/wengines/anomaly/FlamemakerShaker.jxl";

    flightOfFancy.name = "Flight of Fancy";
    flightOfFancy.rarity = "S";
    flightOfFancy.specialty = "Anomaly";
    flightOfFancy.baseAtk = 713;
    flightOfFancy.stat = calc::stats::AnomalyProficiency;
    flightOfFancy.statPercent = 90;
    flightOfFancy.effect = R"(Increases Anomaly Buildup Rate by 40%/46%/52%/58%/64%. When the equipper deals Ether DMG, their Anomaly Proficiency increases by 20/23/26/29/32 for 5s, stacking up to 6 times. This effect can trigger once every 0.5s, and repeated triggers reset the duration.)";
    flightOfFancy.image = ":/wengines/anomaly/FlightofFancy.jxl";

    fusionCompiler.name = "Fusion Compiler";
    fusionCompiler.rarity = "S";
    fusionCompiler.specialty = "Anomaly";
    fusionCompiler.baseAtk = 684;
    fusionCompiler.stat = calc::stats::PenRatio;
    fusionCompiler.statPercent = 24;
    fusionCompiler.effect = R"(Increases ATK by 12%/15%/18%/21%/24%. When using a Special Attack or EX Special Attack, the equipper's Anomaly Proficiency is increased by 25/31/37/43/50 for 8s, stacking up to 3 times. The duration of each stack is calculated separately.)";
    fusionCompiler.image = ":/wengines/anomaly/FusionCompiler.jxl";

    magneticStormAlpha.name = "[Magnetic Storm] Alpha";
    magneticStormAlpha.rarity = "B";
    magneticStormAlpha.specialty = "Anomaly";
    magneticStormAlpha.baseAtk = 475;
    magneticStormAlpha.stat = calc::stats::ATKPercent;
    magneticStormAlpha.statPercent = 20;
    magneticStormAlpha.effect = R"(Accumulating Anomaly Buildup increases the equipper's Anomaly Mastery by 25 for 10s. This effect can trigger once every 20s.)";
    magneticStormAlpha.image = ":/wengines/anomaly/MagneticStormAlpha.jxl";

    magneticStormBravo.name = "[Magnetic Storm] Bravo";
    magneticStormBravo.rarity = "B";
    magneticStormBravo.specialty = "Anomaly";
    magneticStormBravo.baseAtk = 475;
    magneticStormBravo.stat = calc::stats::AnomalyProficiency;
    magneticStormBravo.statPercent = 60;
    magneticStormBravo.effect = R"(Accumulating Anomaly Buildup increases the equipper's Anomaly Proficiency by 25/28/32/36/40 for 10s. This effect can trigger once every 20s.)";
    magneticStormBravo.image = ":/wengines/anomaly/MagneticStormBravo.jxl";

    magneticStormCharlie.name = "[Magnetic Storm] Charlie";
    magneticStormCharlie.rarity = "B";
    magneticStormCharlie.specialty = "Anomaly";
    magneticStormCharlie.baseAtk = 475;
    magneticStormCharlie.stat = calc::stats::PenRatio;
    magneticStormCharlie.statPercent = 16;
    magneticStormCharlie.effect = R"(Whenever a squad member inflicts an Attribute Anomaly on an enemy, the equipper generates 3.5/4/4.5/5/5.5 Energy. This effect can trigger once every 12s.)";
    magneticStormCharlie.image = ":/wengines/anomaly/MagneticStormCharlie.jxl";

    severedInnocence.name = "Severed Innocence";
    severedInnocence.rarity = "S";
    severedInnocence.specialty = "Attack";
    severedInnocence.baseAtk = 713;
    severedInnocence.stat = calc::stats::CritDamage;
    severedInnocence.statPercent = 48;
    severedInnocence.effect = R"(CRIT DMG is increased by 30%/34.5%/39%/43.5%/48%. When the equipper lands a hit with a Basic Attack, Special Attack, or Aftershock, they gain 1 stack of a buff. Each stack increases the equipper's CRIT DMG by an additional 10%/11.5%/13%/14.5%/16%, stacking up to 3 times. The effect lasts for 30s, with each stack ' s duration calculated separately, and can only be triggered once per use of a skill. With all 3 stacks, the equipper's Electric DMG increases by 20%/23%/26%/29%/32%.)";
    severedInnocence.image = ":/wengines/attack/SeveredInnocence.jxl";

    sharpenedStinger.name = "Sharpened Stinger";
    sharpenedStinger.rarity = "S";
    sharpenedStinger.specialty = "Anomaly";
    sharpenedStinger.baseAtk = 713;
    sharpenedStinger.stat = calc::stats::AnomalyProficiency;
    sharpenedStinger.statPercent = 90;
    sharpenedStinger.effect = R"(Upon activating a Dash Attack, gain 1 stack of Predatory Instinct. Each stack of Predatory Instinct increases the equipper's Physical DMG by 12%/15%/18%/21%/24% for 10s, stacking up to 3 times. This effect can trigger once every 0.5s and repeated triggers reset the duration. When entering combat or triggering Perfect Dodge, gain 3 stacks of Predatory Instinct. While Predatory Instinct is at maximum stacks, the equipper's Anomaly Buildup Rate increases by 40%/50%/60%/70%/80%.)";
    sharpenedStinger.image = ":/wengines/anomaly/SharpenedStinger.jxl";

    spectralGaze.name = "Spectral Gaze";
    spectralGaze.rarity = "S";
    spectralGaze.specialty = "Stun";
    spectralGaze.baseAtk = 713;
    spectralGaze.stat = calc::stats::CritRate;
    spectralGaze.statPercent = 24;
    spectralGaze.effect = R"(When the equipper's Aftershock hits an enemy, causing Electric DMG, the target ' s DEF is reduced by 25%/28.75%/32.5%/36.25%/40% for 5s. Passive effects of the same name do not stack. When this effect is triggered, if the equipper is not the active character, they gain 1 stack of Spirit Lock, up to a maximum of 3 stacks. This can trigger only once per use of a skill. Each stack of Spirit Lock increases the equipper's Impact by 4%/4.6%/5.2%/5.8%/6.4%, lasting 12s. The duration of each stack is calculated separately. At full stacks of Spirit Lock, the equipper's Impact increases by an additional 8%/9.2%/10.4%/11.6%/12.8%.)";
    spectralGaze.image = ":/wengines/stun/SpectralGaze.jxl";

    theBrimstone.name = "The Brimstone";
    theBrimstone.rarity = "S";
    theBrimstone.specialty = "Attack";
    theBrimstone.baseAtk = 684;
    theBrimstone.stat = calc::stats::ATKPercent;
    theBrimstone.statPercent = 30;
    theBrimstone.effect = R"(Upon hitting an enemy with a Basic Attack, Dash Attack, or Dodge Counter, the equipper's ATK increases by 3.5%/4.4%/5.2%/6%/7% for 8s, stacking up to 8 times. This effect can trigger once every 0.5s. The duration of each stack is calculated separately.)";
    theBrimstone.image = ":/wengines/attack/TheBrimstone.jxl";

    theRestrained.name = "The Restrained";
    theRestrained.rarity = "S";
    theRestrained.specialty = "Stun";
    theRestrained.baseAtk = 684;
    theRestrained.stat = calc::stats::Impact;
    theRestrained.statPercent = 18;
    theRestrained.effect = R"(When an attack hits an enemy, DMG and Daze from Basic Attacks increase by 6%/7.5%/9%/10.5%/12% for 8s, stacking up to 5 times. This effect can trigger at most once during each skill. The duration of each stack is calculated separately.)";
    theRestrained.image = ":/wengines/stun/TheRestrained.jxl";

    timeweaver.name = "Timeweaver";
    timeweaver.rarity = "S";
    timeweaver.specialty = "Anomaly";
    timeweaver.baseAtk = 713;
    timeweaver.stat = calc::stats::ATKPercent;
    timeweaver.statPercent = 30;
    timeweaver.effect = R"(The equipper's Electric Anomaly Buildup Rate increases by 30%/35%/40%/45%/50%. When Special Attacks or EX Special Attacks hit enemies suffering an Attribute Anomaly, the equipper's Anomaly Proficiency increases by 75/85/95/105/115 for 15s.When the equipper's Anomaly Proficiency is greater than or equal to 375, Disorder DMG inflicted by the equipper increases by 25%/27.5%/30%/32.5%/35%.)";
    timeweaver.image = ":/wengines/anomaly/Timeweaver.jxl";

    tusksOfFury.name = "Tusks of Fury";
    tusksOfFury.rarity = "S";
    tusksOfFury.specialty = "Defense";
    tusksOfFury.baseAtk = 713;
    tusksOfFury.stat = calc::stats::Impact;
    tusksOfFury.statPercent = 18;
    tusksOfFury.effect = R"(The Shield value provided by the equipper increases by 30%/38%/46%/52%/60%. When any squad member triggers Interrupt or Perfect Dodge, all squad members ' DMG increases by 18%/22.5%/27%/31.5%/36% and Daze dealt increases by 12%/15%/18%/21%/24% for 20s. Passive effects of the same name do not stack.)";
    tusksOfFury.image = ":/wengines/defense/TusksofFury.jxl";

    weepingCradle.name = "Weeping Cradle";
    weepingCradle.rarity = "S";
    weepingCradle.specialty = "Support";
    weepingCradle.baseAtk = 684;
    weepingCradle.stat = calc::stats::PenRatio;
    weepingCradle.statPercent = 24;
    weepingCradle.effect = R"(While off - field, the equipper's Energy Regen increases by 0.6/0.75/0.9/1.05/1.2 /s. Attacks from the equipper increase all units ' DMG against a struck target by 10%/12.5%/15%/17.5%/20% for 3 seconds. During this period, this effect is further increased by 1.7%/2%/2.5%/3%/3.3% every 0.5s, up to a maximum additional increase of 10.2%/12%/15%/18%/19.8%. Repeated triggers only refresh the duration without refreshing the DMG increase effect. Passive effects of the same name do not stack.)";
    weepingCradle.image = ":/wengines/support/WeepingCradle.jxl";

    zanshinHerbCase.name = "Zanshin Herb Case";
    zanshinHerbCase.rarity = "S";
    zanshinHerbCase.specialty = "Attack";
    zanshinHerbCase.baseAtk = 713;
    zanshinHerbCase.stat = calc::stats::CritDamage;
    zanshinHerbCase.statPercent = 48;
    zanshinHerbCase.effect = R"(CRIT Rate increases by 10%/11.5%/13%/14.5%/16%. Dash Attack Electric DMG increases by 40%/46%/52%/58%/64%. When any squad member applies an Attribute Anomaly or Stuns an enemy, the equipper's CRIT Rate increases by an additional 10%/11.5%/13%/14.5%/16% for 15s.)";
    zanshinHerbCase.image = ":/wengines/attack/ZanshinHerbCase.jxl";

    wengineList = {
        bashfulDemon, bellicoseBlaze, bigCylinder, blazingLaurel, boxCutter, bunnyBand, cannonRotor, cinderCobalt, cordisGermina, deepSeaVisitor, demaraBatteryMarkII, dreamlitHearth, drillRigRedAxis, electroLipGloss, elegantVanity, flamemakerShaker, flightOfFancy, fusionCompiler, gildedBlossom, grillOWisp, hailstormShrine, heartstringNocturne, hellfireGears, housekeeper, iceJadeTeapot, identityBase, identityInflection, kaboomTheCannon, lunarDecrescent, lunarNoviluna, lunarPleniluna, magneticStormAlpha, magneticStormBravo, magneticStormCharlie, marcatoDesire, metanukimorphosis, myriadEclipse, originalTransmorpher, peacekeeperSpecialized, practicedPerfection, preciousFossilizedCore, puzzleSphere, qingmingBirdcage, radiowaveJourney, rainforestGourmet, reelProjector, reverbMarkI, reverbMarkII, reverbMarkIII, riotSuppressorMarkVI, roaringFurnace, roaringRide, severedInnocence, sharpenedStinger, sixShooter, sliceOfTime, spectralGaze, springEmbrace, starlightEngine, starlightEngineReplica, steamOven, steelCushion, streetSuperstar, theBrimstone, theRestrained, theVault, timeweaver, tremorTrigramVessel, tusksOfFury, unfetteredGameBall, vortexArrow, vortexHatchet, vortexRevolver, weepingCradle, weepingGemini, zanshinHerbCase
    };
}
