#include "reference.h"
#include <QComboBox>
#include <QPushButton>
#include "../selectors/charselector.h"

reference::reference(QWidget *parent) : QWidget(parent) {
    // top-level pages stack (main page + selector page)
    pagesStack = new QStackedWidget();
    QVBoxLayout *outer = new QVBoxLayout();
    setLayout(outer);
    outer->addWidget(pagesStack);

    // --- main page ---
    mainPage = new QWidget();
    mainLayout = new QVBoxLayout();
    mainPage->setLayout(mainLayout);

    referenceLayout = new QGridLayout();
    refInfo = new QGridLayout();

    mainLayout->addLayout(referenceLayout);

    // labels
    refCharacter = new QLabel;
    refRarity = new QLabel;
    refSpecialty = new QLabel;
    refAttribute = new QLabel;
    refFactionText = new QLabel;
    refFaction = new QLabel;
    refMindscapeImage = new QLabel;

    // allow mindscape image to scale with the widget
    refMindscapeImage->setScaledContents(true);
    refMindscapeImage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // button to open the full character selector page
    openSelectorButton = new QToolButton();
    referenceLayout->addWidget(openSelectorButton, 0, 0);

    connect(openSelectorButton, &QToolButton::clicked, this, [this]() {
        if (pagesStack) pagesStack->setCurrentWidget(charSelectorWidget);
    });

    // set label locations
    referenceLayout->addLayout(refInfo, 0, 1);
    refInfo->addWidget(refCharacter, 0, 0);
    refInfo->addWidget(refRarity, 1, 0);
    refInfo->addWidget(refSpecialty, 2, 0);
    refInfo->addWidget(refAttribute, 3, 0);
    refInfo->addWidget(refFactionText, 4, 0);
    refInfo->addWidget(refFaction, 5, 0);
    referenceLayout->addWidget(refMindscapeImage, 1, 0, 1, 2);

    pagesStack->addWidget(mainPage);

    // --- selector page ---
    charSelectorWidget = new charSelector(this);
    pagesStack->addWidget(charSelectorWidget);

    // when a character is selected from the selector page, update and return to main
    connect(charSelectorWidget, &charSelector::characterSelected, this, [this](const character::character &c) {
        setCharacter(c);
        if (pagesStack) pagesStack->setCurrentWidget(mainPage);
    });

    // set default character
    setCharacter(character::jufufu);
}

void reference::setCharacter(character::character c) {
    currentRefCharacter = c;
    updateReference();
}

void reference::updateReference() {
    // selector button
    QPixmap buttonPix(QString::fromStdString(currentRefCharacter.images.normalIcon));
    openSelectorButton->setIcon(buttonPix);
    openSelectorButton->setIconSize(QSize(100, 100));
    openSelectorButton->setText(QString::fromStdString(currentRefCharacter.nickname));

    // text
    refCharacter->setText(QString::fromStdString(currentRefCharacter.name));
    refRarity->setText(QString::fromStdString(currentRefCharacter.rarity + " rank"));
    refSpecialty->setText(QString::fromStdString(currentRefCharacter.specialty));
    refAttribute->setText(QString::fromStdString(currentRefCharacter.attribute));
    refFactionText->setText("Faction:");
    refFaction->setText(QString::fromStdString(currentRefCharacter.faction));
    // image
    QPixmap pix(QString::fromStdString(currentRefCharacter.images.mindscapeFull));
    QSize size = refMindscapeImage->contentsRect().size();
    QPixmap scaledPix = pix.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    refMindscapeImage->setPixmap(scaledPix);
    refMindscapeImage->setAlignment(Qt::AlignCenter);
}

reference::~reference() {
    // default cleanup handled by Qt parent/child ownership
}
