#pragma once

#include <QtGui/QWidget>
#include <QtGui/QPushButton>
#include <QtCore/QSignalMapper>

#include "calcProcessor.h"
#include "formulaChecker.h"

namespace Ui {
class CalcWidget;
}

class CalcWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit CalcWidget(QWidget *parent = 0);
    ~CalcWidget();

public slots:
    void addCharLine(QString newChar);
    void calculate();

private:
    int const numbersCount;
    Ui::CalcWidget *ui;
    QPushButton *numbersBtn[10];
    QSignalMapper *btnMapper;
    CalcProcessor mainCalculator;
    FormulaChecker formulaChecker;
    void createButtons();
    void makeConnect();
};

