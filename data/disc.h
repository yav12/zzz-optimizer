#ifndef DISC_H
#define DISC_H
#pragma once

#include <string>
#include <map> 
#include "../calculations/types.h"


class disc
{
public:
    disc();
    void setSet(calc::discSet); //name of the disc (what set is it)
    void setRank(std::string); //rarity of disc (B, A, S)
    void setSlot(int); //slot of the disc (1-6)
    void setMainStat(calc::stats); // main stat of the disc (e.g., ATK%, CRIT Rate, etc)
    void setSub1(calc::stats, int); // first substat of the disc
    void setSub2(calc::stats, int); // second substat of the disc
    void setSub3(calc::stats, int); // third substat of the disc
    void setSub4(calc::stats, int); // fourth substat of the disc

    calc::discSet getSet() const;
    int getSlot() const;
    std::string getRank() const;

    calc::stats getMainStat() const;
    calc::stats getSubStat1() const;
    calc::stats getSubStat2() const;
    calc::stats getSubStat3() const;
    calc::stats getSubStat4() const;

    double getMainStatValue() const;
    double getSub1Value() const;
    double getSub2Value() const;
    double getSub3Value() const;
    double getSub4Value() const;

    struct DiscInfo {
        std::string displayName;
        std::string resource;
        calc::stats bonus2pc;
        int bonus2pcValue;
        std::string bonus4pcEffect;
    };

