#include "charselector.h"

charSelector::charSelector(QWidget *parent) : QWidget(parent)
{
    //layout
    mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    //title
    titleLabel = new QLabel("Select Character");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);
    
    // character selection
    selectionLayout = new QGridLayout();
    mainLayout->addLayout(selectionLayout);
    selectionLayout->setAlignment(Qt::AlignCenter);
    int characterCount = character::characterList.size();
    int columns = 7; // Number of columns in the grid
    int index = 0;

    for (const auto& character : character::characterList) {
        int row = index / columns;
        int col = index % columns;

        QToolButton *characterButton = new QToolButton();
        QPixmap charPix(QString::fromStdString(character.images.normalIcon));
        characterButton->setIcon(QIcon(charPix));
        characterButton->setIconSize(QSize(150, 150));
        characterButton->setText(QString::fromStdString(character.nickname).replace('&', "&&")); // make & actually show up 
        characterButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        selectionLayout->addWidget(characterButton, row, col);
        int buttonIndex = index;
        ++index;

        connect(characterButton, &QToolButton::clicked, this, [this, buttonIndex]() {
            // ai told me this would work
            selectedIndex = buttonIndex;
            emit characterSelected(character::characterList[buttonIndex]);
        });
    }
}

charSelector::~charSelector()
{
}

