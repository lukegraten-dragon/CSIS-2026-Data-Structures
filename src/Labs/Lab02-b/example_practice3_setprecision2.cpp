#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double distance = 78.456789;

    cout << distance << endl;
    cout << fixed << setprecision(2) << distance << endl;
    cout << scientific << setprecision(4) << distance << endl;

    return 0;
}

/*
Using formatting modifiers only changes the displayed value
, so internally the variable distance still reads
as 78.456789.


Formatting modifiers are useful for making printed data
look more clean and understandable.
*/

