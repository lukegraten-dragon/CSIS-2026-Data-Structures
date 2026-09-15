#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double measurement = 0.000456789;

    cout << "Measurement Report" << endl << endl;
    cout << setw(18) << "General:"
    << setw(15) << setprecision(8)
    << measurement << endl;

    cout << setw(18) << "Rounded:"
    << setw(15) << round(measurement)
    << endl;

    cout << showpoint << fixed << setprecision(2);
    cout << setw(18) << "Fixed:"
    << setw(15) << measurement
    << endl;

    cout << scientific << setprecision(4);
    cout << setw(18) << "Scientific:"
    << setw(15) << measurement
    << endl;

    cout.unsetf(ios::scientific);
    cout.unsetf(ios::showpoint);

    return 0;
}

/*
 setprecision(8) controls the general display.
 round() calculates a whole-number result.
 showpoint, fixed, and setprecision(2) prepare the fixed-point display.
 scientific changes the floating-point format again.
 setprecision(4) sets four digits after the decimal point for the scientific display.
 setw() is repeated because each call controls only the next output item.
 unsetf() clears selected formatting flags when they are no longer needed.


*/