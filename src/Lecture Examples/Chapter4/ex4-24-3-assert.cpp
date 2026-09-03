#include <iostream>

//#define NDEBUG
#include <cassert>

using namespace std;

int main() {

    int numerator = 10 ;
    int denominator = 0 ;

    // Use assert to ensure denominator is not zero before division
    assert(denominator != 0) ;
    //assert(denominator != 0 && "Error: Division by zero!") ;

    // Perform the division
    int result = numerator / denominator ;

    cout << "Result: " << result << endl ;

    return 0 ;
}

// The message "Aborted (core dumped)" in C++ (and many other languages) 
// occurs when a program terminates unexpectedly due to a critical error, 
// and a core dump file is generated. Let's break this down:

// 1. Aborted:
// This happens when the program explicitly or implicitly calls the abort() 
// function, either directly or indirectly, which immediately terminates 
// the program. In the case of assert, if an assertion fails, it calls abort(), 
// causing the program to be aborted.

// 2. Core Dumped:
// A core dump is a file that captures the memory state of the program 
// at the moment it crashed. It includes information about variables, 
// memory addresses, and the call stack at the time of the error. 
// This can be very useful for debugging, as it allows developers to 
// inspect what went wrong in detail.

// Common Causes of "Aborted (core dumped)" in C++:
// - Failed assertion: As we saw in the examples using assert, 
//   if an assertion fails, the program aborts.
// - Segmentation fault: When a program tries to access memory that it's not 
//   supposed to (e.g., accessing a null pointer or out-of-bounds array index), 
//   it results in a segmentation fault, which can lead to an abort.
// - Explicit abort() call: The program can directly call the abort() function 
//   when it detects an unrecoverable error.
