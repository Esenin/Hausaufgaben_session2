#ifndef FORMULACHECKER_H
#define FORMULACHECKER_H

#include <QString>
#include "priorityInfo.h"
#include "linkedStack.h"


class FormulaChecker
{
public:
    FormulaChecker();
    ~FormulaChecker();
    bool isCorrect(const QString &formula);

private:
    LinkedStack mainStack;
    bool isGoodSkobe(const QString &formula);
    bool isGoodOperatorOperandSequence(QString formula);
};

#endif // FORMULACHECKER_H
