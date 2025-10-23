#include "wengineselector.h"

wengineSelector::wengineSelector(QWidget *parent) : QWidget(parent)
{
    //layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    //title
    titleLabel = new QLabel("Select Wengine");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);
    
    // wengine selection
    QWidget *gridContainer = new QWidget();
    selectionLayout = new QGridLayout(gridContainer);
    gridContainer->setLayout(selectionLayout);
    selectionLayout->setAlignment(Qt::AlignCenter);

    QScrollArea *scroll = new QScrollArea();
    scroll->setWidgetResizable(true);
    scroll->setWidget(gridContainer);
    // only vertical scrolling; prevent horizontal scrollbar
    scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    mainLayout->addWidget(scroll);

    // create buttons and place them in a fixed 10-column grid
    int index = 0;
    const int columns = 10;
    for (const auto& wengineItem : wengine::wengineList) {
        QToolButton *wengineButton = new QToolButton();
        QPixmap wenginePix(QString::fromStdString(wengineItem.image));
        wengineButton->setIcon(QIcon(wenginePix));
        wengineButton->setIconSize(QSize(150, 150));
        wengineButton->setText(QString::fromStdString(wengineItem.name));
        wengineButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        // store the button and an item copy for the click handler
        wengineButtons.append(wengineButton);
        wengineCopies.append(wengineItem);

        int thisIndex = index; // capture index per-iteration
        auto itemCopy = wengineItem;
        connect(wengineButton, &QToolButton::clicked, this, [this, thisIndex, itemCopy]() {
            selectedIndex = thisIndex;
            emit wengineSelected(itemCopy);
        });

        // set position of the button
        int row = index / columns;
        int col = index % columns;

        // add the button centered inside the grid cell
        selectionLayout->addWidget(wengineButton, row, col, Qt::AlignCenter);

        ++index;
    }
}


// Responsive reflow removed: grid is populated with a fixed column count at construction

wengineSelector::~wengineSelector()
{
}