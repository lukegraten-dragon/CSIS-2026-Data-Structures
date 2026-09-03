//C++ 14 Digit Separator
 
#include <iostream>
#include <iomanip>

using namespace std ;

int main() 
{
    int x = 7'087'625 ;
    long long y = 28'087'523'872'918 ;
    double z = 47'034'612'982.68'741 ;

    // In C++, showpoint is a manipulator used to ensure that 
    // floating-point numbers are always displayed with a decimal point, 
    // even if the fractional part is zero. 
    // By default, if the fractional part of a floating-point number 
    // is zero, the decimal point and trailing zeros are not displayed. 
    // Using showpoint forces the output to include the decimal point 
    // and any trailing zeros that would otherwise be omitted.
    cout << fixed << showpoint << setprecision(5) ;

    cout << "x = " << x << endl ;
    cout << "y = " << y << endl ;
    cout << "z = " << z << endl ;
    cout << 1'2'3'4'5'6'7'8'9'0 << endl ;
    cout << "8'403 * 3'600 = " << 8'403 * 3'600 << endl ;
    
    return 0 ;
}