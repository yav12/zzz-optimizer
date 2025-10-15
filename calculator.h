#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "character.h"
#include <string>

class calculator
{
public:

    void setCharacter(character::character);
    void setCurrentWengine(std::string);
    void setDisc1();
    void setDisc2();
    void setDisc3();
    void setDisc4();
    void setDisc5();
    void setDisc6();

    void recalculate();

private:
    character::character currentCharacter;
    std::string currentWengine;
    
    double statHP;
    double statDEF;
    double statATK;
    double statCR;
    double statCD;
    double statAM;
    double statAP;
    double statPENR;
    double statSF;
    double statER;
    double statAAA;
    double statImpact;


};

#endif // CALCULATOR_H
