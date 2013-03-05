#pragma once

#include <QtGui/QWidget>
#include <QtGui/QLayout>
#include <QtGui/QProgressBar>
#include <QtGui/QSlider>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private:
    Ui::Widget *ui;
    QSlider *slider1;
    QProgressBar *progressBar1;
    QHBoxLayout *mainLayout;

};

