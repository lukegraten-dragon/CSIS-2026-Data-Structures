// Floating Point Types: Float, Double, and Long Double

float a = 3.14f ; // Float literal
double b = 3.14 ; // Double literal 
long double c = 3.14L ; // Long double literal

/*
Double is a general-purpose decimal data type
capable of storing 15 significant digits. This should
be used in most contexts. Double is also the default
literal for most decimal values.

Float and Long Double must be specified with f and L respectively
after the decimal value. 

Its best practice to avoid truncating decimal precision.
*/

/*
1.234567 -> about 7 significant digits
1234567 -> also about 7 significant digits
0.0001234567 -> leading zeros are not significant digits
*/

#include <iostream>
using namespace std;

int main()
{
    float a = 3.14f;
    double b = 3.14;
    long double c = 3.14L;

    cout << "sizeof(float) = " << sizeof(a) << " bytes" << endl;

    // On Mac, both of these have the same memory footprint. But on Windows,
    // this behaves differently. So if you need an extra precise decimal data type
    // use long double.
    cout << "sizeof(double) = " << sizeof(b) << " bytes" << endl;
    cout << "sizeof(long double) = " << sizeof(c) << " bytes" << endl;
    
    return 0;
}

// float (commonly binary32) -> about 7 significant decimal digits
// double (commonly binary64) -> about 15-16 significant decimal digits