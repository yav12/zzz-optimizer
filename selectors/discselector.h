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
#include <QComboBox>
#include <QSpinBox>
#include <vector>
#include "../data/disc.h" // adjust if your data type header is different

class discSelector : public QWidget {
    Q_OBJECT
public:
    discSelector(QWidget *parent = nullptr, int slotNumber = 0, disc initialDisc = disc());
    ~discSelector();

signals:
    void discSelected(const disc &d);

private:
    disc selectedDisc;
    QStackedLayout *mainLayout;
    QWidget *discWidget;
    QVBoxLayout *discLayout;
    QWidget *subsWidget;
    QGridLayout *subsLayout;
    QLabel *titleLabel;
    QGridLayout *selectionLayout;
    int slot;
    // per-disc substat widgets (4 subs)
    std::vector<QComboBox*> subCombos;
    std::vector<QSpinBox*> subRolls;
};
