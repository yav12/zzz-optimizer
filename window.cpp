#include "window.h"
#include "./ui_window.h"
#include "disc.h"
#include "discrender.h"
#include "QFileDialog"
#include "QStringList"
#include <qlabel.h>
#include <qdebug.h>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

window::window(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::window)
{
    ui->setupUi(this);

    //make the import button do something
    connect(ui->importButton, &QPushButton::clicked, this, &window::import);
    connect(ui->testButton, &QPushButton::clicked, this, &window::test);
}

window::~window()
{
    delete ui;
}

void window::import() {
    QFileDialog importfile;
    importfile.setAcceptMode(QFileDialog::AcceptOpen);
    importfile.setFileMode(QFileDialog::ExistingFile);
    importfile.setNameFilter("JSON Files (*.json)");

    if (importfile.exec()) {
        if (!importfile.selectedFiles().isEmpty()) {  //check if a file was picked
            // save to temp location
            std::ofstream librarytemp("/tmp/zzzlibrary.json");
            std::ifstream userdisklocation(importfile.selectedFiles().at(0).toStdString());
            std::string content;
            while (std::getline(userdisklocation, content)) {
                librarytemp << content;
            }
        }
    }
    updateLibrary();
}

// test to see if this will work
void window::updateLibrary() {
    std::ifstream librarytemp("/tmp/zzzlibrary.json");
    json j;
    librarytemp >> j;

    for (const auto& i : j["discs"]) {
        QPushButton *button = new QPushButton(this);
        ui->gridLayout->addWidget(button);
        button->show();
    }
}

void window::test() {
    // QPushButton *button = new QPushButton(this);
    QLabel *disk = new QLabel;
    disk->setPixmap(QPixmap(":/discs/AstralVoice.png"));
    qDebug() << QPixmap(":/discs/AstralVoice.png").isNull();
    QStringList files = QDir(":/discs").entryList();
    qDebug() << files;
    disk->setFixedSize(128, 128);
    ui->gridLayout->addWidget(disk);
}

// void window::updateLibrary() {
//     std::ifstream librarytemp("/tmp/zzzlibrary.json");
//     json j;
//     librarytemp >> j;
//     auto layout = new QGridLayout();

//     for (const auto& i : j["discs"]) {
//         disc unit;
//         unit.setSet(i["setKey"]);
//         unit.setSlot(std::stoi(i["slotKey"].get<std::string>()));
//         unit.setLevel(i["level"]);
//         unit.setRarity(i["rarity"]);
//         unit.setMainStat(i["mainStatKey"]);
//         unit.setSubstats(i["substats"]);
//         discRender render(ui->importFrame);
//         render.setDiscInfo(unit);
//         layout->addWidget(render(this));
//         render.show();
//     }
// }
