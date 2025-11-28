#pragma once

#include <string>


namespace calc {
    //enum for different discs to keep track of
    enum class discSet
    {
        AstralVoice,
        BranchAndBladeSong,
        ChaosJazz,
        ChaoticMetal,
        DawnsBloom,
        FangedMetal,
        FreedomBlues,
        HormonePunk,
        InfernoMetal,
        KingOfTheSummit,
        MoonlightLullaby,
        PhaethonsMelody,
        PolarMetal,
        ProtoPunk,
        PufferElectro,
        ShadowHarmony,
        ShockstarDisco,
        SoulRock,
        SwingJazz,
        ThunderMetal,
        WoodpeckerElectro,
        YunkuiTales,
        None
    };

    // enum for different main stats moved out of calc.h to break include cycles
    enum class stats
    {
        // simple stats that can be used for out of combat calculations
        ATKFlat,
        ATKPercent,
        DEFFlat,
        DEFPercent,
        HPFlat,
        HPPercent,
        CritRate,
        CritDamage,
        AnomalyProficiency,
        AnomalyMastery,
        PEN,
        PenRatio,
        FireDamage,
        PhysicalDamage,
        EtherDamage,
        IceDamage,
        ElectricDamage,
        ImpactFlat,
        ImpactPercent,
        EnergyRegenFlat,
        EnergyRegenPercent,
        SheerForce,
        AdrenalineRegen,

        // different stats for damage and other things that appear from discs and w engines
        // attack type bonuses
        BasicAttackDamage,
        DashAttackDamage,
        EXSpecialAttackDamage,
        UltimateDamage,
        ChainAttackDamage,
        AssistAttackDamage,
        AftershockBonus,
        DodgeCounterBonus,

        // random things?
        ShieldBonus,
        DazeBonus,
        DamageReduction
    };

    enum class specialty
    {
        Attack,
        Defense,
        Rupture,
        Anomaly,
        Support,
        Stun
    };



    enum class attribute
    {
        Fire,
        Physical,
        Ether,
        Ice,
        Electric,
        Frost,
        AuricInk
    };

    // convert specialty enum to a display string
    inline std::string specialtyString(specialty characterSpecialty) {
        switch (characterSpecialty) {
            case specialty::Attack:   return "Attack";
            case specialty::Defense:  return "Defense";
            case specialty::Rupture:  return "Rupture";
            case specialty::Anomaly:  return "Anomaly";
            case specialty::Support:  return "Support";
            case specialty::Stun:     return "Stun";
            default:                  return "Unknown";
        }
    }

    // convert attribute enum to a display string
    inline std::string attributeString(attribute characterAttribute) {
        switch (characterAttribute) {
            case attribute::Fire:      return "Fire";
            case attribute::Physical:  return "Physical";
            case attribute::Ether:     return "Ether";
            case attribute::Ice:       return "Ice";
            case attribute::Electric:  return "Electric";
            case attribute::Frost:     return "Frost";
            case attribute::AuricInk:  return "Auric Ink";
            default:                   return "Unknown";
        }
    }

    // convert stats enum to a display string (only possible substats)
    inline std::string statsString(stats stat) {
        switch (stat) {
            case stats::ATKFlat:               return "ATK";
            case stats::ATKPercent:            return "ATK%";
            case stats::DEFFlat:               return "DEF";
            case stats::DEFPercent:            return "DEF%";
            case stats::HPFlat:                return "HP";
            case stats::HPPercent:             return "HP%";
            case stats::CritRate:              return "CRIT Rate";
            case stats::CritDamage:            return "CRIT Damage";
            case stats::AnomalyProficiency:    return "Anomaly Proficiency";
            case stats::PEN:                   return "PEN";
            default:                           return "Unknown Stat";
        }
    }

    // convert string to stats enum (only possible substats)
    inline stats stringToStats(const std::string& statStr) {
        if (statStr == "ATK")                       return stats::ATKFlat;
        else if (statStr == "ATK%")                 return stats::ATKPercent;
        else if (statStr == "DEF")                  return stats::DEFFlat;
        else if (statStr == "DEF%")                 return stats::DEFPercent;
        else if (statStr == "HP")                   return stats::HPFlat;
        else if (statStr == "HP%")                  return stats::HPPercent;
        else if (statStr == "CRIT Rate")            return stats::CritRate;
        else if (statStr == "CRIT Damage")          return stats::CritDamage;
        else if (statStr == "Anomaly Proficiency")  return stats::AnomalyProficiency;
        else if (statStr == "PEN")                  return stats::PEN;
        else if (statStr == "Impact%")              return stats::ImpactPercent;
        else                                        return stats::ATKFlat; // default case
    }
}
