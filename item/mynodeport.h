/*************************************************
**版  权：RenGu Company
**文件名: mynodeport.h
**作  者: wey       Version: 1.0       Date: 2016.09.18
**描  述: 控件上的端口
**Others:1.需要支持拖入
**       2.支持移动、动态添加
**       3.支持连线
**
**修改历史:
**
*************************************************/
#ifndef MYNODEPORT_H
#define MYNODEPORT_H

#include <QGraphicsObject>

#include "ItemHeader.h"

class MyItem;

class MyNodePort : public QGraphicsObject
{
    Q_OBJECT
public:
    MyNodePort(QGraphicsItem * parentItem);
    ~MyNodePort();

    QRectF boundingRect() const;

    void setPos(const QPointF &pos);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setDragDirect(DragDirect direct);
    DragDirect getDragDirect(){return this->dragDirect;}

    void setScaleFactor(qreal scaleFactor);
    qreal getScaleFactor(){return this->scaleFactor;}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

signals:
    void portPosChanged(MouseType,QPointF);

private:
    QRectF boundRect;
    int radius;

    QPolygonF itemPolygon;             //当前图形的各个顶点坐标集合

    DragDirect dragDirect;

    qreal scaleFactor;                 //拖入的位置相当于当前一边所在的比例

};

#endif // MYNODEPORT_H
