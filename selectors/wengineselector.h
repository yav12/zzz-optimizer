#pragma once
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QGridLayout>
#include <QToolButton>
#include <QPixmap>
#include <QIcon>
#include <QSize>
#include <QList>
#include <QScrollArea>
#include <QResizeEvent>
#include "../data/wengine.h"

class wengineSelector : public QWidget {
    Q_OBJECT
public:
    wengineSelector(QWidget *parent = nullptr);
    ~wengineSelector();

signals:
    void wengineSelected(const wengine::wengine &w);

private:
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QGridLayout *selectionLayout;
    int selectedIndex = -1;
    QList<QToolButton*> wengineButtons;
    QList<wengine::wengine> wengineCopies;
};
