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

    swap2(a, b) ;

    cout << "After calling swap()" << endl 
         << "a = " << a << endl
         << "b = " << b << endl << endl ;

    return 0 ;
}

// Call by Value
void swap(int a, int b)
{
    /*
    temp will have a's value and a will point to b's value and
    b will point to the tmp value (which contained the original a value)
    But it doesn't work.
    */
    int tmp = a ;
    a = b ;
    b = tmp ;
}

void swap2(int& a, int& b)
{
    int tmp = a ;
    a = b ;
    b = tmp ;
}