#include "window.h"
#include "character.h"
void window::setupLibrary() {
    //set up layout
    library = new QWidget(this);
    libraryLayout = new QHBoxLayout();

    library->setLayout(libraryLayout);
    content->addWidget(library);

    //make navigation work
    connect(libraryButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(library);});

    //display stuff
    libraryPlaceholderLabel = new QLabel;
    libraryPlaceholderLabel->setPixmap(QPixmap(QString::fromStdString(character::yixuan.images.mindscapeFull)));
    libraryPlaceholderLabel->setAlignment(Qt::AlignCenter);
    libraryLayout->addWidget(libraryPlaceholderLabel);
}
