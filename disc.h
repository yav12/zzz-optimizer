#ifndef DISC_H
#define DISC_H

#include <string>

class disc
{
public:
    disc();
    void setRank(std::string); //rarity of disc (B, A, S)
    void setSlot(int); //slot of the disc (1-6)
    void setMainStat(std::string); // main stat of the disc (e.g., ATK%, CRIT Rate, etc)
    void setSub1(std::string, int); // first substat of the disc
    void setSub2(std::string, int); // second substat of the disc
    void setSub3(std::string, int); // third substat of the disc
    void setSub4(std::string, int); // fourth substat of the disc

    double getMainStatValue();
    double getSub1Value();
    double getSub2Value();
    double getSub3Value();
    double getSub4Value();

private:
    std::string rank;
    int slot;
    std::string mainStat;
    double mainStatValue;

    std::string subStat1;
    int sub1Level;
    double subStat1Value;
    std::string subStat2;
    int sub2Level;
    double subStat2Value;
    std::string subStat3;
    int sub3Level;
    double subStat3Value;
    std::string subStat4;
    int sub4Level;
    double subStat4Value;

    void calculateSubValue(int, std::string, double&); // helper function to calculate substat value based on level

    struct baseValues {
        struct b {
            double mainHP[10] = {};
            double mainATK[10] = {};
            double mainDEF[10] = {};
            double mainHPPercent[10] = {};
            double mainATKPercent[10] = {};
            double mainDEFPercent[10] = {};
            double mainCritRate[10] = {};
            double mainCritDmg[10] = {};
            double mainAP[10] = {};
            double mainAM[10] = {};
            double mainPENR[10] = {};
            double attributeBonus[10] = {};
            double mainImpact[10] = {};
            double mainER[10] = {};

            double hp = 39;
            double atk = 7;
            double def = 5;
            double hpPercent = 1;
            double atkPercent = 1;
            double defPercent = 1.6;
            double critRate = 0.8;
            double critDmg = 1.6;
            double AP = 3;
            double PEN = 3;
        };
        struct a {
            double mainHP[13] = {367, 458, 550, 642, 734, 825, 917, 1009, 1101, 1192, 1284, 1376, 1468};
            double mainATK[13] = {};
            double mainDEF[13] = {};
            double mainHPPercent[13] = {};
            double mainATKPercent[13] = {};
            double mainDEFPercent[13] = {};
            double mainCritRate[13] = {};
            double mainCritDmg[13] = {};
            double mainAP[13] = {};
            double mainAM[13] = {};
            double mainPENR[13] = {};
            double attributeBonus[13] = {};
            double mainImpact[13] = {};
            double mainER[13] = {10, 12.5, 15, 17.5, 20, 22.5, 25, 27.5, 30, 32.5, 35, 37.5, 40};

            double hp = 75;
            double atk = 13;
            double def = 10;
            double hpPercent = 2;
            double atkPercent = 2;
            double defPercent = 3.2;
            double critRate = 1.6;
            double critDmg = 3.2;
            double AP = 6;
            double PEN = 6;
        };
        struct s {
            double mainHP[16] = {500, 610, 720, 830, 940, 1050, 1160, 1270, 1380, 1490, 1600, 1710, 1820, 1930, 2040, 2150};
            double mainATK[16] = {79, 94, 110, 126, 142, 158, 173, 189, 205, 221, 237, 252, 268, 284, 300, 316};
            double mainDEF[16] = {46, 55, 64, 73, 82, 92, 101, 110, 119, 128, 138, 147, 156, 165, 174, 184};
            double mainHPPercent[16] = {7.5, 9, 10.5, 12, 13.5, 15, 16.5, 18, 19.5, 21, 22.5, 24, 25.5, 27, 28.5, 30};
            double mainATKPercent[16] = {7.5, 9, 10.5, 12, 13.5, 15, 16.5, 18, 19.5, 21, 22.5, 24, 25.5, 27, 28.5, 30};
            double mainDEFPercent[16] = {12, 14.4, 16.8, 19.2, 21.6, 24, 26.4, 28.8, 31.2, 33.6, 36, 38.4, 40.8, 43.2, 45.6, 48};
            double mainCritRate[16] = {6, 7.2, 8.4, 9.6, 10.8, 12, 13.2, 14.4, 15.6, 16.8, 18, 19.2, 20.4, 21.6, 22.8, 24};
            double mainCritDmg[16] = {12, 14.4, 16.8, 19.2, 21.6, 24, 26.4, 28.8, 31.2, 33.6, 36, 38.4, 40.8, 43.2, 45.6, 48};
            double mainAP[16] = {23, 27, 32, 36, 41, 46, 50, 55, 59, 64, 69, 73, 78, 82, 87, 92};
            double mainAM[16] = {7.5, 9, 10.5, 12, 13.5, 15, 16.5, 18, 19.5, 21, 22.5, 24, 25.5, 27, 28.5, 30};
            double mainPENR[16] = {6, 7.2, 8.4, 9.6, 10.8, 12, 13.2, 14.4, 15.6, 16.8, 18, 19.2, 20.4, 21.6, 22.8, 24};
            double attributeBonus[16] = {7.5, 9, 10.5, 12, 13.5, 15, 16.5, 18, 19.5, 21, 22.5, 24, 25.5, 27, 28.5, 30};
            double mainImpact[16] = {4.5, 5.4, 6.3, 7.2, 8.1, 9, 9.9, 10.8, 11.7, 12.6, 13.5, 14.4, 15.3, 16.2, 17.1, 18};
            double mainER[16] = {15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54, 57, 60};

            double hp = 112;
            double atk = 19;
            double def = 15;
            double hpPercent = 3;
            double atkPercent = 3;
            double defPercent = 4.8;
            double critRate = 2.4;
            double critDmg = 4.8;
            double AP = 9;
            double PEN = 9;
        };
    };

};

#endif // DISC_H
