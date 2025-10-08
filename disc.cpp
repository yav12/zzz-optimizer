#include "disc.h"

#include <nlohmann/json.hpp>
#include <vector>
#include <string>

disc::disc() {

}

void disc::setSet(std::string i) {
    set = i;
};
std::string disc::getSet() {
    return set;
}

void disc::setSlot(int i) {
    slot = i;
};
int disc::getSlot() {
    return slot;
}

void disc::setLevel(int i) {
    level = i;
};
int disc::getLevel() {
    return level;
}

void disc::setRarity(std::string i) {
    rarity = i;
};
std::string disc::getRarity() {
    return rarity;
}

void disc::setMainStat(std::string i) {
    mainStat = i;
};
std::string disc::getMainStat() {
    return mainStat;
}

void disc::setSubstats(nlohmann::json j) {
    for (const auto& sub : j) {
        substats.push_back({sub["key"], sub["upgrades"]});
    }
}
