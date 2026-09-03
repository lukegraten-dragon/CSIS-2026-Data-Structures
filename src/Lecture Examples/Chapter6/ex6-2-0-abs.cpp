// How to use a user-defined functions.  
#include <iostream>

using namespace std ;

//int abs(int number) ;

int main()
{
    int a = -10 ;

    cout << "abs(" << a << ") = " << abs(a) << endl ;

    return 0 ;
}

int abs(int number)
{
    if (number < 0)
        number = -number ;

    return number ;
}