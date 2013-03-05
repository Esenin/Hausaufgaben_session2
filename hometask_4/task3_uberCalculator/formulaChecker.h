#pragma once

#include <QtCore/QString>
#include <QtCore/QStack>

#include "priorityInfo.h"


class FormulaChecker
{
public:
    FormulaChecker();
    bool isCorrect(const QString &formula);

private:
    QStack<QChar> mainStack;
    bool isGoodSkobe(const QString &formula);
    bool isGoodOperatorOperandSequence(QString formula);
};

