#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>

#include "wengine.h"
#include "disc.h"

#include "../calculations/types.h"

namespace character {
struct character {
    std::string name;
    std::string nickname;
    std::string rarity;
    calc::specialty specialty;
    calc::attribute attribute;
    std::string faction;
    struct stats {
        double hp;
        double atk;
        double def;
        double impact;
        double cr;
        double cd;
        double am;
        double ap;
        double penr;
        double pen;
        double sf;
        double er;
        double aaa;
        double damagePercent;
    };
    stats stats;
    struct assets {
        std::string circleIcon;
        std::string normalIcon;
        std::string portrait;
        std::string mindscapeNone;
        std::string mindscapeHalf;
        std::string mindscapeFull;
    };
    assets images;
    std::vector <disc> discs = std::vector<disc>(6); // 6 disc slots
    wengine::wengine preferredWengine;

};
// List of all characters
inline std::vector<character> characterList;

//set all the character data
void setCharacterData();

//character definitions
inline character alice;
inline character anby;
inline character anton;
inline character astra;
inline character ben;
inline character billy;
inline character burnice;
inline character caesar;
inline character corin;
inline character ellen;
inline character evelyn;
inline character grace;
inline character harumasa;
inline character hugo;
inline character jane;
inline character jufufu;
inline character koleda;
inline character lighter;
inline character lucia;
inline character lucy;
inline character lycaon;
inline character miyabi;
inline character manato;
inline character nekomata;
inline character nicole;
inline character orphiemagus;
inline character piper;
inline character pulchra;
inline character qingyi;
inline character rina;
inline character s0anby;
inline character seed;
inline character seth;
inline character soldier11;
inline character soukaku;
inline character trigger;
inline character vivian;
inline character yanagi;
inline character yidhari;
inline character yinhu;
inline character yixuan;
inline character yuzuha;
inline character zhuyuan;

};

#endif // CHARACTER_H
