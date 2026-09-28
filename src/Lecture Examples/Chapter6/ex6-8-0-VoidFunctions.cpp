// How to use void functions.  
#include <iostream>

// This program highlights the concept of Call by Value and Call by Reference

using namespace std ;

// void swap(int a, int b) ; // Prototype to deleter later on

// Call by Value (Via a copy)
void swap(int a, int b)
{
    int tmp = a ; // Copy of a not the original
    a = b ; // Copy of b
    b = tmp ;

    // This function actually swaps the copies of a and b, not the original
}

// Call by Reference (aliases)
void swap2(int& a, int& b)
{
    // Variables are passed in with nicknames or aliases
    // An & passes the variables using a nickname
    int tmp = a ;
    a = b ;
    b = tmp ;
}

int main()
{
    int a = 2 ;
    int b = 19 ;

    cout << "Before calling swap()" << endl 
         << "a = " << a << endl
         << "b = " << b << endl << endl ;

    swap2(a, b) ; // Switch this between swap() and swap2() to see what happens

    cout << "After calling swap()" << endl 
         << "a = " << a << endl
         << "b = " << b << endl << endl ;

    return 0 ;
}