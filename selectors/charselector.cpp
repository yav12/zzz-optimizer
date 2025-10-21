#include "charselector.h"

charSelector::charSelector(QWidget *parent) : QDialog(parent)
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
    int columns = 6; // Number of columns in the grid
    int rows = (characterCount + columns - 1) / columns; // Calculate required rows
    int index = 0;

    for (const auto& character : character::characterList) {
        int row = index / columns;
        int col = index % columns;

        QToolButton *characterButton = new QToolButton();
        QPixmap charPix(QString::fromStdString(character.images.normalIcon));
        characterButton->setIcon(QIcon(charPix));
        characterButton->setIconSize(QSize(100, 100));
        characterButton->setText(QString::fromStdString(character.nickname));
        characterButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        selectionLayout->addWidget(characterButton, row, col);
        int buttonIndex = index;
        ++index;

        connect(characterButton, &QToolButton::clicked, this, [this, buttonIndex]() {
            selectedIndex = buttonIndex;
            this->accept();
        });
    }
}

charSelector::~charSelector()
{
}

character::character charSelector::picker(QWidget *parent)
{
    charSelector dlg(parent);
    if (dlg.exec() == QDialog::Accepted && dlg.selectedIndex >= 0) {
        return character::characterList[dlg.selectedIndex];
    }
    return character::character();
}