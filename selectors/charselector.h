#ifndef CHARSELECTOR_H
#define CHARSELECTOR_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QToolButton>
#include "../data/character.h"

class charSelector : public QDialog
{
    Q_OBJECT

public:
    charSelector(QWidget *parent = nullptr);
    ~charSelector();

    character::character picker(QWidget *parent = nullptr);
    QVBoxLayout *mainLayout;
    QGridLayout *selectionLayout;

    //title
    QLabel *titleLabel;

    // character selection
    QLabel *characterLabel;
    int selectedIndex = -1;
};

#endif // CHARSELECTOR_H
