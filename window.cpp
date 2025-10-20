#include "window.h"
#include "QLayout"
#include "QPushButton"
#include "QStackedWidget"
#include "QLabel"
#include "QPixmap"
#include "content/character.h"

window::window(QWidget *parent)
    : QMainWindow(parent)
{
    wengine::setWengineData(); 
    character::setCharacterData(); // populate image paths & stats
    setupWindow();
}

void window::setupWindow() {
    setWindowTitle(tr("zzz optimizer"));
    //set the widget so things can actually be seen
    windowWidget = new QWidget(this);
    setCentralWidget(windowWidget);

    //set the main window layout
    layout = new QVBoxLayout();
    windowWidget->setLayout(layout);

    //set navigation
    setupNavigation();

    //set content
    content = new QStackedWidget;
    layout->addWidget(content);
    setupHome();
    setupReference();
    calcWidget = new calculator(this);
    content->addWidget(calcWidget);
    setupLibrary();

    //navigation connects
    connect(calculatorButton, &QPushButton::clicked, [=]() { content->setCurrentWidget(calcWidget); });
}


window::~window()
{
}

