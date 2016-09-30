/*************************************************
**版  权：RenGu Company
**文件名: draglinepoint.h
**作  者: wey       Version: 1.0       Date: 2016.09.30
**描  述:
**Others: 拖拽线条节点
**
**修改历史:
**
*************************************************/
#ifndef DRAGLINEPOINT_H
#define DRAGLINEPOINT_H

#include <QGraphicsObject>

#include "ItemHeader.h"

class MyItem;

class DragLinePoint : public QGraphicsObject
{
    Q_OBJECT
public:
    DragLinePoint(const PointType pointType, MyItem * parent = 0 );

    QRectF boundingRect()const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

private:
    QRectF boundRect;
    qreal radius;
    PointType pointType;
};

#endif // DRAGLINEPOINT_H
