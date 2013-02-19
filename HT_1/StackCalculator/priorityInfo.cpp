#include "priorityInfo.h"


OperatorPriority getPriority(QChar const &x)
{
    if (x == QChar('('))
        return pLowest;
    if (x == QChar('+') || x == QChar('-'))
        return pLow;
    if (x == QChar('^'))
            return pHigh;
    if (x == QChar('*') || x == QChar('/'))
        return pMiddle;
    return pNonOperator;
}


bool isOperator (QChar const &x)
{
    QString operators = "(+-*/^";

    for (int i = 0; i < operators.size(); i++)
        if (x == operators.at(i))
            return true;
    return false;
}

bool isOperand (QChar const &x)
{
    bool isLetter = ((x >= QChar('a') && x <= QChar('z')) || (x == QChar('.')));
    bool isNumber = (x >= QChar('0') && x <= QChar('9'));
    return isLetter || isNumber;
}
