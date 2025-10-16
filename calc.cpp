// #include "window.h"
// #include "character.h"
// #include "QComboBox"

// void window::setupCalculator() {
//     //set up layout
//     calc = new QWidget(this);
//     calcLayout = new QGridLayout();
//     calcSelectLayout = new QGridLayout();

//     content->addWidget(calc);
//     calc->setLayout(calcLayout);
//     calcLayout->addLayout(calcSelectLayout, 0, 0, 1, 1);

//     //make navigation work
//     connect(calculatorButton, &QPushButton::clicked, [=]() {content->setCurrentWidget(calc);});


//     //labels
//     calcWengineImage = new QLabel;
//     calcMindscapeImage = new QLabel;
//     calcMindscapeImage->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
//     calcMindscapeImage->setAlignment(Qt::AlignCenter);

//     //set label locations
//     calcLayout->addWidget(calcWengineImage, 0, 1, 1, 1);
//     calcLayout->addWidget(calcMindscapeImage, 1, 0, 1, -1);
    

//     //character select combobox
//     calcCharacterSelect = new QComboBox;
//     for (const auto& character : character::characterList) {
//         calcCharacterSelect->addItem(QString::fromStdString(character.nickname));
//     }

//     calcSelectLayout->addWidget(calcCharacterSelect,0,0);

//     connect(calcCharacterSelect, &QComboBox::currentTextChanged, [this](const QString &selection) {
//         std::string comboString = selection.toStdString();
//         setCurrentCalcCharacter(comboString);
//     });

//     //w engine select combobox
//     calcWEngineSelect = new QComboBox;
//     for (const auto& wengine : wengine::wengineList) {
//         calcWEngineSelect->addItem(QString::fromStdString(wengine.name));
//     }

//     calcSelectLayout->addWidget(calcWEngineSelect,0,1);

//     connect(calcWEngineSelect, &QComboBox::currentTextChanged, [this](const QString &selection) {
//         std::string comboString = selection.toStdString();
//         setCurrentCalcWEngine(comboString);
//     });

//     //calculate button
//     calcCalculateButton = new QPushButton("Calculate");
//     calcSelectLayout->addWidget(calcCalculateButton,1,0,1,2);
//     connect(calcCalculateButton, &QPushButton::clicked, [this]() {
//         performCalculation(currentCalcCharacter, currentWEngine);
//     });

//     //set default character and w engine
//     calcCharacterSelect->setCurrentText(QString::fromStdString(character::anby.nickname));
//     calcWEngineSelect->setCurrentText(QString::fromStdString(character::anby.preferredWengine.name));
//     updateCalculator();
// }

// void window::setCurrentCalcCharacter(std::string &comboString) {
//     for (const auto& c : character::characterList) {
//         if (c.nickname == comboString) {
//             currentCalcCharacter = c;
//             break;
//         } //no catch cuz its not possible for it to miss (i think)
//     }
//     updateCalculator();
// }

// void window::setCurrentCalcWEngine(std::string &comboString) {
//     for (const auto& w : wengine::wengineList) {
//         if (w.name == comboString) {
//             currentWEngine = w;
//             break;
//         }
//     }
//     updateCalculator();
// }

// void window::updateCalculator() {
//     //images
//     QPixmap wenginePix(QString::fromStdString(currentWEngine.image));
//     QSize wengineAvailableSize(200,200); // shouldnt change?
//     QPixmap scaledWenginePix = wenginePix.scaled(wengineAvailableSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
//     calcWengineImage->setPixmap(scaledWenginePix);
//     calcWengineImage->setAlignment(Qt::AlignCenter);

//     QPixmap characterPix(QString::fromStdString(currentCalcCharacter.images.mindscapeFull));
//     QSize characterAvailableSize = this->size(); // rough estimate of available space
//     qDebug() << "window size:" << this->size();
//     QPixmap scaledCharacterPix = characterPix.scaledToWidth(1908, Qt::SmoothTransformation);
//     qDebug() << "Scaled character pix size:" << scaledCharacterPix.size();
//     calcMindscapeImage->setPixmap(scaledCharacterPix);
// }

// void window::performCalculation(character::character& currentCalcCharacter, wengine::wengine& currentWEngine) {
//     character::character calcStats = currentCalcCharacter;
//     //apply w engine effects (unconditional)
//     calcStats.stats.atk += currentWEngine.baseAtk;
//     if (currentWEngine.stat == "ATK") {
//         calcStats.stats.atk *= (1 + currentWEngine.statPercent / 100.0);
//     } else if (currentWEngine.stat == "HP") {
//         calcStats.stats.hp *= (1 + currentWEngine.statPercent / 100.0);
//     } else if (currentWEngine.stat == "DEF") {
//         calcStats.stats.def *= (1 + currentWEngine.statPercent / 100.0);
//     } else if (currentWEngine.stat == "Impact") {
//         calcStats.stats.impact *= (1 + currentWEngine.statPercent / 100.0);
//     } else if (currentWEngine.stat == "CR") { //additive
//         calcStats.stats.cr += currentWEngine.statPercent;
//     } else if (currentWEngine.stat == "CD") {
//         calcStats.stats.cd += currentWEngine.statPercent;
//     } else if (currentWEngine.stat == "AM") {
//         calcStats.stats.am += currentWEngine.statPercent;
//     } else if (currentWEngine.stat == "AP") {
//         calcStats.stats.ap += currentWEngine.statPercent;
//     } else if (currentWEngine.stat == "PEN Ratio") {
//         calcStats.stats.penr += currentWEngine.statPercent;
//     } else if (currentWEngine.stat == "ER") {
//         calcStats.stats.er *= (1 + currentWEngine.statPercent / 100.0);
//     }

//     //update window with calcStats
//     updateCalculator();
// }