#include "formulaChecker.h"

FormulaChecker::FormulaChecker()
{
    mainStack.clear();
}

bool FormulaChecker::isGoodSkobe(QString const &formula)
{
    mainStack.clear();
    for (int i = 0; i < formula.size(); i++)
    {
        if (formula.at(i) == QChar('('))
            mainStack.push('(');
        if (formula.at(i) == QChar(')'))
        {
            if (mainStack.isEmpty())
                return false;
            else
                mainStack.pop();
        }
    }
    return mainStack.isEmpty();
}

bool FormulaChecker::isGoodOperatorOperandSequence(QString formula)
{
    bool needOperand = true;
    bool isStillOperand = false;
    int operandCount = 0;
    formula += " ";

    for (int i = 0; i < formula.size(); i++)
    {
        if (isOperand(formula.at(i)))
        {
            if (needOperand)
                isStillOperand = true;
            else
                return false;
        }
        else
        {
            // here is not orerand
            if (isStillOperand)
            {
                operandCount++;
                isStillOperand = false;
                needOperand = false;
            }

            if (isOperator(formula.at(i)) && (formula.at(i) != QChar('(')))
            {
                if (!needOperand)
                {
                    needOperand = true;
                }
                else
                    return false;
            }
        }
    }
    return (!needOperand) && (operandCount > 1);
}

bool FormulaChecker::isCorrect(const QString &formula)
{
    return (isGoodSkobe(formula) && isGoodOperatorOperandSequence(formula));
}
