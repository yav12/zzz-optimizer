#include "window.h"
#include "content/character.h"

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
    homePlaceholderLabel->setPixmap(QPixmap(QString::fromStdString(character::jufufu.images.mindscapeFull)));
    homePlaceholderLabel->setAlignment(Qt::AlignCenter);
    homeLayout->addWidget(homePlaceholderLabel);

}
