#include "window.h"
#include "data/character.h"

void window::setupHome() {
    //set up layout
    home = new QWidget(this);
    homeLayout = new QHBoxLayout();

    home->setLayout(homeLayout);
    content->addWidget(home);

    //make navigation work
    connect(homeButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(home);});

    //display stuff
    homePlaceholderLabel = new QLabel;
    // allow the image to scale with the label when the window resizes
    homePlaceholderLabel->setScaledContents(true);
    homePlaceholderLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    homePlaceholderLabel->setAlignment(Qt::AlignCenter);
    homePlaceholderLabel->setPixmap(QPixmap(QString::fromStdString(character::jufufu.images.mindscapeFull)));
    homeLayout->addWidget(homePlaceholderLabel);

}
