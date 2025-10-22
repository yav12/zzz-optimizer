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

    // create buttons and keep them so we can reflow on resize
    int index = 0;
    for (const auto& wengineItem : wengine::wengineList) {
        QToolButton *wengineButton = new QToolButton();
        QPixmap wenginePix(QString::fromStdString(wengineItem.image));
        wengineButton->setIcon(QIcon(wenginePix));
        wengineButton->setIconSize(QSize(100, 100));
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

        ++index;
    }

    // initial layout will be done in resizeEvent
}


void wengineSelector::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    // determine columns based on current width (min 1)
    int columns = std::max(1, width() / 100);

    // clear existing items from layout (but don't delete widgets)
    while (QLayoutItem *item = selectionLayout->takeAt(0)) {
        // takeAt removes the layout item but doesn't delete the widget
    }

    // re-add widgets with new grid positions
    for (int i = 0; i < wengineButtons.size(); ++i) {
        int row = i / columns;
        int col = i % columns;
        selectionLayout->addWidget(wengineButtons[i], row, col);
    }
}

wengineSelector::~wengineSelector()
{
}