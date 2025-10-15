#include "window.h"
#include "character.h"

void window::setupReference() {
    //set up layout
    reference = new QWidget(this);
    referenceLayout = new QGridLayout();

    reference->setLayout(referenceLayout);
    content->addWidget(reference);

    //make navigation work
    connect(referenceButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(reference);});

    //reference combobox
    QComboBox *refCharacterSelect = new QComboBox;
    for (const auto& character : character::characterList) {
        refCharacterSelect->addItem(QString::fromStdString(character.nickname));
    }
    referenceLayout->addWidget(refCharacterSelect,0,0);
    connect(refCharacterSelect, &QComboBox::currentTextChanged, [=] {});

    //display stuff
    referencePlaceholderLabel = new QLabel;
    referencePlaceholderLabel->setPixmap(QPixmap(QString::fromStdString(character::nekomata.images.mindscapeFull)));
    referencePlaceholderLabel->setAlignment(Qt::AlignCenter);
    referenceLayout->addWidget(referencePlaceholderLabel, 2, 0, 1, 2);
}

void window::setCurrentRefCharacter(std::string &comboString) {
    for (const auto& c : character::characterList) {
        if (c.nickname == comboString) {
            currentRefCharacter = c;
            break;
        } //no catch cuz its not possible for it to miss (i think)
    }
}

void window::updateReference() {
    referencePlaceholderLabel->setPixmap(QPixmap(QString::fromStdString(currentRefCharacter.images.mindscapeFull)));
}
