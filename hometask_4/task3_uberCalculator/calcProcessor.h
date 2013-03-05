#pragma once

#include <QtCore/QString>
#include <QtCore/QStack>

#include "priorityInfo.h"
#include "polandFormulaTranslator.h"


class CalcProcessor
{
public:
    CalcProcessor();
    ~CalcProcessor();
    float calculate(QString formula);
    static float const fastNull = 1e-10;

private:
    PolandFormulaTranslator pTranslator;
    QStack <QString> numbersStack;
    bool isInteger(const QChar &x) const;
    float calcCurrent(float const &arg1, float const &arg2, QChar const &action) const;
};

