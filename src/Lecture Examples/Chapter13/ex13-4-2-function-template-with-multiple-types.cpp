// Function Template with Multiple types

/*
Sometimes you may want a function to work with two different data types. 
You can achieve this by specifying multiple template parameters.
*/

#include <iostream>
using namespace std ;

// Function template to find the smaller of two values of different types
template <typename T1, typename T2>
T1 findSmaller(T1 a, T2 b) {
    return (a < b) ? a : b ;
}

int main() {
    int a = 5 ;
    double b = 7.5 ;

    // Calling the template function with int and double types
    cout << "Smaller value: " << findSmaller(a, b) << endl ;

    char c = 'A' ;
    int d = 70 ;

    // Calling the template function with char and int types
    cout << "Smaller value: " << findSmaller(c, d) << endl ;

    return 0 ;
}
/*
Explanation:
- findSmaller(5, 7.5): The template is instantiated with T1 = int and T2 = double, 
  so it can compare and return the smaller of an integer and a double.
- findSmaller('A', 70): The template is instantiated with T1 = char and T2 = int, 
  and the function returns the smaller of a character and an integer.
*/

/*
1. Benefits of Function Templates:
- Code Reusability: Write a single function that works for different data types.
- Type Safety: Function templates are type-safe, meaning the compiler checks for 
  type mismatches.
- Maintainability: Less code to maintain, since you don’t need to write separate 
  functions for each data type.
- Efficiency: The compiler generates specific instances of the template at compile-time, 
  so there’s no runtime overhead for template instantiation.

Summary:
- Function templates allow you to write a function that works with any data type. 
  The template is instantiated with a specific type when the function is called.
- Syntax: Use template <typename T> to define a template function, where T is 
  the placeholder for the actual data type.
- Function Templates with Multiple Types: You can use multiple template parameters 
  (template <typename T1, typename T2>) to handle different data types.
*/
