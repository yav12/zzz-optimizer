#ifndef DISCRENDER_H
#define DISCRENDER_H

#include <QWidget>

namespace Ui {
class discRender;
}

class discRender : public QWidget
{
    Q_OBJECT

public:
    explicit discRender(QWidget *parent = nullptr);
    ~discRender();

private:
    Ui::discRender *ui;
};

#endif // DISCRENDER_H
