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

/*
==========================================================================
    POINTER REFERENCE vs. POINTER VALUE
==========================================================================

    void foo(int* &p, double *q)

    A) CALL BY REFERENCE: int* &p

                 main()                         foo()
        +---------------------+         +----------------------+
        | pp  (points to x)   | <=====> | p  (alias of pp)     |
        +---------------------+  SAME   +----------------------+
                   |             POINTER
                   v
                 +-------+
                 | x = 2 |
                 +-------+

        When foo executes p++, it changes the ORIGINAL pointer pp.
        Afterwards pp holds the address just PAST x, NOT the address of
        another valid int object.

    B) CALL BY VALUE: double *q

                 main()                         foo()
        +---------------------+   COPY  +----------------------+
        | qq  (points to y)   | ------> | q  (separate copy)   |
        +---------------------+ ADDRESS +----------------------+
                   |                              |
                   +------------+-----------------+
                                v
                             +----------+
                             | y = 19.0 |
                             +----------+

        Initially q and qq contain the same address.
        When foo executes q++, ONLY the local pointer q changes.
        The caller's pointer qq STILL points to y after foo returns.

        p++  : modifies the caller's pointer pp (reference parameter).
        q++  : modifies only the local pointer q (value parameter).

        x and y are SINGLE variables, not arrays.
        p++ and q++ may form one-past addresses, but dereferencing those
        pointers (*p and *q) afterward is UNDEFINED BEHAVIOR.
        Similarly, *pp after foo returns is UNDEFINED BEHAVIOR because
        pp was changed by p++. A displayed 0 or an unexpected floating-
        point number is NOT a predictable or valid program result.

        The original cout label says "int* q", but its actual parameter
        type is double *q. This is a label typo, not a declaration change.

==========================================================================
*/

/*

    This example demonstrates the difference between
    passing a pointer by reference and by value.

    1. p is a reference to the original pointer pp.
       Therefore, p++ also changes pp in main().

    2. q is a copy of the original pointer qq.
       Therefore, q++ changes only the local pointer q.
       The original qq in main() remains unchanged.

    CAUTION:

    Both pointers initially point to single variables,
    not arrays.

    After p++ and q++, dereferencing these pointers
    causes undefined behavior.

    The program may still print numerical values,
    but those values are not guaranteed by C++.

    The important observation is the change in the
    POINTER ADDRESSES, not the dereferenced values.
*/