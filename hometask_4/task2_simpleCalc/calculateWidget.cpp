#include "calculateWidget.h"
#include "ui_calculateWidget.h"

CalculateWidget::CalculateWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalculateWidget)
{
    ui->setupUi(this);

    connect(ui->leftArg, SIGNAL(valueChanged(int)), this, SLOT(changeParams()));
    connect(ui->rightArg, SIGNAL(valueChanged(int)), this, SLOT(changeParams()));
    connect(ui->operation, SIGNAL(currentIndexChanged(int)), this, SLOT(changeParams()));
}

CalculateWidget::~CalculateWidget()
{
    delete ui;
}


void CalculateWidget::changeParams()
{
    ui->resultLine->setText(QString::number(calcMachine.calcNewParams(
        ui->leftArg->value(),
        ui->rightArg->value(),
        ui->operation->currentIndex())));
}
