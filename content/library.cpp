#include "../window.h"
#include "../data/character.h"
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
    // allow the image to scale with the label when the window resizes
    libraryPlaceholderLabel->setScaledContents(true);
    libraryPlaceholderLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    libraryPlaceholderLabel->setAlignment(Qt::AlignCenter);
    libraryPlaceholderLabel->setPixmap(QPixmap(QString::fromStdString(character::yixuan.images.mindscapeFull)));
    libraryLayout->addWidget(libraryPlaceholderLabel);
}
