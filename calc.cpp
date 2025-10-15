#include "window.h"
#include "character.h"
#include "QComboBox"

void window::setupCalculator() {
    //set up layout
    calc = new QWidget(this);
    calcLayout = new QGridLayout();

    calc->setLayout(calcLayout);
    content->addWidget(calc);

    //make navigation work
    connect(calculatorButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(calc);});

    //display stuff
    calcPlaceholderLabel = new QLabel;
    calcPlaceholderLabel->setPixmap(QPixmap(QString::fromStdString(character::anby.images.mindscapeFull)));
    calcPlaceholderLabel->setAlignment(Qt::AlignCenter);
    calcLayout->addWidget(calcPlaceholderLabel, 2, 0, 1, 2);


    //calculator buttons
    QComboBox *characterSelect = new QComboBox;
    for (const auto& character : character::characterList) {
        characterSelect->addItem(QString::fromStdString(character.nickname));
    }
    calcLayout->addWidget(characterSelect,0,0);
}
