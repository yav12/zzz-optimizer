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
    QWidget *reference;
    QWidget *calc;
    QWidget *library;
    //home content
    QHBoxLayout *homeLayout;
    QLabel *homePlaceholderLabel;
    //reference content
    QGridLayout *referenceLayout;
    QComboBox *refCharacterSelect;
    void setCurrentRefCharacter(std::string &);
    character::character currentRefCharacter;
    void updateReference();
    QGridLayout *refInfo;
    QLabel *refCharacter;
    QLabel *refRarity;
    QLabel *refSpecialty;
    QLabel *refAttribute;
    QLabel *refFactionText;
    QLabel *refFaction;
    QLabel *refPortrait;
    QLabel *refMindscapeImage;
    //calculator content
    calculator *calcWidget;
    //library content
    QHBoxLayout *libraryLayout;
    QLabel *libraryPlaceholderLabel;
};
#endif // WINDOW_H
