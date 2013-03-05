#pragma once

#include <QtCore/QString>
#include <QtCore/QStack>

#include "priorityInfo.h"


class PolandFormulaTranslator
{
public:
    PolandFormulaTranslator();
    ~PolandFormulaTranslator();

    QString translate (const QString &formula);
private:
    QString result;
    QStack<QString> polandStack;
    void finalPopAll();
    void popUntilSkobe();
};

