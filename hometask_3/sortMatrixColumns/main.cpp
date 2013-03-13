/*!
    autodocumentation test begin
    @author Esenin
*/
#include <iostream>
#include <stdlib.h>
#include "quickSorter.h"
#include "sorterTest.h"

using namespace std;



int main()
{
    SorterTest test;
    QTest::qExec(&test);

    cout << "done\n";
    return 0;
}

