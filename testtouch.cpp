#include "testtouch.h"

#include <qdebug.h>
TestTouch::TestTouch(QWidget *parent)
    : QWidget(parent)
{

    tableView = new QTableView(this);
    model = new QStandardItemModel();
    model->setColumnCount(10);
    model->setRowCount(18);
    tableView->resize(1000,800);
    tableView->setModel(model);
    pv = new PointerView(0,0,50);
    QStackedLayout* stackLay = new QStackedLayout();
    stackLay->addWidget(tableView);
    stackLay->addWidget(pv);
    stackLay->setStackingMode(QStackedLayout::StackAll);


    QPushButton* buttonOpen = new QPushButton(this);
    buttonOpen->setText("open");
    QPushButton* buttonClose = new QPushButton(this);
    buttonClose->setText("close");
    QPushButton* buttonPlus = new QPushButton(this);
    buttonPlus->setText("+");
    QPushButton* button1 = new QPushButton(this);
    button1->setText("-");
    QHBoxLayout* hLay1 = new QHBoxLayout();
    hLay1->addWidget(buttonOpen);
    hLay1->addWidget(buttonClose);
    hLay1->addWidget(buttonPlus);
    hLay1->addWidget(button1);
    hLay1->addStretch();



    QSlider * slide = new QSlider(this);
    QLineEdit * lineEdit = new QLineEdit(this);
    QHBoxLayout* hLay2 = new QHBoxLayout();

    slide->setOrientation(Qt::Horizontal);
    hLay2->addWidget(lineEdit);
    hLay2->addWidget(slide,5);




    QVBoxLayout* vlay = new QVBoxLayout();
    vlay->addLayout(hLay1);
    vlay->addLayout(stackLay);

    vlay->addLayout(hLay2);
    setLayout(vlay);


   // connect(buttonOpen,SIGNAL(clicked()),this,SLOT(chengeRoundLocation()));
}

TestTouch::~TestTouch()
{

}
void TestTouch::chengeRoundLocation()
{
    //qDebug()<<"button trigger..";
    static int w = 100;
    static int h = 200;
    static int r = 50;
    w += 10;
    h += 10;
    r += 10;
    pv->setW(w++);
    pv->setH(h++);
    pv->setR(r++);

    pv->repaint();
}
