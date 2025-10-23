
#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QToolButton>
#include "../data/disc.h" // adjust if your data type header is different

class discSelector : public QWidget {
    Q_OBJECT
public:
    discSelector(QWidget *parent = nullptr);
    ~discSelector();

signals:

private:
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QGridLayout *selectionLayout;
    int selectedIndex = -1;
};
