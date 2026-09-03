// Pointers and Function Return Values

#include <iostream>

using namespace std ;

int* foo (int* pp) ;

int main()
{
    int x = 2 ;
    int y = 19 ;

    int *p = &x ;
    int *q ;

    cout << "Before foo()" << endl ;
    cout << "p: " << p << endl << endl ;

    q = foo(p) ;

    cout << "After foo()" << endl ;
    cout << "p: " << p << endl ;
    cout << "q: " << q << endl ;

    return 0 ;
}

int* foo (int* pp)
{
    return ++pp ; // What if pp++ ? Test hits!!!
}
