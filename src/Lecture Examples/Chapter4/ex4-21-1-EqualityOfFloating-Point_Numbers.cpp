#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std ;
 
int main()
{ 
    // Comparison of floating-point numbers for equality may not 
    // behave as you would expect.
    
    double x = 1.0 ;
    double y = 3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0 ;

    cout << fixed << showpoint << setprecision(17) ;

    cout << "3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0 = "
         << 3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0 << endl ;

    cout << "x = " << x << endl ;
    cout << "y = " << y << endl ;

    if (x == y)
        cout << "x and y are the same." << endl ;
    else
        cout << "x and y are not the same." << endl ; 

    if (fabs(x - y) < 0.000001)
        cout << "x and y are the same within the tolerance "
             << "0.000001." << endl ;
    else
        cout << " x and y are not the same within the "
             << "tolerance 0.000001." << endl ;

    // In this program, x is initialized to 1.0 and y is initialized to 
    // 3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0. 
    // Now, due to rounding, as shown by the output, this expression 
    // evaluates to 0.99999999999999989. 
    // Therefore, the expression (x == y) evaluates to false. 
    // However, if you evaluate the expression 3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0 
    // by hand using a paper and a pencil, you will get 
    // 3.0 / 7.0 + 2.0 / 7.0 + 2.0 / 7.0 = (3.0 + 2.0 + 2.0) / 7.0 = 7.0 / 7.0 = 1.0. 
    // That is, the value of y should be set to 1.0 and x should be equal to y.

    // The preceding program and its output show that you should be careful 
    // when comparing floating-point numbers for equality. 
    // One way to check whether two floating-point numbers are equal is 
    // to check whether the absolute value of their difference is less than
    // a certain tolerance. For example, suppose the tolerance is 0.000001. 
    // Then, x and y are equal if the absolute value of (x – y) is less than 0.000001. 
    // To find the absolute value, you can use the function fabs (find the 
    // absolute value of a floating-point number), of the header file cmath, 
    // as shown in the program. Therefore, the expression fabs(x – y)

    return 0 ;
}