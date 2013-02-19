#ifndef SENINSUPPORT_H
#define SENINSUPPORT_H

#include <QString>

int const startIndex = 0;


enum OperatorPriority
{
    pLowest = -1,
    pLow,
    pMiddle,
    pHigh,
    pNonOperator = -2
};

OperatorPriority getPriority(const QChar &x);
bool isOperand(const QChar &x);
bool isOperator(const QChar &x);

#endif // SENINSUPPORT_H
