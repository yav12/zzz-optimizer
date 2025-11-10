#pragma once

namespace calc {
    // enum for different main stats moved out of calc.h to break include cycles
    enum class stats
    {
        ATK,
        ATKPercent,
        DEF,
        DEFPercent,
        HP,
        HPPercent,
        CritRate,
        CritDamage,
        AnomalyProficiency,
        AnomalyMastery,
        PenRatio,
        FireDamage,
        PhysicalDamage,
        EtherDamage,
        IceDamage,
        ElectricDamage,
        Impact,
        EnergyRegen,
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
}
