#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <qtoolbutton.h>
#pragma once

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QStackedLayout>
#include <QToolButton>
#include <QComboBox>
#include <QPushButton>

#include <vector>

#include "../data/character.h"
#include "../data/wengine.h"

#include "../calculations/calc.h"

class calculator : public QWidget
{
    Q_OBJECT

public:
    calculator(QWidget *parent = nullptr);
    ~calculator();
    void setCharacter(character::character);
    void setWengine(wengine::wengine);

    void recalculate();

private:
    character::character currentCharacter;
    wengine::wengine currentWengine;
    character::character calculatedCharacter;

    void redrawStats(character::character);
    void redrawImages();
    void redrawDisc(int slotNumber);

    // top-level pages stack (used to swap entire window pages)
    QStackedLayout *pagesStack = nullptr;
    QWidget *mainPage = nullptr;

    //discs
    QHBoxLayout *discLayout;
    std::vector<QToolButton *> discButtons;

    //display items
    QGridLayout *layout;
    QGridLayout *selectionsLayout;
    QToolButton *characterSelect;
    QToolButton *wengineSelect;
    QPushButton *calculateButton;
    QLabel *characterImage;
    QLabel *wengineImage;
    QGridLayout *statsLayout;

    //stats labels
    QStackedLayout *ruptureStack;
    QGridLayout *nonRuptureLayout;
    QGridLayout *ruptureLayout;
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
    QLabel *penLabel;
    QLabel *statsPEN;
    QLabel *sfLabel;
    QLabel *statsSF;
    QLabel *erLabel;
    QLabel *statsER;
    QLabel *aaaLabel;
    QLabel *statsAAA;

};

#endif // CALCULATOR_H
