/*!
    autodocumentation test begin
    @author Esenin
*/
#include <iostream>
#include <stdlib.h> /// for random

#include "quickSorter.h"
#include "bubbleSorter.h"
#include "sortersTest.h"

using namespace std;

int main()
{
    SortersTest test;
    QTest::qExec(&test);

    return 0;
}

