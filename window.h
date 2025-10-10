#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "librarywidget.h"

class window : public QMainWindow
{
    Q_OBJECT

public:
    window(QWidget *parent = nullptr);
    void setupWindow();
    ~window();
private:
    void initializations();
    //main window
    QWidget *windowWidget;
    QVBoxLayout *layout;
    //navigation
    QHBoxLayout *navLayout;
    QPushButton *homeButton;
    QPushButton *referenceButton;
    QPushButton *calculatorButton;
    QPushButton *libraryButton;
    QPushButton *importButton;
    //content widgets
    QStackedWidget *content;
    QWidget *home;
    QWidget *reference;
    QWidget *calc;
    libraryWidget *library;
    //home content
    QHBoxLayout *homeLayout;
    QLabel *homePlaceholderLabel;
    //reference content
    QHBoxLayout *referenceLayout;
    QLabel *referencePlaceholderLabel;
    //calculator content
    QHBoxLayout *calcLayout;
    QLabel *calcPlaceholderLabel;
    //library content
    QHBoxLayout *libraryLayout;
    QLabel *libraryPlaceholderLabel;
};
#endif // WINDOW_H
