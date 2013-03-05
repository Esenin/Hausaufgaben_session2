#include <QtGui>
#include "calculateWidget.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    CalculateWidget mainWidget;
    mainWidget.show();

    return application.exec();
}
