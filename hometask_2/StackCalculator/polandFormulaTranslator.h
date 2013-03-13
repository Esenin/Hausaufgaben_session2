#pragma once

#include "priorityInfo.h"
#include <QString>
#include "arrayStack.h"

class PolandFormulaTranslator
{
public:
    PolandFormulaTranslator();
    ~PolandFormulaTranslator();
    QString translate(const QString &formula);
private:
    QString result;
    ArrayStack polandStack;
    void finalPopAll();
    void popUntilSkobe();
};

