#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double number = 45.67891234;

    cout << setprecision(4) << number << endl;
    cout << fixed << setprecision(4) << number << endl;
    cout << scientific << setprecision(4) << number << endl;

    return 0;
}

/*
Set precision controls significant digits generally speaking.

With fixed or scientific formatting flags enabled setprecision(n)
controls digits after the decimal point.

Use unsetf to disable the scientific and fixed flags
to restore setprecision() to its default behavior of controlling
significant digits.
*/