    inline static const std::map<calc::discSet, DiscInfo> discMap = {
        {calc::discSet::AstralVoice, {"Astral Voice", ":/discs/AstralVoice.jxl", calc::stats::ATKPercent, 10, "Whenever any squad member enters the field using a Quick Assist, all squad members gain 1 stack of Astral, up to a maximum of 3 stacks, and lasting 15s. Repeated triggers reset the duration. Each stack of Astral increases the DMG dealt by the character entering the field using a Quick Assist by 8%. Passive effects of the same name do not stack."}},
        {calc::discSet::BranchAndBladeSong, {"Branch & Blade Song", ":/discs/BranchBladeSong.jxl", calc::stats::CritDamage, 16, "When Anomaly Mastery exceeds or equals 115 points, the equipper's CRIT DMG increases by 30%. When any squad member applies Freeze or triggers the Shatter effect on an enemy, the equipper's CRIT Rate increases by 12%, lasting 15s."}},
        {calc::discSet::ChaosJazz, {"Chaos Jazz", ":/discs/ChaosJazz.jxl", calc::stats::AnomalyProficiency, 30, "Fire DMG and Electric DMG increases by 15%. While off-field, EX Special Attack and Assist Attack DMG increases by 20%. When switching on-field, this buff continues for 5s, and this continuation effect can trigger once every 7.5s."}},
        {calc::discSet::ChaoticMetal, {"Chaotic Metal", ":/discs/ChaoticMetal.jxl", calc::stats::EtherDamage, 10, "The equipper's CRIT DMG increases by 20%. When any character in the squad triggers Corruption's additional DMG, this effect further increases by 5.5% for 8s, stacking up to 6 times. Repeated triggers reset the duration."}},
        {calc::discSet::DawnsBloom, {"Dawn's Bloom", ":/discs/DawnsBloom.jxl", calc::stats::BasicAttackDamage, 15, "Increases Basic Attack DMG by 20%. When equipped by an Attack character, using an EX Special Attack or Ultimate will further increase Basic Attack DMG by 20% for 25s. Repeated triggers reset the duration."}},
        {calc::discSet::FangedMetal, {"Fanged Metal", ":/discs/FangedMetal.jxl", calc::stats::PhysicalDamage, 10, "Whenever a squad member inflicts Assault on an enemy, the equipper deals 35% additional DMG to the target for 12s."}},
        {calc::discSet::FreedomBlues, {"Freedom Blues", ":/discs/FreedomBlues.jxl", calc::stats::AnomalyProficiency, 30, "When an EX Special Attack hits an enemy, reduce the target's Anomaly Buildup RES to the equipper's Attribute by 20% for 8s. This effect does not stack with others of the same attribute."}},
        {calc::discSet::HormonePunk, {"Hormone Punk", ":/discs/HormonePunk.jxl", calc::stats::ATKPercent, 25, "Upon becoming the active character in combat, the equipper's ATK increases by 25% for 10s. This effect can trigger once every 20s."}},
        {calc::discSet::InfernoMetal, {"Inferno Metal", ":/discs/InfernoMetal.jxl", calc::stats::FireDamage, 10, "Upon hitting a Burning enemy, the equipper's CRIT Rate is increased by 28% for 8s."}},
        {calc::discSet::KingOfTheSummit, {"King of the Summit", ":/discs/KingoftheSummit.jxl", calc::stats::ImpactPercent, 6, "When the equipper is a Stun character and uses an EX Special Attack or Chain Attack, increases CRIT DMG of all squad members by 15%, and when the equipper's CRIT Rate is more than or equal to 50%, further increases CRIT DMG by 15%, lasting 15s. Repeated triggers reset the duration. Passive effects of the same name do not stack."}},
        {calc::discSet::MoonlightLullaby, {"Moonlight Lullaby", ":/discs/MoonlightLullaby.jxl", calc::stats::EnergyRegenPercent, 20, "When the equipper is a Support character and uses an EX Special Attack or Ultimate, the DMG dealt by all squad members increases by 18% for 25s. Repeated triggers reset the duration. Passive effects of the same name do not stack."}},
        {calc::discSet::PhaethonsMelody, {"Phaethon's Melody", ":/discs/PhaethonsMelody.jxl", calc::stats::AnomalyMastery, 8, "When any squad member uses an EX Special Attack, the equipper's Anomaly Proficiency increases by 45 for 8s. If the character using the EX Special Attack is not the equipper, the equipper's Ether DMG is increased by 25%."}},
        {calc::discSet::PolarMetal, {"Polar Metal", ":/discs/PolarMetal.jxl", calc::stats::IceDamage, 10, "Increase the DMG of Basic Attack and Dash Attack by 20%. When any squad member inflicts Freeze or Shatter, this effect increases by an additional 20% for 12s."}},
        {calc::discSet::ProtoPunk, {"Proto Punk", ":/discs/ProtoPunk.jxl", calc::stats::ShieldBonus, 15, "When any squad member triggers a Defensive Assist or Evasive Assist, all squad members deal 15% increased DMG, lasting 10s. Passive effects of the same name do not stack."}},
        {calc::discSet::PufferElectro, {"Puffer Electro", ":/discs/PufferElectro.jxl", calc::stats::PenRatio, 8, "Ultimate DMG increases by 20%. Launching an Ultimate increases the equipper's ATK by 15% for 12s."}},
        {calc::discSet::ShadowHarmony, {"Shadow Harmony", ":/discs/ShadowHarmony.jxl", calc::stats::AftershockBonus, 15, "Upon hitting an enemy with an Aftershock or Dash Attack, if the DMG dealt aligns with the equipper's attribute, the equipper gains 1 stack of a buff effect, at most once per use of a skill. For each stack, the equipper's ATK increases by 4%, and CRIT Rate increases by 4%. The effect can stack up to 3 times and lasts for 15s. Repeated triggers reset the duration."}},
        {calc::discSet::ShockstarDisco, {"Shockstar Disco", ":/discs/ShockstarDisco.jxl", calc::stats::DazeBonus, 20, "Basic Attacks, Dash Attacks, and Dodge Counters inflict 20% more Daze to the main target."}},
        {calc::discSet::SoulRock, {"Soul Rock", ":/discs/SoulRock.jxl", calc::stats::DamageReduction, 40, "Upon receiving an enemy attack and losing HP, the equipper takes 40% less DMG for 2.5s. This effect can trigger once every 15s."}},
        {calc::discSet::SwingJazz, {"Swing Jazz", ":/discs/SwingJazz.jxl", calc::stats::EnergyRegenPercent, 20, "Launching a Chain Attack or Ultimate increases all squad members' DMG by 15% for 12s. Passive effects of the same name do not stack."}},
        {calc::discSet::ThunderMetal, {"Thunder Metal", ":/discs/ThunderMetal.jxl", calc::stats::ElectricDamage, 10, "As long as an enemy in combat is Shocked, the equipper's ATK is increased by 28%."}},
        {calc::discSet::WoodpeckerElectro, {"Woodpecker Electro", ":/discs/WoodpeckerElectro.jxl", calc::stats::CritRate, 8, "Landing a critical hit on an enemy with a Basic Attack, Dodge Counter, or EX Special Attack increases the equipper's ATK by 9% for 6s. The buff duration for different skills are calculated separately."}},
        {calc::discSet::YunkuiTales, {"Yunkui Tales", ":/discs/YunkuiTales.jxl", calc::stats::HPPercent, 10, "When using EX Special Attack, Chain Attack, or Ultimate, CRIT Rate increases by 4%, stacking up to 3 times and lasting 15s. Repeated triggers reset the duration. When having 3 stacks of this effect, Sheer DMG increases by 10%."}}
    };

private:
    std::string rank;
    int slot;
    calc::discSet set;

