#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a = 4.2;
    double b = 4.8;
    double c = -3.6;

    cout << round(a) << endl;
    cout << round(b) << endl;
    cout << round(c) << endl;

    // Added values

    double d = 5.49;
    double e = 5.50;
    double f = -5.49;
    double g = -5.50;

    cout << "My added values:\n" << endl;
    cout << round(d) << endl;
    cout << round(e) << endl;
    cout << round(f) << endl;
    cout << round(g) << endl;

    return 0;
}

/*
Round performs a calcuation and is different from
a stream modifier/manipulator that simply changes the formatting.

For halfway cases e.g. 5.5, round() will round away from 0. So 6 in this case
since its farther from zero than 5.

Otherwise it rounds how anyone normally would.
*/