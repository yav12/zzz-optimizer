#include "window.h"
#include "character.h"

void window::setupCalculator() {
    //set up layout
    calc = new QWidget(this);
    calcLayout = new QHBoxLayout();

    calc->setLayout(calcLayout);
    content->addWidget(calc);

    //make navigation work
    connect(calculatorButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(calc);});

    //display stuff
    calcPlaceholderLabel = new QLabel;
    calcPlaceholderLabel->setPixmap(QPixmap(QString::fromStdString(character::anby.images.mindscapeFull)));
    calcPlaceholderLabel->setAlignment(Qt::AlignCenter);
    calcLayout->addWidget(calcPlaceholderLabel);

}
