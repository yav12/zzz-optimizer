#ifndef WINDOW_H
#define WINDOW_H


#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include "data/character.h"
#include "content/calculator.h"
#include "content/reference.h"

class window : public QMainWindow
{
    Q_OBJECT

public:
    window(QWidget *parent = nullptr);
    void setupWindow();
    void setupNavigation();
    void setupHome();
    void setupReference();
    void setupCalculator();
    void setupLibrary();
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
    QWidget *calc;
    QWidget *library;
    //home content
    QHBoxLayout *homeLayout;
    QLabel *homePlaceholderLabel;
    // reference content
    reference *referenceWidget;
    //calculator content
    calculator *calcWidget;
    //library content
    QHBoxLayout *libraryLayout;
    QLabel *libraryPlaceholderLabel;
};
#endif // WINDOW_H
