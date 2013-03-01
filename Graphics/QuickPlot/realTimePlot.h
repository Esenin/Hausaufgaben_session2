#pragma once

#include <QDockWidget>
#include <QtGui>
#include <QTimer>

#include "sensorGraph.h"

namespace Ui {
class RealTimePlot;
}

class RealTimePlot : public QDockWidget
{
	Q_OBJECT

public:
	explicit RealTimePlot(QWidget *parent = 0);
	~RealTimePlot();

public slots:
	void sensorOne(qreal const value);
	void sensorTwo(qreal const value);
	void sensorThree(qreal const value);
	void sensorFour(qreal const value);
	void setMainSensor(int const newSlotIndex);


protected:
	void initGui();
	void setupToolElements();
	void makeConnections();

private:
	Ui::RealTimePlot *ui;
	SensorGraph *mPlotFrame;
	QHBoxLayout mToolLayout;
	QToolButton mStopButton;
	QToolButton mStartButton;
	QToolButton mZoomInButton;
	QToolButton mZoomOutButton;
	QToolButton mResetButton;
	QComboBox mSlotComboBox;
	QTimer mEmulatorTimer; //! debug mode
	int mCurrentSlot;
	qreal mDebugValue; //! debug mode

	//! debug mode
private slots:
	void emulatorTimerEvent();

};

