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

    //set default character
    refCharacterSelect->setCurrentIndex(0);

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
    QPixmap pix(QString::fromStdString(currentRefCharacter.images.mindscapeFull));
    QSize size = refMindscapeImage->contentsRect().size();
    QPixmap scaledPix = pix.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    refMindscapeImage->setPixmap(scaledPix);
    refMindscapeImage->setAlignment(Qt::AlignCenter);
}
