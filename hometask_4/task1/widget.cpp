#include "widget.h"
#include "ui_Widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    slider1 = new QSlider(Qt::Horizontal, this);
    progressBar1 = new QProgressBar(this);
    mainLayout = new QHBoxLayout(this);

    mainLayout->addWidget(slider1);
    mainLayout->addWidget(progressBar1);

    connect(slider1, SIGNAL(valueChanged(int)), progressBar1, SLOT(setValue(int)));

    setWindowTitle("Task 1");
}

Widget::~Widget()
{
    delete slider1;
    delete progressBar1;
    delete mainLayout;
    delete ui;
}
