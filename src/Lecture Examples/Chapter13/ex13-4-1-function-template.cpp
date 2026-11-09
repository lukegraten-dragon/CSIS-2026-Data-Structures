// Function Templates in C++

/*
A function template in C++ allows you to write a generic function that 
can work with different data types without having to rewrite the same 
function for each type. Function templates are defined using the template 
keyword and a placeholder for the data type (commonly T). 

When you call a function template, the compiler automatically deduces 
the data type from the arguments provided.

Basic Syntax of a Function Template

template <typename T>
T add(T a, T b) {
    return a + b;
}

Breakdown:
- template <typename T>: This tells the compiler that T is a placeholder 
  for a data type, and the function should be templated.
- T add(T a, T b): This declares the function add that takes two arguments 
  of type T and returns a value of type T. The actual type of T is determined 
  when the function is called.

Example: Simple Function Template
*/
#include <iostream>
using namespace std ;

// Function template to add two numbers
template <typename T>
T add(T a, T b) {
    return a + b ;
}

int main() {
    // Calling the template function with int type
    int intResult = add(3, 4) ;
    cout << "Sum of integers: " << intResult << endl ;

    // Calling the template function with double type
    double doubleResult = add(3.5, 2.1) ;
    cout << "Sum of doubles: " << doubleResult << endl ;

    // Calling the template function with float type
    float floatResult = add(3.2f, 1.1f) ;
    cout << "Sum of floats: " << floatResult << endl ;

    return 0 ;
}
/*
Explanation:
- add(3, 4): The template function is instantiated with int type because 
  the arguments are integers. So, the compiler creates a version of add 
  that works with int.
- add(3.5, 2.1): Here, the function is instantiated with double because 
  the arguments are doubles.
- add(3.2f, 1.1f): The function is instantiated with float because the 
  arguments are floats.
*/