    calc::stats mainStat;
    double mainStatValue;

    calc::stats subStat1;
    int sub1Level;
    double subStat1Value;

    calc::stats subStat2;
    int sub2Level;
    double subStat2Value;

    calc::stats subStat3;
    int sub3Level;
    double subStat3Value;

    calc::stats subStat4;
    int sub4Level;
    double subStat4Value;

    void calculateSubValue(int, calc::stats, double&); // helper function to calculate substat value based on level

    struct baseValues
    {
        struct b
        {
            double mainHP[10] = {183, 243, 305, 366, 426, 488, 549, 609, 671, 732};
            double mainATK[10] = {26, 34, 43, 52, 60, 69, 78, 86, 95, 104};
            double mainDEF[10] = {15, 19, 25, 30, 34, 40, 45, 49, 55, 60};
            double mainHPPercent[10] = {2.5, 3.3, 4.2, 5, 5.8, 6.7, 7.5, 8.3, 9.2, 10};
            double mainATKPercent[10] = {2.5, 3.3, 4.2, 5, 5.8, 6.7, 7.5, 8.3, 9.2, 10};
            double mainDEFPercent[10] = {4, 5.3, 6.7, 8, 9.3, 10.7, 12, 13.3, 14.7, 16};
            double mainCritRate[10] = {2, 2.7, 3.3, 4, 4.7, 5.3, 6, 6.7, 7.3, 8};
            double mainCritDmg[10] = {4, 5.3, 6.7, 8, 9.3, 10.7, 12, 13.3, 14.7, 16};
            double mainAP[10] = {8, 9, 10, 10, 11, 13, 13, 14, 14, 16}; // approximate values, validate later
            double mainAM[10] = {2.5, 3.3, 4.2, 5, 5.8, 6.7, 7.5, 8.3, 9.2, 10};
            double mainPENR[10] = {2, 2.7, 3.3, 4, 4.7, 5.3, 6, 6.7, 7.3, 8};
            double attributeBonus[10] = {2.5, 3.3, 4.2, 5, 5.8, 6.7, 7.5, 8.3, 9.2, 10};
            double mainImpact[10] = {1.5, 2, 2.5, 3, 3.5, 4, 4.5, 5, 5.5, 6};
            double mainER[10] = {5, 5.5, 6, 6.5, 7, 7.5, 8, 8.5, 9, 9.5}; // approximate values, validate later

