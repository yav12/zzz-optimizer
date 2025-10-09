#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qlabel.h>

class window : public QMainWindow
{
    Q_OBJECT

public:
    window(QWidget *parent = nullptr);
    void setupWindow();
    ~window();
private:
    QWidget *windowWidget;
    QVBoxLayout *layout;
    QHBoxLayout *navLayout;
    QPushButton *homeButton;
    QPushButton *referenceButton;
    QPushButton *calculatorButton;
    QPushButton *libraryButton;
    QPushButton *importButton;
    QLabel *placeholder;
};
#endif // WINDOW_H
