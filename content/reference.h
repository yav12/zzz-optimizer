#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QToolButton>
#include <QPixmap>
#include <QSizePolicy>
#include "../data/character.h"
#include "../selectors/charselector.h"
#include <QStackedWidget>

class reference : public QWidget {
    Q_OBJECT
public:
    explicit reference(QWidget *parent = nullptr);
    ~reference();

    // set the currently selected reference by nickname
    void setCharacter(character::character);
    // refresh the displayed reference data
    void updateReference();

private:
    QVBoxLayout *mainLayout;
    QGridLayout *referenceLayout;
    QGridLayout *refInfo;
    QStackedWidget *pagesStack;
    QWidget *mainPage;
    charSelector *charSelectorWidget;
    QToolButton *openSelectorButton;
    QLabel *refCharacter;
    QLabel *refRarity;
    QLabel *refSpecialty;
    QLabel *refAttribute;
    QLabel *refFactionText;
    QLabel *refFaction;
    QLabel *refMindscapeImage;

    character::character currentRefCharacter;
};
