#include "window.h"
#include "QLayout"
#include "QPushButton"
#include "QStackedWidget"
#include "QLabel"
#include "QPixmap"
#include "character.h"

window::window(QWidget *parent)
    : QMainWindow(parent)
{
    setupWengines();
    setupCharacters();
    setupWindow();

}

void window::setupWengines() {
    wengine::setWengineData(); // populate image paths & stats
}

void window::setupCharacters() {
    character::setCharacterData(); // populate image paths & stats
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
    setupCalculator();
    setupLibrary();
}


window::~window()
{
}

