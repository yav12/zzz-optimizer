#include "calculator.h"

calculator::calculator(QWidget *parent) : QWidget(parent) {
    //layout
    layout = new QGridLayout();
    setLayout(layout);

    //character select combobox
    characterSelect = new QComboBox();
    for (const auto& character : character::characterList) {
        characterSelect->addItem(QString::fromStdString(character.nickname));
    }
    layout->addWidget(characterSelect, 0, 0);
    connect(characterSelect, &QComboBox::currentTextChanged, [this]() {
        setCharacter(character::characterList[characterSelect->currentIndex()]);
    });

    //wengine select combobox
    wengineSelect = new QComboBox();
    for (const auto& wengine : wengine::wengineList) {
        wengineSelect->addItem(QString::fromStdString(wengine.name));
    }
    layout->addWidget(wengineSelect, 0, 1);
    connect(wengineSelect, &QComboBox::currentTextChanged, [this]() {
        setWengine(wengine::wengineList[wengineSelect->currentIndex()]);
    });
    //calculate button
    calculateButton = new QPushButton("Calculate");
    layout->addWidget(calculateButton, 1, 0, 1, 2);
    connect(calculateButton, &QPushButton::clicked, this, &calculator::recalculate);

    //images
    characterImage = new QLabel;
    wengineImage = new QLabel;
    layout->addWidget(characterImage, 2, 0);
    layout->addWidget(wengineImage, 2, 1);

    //stats layout
    statsLayout = new QGridLayout();
    layout->addLayout(statsLayout, 0, 1, 1, 1);

    //stats labels
    hpLabel = new QLabel("HP:");
    statsLayout->addWidget(hpLabel, 0, 0);
    atkLabel = new QLabel("ATK:");
    statsLayout->addWidget(atkLabel, 1, 0);
    defLabel = new QLabel("DEF:");
    statsLayout->addWidget(defLabel, 2, 0);
    impactLabel = new QLabel("Impact:");
    statsLayout->addWidget(impactLabel, 3, 0);
    crLabel = new QLabel("CR:");
    statsLayout->addWidget(crLabel, 4, 0);
    cdLabel = new QLabel("CD:");
    statsLayout->addWidget(cdLabel, 5, 0);
    amLabel = new QLabel("AM:");
    statsLayout->addWidget(amLabel, 6, 0);
    apLabel = new QLabel("AP:");
    statsLayout->addWidget(apLabel, 7, 0);
    penrLabel = new QLabel("PEN Ratio:");
    statsLayout->addWidget(penrLabel, 8, 0);
    erLabel = new QLabel("ER:");
    statsLayout->addWidget(erLabel, 9, 0);
}

void calculator::redrawImages() {
    //character image
    QPixmap charPix(QString::fromStdString(currentCharacter.images.portrait));
    characterImage->setPixmap(charPix.scaled(200, 200, Qt::KeepAspectRatio));

    //wengine image
    QPixmap wengPix(QString::fromStdString(currentWengine.image));
    wengineImage->setPixmap(wengPix.scaled(200, 200, Qt::KeepAspectRatio));
}

void calculator::redrawStats() {
    statsHP->setText(QString::number(currentCharacter.stats.hp));
    statsATK->setText(QString::number(currentCharacter.stats.atk));
    statsDEF->setText(QString::number(currentCharacter.stats.def));
    statsImpact->setText(QString::number(currentCharacter.stats.impact));
    statsCR->setText(QString::number(currentCharacter.stats.cr) + "%");
    statsCD->setText(QString::number(currentCharacter.stats.cd) + "%");
    statsAM->setText(QString::number(currentCharacter.stats.am) + "%");
    statsAP->setText(QString::number(currentCharacter.stats.ap) + "%");
    statsPENR->setText(QString::number(currentCharacter.stats.penr) + "%");
    statsSF->setText(QString::number(currentCharacter.stats.sf));
    statsER->setText(QString::number(currentCharacter.stats.er) + "%");
    statsAAA->setText(QString::number(currentCharacter.stats.aaa) + "%");
}

void calculator::setCharacter(character::character c) {
    currentCharacter = c; 
    redrawImages();
}

void calculator::setWengine(wengine::wengine w) {
    currentWengine = w;
    redrawImages();
}

void calculator::recalculate() {

}


calculator::~calculator() {
}
