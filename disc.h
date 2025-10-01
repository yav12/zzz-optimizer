#ifndef DISC_H
#define DISC_H

#include <string>
#include <vector>

struct substat {
    std::string uprgrade;
    int rolls;
};

class disc
{
public:
    disc();
    std::string set;
    int slot;
    int level;
    std::string rarity;
    std::string mainStat;
    std::vector<substat> substats;
    void addSubstat(const std::string&, int);
};

#endif // DISC_H
