#include <iostream>
#include <QString>
#include "formulaChecker.h"
#include "calcProcessor.h"

using namespace std;

bool calculate(const QString &expression)
{
    FormulaChecker checker;
    if (!checker.isCorrect(expression))
        return false;

    CalcProcessor mathProcessor;
    cout << "Result:" << endl << mathProcessor.calculate(expression) << endl;
    return true;
}

void sample()
{
    QString expression = QString("2 * (1 + 3) - 3 * 1");

    cout << "Testing:" << endl << expression.toStdString() << endl ;
    calculate(expression);
}

void testing()
{
    sample();

    const int maxLength = 50;
    char input[maxLength] = {};

    cout << "Now type your expression or type 'exit' to escape:\n";
    cin.getline(input, maxLength);


    while (!(QString(input).toLower() == "exit"))
    {
        if (!calculate(QString(input)))
            cout << "Expression is invalid ('exit' to escape)\n";
        cin.getline(input, maxLength);
    }
    cout << "Program closed\n";
}

int main()
{
    testing();
    return 0;
}

