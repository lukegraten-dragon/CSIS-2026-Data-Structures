#include <iostream>

using namespace std ;
 
int main()   
{  
    // Declared variables
    int a ;
    int b ;

    a = 5 ;
    // Adds 2 with the variable a pre incremented. Resulting in 8.
    b = 2 + (++a) ;

    cout << "a = " << a << endl << "b = " << b << endl ;

    a = 5 ;
    // This one is different. 2 will be added with the 5 and then variable a will be increased separately. Resulting in potentially unintended behavior :(
    b = 2 + (a++) ;
    cout << "a = " << a << endl << "b = " << b << endl ;

    return 0 ;
}