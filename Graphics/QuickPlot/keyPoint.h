#ifndef KEYPOINT_H
#define KEYPOINT_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRadialGradient>

class KeyPoint : public QGraphicsItem
{
public:
    KeyPoint();

    QRectF boundingRect() const;
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option, QWidget *widget);

private:
    QRectF visualArea;
};

#endif // KEYPOINT_H
