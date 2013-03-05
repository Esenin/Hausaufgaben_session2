#pragma once

namespace Calculators
{

enum operators
{
    plus = 0,
    minus,
    multy,
    divide
};


class Calculator
{

public:
    Calculator();

    float getResult();
    float calcNewParams(int leftVal, int rightVal, int action);

protected:
    int leftArg;
    int rightArg;
    operators mainOperator;
    float result;
    void calcIt();

};

}

