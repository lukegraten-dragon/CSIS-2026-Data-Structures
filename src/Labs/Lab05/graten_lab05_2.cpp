/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 05 Part 2
// Date Modified: 10-04-2026
//
/******************************************************/

# include <iostream>
using namespace std ;

void increment (int& integer) {
    // Uses Pass-By-Reference (PBR) to increment an integer
    cout << 

    integer++ ;
}

void displayValues (const int& integer1, const int& integer2)
{
    // Pass parameters in via a reference
    cout << "*** num1 = " << integer1 << '\n' ;
    cout << "*** num2 = " << integer2 << '\n' ;
}


int main ()
{
    int numOne = 0 ;
    int numTwo = 0 ;

    // Ask for integers from user
    cout << "Enter the first number: " ;
    cin >> numOne ;
    cout << "Enter the second number: " ;
    cin >> numTwo ;

    // Before incrementing
    cout << "Before incrementing:" << '\n' ;
    displayValues(numOne, numTwo) ;

    // Increment first integer via PBR
    increment(numOne) ;

    // After Incrementing
    cout << "After incrementing:" << '\n' ;
    displayValues(numOne, numTwo) ;

    return 0 ;
}

/*
Post Lab Reflection:

In this case, based on my knowledge of C++ Pass-By-Value (copy)
and Pass-By-Reference (alias on the original). I think passing by
const reference is a good approach here since the referenced integers
the user inputted are immutable when passed in, and PBR does
result in memory savings due to not having to create a duplicate
in memory to pass to a function.

Overall I'd say that the use of a function to display out values
does improve readability and prevents repeated statements of code
that do the same thing. 

An alternative approach would by to use Pass-By-Value for the 
displayValues function which would functionally
achieve the same result. If we are focused on memory savings, then
the Pass-By-Reference approach is the more ideal one. 

Passing By Reference (without const) modifies the original variables via an alias
which could lead to unintended behavior if we use those original variables
again at some point for a future computation and don't intend them to 
be changed.

I think the main takeaway when using PBR is to be intentional about it.
*/