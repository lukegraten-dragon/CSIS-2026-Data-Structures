#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double first = 345.678;
    double second = 12.345;

    cout << scientific << setprecision(3);
    cout << first << endl;

    cout.unsetf(ios::scientific);
    cout << second << endl;

    return 0;
}

/*
setprecision remains active even when scientific is disable via
setf().

This is something to keep into account when controlling
the formatting of decimal values. As unsetf() only applies
to showpoint, fixed, and
*/