#include <QtGui/QApplication>
#include "calcWidget.h"

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);
    CalcWidget window;
    window.show();
    
    return application.exec();
}
