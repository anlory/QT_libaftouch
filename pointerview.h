#ifndef POINTERVIEW_H
#define POINTERVIEW_H

#include <QWidget>
#include <qpainter.h>

class PointerView : public QWidget
{
    Q_OBJECT
public:
    explicit PointerView(QWidget *parent = nullptr);
    PointerView(int w = 100,int h = 100,int r = 100);
    void setW(int w);
    void setH(int h);
    void setR(int r);
signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);
    int w;
    int h;
    int r;

};

#endif // POINTERVIEW_H
