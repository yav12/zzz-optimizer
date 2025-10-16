#ifndef WINDOW_H
#define WINDOW_H

#include "character.h"
#include <QMainWindow>
#include <QWidget>
#include <QStackedWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>

class window : public QMainWindow
{
    Q_OBJECT

public:
    window(QWidget *parent = nullptr);
    void setupWindow();
    void setupNavigation();
    void setupWengines();
    void setupCharacters();
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
    QGridLayout *calcLayout;
    QGridLayout *calcSelectLayout;
    QComboBox *calcCharacterSelect;
    QComboBox *calcWEngineSelect;
    void setCurrentCalcCharacter(std::string &);
    void setCurrentCalcWEngine(std::string &);
    character::character currentCalcCharacter;
    wengine::wengine currentWEngine;
    character::character calcStats;
    void updateCalculator();
    QGridLayout *calcInfo;
    QPushButton *calcCalculateButton;
    QLabel *calcWengineImage;
    QLabel *calcMindscapeImage;
    void performCalculation(character::character&, wengine::wengine&);
    //library content
    QHBoxLayout *libraryLayout;
    QLabel *libraryPlaceholderLabel;
};
#endif // WINDOW_H
