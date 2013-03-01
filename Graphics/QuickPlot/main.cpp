#include <QtGui/QApplication>

#include "realTimePlot.h"

int main(int argc, char *argv[])
{
	QApplication application(argc, argv);

	RealTimePlot mainWidget;
	mainWidget.show();
	return application.exec();
}
