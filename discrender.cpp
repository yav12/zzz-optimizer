#include "discrender.h"
#include "ui_discrender.h"

discRender::discRender(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::discRender)
{
    ui->setupUi(this);
}

void discRender::setDiscInfo(disc d) {
    ui->set->setText(QString::fromStdString(d.getSet()));

}

discRender::~discRender()
{
    delete ui;
}
