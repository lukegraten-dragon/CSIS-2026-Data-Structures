// Includes standard C++ library

#include <iostream>

// Use standard namespace
using namespace std ;


// Main function (int is declared since we have to return 0 later on)
// C++ has explicit syntax rules, such as surrounding functions with curly braces
// and using semicolons to terminate a code statement.
// NOTE: Code WILL NOT be compiled if there are any syntax errors.
int main () 
{
    // Use 4 spaces (not tab) to make code copyable while having great readability.
    // Variables with their type explicity declared or static
    int length = 3 ;
    int width = 2 ;

    int perimeter = 2 * (length + width) ;
    
    // cout is like a print statement in Python
    // endl is to terminate the print statement
    cout << "perimeter = " << perimeter << endl ;

    int area = length * width ;

    cout << "area = " << area << endl ;

    // Main function returns 0 if the program runs successfully
    return 0 ;
}
