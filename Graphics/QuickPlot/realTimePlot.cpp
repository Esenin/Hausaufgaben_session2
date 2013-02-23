#include "realTimePlot.h"
#include "ui_realTimePlot.h"

RealTimePlot::RealTimePlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RealTimePlot)
{
    ui->setupUi(this);
}

RealTimePlot::~RealTimePlot()
{
    delete ui;
}
