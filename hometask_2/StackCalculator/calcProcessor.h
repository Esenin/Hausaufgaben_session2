#pragma once

#include <QString>

#include "priorityInfo.h"
#include "polandFormulaTranslator.h"
#include "arrayStack.h"


class CalcProcessor
{
public:
    CalcProcessor();
    ~CalcProcessor();
    float calculate(QString formula);
    static float const fastNull = 1e-10;

private:
    PolandFormulaTranslator pTranslator;
    ArrayStack numbersStack;
    bool isInteger(const QChar &x);
    bool isOperator(const QChar &x);    
    float calcCurrent(float const &arg1, float const &arg2, QChar const &action);
};

