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
    return operators.contains(x);
}

bool isOperand (QChar const &x)
{
    bool isLetter = (x == QChar('.'));
    bool isNumber = (x >= QChar('0') && x <= QChar('9'));
    return isLetter || isNumber;
}
