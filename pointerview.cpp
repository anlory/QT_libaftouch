#include "pointerview.h"
#include "qdebug.h"

PointerView::PointerView(QWidget *parent) : QWidget(parent)
{
    resize(1000,800);
qDebug()<<"draw ...";
}


void PointerView::paintEvent(QPaintEvent *event)
{
    qDebug()<<"draw ..."<< w << "   "<< h << "  "<< r;
    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.drawEllipse(w,h,r,r);
}
PointerView::PointerView(int w ,int h ,int r)
{
    this->w = w;
    this->h = h;
    this->r = r;

}
void PointerView::setW(int w)
{
    this->w =w;
}

void PointerView::setH(int h)
{
    this->h = h;
}

void PointerView::setR(int r)
{
    this->r = r;
}
