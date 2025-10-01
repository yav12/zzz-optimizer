#include "disc.h"

#include <vector>
#include <string>

disc::disc() {

}

void disc::addSubstat(const std::string& upgradeName, int upgrades) {
    substats.push_back({upgradeName, upgrades});
}
