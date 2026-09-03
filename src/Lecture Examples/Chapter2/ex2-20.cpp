#include <iostream>

using namespace std ;
 
int main()   
{  

    int a ;
    int b ;

    a = 5 ;
    b = 2 + (++a) ;

    cout << "a = " << a << endl << "b = " << b << endl ;

    a = 5 ;
    b = 2 + (a++) ;
    cout << "a = " << a << endl << "b = " << b << endl ;

    return 0 ;
}