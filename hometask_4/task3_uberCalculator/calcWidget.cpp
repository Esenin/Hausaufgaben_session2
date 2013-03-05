#include "calcWidget.h"
#include "ui_calcWidget.h"

CalcWidget::CalcWidget(QWidget *parent) :
    QWidget(parent),
    numbersCount(10),
    ui(new Ui::CalcWidget),
    btnMapper(new QSignalMapper(this))
{
    ui->setupUi(this);
    createButtons();
    makeConnect();
}

CalcWidget::~CalcWidget()
{
    delete[] numbersBtn;
    delete ui;
    delete btnMapper;
}

void CalcWidget::createButtons()
{
    int const btnMinSize = 30;
    int const btnMaxSize = 145;
    int const colRowCount = 3;

    for (int i = 0; i < numbersCount; i++)
    {
        QString caption = QString::number(i);
        numbersBtn[i] = new QPushButton(caption, this);
        numbersBtn[i]->setMaximumSize(QSize(btnMaxSize, btnMaxSize));
        numbersBtn[i]->setMinimumSize(QSize(btnMinSize, btnMinSize));
        numbersBtn[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        ui->gridLayout->addWidget(numbersBtn[i], i / colRowCount, (i % colRowCount) + 2);
    }
}

void CalcWidget::makeConnect()
{
    for (int i = 0; i < numbersCount; i++)
    {
        btnMapper->setMapping(numbersBtn[i], numbersBtn[i]->text());
        connect(numbersBtn[i], SIGNAL(clicked()), btnMapper, SLOT(map()));
    }

    btnMapper->setMapping(ui->btnPlus, QString("+"));
    btnMapper->setMapping(ui->btnMinus, QString("-"));
    btnMapper->setMapping(ui->btnMult, QString("*"));
    btnMapper->setMapping(ui->btnDivide, QString("/"));
    btnMapper->setMapping(ui->btnOpen, QString("("));
    btnMapper->setMapping(ui->btnClose,QString(")"));
    btnMapper->setMapping(ui->btnDot, QString("."));

    connect(ui->btnPlus, SIGNAL(clicked()), btnMapper, SLOT(map()));
    connect(ui->btnMinus, SIGNAL(clicked()), btnMapper, SLOT(map()));
    connect(ui->btnMult, SIGNAL(clicked()), btnMapper, SLOT(map()));
    connect(ui->btnDivide, SIGNAL(clicked()), btnMapper, SLOT(map()));
    connect(ui->btnOpen, SIGNAL(clicked()), btnMapper, SLOT(map()));
    connect(ui->btnClose, SIGNAL(clicked()), btnMapper, SLOT(map()));
    connect(ui->btnDot, SIGNAL(clicked()), btnMapper, SLOT(map()));

    connect(btnMapper, SIGNAL(mapped(QString)), this, SLOT(addCharLine(QString)));

    connect(ui->btnEquals, SIGNAL(clicked()), this, SLOT(calculate()));
    connect(ui->btnClear, SIGNAL(clicked()), ui->lineEdit, SLOT(clear()));
}

void CalcWidget::addCharLine(QString newChar)
{
    if (ui->lineEdit->text() == "Formula is invalid")
        ui->lineEdit->clear();
    ui->lineEdit->setText(ui->lineEdit->text() + newChar);
}

void CalcWidget::calculate()
{
    int const digAfterDot = 2;
    QString formula = ui->lineEdit->text();
    if (formulaChecker.isCorrect(formula))
    {
        float answer = mainCalculator.calculate(ui->lineEdit->text());
        ui->lineEdit->setText(QString::number(answer,
            'f',
            (answer - (int) answer < CalcProcessor::fastNull)? 0 : digAfterDot));
    }
    else
        ui->lineEdit->setText("Formula is invalid");
}
