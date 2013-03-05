#pragma once

#include <QtGui/QWidget>
#include "calculator.h"

namespace Ui {
class CalculateWidget;
}

class CalculateWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit CalculateWidget(QWidget *parent = 0);
    ~CalculateWidget();

public slots:
    void changeParams();

protected:
    Calculator calcMachine;

    
private:
    Ui::CalculateWidget *ui;
};

