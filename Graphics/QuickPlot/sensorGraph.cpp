#include "sensorGraph.h"

SensorGraph::SensorGraph(QWidget *parent) :
    QGraphicsView(parent),
    fpsDelay(50),
    stepSize(2),
    zoomRate(2),
    isZoomed(false),
    maxLimit(1),
    minLimit(0),
    nextToDraw(QPointF(0, -80))
{
    debugValue = 50;

    initGraphicsOutput();

    connect(&visualTimer, SIGNAL(timeout()), this, SLOT(visualTimerEvent()));
}

SensorGraph::~SensorGraph()
{
    scene->removeItem(mainPoint);
    delete mainPoint;
    delete scene;
}

void SensorGraph::initGraphicsOutput()
{
    scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200, -160, 220, 160);

    setScene(scene);
    setRenderHint(QPainter::Antialiasing, false);

    /// This makes information on left side actual
    setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setCacheMode(CacheNone);
    setRenderHint(QPainter::Antialiasing);
    setMinimumSize(220, 160);


    mainPoint = new KeyPoint;
    scene->addItem(mainPoint);
    mainPoint->setPos(nextToDraw);

    graphHeight = scene->sceneRect().height() - 20;
}


void SensorGraph::startJob()
{
    visualTimer.start(fpsDelay);
}

void SensorGraph::stopJob()
{
    visualTimer.stop();
}

void SensorGraph::clear()
{
    pointsQueue.clear();
    minLimit = 0;
    maxLimit = 1;
    //nextToDraw = QPointF(0, -80);

    foreach (QGraphicsItem *item, scene->items())
    {
        QGraphicsLineItem *curLine = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        if (curLine == NULL)
            continue;
        scene->removeItem(curLine);
    }


    matrix().reset();
}

qreal SensorGraph::abstractValueToPoint(qreal value)
{
    return ((value - minLimit) / (maxLimit - minLimit) * graphHeight + 10) * (-1);
}

qreal SensorGraph::pointToAbstractValue(qreal yValue, qreal minValue, qreal maxValue)
{
    return (((maxValue - minValue) * (-yValue - 10)) / graphHeight) + minValue;
}

void SensorGraph::setNextValue(qreal newValue)
{
    int oldMax = maxLimit;
    int oldMin = minLimit;
    if (newValue > maxLimit)
        maxLimit = newValue;
    if (newValue < minLimit)
        minLimit = newValue;
    update();

    if (oldMax != maxLimit || oldMin != minLimit)
    {
        graphAutoScaling(oldMin, oldMax);
    }

    nextToDraw.setY(abstractValueToPoint(newValue));
}

void SensorGraph::graphAutoScaling(qreal oldMin, qreal oldMax)
{
    qreal currentValue;
    for (int i = 0; i < pointsQueue.size(); i++)
    {
        currentValue = pointToAbstractValue(pointsQueue[i].y(), oldMin, oldMax);
        pointsQueue[i].setY(abstractValueToPoint(currentValue));
    }
}

void SensorGraph::drawNextFrame()
{
    pointsQueue.append(QPointF(mainPoint->pos().x() - stepSize, mainPoint->pos().y()));
    mainPoint->setPos(nextToDraw);
    pointsQueue.append(nextToDraw);

    /// shifting lines left
    foreach (QGraphicsItem *item, scene->items())
    {
        QGraphicsLineItem *curLine = qgraphicsitem_cast<QGraphicsLineItem *>(item);
        if (curLine == NULL)
            continue;

        curLine->setPos(curLine->pos().x() - stepSize, curLine->pos().y());
        if (curLine->x() < scene->sceneRect().left() - stepSize)
            scene->removeItem(curLine);
    }

    QPen regularPen = QPen(QBrush(Qt::yellow), 2,
                           Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    QLineF quantOfGraph;
    for (int i = 0; i < pointsQueue.size() - 1; i++)
    {
        quantOfGraph = QLineF(pointsQueue[i], pointsQueue[i + 1]);
        scene->addLine(quantOfGraph, regularPen);
    }
    pointsQueue.clear();

}

void SensorGraph::visualTimerEvent()
{
    drawNextFrame();


    /// debug
    if (rand() % 10 > 5)
    {
        debugValue += (rand() % 7) - 3;
        if (debugValue < 5)
            debugValue = 5;
        if (debugValue > 95)
            debugValue = 95;

        setNextValue(debugValue);
    }
}

void SensorGraph::drawBackground(QPainter *painter, const QRectF &rect)
{
    QRectF sceneRect = this->sceneRect();

    // Fill
    QLinearGradient gradient(sceneRect.topLeft(), sceneRect.bottomRight());
    gradient.setColorAt(0, Qt::darkGreen);
    gradient.setColorAt(1, Qt::black);
    painter->fillRect(scene->sceneRect(), gradient);
    painter->setBrush(Qt::NoBrush);
    painter->drawRect(scene->sceneRect());

    // Text
    QRectF textRect(sceneRect.left() + 4, sceneRect.top() + 4,
                    50, 50);
    QString maxDisplay(QString::number(maxLimit));
    QString minDisplay(QString::number(minLimit));

    QFont font = painter->font();
    font.setBold(true);
    font.setPointSize(10);
    painter->setFont(font);
    painter->setPen(Qt::lightGray);
    painter->drawText(textRect.translated(2, 2), maxDisplay);
    painter->drawText(textRect.translated(2, scene->sceneRect().height() - 20), minDisplay);
    painter->setPen(Qt::black);
    //painter->drawText(textRect, maxDisplay);
}

void SensorGraph::mouseReleaseEvent(QMouseEvent *event)
{
    if (isZoomed)
        zoomOut();
    else
        zoomIn();
    isZoomed = !isZoomed;
}

void SensorGraph::zoomIn()
{
    QMatrix outputMatrix = matrix();
    outputMatrix.scale(zoomRate, zoomRate);
    setMatrix(outputMatrix);
}

void SensorGraph::zoomOut()
{
    QMatrix outputMatrix = matrix();
    outputMatrix.scale(1 / qreal(zoomRate), 1 / qreal(zoomRate));
    setMatrix(outputMatrix);
}
