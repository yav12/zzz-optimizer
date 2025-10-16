#include "window.h"
#include "character.h"
#include "QComboBox"

void window::setupCalculator() {
    //set up layout
    calc = new QWidget(this);
    calcLayout = new QGridLayout();
    calcSelectLayout = new QGridLayout();

    content->addWidget(calc);
    calc->setLayout(calcLayout);
    calcLayout->addLayout(calcSelectLayout, 0, 0, 1, 1);

    //make navigation work
    connect(calculatorButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(calc);});


    //labels
    calcWengineImage = new QLabel;
    calcMindscapeImage = new QLabel;
    calcMindscapeImage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    calcMindscapeImage->setAlignment(Qt::AlignCenter);

    //set label locations
    calcLayout->addWidget(calcWengineImage, 0, 1, 1, 1);
    calcLayout->addWidget(calcMindscapeImage, 1, 0, 1, 2);
    

    //character select combobox
    calcCharacterSelect = new QComboBox;
    for (const auto& character : character::characterList) {
        calcCharacterSelect->addItem(QString::fromStdString(character.nickname));
    }

    calcSelectLayout->addWidget(calcCharacterSelect,0,0);

    connect(calcCharacterSelect, &QComboBox::currentTextChanged, [this](const QString &selection) {
        std::string comboString = selection.toStdString();
        setCurrentCalcCharacter(comboString);
    });

    //w engine select combobox
    calcWEngineSelect = new QComboBox;
    for (const auto& wengine : wengine::wengineList) {
        calcWEngineSelect->addItem(QString::fromStdString(wengine.name));
    }

    calcSelectLayout->addWidget(calcWEngineSelect,0,1);

    connect(calcWEngineSelect, &QComboBox::currentTextChanged, [this](const QString &selection) {
        std::string comboString = selection.toStdString();
        setCurrentCalcWEngine(comboString);
    });

    //set default character and w engine
    calcCharacterSelect->setCurrentIndex(0);
    calcWEngineSelect->setCurrentIndex(0);
}

void window::setCurrentCalcCharacter(std::string &comboString) {
    for (const auto& c : character::characterList) {
        if (c.nickname == comboString) {
            currentCalcCharacter = c;
            break;
        } //no catch cuz its not possible for it to miss (i think)
    }
    updateCalculator();
}

void window::setCurrentCalcWEngine(std::string &comboString) {
    for (const auto& w : wengine::wengineList) {
        if (w.name == comboString) {
            currentWEngine = w;
            break;
        }
    }
    updateCalculator();
}

void window::updateCalculator() {
    //images
    QPixmap wenginePix(QString::fromStdString(currentWEngine.image));
    QSize wengineAvailableSize(200,200); // shouldnt change?
    QPixmap scaledWenginePix = wenginePix.scaled(wengineAvailableSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    calcWengineImage->setPixmap(scaledWenginePix);
    calcWengineImage->setAlignment(Qt::AlignCenter);

    QPixmap characterPix(QString::fromStdString(currentCalcCharacter.images.mindscapeFull));
    QSize characterAvailableSize = calc->size() * 3 / 4; // rough estimate of available space
    QPixmap scaledCharacterPix = characterPix.scaled(characterAvailableSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    calcMindscapeImage->setPixmap(scaledCharacterPix);
}