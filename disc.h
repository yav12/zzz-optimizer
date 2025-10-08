#ifndef DISC_H
#define DISC_H

#include <nlohmann/json.hpp>
#include <string>
#include <vector>

struct substat {
    std::string uprgrade;
    int rolls;
};

class disc
{
private:
    std::string set;
    int slot;
    int level;
    std::string rarity;
    std::string mainStat;
    std::vector<substat> substats;

public:
    disc();
    void setSet(std::string);
    std::string getSet();
    void setSlot(int);
    int getSlot();
    void setLevel(int);
    int getLevel();
    void setRarity(std::string);
    std::string getRarity();
    void setMainStat(std::string);
    std::string getMainStat();
    void setSubstats(nlohmann::json);
    std::vector<substat> getSubstats;


};

#endif // DISC_H
