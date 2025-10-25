#include "calculator.h"

calculator::calculator(QWidget *parent) : QWidget(parent) {
    // top-level pages stack: allows swapping the entire window
    pagesStack = new QStackedLayout();
    setLayout(pagesStack);

    // add the selector widget as a full-window page directly to pagesStack
    charSelectorWidget = new charSelector(this);
    pagesStack->addWidget(charSelectorWidget);

    // connect selector -> apply selection, update UI and switch back to controls page
    connect(charSelectorWidget, &charSelector::characterSelected, this,
            [this](const character::character &c)
            {
                setCharacter(c); 
                // set default wengine from character
                setWengine(c.preferredWengine);

                // switch back to main page
                if (this->pagesStack)
                    this->pagesStack->setCurrentWidget(this->mainPage);
            });

    // wengine selector widget
    wengineSelectorWidget = new wengineSelector(this);
    pagesStack->addWidget(wengineSelectorWidget);

    // connect selector -> apply selection, update UI and switch back to controls page
    connect(wengineSelectorWidget, &wengineSelector::wengineSelected, this,
            [this](const wengine::wengine &w)
            {
                setWengine(w); // updates currentWengine and images

                // switch back to controls page (main page)
                if (this->pagesStack)
                    this->pagesStack->setCurrentWidget(this->mainPage);
            });

    // main page: contains the original grid layout
    mainPage = new QWidget();
    layout = new QGridLayout();
    mainPage->setLayout(layout);

    selectionsLayout = new QGridLayout(); // layout for selections & buttons
    selectionsLayout->setAlignment(Qt::AlignCenter);

    // add the container to the main page grid
    layout->addLayout(selectionsLayout, 0, 1, 1, 1);
    statsLayout = new QGridLayout(); // layout for stats display
    layout->addLayout(statsLayout, 1, 1, 1, 1);

    // add the main page to the top-level pages stack
    pagesStack->addWidget(mainPage);
    pagesStack->setCurrentWidget(mainPage);
    
    //character select button
    characterSelect = new QToolButton();
    characterSelect->setText("Select Character");
    characterSelect->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    selectionsLayout->addWidget(characterSelect, 0, 0, Qt::AlignCenter);
    connect(characterSelect, &QToolButton::clicked, [this]() {
        // switch entire window to selector page
        if (this->pagesStack) {
            this->pagesStack->setCurrentWidget(this->charSelectorWidget);
        }
    });

    //wengine select button
    wengineSelect = new QToolButton();
    wengineSelect->setText("Select Wengine");
    wengineSelect->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    selectionsLayout->addWidget(wengineSelect, 0, 1, Qt::AlignCenter);
    connect(wengineSelect, &QToolButton::clicked, [this]() {
        // switch entire window to selector page
        if (this->pagesStack) {
            this->pagesStack->setCurrentWidget(this->wengineSelectorWidget);
        }
    });

    // disc selector buttons
    discLayout = new QHBoxLayout();
    discLayout->setAlignment(Qt::AlignCenter);
    selectionsLayout->addLayout(discLayout, 1, 0, 1, 2);

    disc1Button = new QToolButton();
    disc1Button->setText("Select Disc 1");
    disc1Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    discLayout->addWidget(disc1Button);

    disc2Button = new QToolButton();
    disc2Button->setText("Select Disc 2");
    disc2Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    discLayout->addWidget(disc2Button);

    disc3Button = new QToolButton();
    disc3Button->setText("Select Disc 3");
    disc3Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    discLayout->addWidget(disc3Button);

    disc4Button = new QToolButton();
    disc4Button->setText("Select Disc 4");
    disc4Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    discLayout->addWidget(disc4Button);

    disc5Button = new QToolButton();
    disc5Button->setText("Select Disc 5");
    disc5Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    discLayout->addWidget(disc5Button);

    disc6Button = new QToolButton();
    disc6Button->setText("Select Disc 6");
    disc6Button->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    discLayout->addWidget(disc6Button);

    //calculate button
    calculateButton = new QPushButton("Calculate");
    selectionsLayout->addWidget(calculateButton, 2, 0, 1, 2);
    connect(calculateButton, &QPushButton::clicked, this, &calculator::recalculate);

    //images
    characterImage = new QLabel;
    wengineImage = new QLabel;
    characterImage->setScaledContents(false);
    characterImage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    characterImage->setAlignment(Qt::AlignCenter);

    wengineImage->setScaledContents(false);
    wengineImage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    wengineImage->setAlignment(Qt::AlignCenter);
    layout->addWidget(characterImage, 0, 0, -1, 1);
    layout->addWidget(wengineImage, 2, 1);

    //stats labels
    //unchanging labels
    hpLabel = new QLabel("HP:");
    statsLayout->addWidget(hpLabel, 0, 0);
    atkLabel = new QLabel("ATK:");
    statsLayout->addWidget(atkLabel, 1, 0);
    defLabel = new QLabel("DEF:");
    statsLayout->addWidget(defLabel, 2, 0);
    impactLabel = new QLabel("Impact:");
    statsLayout->addWidget(impactLabel, 3, 0);
    crLabel = new QLabel("Crit Rate:");
    statsLayout->addWidget(crLabel, 4, 0);
    cdLabel = new QLabel("Crit Damage:");
    statsLayout->addWidget(cdLabel, 5, 0);
    amLabel = new QLabel("Anomaly Mastery:");
    statsLayout->addWidget(amLabel, 6, 0);
    apLabel = new QLabel("Anomaly Proficiency:");
    statsLayout->addWidget(apLabel, 7, 0);

    // will change based on rupture/not rupture
    ruptureStack = new QStackedLayout();
    ruptureStack->setContentsMargins(0, 0, 0, 0);
    ruptureStack->setSpacing(0);
    ruptureLayout = new QGridLayout();
    ruptureLayout->setContentsMargins(0, 0, 0, 0);
    nonRuptureLayout = new QGridLayout();
    nonRuptureLayout->setContentsMargins(0, 0, 0, 0);
    statsLayout->addLayout(ruptureStack, 8, 0, 3, 2);
    //non-rupture layout
    QWidget *nonRuptureWidget = new QWidget();
    nonRuptureWidget->setLayout(nonRuptureLayout);
    ruptureStack->addWidget(nonRuptureWidget);
    penrLabel = new QLabel("PEN Ratio:");
    nonRuptureLayout->addWidget(penrLabel, 0, 0);
    penLabel = new QLabel("PEN:");
    nonRuptureLayout->addWidget(penLabel, 1, 0);
    erLabel = new QLabel("Energy Regen:");
    nonRuptureLayout->addWidget(erLabel, 2, 0);
    //rupture layout
    QWidget *ruptureWidget = new QWidget();
    ruptureWidget->setLayout(ruptureLayout);
    ruptureStack->addWidget(ruptureWidget);
    sfLabel = new QLabel("Sheer Force:");
    ruptureLayout->addWidget(sfLabel, 0, 0);
    aaaLabel = new QLabel("Automatic Adrenaline Accumulation:");
    ruptureLayout->addWidget(aaaLabel, 1, 0);
    QLabel *spacer = new QLabel(""); // empty spacer
    ruptureLayout->addWidget(spacer, 2, 0);

    //default values for stats
    statsHP = new QLabel("?");
    statsLayout->addWidget(statsHP, 0, 1);
    statsATK = new QLabel("?");
    statsLayout->addWidget(statsATK, 1, 1);
    statsDEF = new QLabel("?");
    statsLayout->addWidget(statsDEF, 2, 1);
    statsImpact = new QLabel("?");
    statsLayout->addWidget(statsImpact, 3, 1);
    statsCR = new QLabel("?");
    statsLayout->addWidget(statsCR, 4, 1);
    statsCD = new QLabel("?");
    statsLayout->addWidget(statsCD, 5, 1);
    statsAM = new QLabel("?");
    statsLayout->addWidget(statsAM, 6, 1);
    statsAP = new QLabel("?");
    statsLayout->addWidget(statsAP, 7, 1);

    statsPENR = new QLabel("?");
    nonRuptureLayout->addWidget(statsPENR, 0, 1);
    statsPEN = new QLabel("?");
    nonRuptureLayout->addWidget(statsPEN, 1, 1);
    statsER = new QLabel("?");
    nonRuptureLayout->addWidget(statsER, 2, 1);
    statsSF = new QLabel("?");
    ruptureLayout->addWidget(statsSF, 0, 1);
    statsAAA = new QLabel("?");
    ruptureLayout->addWidget(statsAAA, 1, 1);
}

