#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double largeValue = 987654.321;
    double smallValue = 0.0000321;

    cout << scientific << setprecision(4);
    cout << largeValue << endl;
    cout << smallValue << endl;

    return 0;
}

/*
e+ means the value is being raised to a positive exponent

e- means the value is being raised to a negative exponent

Scientific notation is useful for conveying extremely large and
small numbers in a way that is easier to read.

e-05 means value x 10^-5
*/

