// How to use a user-defined functions.  
#include <iostream>

using namespace std ;

double larger(double x, double y) ;

int main()
{
    double num1 = 13.00 ;
    double num2 = 36.53 ;
    double maxNum ;

    cout << "The larger of 5 and 6 is " << larger(5, 6)
         << endl ;                                        //Line 1
    
    cout << "The larger of " << num1 << " and " << num2
         << " is " << larger(num1, num2) << endl ;        //Line 2
    
    cout << "The larger of " << num1 << " and 29 is "
         << larger(num1, 29) << endl ;                    //Line 3
    
    maxNum = larger(38.45, 56.78) ;                       //Line 4

    cout << "larger(38.45, 56.78) = " << maxNum << endl ;

    return 0 ;
}

double larger(double x, double y)
{
    // double max ;

    // if (x >= y)
    //     max = x ;
    // else
    //     max = y ;
    
    // return max ;
    return (x > y) ? x : y ;
}