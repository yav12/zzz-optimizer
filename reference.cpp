#include "window.h"
#include "character.h"

void window::setupReference() {
    //set up layout
    reference = new QWidget(this);
    referenceLayout = new QHBoxLayout();

    reference->setLayout(referenceLayout);
    content->addWidget(reference);

    //make navigation work
    connect(referenceButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(reference);});

    //display stuff
    referencePlaceholderLabel = new QLabel;
    referencePlaceholderLabel->setPixmap(QPixmap(QString::fromStdString(character::nekomata.images.mindscapeFull)));
    referencePlaceholderLabel->setAlignment(Qt::AlignCenter);
    referenceLayout->addWidget(referencePlaceholderLabel);

}
