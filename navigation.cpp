#include "window.h"

void window::setupNavigation() {
    //put the navigation layout in the window
    navLayout = new QHBoxLayout();
    navLayout->setSizeConstraint(QLayout::SetNoConstraint);
    layout->addLayout(navLayout);

    //set the buttons
    homeButton = new QPushButton("home");
    referenceButton = new QPushButton("reference");
    calculatorButton = new QPushButton("calculator");
    libraryButton = new QPushButton("library");
    importButton = new QPushButton("import");

    //put the buttons in the navigation
    navLayout->addWidget(homeButton);
    navLayout->addWidget(referenceButton);
    navLayout->addWidget(calculatorButton);
    navLayout->addWidget(libraryButton);
    navLayout->addWidget(importButton);

    //navigation connects are with each respective widget

}
