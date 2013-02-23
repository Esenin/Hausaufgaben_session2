#include <QtGui/QApplication>
#include "realTimePlot.h"
#include "sensorGraph.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    SensorGraph mainGraph;

    mainGraph.show();
    mainGraph.startJob();
    return a.exec();
}
