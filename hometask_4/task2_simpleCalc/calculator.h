#pragma once

class Calculator
{

public:
    Calculator();

    float getResult();
    float calcNewParams(int leftVal, int rightVal, int action);

protected:
    enum operators
    {
        plus = 0,
        minus,
        multy,
        divide
    };
    int leftArg;
    int rightArg;
    operators mainOperator;
    float result;
    void calcIt();

};

