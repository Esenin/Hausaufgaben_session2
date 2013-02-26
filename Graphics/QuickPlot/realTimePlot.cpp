#include "realTimePlot.h"
#include "ui_realTimePlot.h"

RealTimePlot::RealTimePlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RealTimePlot)
{
    ui->setupUi(this);
    initGui();
}


RealTimePlot::~RealTimePlot()
{
    delete plotFrame;
    delete ui;
}

void RealTimePlot::initGui()
{
    QSize iconSize(20, 20);

    stopButton = new QToolButton;
    stopButton->setIcon(QPixmap("stop_btn"));
    stopButton->setIconSize(iconSize);

    startButton = new QToolButton;
    startButton->setIcon(QPixmap("start_btn"));
    startButton->setIconSize(iconSize);

    resetButton = new QToolButton;
    resetButton->setIcon(QPixmap("reset_btn"));
    resetButton->setIconSize(iconSize);

    zoomInButton = new QToolButton;
    zoomInButton->setIcon(QPixmap("zoomIn_btn"));
    zoomInButton->setIconSize(iconSize);

    zoomOutButton = new QToolButton;
    zoomOutButton->setIcon(QPixmap("zoomOut_btn"));
    zoomOutButton->setIconSize(iconSize);

    toolLayout = new QHBoxLayout;
    toolLayout->addWidget(stopButton);
    toolLayout->addWidget(startButton);
    toolLayout->addWidget(zoomInButton);
    toolLayout->addWidget(zoomOutButton);
    toolLayout->addWidget(resetButton);

    plotFrame = new SensorGraph(this);

    ui->mainLayout->addWidget(plotFrame, 0, 0);
    ui->mainLayout->addLayout(toolLayout, 1, 0);


    connect(stopButton, SIGNAL(clicked()), plotFrame, SLOT(stopJob()));
    connect(startButton, SIGNAL(clicked()), plotFrame, SLOT(startJob()));
    connect(resetButton, SIGNAL(clicked()), plotFrame, SLOT(clear()));
    connect(zoomInButton, SIGNAL(clicked()), plotFrame, SLOT(zoomIn()));
    connect(zoomOutButton, SIGNAL(clicked()), plotFrame, SLOT(zoomOut()));


    plotFrame->startJob();
}
