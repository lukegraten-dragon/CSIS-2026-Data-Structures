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

/*
    int* foo(int* pp)

    The return type int* means that foo returns a pointer to an int,
    rather than an int value. The parameter pp is passed by value, so
    it receives a copy of the address stored in p.

    Before foo(p):

           main()                            foo()
        +----------+                     +----------+
        | p = &x   |                     | pp = &x  |
        +----------+                     +----------+
             |                                 |
             +---------------+-----------------+
                             |
                             v
                         +---------+
                         |  x = 2  |
                         +---------+

        q has been declared but has not yet been assigned a value.

    The function call and return statement are:

        q = foo(p);
        return ++pp;

    The expression ++pp increments the local pointer BEFORE returning
    it. Pointer arithmetic moves by one int element, not one byte.
    For example, if sizeof(int) is 4 and x is at address 0x1000:

        p initially:            0x1000   (&x)
        pp initially:           0x1000   (copy of p)
        pp after ++pp:          0x1004   (one past x)
        q after foo returns:    0x1004   (returned pointer)
        p after foo returns:    0x1000   (unchanged)

    After foo(p), using these example addresses:

        p --------------------> +---------+
                                |  x = 2  |   one-past-x
                                +---------+   +----------+
                                  0x1000      |  0x1004  |
                                               +----------+
                                                    ^
                                                    |
                                                    q

    If the return statement is changed to:

        return pp++;

    the expression returns the OLD pointer value before incrementing
    the local pp. In that case q receives the same address as p:

        p = 0x1000
        q = 0x1000

    x and y are separate local variables. Their addresses are not
    guaranteed to be adjacent or in any particular order. Incrementing
    a pointer to x does not mean that it will point to y.

    For a pointer to the single object x, x's address plus one int
    position is a valid one-past pointer, but it cannot be dereferenced.
    The program prints q as an address and does not evaluate *q.
*/
