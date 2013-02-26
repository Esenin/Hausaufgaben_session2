#ifndef REALTIMEPLOT_H
#define REALTIMEPLOT_H

#include <QWidget>
#include <QtGui>
#include "sensorGraph.h"

namespace Ui {
class RealTimePlot;
}

class RealTimePlot : public QWidget
{
    Q_OBJECT
    
public:
    explicit RealTimePlot(QWidget *parent = 0);
    ~RealTimePlot();

protected:
    void initGui();
    
private:
    Ui::RealTimePlot *ui;
    SensorGraph *plotFrame;
    QHBoxLayout *toolLayout;
    QToolButton *stopButton;
    QToolButton *startButton;
    QToolButton *zoomInButton;
    QToolButton *zoomOutButton;
    QToolButton *resetButton;

};

#endif // REALTIMEPLOT_H
