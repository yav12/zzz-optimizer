#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QToolButton>
#include <QPixmap>
#include <QIcon>
#include <QSize>
#include "../data/character.h"

class charSelector : public QWidget {
    Q_OBJECT
public:
    explicit charSelector(QWidget *parent = nullptr);
    ~charSelector();

signals:
    void characterSelected(const character::character &c);

private:
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QGridLayout *selectionLayout;
    int selectedIndex = -1;
};
