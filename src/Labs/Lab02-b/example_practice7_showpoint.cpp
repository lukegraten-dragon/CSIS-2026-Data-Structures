#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double a = 10.0;
    double b = 10.5;
    double c = 3.0;

    cout << setprecision(5);

    cout << "Without showpoint:" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << showpoint;

    cout << "\nWith showpoint:" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}

/*
In this example, setprecision() controls
the amount of sig figs present (since fixed and
scientific are disabled)

Showpoint acts like a filler, adding trailing zeros
to the sig fig limit imposed by setprecision().

This makes decimal values look more consistent by
occupying a similar amount of sig figs (trailing zeros
are sig figs in most cases).
*/