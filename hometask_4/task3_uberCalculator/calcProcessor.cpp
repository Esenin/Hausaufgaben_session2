#include "calcProcessor.h"

CalcProcessor::CalcProcessor()
{
    numbersStack.clear();
}

CalcProcessor::~CalcProcessor()
{
    numbersStack.clear();
}

bool CalcProcessor::isInteger(QChar const &x) const
{
    return ((x >= QChar('0') && x <= QChar('9')) || (x == QChar('.')));
}

float CalcProcessor::calcCurrent(const float &arg1, const float &arg2, const QChar &action) const
{
    switch (action.toAscii())
    {
    case '+':
    {
        return arg1 + arg2;
    }
    case '-':
    {
        return arg1 - arg2;
    }
    case '*':
    {
        return arg1 * arg2;
    }
    case '/':
    {
        if (arg2 < fastNull) // arg2 == 0
            return 0;
        else
            return arg1 / arg2;
    }
    }
    return 0;
}

float CalcProcessor::calculate(QString formula)
{
    formula = pTranslator.translate(formula);
    numbersStack.clear();
    QString word = "";
    bool isEditing = false;

    for (int i = 0; i < formula.size(); i++)
    {
        if (isInteger(formula.at(i)))
        {
            word.push_back(formula.at(i));
            isEditing = true;
        }
        if (isOperator(formula.at(i)))
        {
            numbersStack.push(QString::number(
                                   calcCurrent(numbersStack.pop().toFloat(),
                                               numbersStack.pop().toFloat(),
                                               formula.at(i))));
        }
        if (formula.at(i) == QChar(' ') && isEditing)
        {
            numbersStack.push(word);
            word.clear();
            isEditing = false;
        }
    }

    return numbersStack.pop().toFloat();
}

