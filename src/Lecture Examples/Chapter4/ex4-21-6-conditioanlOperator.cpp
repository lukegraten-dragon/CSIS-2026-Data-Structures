// ternary operator

#include <iostream>

using namespace std ;

int main () 
{
    int a = 2;
    int b = 19 ;
    int max ;

    // if (a >= b)
    //     max = a ;
    // else
    //     max = b ;

    max = (a >= b) ? a : b ;

    cout << "max = " << max << endl ;

    return 0 ;
}