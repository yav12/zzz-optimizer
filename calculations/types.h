#pragma once

#include <string>


namespace calc {
    // enum for different main stats moved out of calc.h to break include cycles
    enum class stats
    {
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
        AdrenalineRegen
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
}
