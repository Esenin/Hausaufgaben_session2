#include "realTimePlot.h"
#include "ui_realTimePlot.h"

RealTimePlot::RealTimePlot(QWidget *parent) :
	QDockWidget(parent)
	, ui(new Ui::RealTimePlot)
	, mCurrentSlot(0)
	, mDebugValue(100)
{
	ui->setupUi(this);
	initGui();
	makeConnections();

	mPlotFrame->startJob();

	//! debug mode
	mEmulatorTimer.start(53); //! That's random number, I guarantee
	connect(&mEmulatorTimer, SIGNAL(timeout()), this, SLOT(emulatorTimerEvent()));
}


RealTimePlot::~RealTimePlot()
{
	delete mPlotFrame;
	delete ui;
}

void RealTimePlot::initGui()
{
	setupToolElements();

	//mToolLayout = new QHBoxLayout;
	mToolLayout.addWidget(&mStopButton);
	mToolLayout.addWidget(&mStartButton);
	mToolLayout.addWidget(&mZoomInButton);
	mToolLayout.addWidget(&mZoomOutButton);
	mToolLayout.addWidget(&mResetButton);

	mPlotFrame = new SensorGraph(this);

	ui->mainLayout->addWidget(mPlotFrame, 0, 0);
	ui->mainLayout->addLayout(&mToolLayout, 2, 0);
	ui->mainLayout->addWidget(&mSlotComboBox, 3, 0);

}

void RealTimePlot::setupToolElements()
{
	QSize iconSize(20, 20);

	mStopButton.setIcon(QPixmap("stop_btn"));
	mStopButton.setIconSize(iconSize);

	mStartButton.setIcon(QPixmap("start_btn"));
	mStartButton.setIconSize(iconSize);

	mResetButton.setIcon(QPixmap("reset_btn"));
	mResetButton.setIconSize(iconSize);

	mZoomInButton.setIcon(QPixmap("zoomIn_btn"));
	mZoomInButton.setIconSize(iconSize);

	mZoomOutButton.setIcon(QPixmap("zoomOut_btn"));
	mZoomOutButton.setIconSize(iconSize);

	mSlotComboBox.addItem("Sensor 1", 0);
	mSlotComboBox.addItem("Sensor 2", 2);
	mSlotComboBox.addItem("Sensor 3", 3);
	mSlotComboBox.addItem("Sensor 4", 4);

}

void RealTimePlot::makeConnections()
{
	connect(&mStopButton, SIGNAL(clicked()), mPlotFrame, SLOT(stopJob()));
	connect(&mStartButton, SIGNAL(clicked()), mPlotFrame, SLOT(startJob()));
	connect(&mResetButton, SIGNAL(clicked()), mPlotFrame, SLOT(clear()));
	connect(&mZoomInButton, SIGNAL(clicked()), mPlotFrame, SLOT(zoomIn()));
	connect(&mZoomOutButton, SIGNAL(clicked()), mPlotFrame, SLOT(zoomOut()));
	connect(&mSlotComboBox, SIGNAL(currentIndexChanged(int)), mPlotFrame, SLOT(onSensorChange(int)));
	connect(&mSlotComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setMainSensor(int)));
}

void RealTimePlot::sensorOne(const qreal value)
{
	if (mCurrentSlot == 0)
		mPlotFrame->setNextValue(value);
}

void RealTimePlot::sensorTwo(const qreal value)
{
	if (mCurrentSlot == 1)
		mPlotFrame->setNextValue(value);
}

void RealTimePlot::sensorThree(const qreal value)
{
	if (mCurrentSlot == 2)
		mPlotFrame->setNextValue(value);
}

void RealTimePlot::sensorFour(const qreal value)
{
	if (mCurrentSlot == 3)
		mPlotFrame->setNextValue(value);
}

void RealTimePlot::setMainSensor(const int newSlotIndex)
{
	mCurrentSlot = newSlotIndex;
}

void RealTimePlot::emulatorTimerEvent()
{
	if (rand() % 10  > 5) {
		mDebugValue += (rand() % 21) - 10;
		sensorOne(mDebugValue);
		sensorTwo(42 / mDebugValue);
		sensorThree(mDebugValue + 42 / mDebugValue);
		sensorFour(-mDebugValue);
	}

}
