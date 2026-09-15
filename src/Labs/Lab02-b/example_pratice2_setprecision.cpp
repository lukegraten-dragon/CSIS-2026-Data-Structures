#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    float f = 1.23456789012345f;
    double d = 1.23456789012345;

    cout << setprecision(15);
    cout << "float = " << f << endl;
    cout << "double = " << d << endl;

    return 0;
}

// Since a float is inherently imprecise comapred to double
// it returns a different result compared to a double when
// using setprecision.

// setprecision(15) does not give a float 15 digits of precision. 
// It only asks cout to display more digits. Digits
// beyond the reliable precision of the float 
// reveal the stored binary approximatiion