#ifndef CALCULATOR_H
#define CALCULATOR_H
#pragma once

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QStackedLayout>
#include <QToolButton>
#include <QComboBox>
#include <QPushButton>

#include <string>

#include "../selectors/charselector.h"
#include "../selectors/wengineselector.h"

#include "../data/character.h"
#include "../data/wengine.h"

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
    character::character calculatedCharacter;

    void redrawStats(character::character);
    void redrawImages();

    //selectors
    charSelector *charSelectorWidget = nullptr;
    wengineSelector *wengineSelectorWidget = nullptr;

    // top-level pages stack (used to swap entire window pages)
    QStackedLayout *pagesStack = nullptr;
    QWidget *mainPage = nullptr;

    //discs (unused for now)
    QComboBox *setBonus1;
    QComboBox *setBonus2;
    QComboBox *setBonus3;


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