            double hp = 39;
            double atk = 7;
            double def = 5;
            double hpPercent = 1;
            double atkPercent = 1;
            double defPercent = 1.6;
            double critRate = 0.8;
            double critDmg = 1.6;
            double AP = 3;
            double PEN = 3;
        };
        struct a
        {
            double mainHP[13] = {367, 458, 550, 642, 734, 825, 917, 1009, 1101, 1192, 1284, 1376, 1468};
            double mainATK[13] = {53, 66, 79, 92, 106, 119, 132, 145, 159, 172, 185, 198, 212};
            double mainDEF[13] = {31, 38, 46, 54, 62, 69, 77, 85, 93, 100, 108, 116, 124};
            double mainHPPercent[13] = {5, 6.3, 7.5, 8.8, 10, 11.3, 12.5, 13.8, 15, 16.3, 17.5, 18.8, 20};
            double mainATKPercent[13] = {5, 6.3, 7.5, 8.8, 10, 11.3, 12.5, 13.8, 15, 16.3, 17.5, 18.8, 20};
            double mainDEFPercent[13] = {8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32};
            double mainCritRate[13] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
            double mainCritDmg[13] = {8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32};
            double mainAP[13] = {15, 18, 22, 26, 30, 33, 37, 41, 45, 48, 52, 56, 60};
            double mainAM[13] = {5, 6.3, 7.5, 8.8, 10, 11.3, 12.5, 13.8, 15, 16.3, 17.5, 18.8, 20};
            double mainPENR[13] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
            double attributeBonus[13] = {5, 6.3, 7.5, 8.8, 10, 11.3, 12.5, 13.8, 15, 16.3, 17.5, 18.8, 20};
            double mainImpact[13] = {3, 3.8, 4.5, 5.3, 6, 6.8, 7.5, 8.3, 9, 9.8, 10.5, 11.3, 12};
            double mainER[13] = {10, 12.5, 15, 17.5, 20, 22.5, 25, 27.5, 30, 32.5, 35, 37.5, 40};

            double hp = 75;
            double atk = 13;
            double def = 10;
            double hpPercent = 2;
            double atkPercent = 2;
            double defPercent = 3.2;
            double critRate = 1.6;
            double critDmg = 3.2;
            double AP = 6;
            double PEN = 6;
        };
        struct s
        {
            const double mainHP[16] = {550, 660, 770, 880, 990, 1100, 1210, 1320, 1430, 1540, 1650, 1760, 1870, 1980, 2090, 2200};
            const double mainATK[16] = {79, 94, 110, 126, 142, 158, 173, 189, 205, 221, 237, 252, 268, 284, 300, 316};
            const double mainDEF[16] = {46, 55, 64, 73, 82, 92, 101, 110, 119, 128, 138, 147, 156, 165, 174, 184};
            const double mainHPPercent[16] = {7.5, 9, 10.5, 12, 13.5, 15, 16.5, 18, 19.5, 21, 22.5, 24, 25.5, 27, 28.5, 30};
            const double mainATKPercent[16] = {7.5, 9, 10.5, 12, 13.5, 15, 16.5, 18, 19.5, 21, 22.5, 24, 25.5, 27, 28.5, 30};
            const double mainDEFPercent[16] = {12, 14.4, 16.8, 19.2, 21.6, 24, 26.4, 28.8, 31.2, 33.6, 36, 38.4, 40.8, 43.2, 45.6, 48};
            const double mainCritRate[16] = {6, 7.2, 8.4, 9.6, 10.8, 12, 13.2, 14.4, 15.6, 16.8, 18, 19.2, 20.4, 21.6, 22.8, 24};
            const double mainCritDmg[16] = {12, 14.4, 16.8, 19.2, 21.6, 24, 26.4, 28.8, 31.2, 33.6, 36, 38.4, 40.8, 43.2, 45.6, 48};
            const double mainAP[16] = {23, 27, 32, 36, 41, 46, 50, 55, 59, 64, 69, 73, 78, 82, 87, 92};
            const double mainAM[16] = {7.5, 9, 10.5, 12, 13.5, 15, 16.5, 18, 19.5, 21, 22.5, 24, 25.5, 27, 28.5, 30};
            const double mainPENR[16] = {6, 7.2, 8.4, 9.6, 10.8, 12, 13.2, 14.4, 15.6, 16.8, 18, 19.2, 20.4, 21.6, 22.8, 24};
            const double attributeBonus[16] = {7.5, 9, 10.5, 12, 13.5, 15, 16.5, 18, 19.5, 21, 22.5, 24, 25.5, 27, 28.5, 30};
            const double mainImpact[16] = {4.5, 5.4, 6.3, 7.2, 8.1, 9, 9.9, 10.8, 11.7, 12.6, 13.5, 14.4, 15.3, 16.2, 17.1, 18};
            const double mainER[16] = {15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60};

            double hp = 112;
            double atk = 19;
            double def = 15;
            double hpPercent = 3;
            double atkPercent = 3;
            double defPercent = 4.8;
            double critRate = 2.4;
            double critDmg = 4.8;
            double AP = 9;
            double PEN = 9;
        };
    };
};

#endif // DISC_H
