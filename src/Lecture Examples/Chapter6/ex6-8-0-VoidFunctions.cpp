// How to use void functions.  
#include <iostream>

using namespace std ;

void swap(int a, int b) ;

int main()
{
    int a = 2 ;
    int b = 19 ;

    cout << "Before calling swap()" << endl 
         << "a = " << a << endl
         << "b = " << b << endl << endl ;

    swap(a, b) ;

    cout << "After calling swap()" << endl 
         << "a = " << a << endl
         << "b = " << b << endl << endl ;

    return 0 ;
}

// Call by Value
void swap(int a, int b)
{
    int tmp = a ;
    a = b ;
    b = tmp ;
}