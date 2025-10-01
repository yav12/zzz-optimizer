#include "discrender.h"
#include "ui_discrender.h"

discRender::discRender(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::discRender)
{
    ui->setupUi(this);
}

discRender::~discRender()
{
    delete ui;
}
