#include "window.h"
#include "QLayout"
#include "QPushButton"
#include "QStackedWidget"
#include "QLabel"
#include "QPixmap"


window::window(QWidget *parent)
    : QMainWindow(parent)
{
    setupWindow();

}

void window::setupWindow() {
    setWindowTitle(tr("zzz optimizer"));
    initializations();
    //set the widget so things can actually be seen
    setCentralWidget(windowWidget);

    //set the main window layout
    layout = new QVBoxLayout();
    navLayout = new QHBoxLayout();
    navLayout->setSizeConstraint(QLayout::SetMinimumSize);
    windowWidget->setLayout(layout);
    layout->addLayout(navLayout);
    layout->addWidget(content);

    //add the navigation buttons
    navLayout->addWidget(homeButton);
    navLayout->addWidget(referenceButton);
    navLayout->addWidget(calculatorButton);
    navLayout->addWidget(libraryButton);
    navLayout->addWidget(importButton);


    //add the content regions
    home->setLayout(homeLayout);
    reference->setLayout(referenceLayout);
    calc->setLayout(calcLayout);
    library->setLayout(libraryLayout);

    content->addWidget(home);
    content->addWidget(reference);
    content->addWidget(calc);
    content->addWidget(library);

    //make navigation buttons work
    connect(homeButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(home);});
    connect(referenceButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(reference);});
    connect(calculatorButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(calc);});
    connect(libraryButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(library);});


    //set placeholder images to see
    homePlaceholderLabel = new QLabel;
    homePlaceholderLabel->setPixmap(QPixmap(":/characters/jufufu/MindscapeFull.png"));
    homePlaceholderLabel->setAlignment(Qt::AlignCenter);
    referencePlaceholderLabel = new QLabel;
    referencePlaceholderLabel->setPixmap(QPixmap(":/characters/nekomata/MindscapeFull.png"));
    referencePlaceholderLabel->setAlignment(Qt::AlignCenter);
    calcPlaceholderLabel = new QLabel;
    calcPlaceholderLabel->setPixmap(QPixmap(":/characters/anby/MindscapeFull.png"));
    calcPlaceholderLabel->setAlignment(Qt::AlignCenter);
    libraryPlaceholderLabel = new QLabel;
    libraryPlaceholderLabel->setPixmap(QPixmap(":/characters/yixuan/MindscapeFull.png"));
    libraryPlaceholderLabel->setAlignment(Qt::AlignCenter);

    //apply placeholder images
    homeLayout->addWidget(homePlaceholderLabel);
    referenceLayout->addWidget(referencePlaceholderLabel);
    calcLayout->addWidget(calcPlaceholderLabel);
    libraryLayout->addWidget(libraryPlaceholderLabel);
}

void window::initializations() {
    //layout
    windowWidget = new QWidget(this);

    //navigation buttons
    homeButton = new QPushButton("home");
    referenceButton = new QPushButton("reference");
    calculatorButton = new QPushButton("calculator");
    libraryButton = new QPushButton("library");
    importButton = new QPushButton("import");

    //content regions
    content = new QStackedWidget;
    home = new QWidget(this);
    homeLayout = new QHBoxLayout();
    reference = new QWidget(this);
    referenceLayout = new QHBoxLayout();
    calc = new QWidget(this);
    calcLayout = new QHBoxLayout();
    library = new QWidget(this);
    libraryLayout = new QHBoxLayout();
}

window::~window()
{
}

