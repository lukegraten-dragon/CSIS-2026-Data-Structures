#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double price = 19.98765;

    cout << fixed << setprecision(1) << price << endl;
    cout << fixed << setprecision(5) << price << endl;

    return 0;
}

/*

In this example, changing the value in setprecision() will
cause the displayed value to show the specified amount of digits
after the decimal point.

(2) 19.99
(4) 19.9876

(1) 20.0
(3) 19.988
(5) 19.98765


*/