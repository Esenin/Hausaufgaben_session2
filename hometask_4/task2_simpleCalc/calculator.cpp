#include "calculator.h"

using namespace Calculators;

Calculator::Calculator() :
    leftArg(0),
    rightArg(0),
    mainOperator(plus),
    result(0)
{
    calcIt();
}

void Calculator::calcIt()
{
    switch (mainOperator)
    {
    case plus:
    {
        result = leftArg + rightArg;
        break;
    }
    case minus:
    {
        result = leftArg - rightArg;
        break;
    }
    case multy:
    {
        result = leftArg * rightArg;
        break;
    }
    case divide:
    {
        result = (rightArg == 0)? 0 : (1.0) * leftArg / rightArg;
        break;
    }
    }
}


float Calculator::getResult()
{
    return result;
}

float Calculator::calcNewParams(int leftVal, int rightVal, int action)
{
    leftArg = leftVal;
    rightArg = rightVal;
    mainOperator = (operators)action;
    calcIt();
    return getResult();
}

