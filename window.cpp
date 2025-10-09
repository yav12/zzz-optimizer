#include "window.h"
#include "QLayout"
#include "QPushButton"
#include "QLabel"
#include "QPixmap"


window::window(QWidget *parent)
    : QMainWindow(parent)
{
    setupWindow();

}

void window::setupWindow() {
    setWindowTitle(tr("zzz optimizer"));
    //set the widget so things can actually be seen
    QWidget *windowWidget = new QWidget(this);
    setCentralWidget(windowWidget);

    //set the main window layout
    layout = new QVBoxLayout();
    navLayout = new QHBoxLayout();
    navLayout->setSizeConstraint(QLayout::SetMinimumSize);
    windowWidget->setLayout(layout);
    layout->addLayout(navLayout);

    //add the navigation buttons
    referenceButton = new QPushButton("reference");
    calculatorButton = new QPushButton("calculator");
    libraryButton = new QPushButton("library");
    importButton = new QPushButton("import");

    navLayout->addWidget(referenceButton);
    navLayout->addWidget(calculatorButton);
    navLayout->addWidget(libraryButton);
    navLayout->addWidget(importButton);

    //placeholder image to see
    QPixmap pix(":/characters/jufufu/MindscapeFull.png");
    placeholder = new QLabel;
    placeholder->setPixmap(pix);
    placeholder->setScaledContents(true);
    layout->addWidget(placeholder);
}

window::~window()
{
}

