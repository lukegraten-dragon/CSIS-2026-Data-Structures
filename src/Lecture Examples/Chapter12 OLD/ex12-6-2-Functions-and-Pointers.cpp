// Functions and Pointers

#include <iostream>

using namespace std ;

void foo(int* &p, double *q) ;

int main()
{
    int    x = 2 ; 
    double y = 19.0 ;
    
    int    *pp = &x ;
    double *qq = &y ;

    cout << "Before foo()" << endl ;
    cout << "pp: " << pp << endl ;
    cout << "*pp: " << *pp << endl ;
    cout << "qq: " << qq << endl ;
    cout << "*qq: " << *qq << endl << endl ;

    cout << "*** foo() has been called..." << endl ;
    cout << "p: call by reference (int* &p)" << endl ;
    cout << "q: call by value (int* q)" << endl << endl ;

    foo(pp, qq) ;

    cout << "After foo()" << endl ;
    cout << "pp: " << pp << "  <-- Address has been changed: Proof of call by reference: Alias (i.e. original) has been passed." << endl ;
    cout << "*pp: " << *pp << endl ;
    cout << "qq: " << qq << "  <-- Address has NOT been changed: Proof of call by value: A copy of the pointer has been passed." << endl ;
    cout << "*qq: " << *qq << endl ;

    return 0 ;
}

void foo(int* &p, double *q)
{
    cout << "In foo()" << endl ;

    cout << "Before changing p and q" << endl ;
    cout << "p: " << p << endl ;
    cout << "*p: " << *p << endl ;
    cout << "q: " << q << endl ;
    cout << "*q: " << *q << endl << endl ;

    p++ ;
    q++ ;

    cout << "After p++ and q++" << endl ;
    cout << "p: " << p << "  <-- p's address increased" << endl ;
    cout << "*p: " << *p << endl ;
    cout << "q: " << q << "  <-- q's address increased" << endl ;
    cout << "*q: " << *q << endl << endl ;

}
