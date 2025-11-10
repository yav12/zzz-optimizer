#include "discselector.h"

discSelector::discSelector(QWidget *parent, int slotNumber) : QWidget(parent), slot(slotNumber)
{
    //layout
    mainLayout = new QStackedLayout();
    setLayout(mainLayout);

    // disc set portion
    discLayout = new QVBoxLayout();
    QWidget *discWidget = new QWidget();
    discWidget->setLayout(discLayout);
    mainLayout->addWidget(discWidget);

    //title
    titleLabel = new QLabel("Select Disc for Slot " + QString::number(slot + 1));
    titleLabel->setAlignment(Qt::AlignCenter);
    discLayout->addWidget(titleLabel);

    // disc selection
    selectionLayout = new QGridLayout();
    discLayout->addLayout(selectionLayout);
    selectionLayout->setAlignment(Qt::AlignCenter);
    const int columns = 5; // choose columns
    int index = 0;

    for (const auto &discItem : disc::discList) {
        int row = index / columns;
        int col = index % columns;

        QToolButton *discButton = new QToolButton();
        QPixmap discPix(QString::fromStdString(discItem.resource));
        discButton->setIcon(QIcon(discPix));
        discButton->setIconSize(QSize(150, 150));
        discButton->setText(QString::fromStdString(discItem.displayName).replace('&', "&&")); 
        discButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        selectionLayout->addWidget(discButton, row, col, Qt::AlignCenter);

        int buttonIndex = index;
        auto itemCopy = discItem; // capture per-iteration copy
        ++index;
        connect(discButton, &QToolButton::clicked, this, [this, buttonIndex, itemCopy]() {
            // store selected disc
            selectedDisc.setName(itemCopy.displayName);
            selectedDisc.setSlot(slot);
        });
    }

    // disc subs portion
    subsLayout = new QHBoxLayout();
    discLayout->addLayout(subsLayout);

    emit discSelected(selectedDisc);

    //stop everything and close
    QShortcut *escShortcut = new QShortcut(QKeySequence(Qt::Key_Escape), this);
    connect(escShortcut, &QShortcut::activated, this, [this]() {
        this->deleteLater();
    });
}

discSelector::~discSelector() 
{

}