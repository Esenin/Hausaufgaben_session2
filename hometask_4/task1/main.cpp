#include <QtGui/QApplication>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    Widget mainWindow;
    mainWindow.show();
    
    return application.exec();
}
