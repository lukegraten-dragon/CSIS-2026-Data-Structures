#include <iostream>

using namespace std ;
 
int main()   
{  
    // Declared variables
    int a ;
    int b ;

    a = 5 ;
    b = 2 + (++a) ;

    cout << "a = " << a << endl << "b = " << b << endl ;

    a = 5 ;
    // This one is different. 5 will be added with the 2 and then variable a will be increased separately. Resulting in potentially unintended behavior :(
    b = 2 + (a++) ;
    cout << "a = " << a << endl << "b = " << b << endl ;

    return 0 ;
}