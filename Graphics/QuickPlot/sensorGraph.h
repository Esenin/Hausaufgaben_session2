#ifndef SENSORGRAPH_H
#define SENSORGRAPH_H

#include <QGraphicsView>
#include <QTimer>
#include <QPainter>
#include "keyPoint.h"

class SensorGraph : public QGraphicsView
{
    Q_OBJECT

public:
    SensorGraph(QWidget *parent = 0);
    ~SensorGraph();
    
signals:
    
public slots:
    void setNextValue(qreal newValue);
    void startJob();
    void stopJob();
    void clear();

protected:
    void drawNextFrame();
    void drawBackground(QPainter *painter, const QRectF &rect);

    void initGraphicsOutput();
    qreal pointToAbstractValue(qreal yValue, qreal minValue, qreal maxValue);
    qreal abstractValueToPoint(qreal value);
    void graphAutoScaling(qreal oldMin, qreal oldMax);

private:
    QGraphicsScene *scene;
    QTimer visualTimer;
    QList<QPointF> pointsQueue;
    KeyPoint *mainPoint;

    const int fpsDelay;
    const int stepSize;
    qreal maxLimit;
    qreal minLimit;
    qreal graphHeight;
    QPointF nextToDraw;

    /// debug
    qreal debugValue;

private slots:
    void visualTimerEvent();
    
};

#endif // SENSORGRAPH_H
