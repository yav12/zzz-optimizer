#include "calculator.h"

#include <QGuiApplication>

#include "../selectors/charselector.h"
#include "../selectors/discselector.h"
#include "../selectors/wengineselector.h"

#include "../data/disc.h"

calculator::calculator(QWidget *parent) : QWidget(parent) {
    // top-level pages stack: allows swapping the entire window
    pagesStack = new QStackedLayout();
    setLayout(pagesStack);

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

    // character select button
    characterSelect = new QToolButton();
    characterSelect->setText("Select Character");
    characterSelect->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    selectionsLayout->addWidget(characterSelect, 0, 0, Qt::AlignCenter);
    connect(characterSelect, &QToolButton::clicked, [this]() {
        // create character selector
        charSelector *charSelectorWidget = new charSelector(this);
        pagesStack->addWidget(charSelectorWidget);

        // switch to selector page
        if (this->pagesStack) {
        this->pagesStack->setCurrentWidget(charSelectorWidget);
        }

        // connect selector -> apply selection, update UI and switch back to
        // calculator page
        // NOTE: capture charSelectorWidget by value (not by reference) to avoid
        // a dangling reference when this lambda returns.
        connect(charSelectorWidget, &charSelector::characterSelected, this,
                [this, charSelectorWidget](const character::character &c) {
                setCharacter(c);
                // set default wengine from character
                setWengine(c.preferredWengine);

                // switch back to main page
                if (this->pagesStack) {
                    this->pagesStack->setCurrentWidget(this->mainPage);
                }

                // delete selector widget
                charSelectorWidget->deleteLater();
                });
    });

    // wengine select button
    wengineSelect = new QToolButton();
    wengineSelect->setText("Select Wengine");
    wengineSelect->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    selectionsLayout->addWidget(wengineSelect, 0, 1, Qt::AlignCenter);
    connect(wengineSelect, &QToolButton::clicked, [this]() {
        // wengine selector widget
        wengineSelector *wengineSelectorWidget = new wengineSelector(this);
        pagesStack->addWidget(wengineSelectorWidget);

        // connect selector -> apply selection, update UI and switch back to
        // calculator page
        connect(wengineSelectorWidget, &wengineSelector::wengineSelected, this,
                [this](const wengine::wengine &w) {
                setWengine(w); // updates currentWengine and images

                // switch back to controls page (main page)
                if (this->pagesStack)
                    this->pagesStack->setCurrentWidget(this->mainPage);
                });

        // switch entire window to selector page
        if (this->pagesStack) {
        this->pagesStack->setCurrentWidget(wengineSelectorWidget);
        }
    });

    // disc selector buttons
    discLayout = new QHBoxLayout();
    discLayout->setAlignment(Qt::AlignCenter);
    selectionsLayout->addLayout(discLayout, 1, 0, 1, 2);

    for (int i = 0; i < 6; ++i) {
        this->discButtons.push_back(new QToolButton());
        this->discButtons[i]->setText(QString("Select Disc %1").arg(i + 1));
        this->discButtons[i]->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        discLayout->addWidget(this->discButtons[i]);
        connect(discButtons[i], &QToolButton::clicked, [this, i]() {
            // open disc selector for disc i + 1 (?) (it might work not sure)
            discSelector *selector = new discSelector(this, i + 1);
            selector->setAttribute(Qt::WA_DeleteOnClose);

            //positioning by ai:
            // make it centered on screen: set size first, then move so rect() has correct size
            selector->setFixedSize(700, 800);
            if (QScreen *screen = QGuiApplication::primaryScreen()) {
                // center inside the available geometry (accounts for taskbars)
                QRect avail = screen->availableGeometry();
                selector->move(avail.center() - selector->rect().center());
            } else {
                // fallback: center relative to this widget
                selector->move(this->geometry().center() - selector->rect().center());
            }

            // make it do something and update the page itself
            connect(selector, &discSelector::discSelected, this,
                    [this, selector, i](const disc &d) {
                        // set disc i to selected disc (also guessing cuz idk what
                        // index its supposed to be)
                        this->currentCharacter.discs[i] = d;
                        this->redrawDisc(i);
                        selector->close();
                    });
            selector->show();
        });
    }
    // calculate button
    calculateButton = new QPushButton("Calculate");
    selectionsLayout->addWidget(calculateButton, 2, 0, 1, 2);
    connect(calculateButton, &QPushButton::clicked, this,
            &calculator::recalculate);

    // images
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

    // stats labels
    // unchanging labels
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
    // non-rupture layout
    QWidget *nonRuptureWidget = new QWidget();
    nonRuptureWidget->setLayout(nonRuptureLayout);
    ruptureStack->addWidget(nonRuptureWidget);
    penrLabel = new QLabel("PEN Ratio:");
    nonRuptureLayout->addWidget(penrLabel, 0, 0);
    penLabel = new QLabel("PEN:");
    nonRuptureLayout->addWidget(penLabel, 1, 0);
    erLabel = new QLabel("Energy Regen:");
    nonRuptureLayout->addWidget(erLabel, 2, 0);
    // rupture layout
    QWidget *ruptureWidget = new QWidget();
    ruptureWidget->setLayout(ruptureLayout);
    ruptureStack->addWidget(ruptureWidget);
    sfLabel = new QLabel("Sheer Force:");
    ruptureLayout->addWidget(sfLabel, 0, 0);
    aaaLabel = new QLabel("Automatic Adrenaline Accumulation:");
    ruptureLayout->addWidget(aaaLabel, 1, 0);
    QLabel *spacer = new QLabel(""); // empty spacer
    ruptureLayout->addWidget(spacer, 2, 0);

    // default values for stats
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

    // redraw character button image
    QPixmap iconPix(QString::fromStdString(currentCharacter.images.normalIcon));
    characterSelect->setIcon(QIcon(iconPix));
    characterSelect->setIconSize(QSize(100, 100));
    characterSelect->setText(QString::fromStdString(currentCharacter.nickname).replace('&', "&&")); // make & actually show up

    // redraw wengine button image
    QPixmap wiconPix(QString::fromStdString(currentWengine.image));
    wengineSelect->setIcon(QIcon(wiconPix));
    wengineSelect->setIconSize(QSize(100, 100));
    wengineSelect->setText(QString::fromStdString(currentWengine.name));
}

void calculator::redrawStats(character::character calcs) {
    // set labels
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
    if (calcs.specialty == calc::specialty::Rupture) {
        ruptureStack->setCurrentIndex(1); // rupture
    } else {
        ruptureStack->setCurrentIndex(0); // not rupture
    }
}

void calculator::redrawDisc(int slotNumber) {
    // redraw the disc button for that slot
    disc redrawnDisc = currentCharacter.discs[slotNumber];

    discButtons[slotNumber]->setText(QString::fromStdString(redrawnDisc.discMap.at(redrawnDisc.getSet()).displayName).replace('&', "&&"));

    QPixmap discPix(QString::fromStdString(redrawnDisc.discMap.at(redrawnDisc.getSet()).resource));
    discButtons[slotNumber]->setIcon(QIcon(discPix));
    discButtons[slotNumber]->setIconSize(QSize(80, 80));

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
    // calculate all stats
    calculatedCharacter = calc::calculateAll(currentCharacter, currentWengine, currentCharacter.discs);

    // show the computed stats (no discs yet)
    redrawStats(calculatedCharacter);
}

calculator::~calculator() {}
