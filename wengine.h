#ifndef WENGINE_H
#define WENGINE_H

#include <string>
#include <vector>

namespace wengine {
struct wengine {
    std::string name; //w-engine name
    std::string rarity; //w-engine rarity
    std::string specialty; //w-engine specialty (attack, defense, support, stun, anomaly or rupture)
    double baseAtk; //base attack provided by w-engine
    std::string stat; //primary stat provided by w-engine
    int statPercent; //percentage value of the primary stat (not always a percentage)
    std::string effect; //special effect description
    std::string image; //path to the w-engine image
};
// List of all W-engines
inline std::vector<wengine> wengineList;

//set all the w engine data
void setWengineData();

// W-engines parsed from data.txt (alphabetical)
inline wengine bashfulDemon;
inline wengine bellicoseBlaze;
inline wengine bigCylinder;
inline wengine blazingLaurel;
inline wengine boxCutter;
inline wengine bunnyBand;
inline wengine cannonRotor;
inline wengine cinderCobalt;
inline wengine cordisGermina;
inline wengine deepSeaVisitor;
inline wengine demaraBatteryMarkII;
inline wengine dreamlitHearth;
inline wengine drillRigRedAxis;
inline wengine elegantVanity;
inline wengine electroLipGloss;
inline wengine gildedBlossom;
inline wengine grillOWisp;
inline wengine hailstormShrine;
inline wengine heartstringNocturne;
inline wengine hellfireGears;
inline wengine housekeeper;
inline wengine iceJadeTeapot;
inline wengine identityBase;
inline wengine identityInflection;
inline wengine kaboomTheCannon;
inline wengine lunarDecrescent;
inline wengine lunarNoviluna;
inline wengine lunarPleniluna;
inline wengine marcatoDesire;
inline wengine metanukimorphosis;
inline wengine myriadEclipse;
inline wengine originalTransmorpher;
inline wengine peacekeeperSpecialized;
inline wengine practicedPerfection;
inline wengine preciousFossilizedCore;
inline wengine puzzleSphere;
inline wengine qingmingBirdcage;
inline wengine radiowaveJourney;
inline wengine rainforestGourmet;
inline wengine reelProjector;
inline wengine reverbMarkI;
inline wengine reverbMarkII;
inline wengine reverbMarkIII;
inline wengine riotSuppressorMarkVI;
inline wengine roaringFurnace;
inline wengine roaringRide;
inline wengine sixShooter;
inline wengine sliceOfTime;
inline wengine springEmbrace;
inline wengine steelCushion;
inline wengine starlightEngine;
inline wengine starlightEngineReplica;
inline wengine steamOven;
inline wengine streetSuperstar;
inline wengine theVault;
inline wengine tremorTrigramVessel;
inline wengine unfetteredGameBall;
inline wengine vortexArrow;
inline wengine vortexHatchet;
inline wengine vortexRevolver;
inline wengine weepingGemini;
inline wengine flamemakerShaker;
inline wengine flightOfFancy;
inline wengine fusionCompiler;
inline wengine magneticStormAlpha;
inline wengine magneticStormBravo;
inline wengine magneticStormCharlie;
inline wengine severedInnocence;
inline wengine sharpenedStinger;
inline wengine spectralGaze;
inline wengine theBrimstone;
inline wengine theRestrained;
inline wengine timeweaver;
inline wengine tusksOfFury;
inline wengine weepingCradle;
inline wengine zanshinHerbCase;
};

#endif // WENGINE_H
