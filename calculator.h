#ifndef CALCULATOR_H
#define CALCULATOR_H
#pragma once

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include "character.h"
#include "wengine.h"
#include <string>


class calculator : public QWidget
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();
    void setCharacter(character::character);
    void setWengine(wengine::wengine);
    void setDisc1();
    void setDisc2();
    void setDisc3();
    void setDisc4();
    void setDisc5();
    void setDisc6();

    void recalculate();

private:
    character::character currentCharacter;
    wengine::wengine currentWengine;
    //discs
    QComboBox *setBonus1;
    QComboBox *setBonus2;
    QComboBox *setBonus3;

    void redrawStats();
    void redrawImages();
    //display items
    QGridLayout *layout;
    QGridLayout *selectionsLayout;
    QComboBox *characterSelect;
    QComboBox *wengineSelect;
    QPushButton *calculateButton;
    QLabel *characterImage;
    QLabel *wengineImage;
    QGridLayout *statsLayout;
    //stats labels
    QLabel *hpLabel;
    QLabel *statsHP;
    QLabel *atkLabel;
    QLabel *statsATK;
    QLabel *defLabel;
    QLabel *statsDEF;
    QLabel *impactLabel;
    QLabel *statsImpact;
    QLabel *crLabel;
    QLabel *statsCR;
    QLabel *cdLabel;
    QLabel *statsCD;
    QLabel *amLabel;
    QLabel *statsAM;
    QLabel *apLabel;
    QLabel *statsAP;
    QLabel *penrLabel;
    QLabel *statsPENR;
    QLabel *sfLabel;
    QLabel *statsSF;
    QLabel *erLabel;
    QLabel *statsER;
    QLabel *aaaLabel;
    QLabel *statsAAA;


};

#endif // CALCULATOR_H
