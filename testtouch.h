#ifndef TESTTOUCH_H
#define TESTTOUCH_H

#include <QWidget>
#include <qtableview.h>
#include <qstandarditemmodel.h>
#include <qpushbutton.h>
#include <qstackedlayout.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include "pointerview.h"
#include <qlineedit.h>
#include <qslider.h>

class TestTouch : public QWidget
{
    Q_OBJECT

public:
    TestTouch(QWidget *parent = 0);
    ~TestTouch();
    PointerView * pv;
private:
    QTableView * tableView;
    QStandardItemModel* model;
public slots:
    void chengeRoundLocation();

};

#endif // TESTTOUCH_H
