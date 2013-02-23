#include "polandFormulaTranslator.h"

PolandFormulaTranslator::PolandFormulaTranslator()
{
    result.clear();
}

PolandFormulaTranslator::~PolandFormulaTranslator()
{
    result.clear();
}

void PolandFormulaTranslator::finalPopAll()
{
    result += " ";
    while (!polandStack.isEmpty())
        result += polandStack.pop();
}

void PolandFormulaTranslator::popUntilSkobe()
{
    result += " ";
    QString current = polandStack.pop();
    while (current != "(")
    {
        result += current;
        current = polandStack.pop();
    }
}

QString PolandFormulaTranslator::translate(QString const &formula)
{
    bool operandWritten = false;
    result.clear();

    for (int i = startIndex; i < formula.size(); i++)
    {
        if (formula.at(i) == QChar(')'))
            popUntilSkobe();
        if (isOperand(formula.at(i)))
        {
            result += formula.at(i);
            operandWritten = true;
        }
        if (isOperator(formula.at(i)))
        {
            if (operandWritten)
            {
                result += " ";
                operandWritten = false;
            }
            if (polandStack.isEmpty())
                polandStack.push(formula.at(i));
            else
            {
                if (formula.at(i) != QChar('('))
                {
                    while (!polandStack.isEmpty() &&
                           (getPriority(polandStack.top().at(startIndex)) >= getPriority(formula.at(i))))
                        result += polandStack.pop();
                }
                polandStack.push(formula.at(i));
            }
        }
    }
    if (!polandStack.isEmpty())
        finalPopAll();

    return result;
}
