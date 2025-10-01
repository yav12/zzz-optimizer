#include "window.h"
#include "./ui_window.h"
#include "QFileDialog"
#include "QStringList"
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

}

void window::updateLibrary() {

}
