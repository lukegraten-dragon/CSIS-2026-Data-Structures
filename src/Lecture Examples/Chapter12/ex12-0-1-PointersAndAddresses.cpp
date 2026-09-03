// Pointers and Addresses

//Basic Pointer Examples from the C Programming Language written by Dennis Ritchie

#include <iostream>

using namespace std ;

int main()
{
    int x = 1, y = 2, z[10], w = 0 ;

    int *ip ;    // ip is a pointer to int

    cout << "*** 1. C and C++ Pointers and Addresses" << endl << endl ;

    cout << "Declare int x = 1, y = 2, z[10], w = 0 ;" << endl ;
    cout << "Declare int *ip ;" << endl << endl ;

    /*
    Referencing 'x' to get its memory address.
    When you reference a variable, you get its address, 
    which can then be stored in a pointer.
    
    &x gives the memory address of x, and this address 
    is stored in the pointer ptr.
    */
    ip = &x ;    // ip now points to x
    //w = &x ;   // error: invalid conversion from ‘int*’ to ‘int’

    cout << "ip = &x means 'referencing x' to get its memory address." << endl ;
    cout << "After ip = &x ;" << endl ;

    cout << "  ip: " << ip << endl ;
    cout << "  x: "   << x << endl ;
    cout << "  &x: " << &x << endl ;
    cout << "  w: "  << w << endl ;
    cout << endl ;

    /*
    Dereferencing 'ip' to get the value stored at the address.
    When you dereference a pointer, you access the actual data 
    at the address it points to, using the * operator.
    */
    y = *ip ;    // y is now 1

    cout << "y = *ip means 'dereferencing ip' to get the value stored at the address." << endl ;
    cout << "After y = *ip ;" << endl ;
    cout << "  y: "   << y << endl ;
    cout << "  *ip: " << *ip << endl << endl ;

    /*
    Dereferencing 'ip' and assign 0 to the memory location it points to
    */
    *ip = 0 ;    // x is now 0

    cout << "*ip = 0 means 'dereferencing ip' and assign 0 to the memory location it points to." << endl ;
    cout << "After *ip = 0 ;" << endl ;
    cout << "  x: "   << x << endl ;
    cout << "  y: "   << y << endl ;
    cout << "  *ip: " << *ip << endl << endl ;

    z[0] = 219 ;
    cout << "z[0] = 219 ;" << endl << endl ;

    ip = &z[0] ; // ip now points to z[0]

    cout << "ip = &z[0] means 'referencing z[0]' to get its memory address." << endl ;
    cout << "After ip = &z[0] ;" << endl ;
    cout << "  ip: " << ip << endl ;
    cout << "  *ip: " << *ip << endl << endl ;

    /*
    If ip points to the integer x, then *ip can occur in any context where x could, so
    *ip = *ip + 10;
    increments *ip by 10.
    */
    *ip = *ip + 10 ;
    cout << "After *ip = *ip + 10 ;" << endl ;
    cout << "  z[0]: " << z[0] << endl ;
    cout << "  ip: " << ip << endl ;
    cout << "  *ip: " << *ip << endl << endl ;

    /*
    The unary operators * and & bind more tightly than arithmetic operators.
    */
    y = *ip + 1 ; // This takes whatever ip points at, adds 1, and assigns the result to y
    cout << "After y = *ip + 1 ;" << endl ;
    cout << "  y: " << y << endl ;
    cout << "  z[0]: " << z[0] << endl ;
    cout << "  ip: " << ip << endl ;
    cout << "  *ip: " << *ip << endl << endl ;

    *ip += 1 ;    // This increments what ip points to
    cout << "After *ip += 1 ;" << endl ;
    cout << "  y: " << y << endl ;
    cout << "  z[0]: " << z[0] << endl ;
    cout << "  ip: " << ip << endl ;
    cout << "  *ip: " << *ip << endl << endl ;

    ++*ip ;    // This increments what ip points to
    cout << "After ++*ip ;" << endl ;
    cout << "  y: " << y << endl ;
    cout << "  z[0]: " << z[0] << endl ;
    cout << "  ip: " << ip << endl ;
    cout << "  *ip: " << *ip << endl << endl ;

    /*
    The parentheses are necessary in this last example; without them, 
    the expression would increment ip instead of what it points to, 
    because unary operators like * and ++ associate right to left.
    */
    (*ip)++ ;    // This increments what ip points to
    cout << "After (*ip)++ ;" << endl ;
    cout << "  y: " << y << endl ;
    cout << "  z[0]: " << z[0] << endl ;
    cout << "  ip: " << ip << endl ;
    cout << "  *ip: " << *ip << endl << endl ;

    /*
    *ip += 1, ++*ip, and (*ip)++ all increment the value that ip points to. 
    */
    cout << "*ip += 1, ++*ip, and (*ip)++ all increment the value that ip points to." << endl << endl ;

    int *iq ;
    cout << "Declare int *iq ;" << endl << endl ;

    /*
    Finally, since pointers are variables, they can be used without dereferencing. 
    For example, if iq is another pointer to int,
    iq = ip
    copies the contents of ip into iq, thus making iq point to whatever ip pointed to.
    */
    iq = ip ;
    cout << "After iq = ip ;" << endl ;
    cout << "  y: " << y << endl ;
    cout << "  z[0]: " << z[0] << endl ;
    cout << "  iq: " << iq << endl ;
    cout << "  *iq: " << *iq << endl << endl ;

    return 0 ;
}