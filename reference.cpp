#include "window.h"
#include "character.h"

void window::setupReference() {
    //set up layout
    reference = new QWidget(this);
    referenceLayout = new QGridLayout();
    refInfo = new QGridLayout;

    content->addWidget(reference);
    reference->setLayout(referenceLayout);
    referenceLayout->addLayout(refInfo,0,1);

    //make navigation work
    connect(referenceButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(reference);});

    //labels
    refCharacter = new QLabel;
    refRarity = new QLabel;
    refSpecialty = new QLabel;
    refAttribute = new QLabel;
    refFactionText = new QLabel;
    refFaction = new QLabel;
    refPortrait = new QLabel;
    refMindscapeImage = new QLabel;
    //default image
    refMindscapeImage->setPixmap(QPixmap(QString::fromStdString(character::nekomata.images.mindscapeFull)));
    refMindscapeImage->setScaledContents(true);
    refMindscapeImage->setAlignment(Qt::AlignCenter);

    //reference combobox
    QComboBox *refCharacterSelect = new QComboBox;
    for (const auto& character : character::characterList) {
        refCharacterSelect->addItem(QString::fromStdString(character.nickname));
    }
    referenceLayout->addWidget(refCharacterSelect,0,0);
    connect(refCharacterSelect, &QComboBox::currentTextChanged, [this](const QString &selection) {
        std::string comboString = selection.toStdString();
        setCurrentRefCharacter(comboString);
    });

    //set label locations
    refInfo->addWidget(refCharacter, 0, 0);
    refInfo->addWidget(refRarity, 1, 0);
    refInfo->addWidget(refSpecialty, 2, 0);
    refInfo->addWidget(refAttribute, 3, 0);
    refInfo->addWidget(refFactionText, 4, 0);
    refInfo->addWidget(refFaction, 5, 0);
    referenceLayout->addWidget(refMindscapeImage, 1, 0, 1, 2);

    referenceLayout->activate();
    reference->updateGeometry();
    reference->update();
}

void window::setCurrentRefCharacter(std::string &comboString) {
    for (const auto& c : character::characterList) {
        if (c.nickname == comboString) {
            currentRefCharacter = c;
            break;
        } //no catch cuz its not possible for it to miss (i think)
    }
    updateReference();
}

void window::updateReference() {
    //text
    refCharacter->setText(QString::fromStdString(currentRefCharacter.name));
    refRarity->setText(QString::fromStdString(currentRefCharacter.rarity + " rank"));
    refSpecialty->setText(QString::fromStdString(currentRefCharacter.specialty));
    refAttribute->setText(QString::fromStdString(currentRefCharacter.attribute));
    refFactionText->setText("Faction:");
    refFaction->setText(QString::fromStdString(currentRefCharacter.faction));
    //image
    refMindscapeImage->setPixmap(QPixmap(QString::fromStdString(currentRefCharacter.images.mindscapeFull)));
    refMindscapeImage->setAlignment(Qt::AlignCenter);
    refMindscapeImage->setScaledContents(true);
}
