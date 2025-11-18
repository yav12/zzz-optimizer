#pragma once

#include <QWidget>
#include <QStackedLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QToolButton>
#include <QShortcut>
#include <qwidget.h>
#include "../data/disc.h" // adjust if your data type header is different

class discSelector : public QWidget {
    Q_OBJECT
public:
    discSelector(QWidget *parent = nullptr, int slotNumber = 0);
    ~discSelector();

signals:
    void discSelected(const disc &d);

private:
    disc selectedDisc;
    QStackedLayout *mainLayout;
    QWidget *discWidget;
    QVBoxLayout *discLayout;
    QWidget *subsWidget;
    QVBoxLayout *subsLayout;
    QLabel *titleLabel;
    QGridLayout *selectionLayout;
    int slot;
};