void calculator::redrawImages() {
    // compute available area for the character image
    QSize availChar = characterImage->contentsRect().size();
    if (availChar.width() <= 0 || availChar.height() <= 0) availChar = this->size();

    QPixmap charPix(QString::fromStdString(currentCharacter.images.portrait));
    if (!charPix.isNull()) {
        // never upscale: target is bounded to both available area and original pix size
        QSize target = charPix.size().boundedTo(availChar);
        QPixmap scaledChar = charPix.scaled(target, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        characterImage->setPixmap(scaledChar);
    } else {
        characterImage->clear();
    }

    // same for wengine image
    QSize availW = wengineImage->contentsRect().size();
    if (availW.width() <= 0 || availW.height() <= 0) availW = this->size();

    QPixmap wengPix(QString::fromStdString(currentWengine.image));
    if (!wengPix.isNull()) {
        QSize targetW = wengPix.size().boundedTo(availW);
        QPixmap scaledW = wengPix.scaled(targetW, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        wengineImage->setPixmap(scaledW);
    } else {
        wengineImage->clear();
    }

    //redraw character button image
    QPixmap iconPix(QString::fromStdString(currentCharacter.images.normalIcon));
    characterSelect->setIcon(QIcon(iconPix));
    characterSelect->setIconSize(QSize(100, 100));
    characterSelect->setText(QString::fromStdString(currentCharacter.nickname));

    //redraw wengine button image
    QPixmap wiconPix(QString::fromStdString(currentWengine.image));
    wengineSelect->setIcon(QIcon(wiconPix));
    wengineSelect->setIconSize(QSize(100, 100));
    wengineSelect->setText(QString::fromStdString(currentWengine.name));
}

void calculator::redrawStats(character::character calcs) {
    //set labels
    statsHP->setText(QString::number(calcs.stats.hp));
    statsATK->setText(QString::number(calcs.stats.atk));
    statsDEF->setText(QString::number(calcs.stats.def));
    statsImpact->setText(QString::number(calcs.stats.impact));
    statsCR->setText(QString::number(calcs.stats.cr) + "%");
    statsCD->setText(QString::number(calcs.stats.cd) + "%");
    statsAM->setText(QString::number(calcs.stats.am));
    statsAP->setText(QString::number(calcs.stats.ap));
    statsPENR->setText(QString::number(calcs.stats.penr) + "%");
    statsPEN->setText(QString::number(calcs.stats.pen));
    statsSF->setText(QString::number(calcs.stats.sf));
    statsER->setText(QString::number(calcs.stats.er));
    statsAAA->setText(QString::number(calcs.stats.aaa));

    // choose the correct page based on the character specialty
    if (calcs.specialty == "Rupture") {
        ruptureStack->setCurrentIndex(1); // rupture
    } else {
        ruptureStack->setCurrentIndex(0); // not rupture
    }
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
    // start with base stats
    calculatedCharacter = currentCharacter;
    // apply wengine
    calculatedCharacter.stats.atk += currentWengine.baseAtk;
    // apply secondary stat bonus
    if (currentWengine.stat == "HP") {
        calculatedCharacter.stats.hp *= (1.0 + static_cast<double>(currentWengine.statPercent) / 100.0);
    } else if (currentWengine.stat == "ATK") {
        calculatedCharacter.stats.atk *= (1.0 + static_cast<double>(currentWengine.statPercent) / 100.0);
    } else if (currentWengine.stat == "DEF") {
        calculatedCharacter.stats.def *= (1.0 + static_cast<double>(currentWengine.statPercent) / 100.0);
    } else if (currentWengine.stat == "Impact") {
        calculatedCharacter.stats.impact *= (1.0 + static_cast<double>(currentWengine.statPercent) / 100.0);
    } else if (currentWengine.stat == "Crit Rate") {
        calculatedCharacter.stats.cr += static_cast<double>(currentWengine.statPercent);
    } else if (currentWengine.stat == "Crit Damage") {
        calculatedCharacter.stats.cd += static_cast<double>(currentWengine.statPercent);
    } else if (currentWengine.stat == "Anomaly Proficiency") {
        calculatedCharacter.stats.ap += static_cast<double>(currentWengine.statPercent);
    } else if (currentWengine.stat == "PEN Ratio") {
        calculatedCharacter.stats.penr += static_cast<double>(currentWengine.statPercent);
    } else if (currentWengine.stat == "Energy Regen") {
        calculatedCharacter.stats.er += static_cast<double>(currentWengine.statPercent);
    } //no w engines give anomaly mastery or sheer force or adrenaline

    // show the computed stats (no discs yet)
    redrawStats(calculatedCharacter);
}


calculator::~calculator() {
}
