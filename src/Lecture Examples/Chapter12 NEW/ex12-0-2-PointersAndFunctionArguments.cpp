// Pointers and Function Arguments

#include <iostream>

using namespace std ;

/*
Since C passes arguments to functions by value, there is no direct way for the called function
to alter a variable in the calling function. For instance, a sorting routine might exchange two
out-of-order arguments with a function called swap. It is not enough to write
swap(a, b);
where the swap function is defined as

void swap(int x, int y)
{
    int temp ;

    temp = x ;
    x = y ;
    y = temp ;
}

Because of call by value, swap can't affect the arguments a and b in the routine that called it.
The function above swaps copies of a and b.
*/

void swap (int *px, int *py)
{
    int temp ;

    temp = *px ;
    *px = *py ;
    *py = temp ;
}

// Function to swap two integers
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 2, b = 19 ;


    cout << "Before swap(&a, &b)" << endl 
         << "a: " << a << endl 
         << "b: " << b << endl << endl ;

    /*
    Passing two reference variables. It doesn't pass them by reference.
    If you are confused, go back to 'ex12-0-1-PointersAndAddresses.cpp'.
    */
    swap(&a, &b) ; // Passing two reference variables. Not passing by reference.
    //swap(a, b) ; // This functional call also works.

    cout << "After swap(&a, &b)" << endl 
         << "a: " << a << endl 
         << "b: " << b << endl ;

    /*
    Pointer arguments enable a function to access and change objects in the function that called it.
    */

    return 0 ;
}


