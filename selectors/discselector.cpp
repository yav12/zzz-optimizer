#include "discselector.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QGridLayout>
#include <QToolButton>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QPushButton>
#include <QStackedLayout>
#include <qboxlayout.h>
#include <qcombobox.h>
#include <QFrame>        // added
#include <qpushbutton.h>
#include <vector>

discSelector::discSelector(QWidget *parent, int slotNumber, disc initialDisc) : QWidget(parent), slot(slotNumber), selectedDisc(initialDisc)
{
    // Use a stacked layout for the main content and center it
    mainLayout = new QStackedLayout();
    QWidget *stackContainer = new QWidget(this);
    stackContainer->setLayout(mainLayout);
    QHBoxLayout *outerLayout = new QHBoxLayout(this);
    outerLayout->addWidget(stackContainer, 0, Qt::AlignCenter);
    setLayout(outerLayout);

    // --- Disc selection page ---
    // use a QFrame so we can style a visible background
    discWidget = new QFrame(this);
    auto discFrame = qobject_cast<QFrame*>(discWidget);
    discFrame->setFrameShape(QFrame::StyledPanel);
    discFrame->setFrameShadow(QFrame::Raised);
    // square background styling — adjust size/color/border as needed
    discFrame->setStyleSheet("background-color: rgba(40,40,40,0.95);");
    // force a square background (change 600 to desired dimension)
    discFrame->setFixedSize(600, 600);
    discLayout = new QVBoxLayout(discFrame);
    discLayout->setContentsMargins(12, 12, 12, 12);
    //title for selection page
    titleLabel = new QLabel("Select Disc for Slot " + QString::number(slot + 1));
    titleLabel->setAlignment(Qt::AlignCenter);
    discLayout->addWidget(titleLabel);

    // disc selection grid
    selectionLayout = new QGridLayout();
    discLayout->addLayout(selectionLayout);
    selectionLayout->setAlignment(Qt::AlignCenter);
    const int columns = 6; // choose columns
    int index = 0;

    // Create the subs page early so lambdas can reference its widgets
    subsWidget = new QFrame(this);
    auto subsFrame = qobject_cast<QFrame*>(subsWidget);
    subsFrame->setFrameShape(QFrame::StyledPanel);
    subsFrame->setFrameShadow(QFrame::Raised);
    subsFrame->setStyleSheet("background-color: rgba(40,40,40,0.95);");
    subsFrame->setFixedSize(600, 600);
    subsLayout = new QGridLayout(subsFrame);
    subsLayout->setContentsMargins(12, 12, 12, 12);

    // subs page header and main stat selector
    QLabel *subsTitleLabel = new QLabel("Disc details");
    subsTitleLabel->setAlignment(Qt::AlignCenter);
    subsLayout->addWidget(subsTitleLabel, 0, 0, 1, 2);

    QLabel *subsMainLabel = new QLabel("Select main stat for disc:");
    subsLayout->addWidget(subsMainLabel, 1, 0);
    QComboBox *mainStatComboBox = new QComboBox();
    subsLayout->addWidget(mainStatComboBox, 1, 1);

    
    QFormLayout *subsSubsLayout = new QFormLayout();
    subsLayout->addLayout(subsSubsLayout, 2, 0, 1, 2);
    QLabel *subsSubsLabel = new QLabel("Select Substats:");
    subsSubsLayout->addWidget(subsSubsLabel);
    // 
    subCombos.assign(4, new QComboBox());
    subRolls.assign(4, new QSpinBox());

    for (size_t i = 0; i < 4; ++i) {
        subsSubsLayout->addRow(subCombos[i], subRolls[i]);
        subCombos[i]->addItem(""); // empty roll cuz they might not have 4 subs

        // add all possible substats
        subCombos[i]->addItem("HP");
        subCombos[i]->addItem("ATK");
        subCombos[i]->addItem("DEF");
        subCombos[i]->addItem("HP%");
        subCombos[i]->addItem("ATK%");
        subCombos[i]->addItem("DEF%");
        subCombos[i]->addItem("CRIT Rate");
        subCombos[i]->addItem("CRIT Damage");
        subCombos[i]->addItem("Anomaly Proficiency");
        subCombos[i]->addItem("PEN");

        // configure roll spinboxes
        subRolls[i]->setRange(0, 5); // you can only have max 5 rolls
        subRolls[i]->setValue(0);    // default to 0 rolls
    }

    QPushButton *backButton = new QPushButton("Back");
    subsLayout->addWidget(backButton, 3, 0, 1, 1, Qt::AlignCenter);
    QPushButton *confirmButton = new QPushButton("Done");
    subsLayout->addWidget(confirmButton, 3, 1, 1, 1, Qt::AlignCenter);

    // populate the disc selection grid
    for (const auto &discItem : disc::discMap) {
        int row = index / columns;
        int col = index % columns;

        QToolButton *discButton = new QToolButton();
        QPixmap discPix(QString::fromStdString(discItem.second.resource));
        discButton->setIcon(QIcon(discPix));
        discButton->setIconSize(QSize(100, 100));
        discButton->setText(QString::fromStdString(discItem.second.displayName).replace('&', "&&")); 
        discButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        selectionLayout->addWidget(discButton, row, col, Qt::AlignCenter);

        auto itemCopy = discItem; // capture per-iteration copy
        connect(discButton, &QToolButton::clicked, this, [this, itemCopy, mainStatComboBox, subsTitleLabel]() {
            // store selected disc
            selectedDisc.setSet(itemCopy.first);
            selectedDisc.setSlot(slot + 1);
            // update subs header and main-stat combobox
            subsTitleLabel->setText(QString::fromStdString(itemCopy.second.displayName));
            mainStatComboBox->clear();
            mainStatComboBox->setCurrentText("");
            switch (slot) {
                case 1:
                    mainStatComboBox->addItem("ATK");
                    mainStatComboBox->setCurrentText("ATK");
                    mainStatComboBox->setEnabled(false);
                    break;
                case 2:
                    mainStatComboBox->addItem("DEF");
                    mainStatComboBox->setCurrentText("DEF");
                    mainStatComboBox->setEnabled(false);
                    break;
                case 3:
                    mainStatComboBox->addItem("HP");
                    mainStatComboBox->setCurrentText("HP");
                    mainStatComboBox->setEnabled(false);
                    break;
                case 4:
                    mainStatComboBox->addItem("HP%");
                    mainStatComboBox->addItem("ATK%");
                    mainStatComboBox->addItem("DEF%");
                    mainStatComboBox->addItem("CRIT Rate");
                    mainStatComboBox->addItem("CRIT Damage");
                    mainStatComboBox->addItem("Anomaly Proficiency");
                    break;
                case 5:
                    mainStatComboBox->addItem("HP%");
                    mainStatComboBox->addItem("ATK%");
                    mainStatComboBox->addItem("DEF%");
                    mainStatComboBox->addItem("PEN Ratio%");
                    mainStatComboBox->addItem("Fire Damage%");
                    mainStatComboBox->addItem("Physical Damage%");
                    mainStatComboBox->addItem("Ether Damage%");
                    mainStatComboBox->addItem("Ice Damage%");
                    mainStatComboBox->addItem("Electric Damage%");
                    break;
                case 6:
                    mainStatComboBox->addItem("HP%");
                    mainStatComboBox->addItem("ATK%");
                    mainStatComboBox->addItem("DEF%");
                    mainStatComboBox->addItem("Anomaly Mastery%");
                    mainStatComboBox->addItem("Energy Regen%");
                    mainStatComboBox->addItem("Impact%");
                    break;
            }

            // switch to the subs/configuration page
            mainLayout->setCurrentWidget(subsWidget);
        });

        ++index;
    }

    // add both pages to the stacked layout
    mainLayout->addWidget(discWidget);
    mainLayout->addWidget(subsWidget);

    // start on the subs page when an initial disc is provided; otherwise show selector
    if (initialDisc.getSet() != calc::discSet::None) {
        mainLayout->setCurrentWidget(subsWidget);
    } else {
        mainLayout->setCurrentWidget(discWidget);
    }

    

    // stop everything and close when esc is pressed
    QShortcut *escShortcut = new QShortcut(QKeySequence(Qt::Key_Escape), this);
    connect(escShortcut, &QShortcut::activated, this, [this]() {
        this->deleteLater();
    });

    // back button returns to disc selection
    connect(backButton, &QPushButton::clicked, this, [this]() {
        mainLayout->setCurrentWidget(discWidget);
    });
    
    // confirm button emits selection and closes
    connect(confirmButton, &QPushButton::clicked, this, [this, mainStatComboBox]() {
        //set the disc
        selectedDisc.setMainStat(calc::stringToStats(mainStatComboBox->currentText().toStdString()));
        for (size_t i = 0; i < subCombos.size(); ++i) {
            calc::stats subStat = calc::stringToStats(this->subCombos[i]->currentText().toStdString());
            int rolls = this->subRolls[i]->value();
            switch (i) {
                case 0:
                    selectedDisc.setSub1(subStat, rolls);
                    break;
                case 1:
                    selectedDisc.setSub2(subStat, rolls);
                    break;
                case 2:
                    selectedDisc.setSub3(subStat, rolls);
                    break;
                case 3:
                    selectedDisc.setSub4(subStat, rolls);
                    break;
            }
        }

        emit discSelected(selectedDisc);
        this->deleteLater();
    });
}

discSelector::~discSelector() 
{

}
 
