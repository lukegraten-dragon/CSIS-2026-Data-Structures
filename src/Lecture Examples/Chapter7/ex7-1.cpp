#include <iostream>

using namespace std ;

// In C++, an enumeration (enum) is a user-defined data type that 
// consists of integral constants. To define an enum, you specify 
// a name and a set of named integer constants that represent 
// different values. Enumerations improve code readability by 
// allowing you to work with meaningful names instead of raw numbers.
int main () 
{
    // This program defines a new data type called colors, 
    // and the values belonging to this data type are 
    // BROWN, BLUE, RED, GREEN, and YELLOW.
    enum colors {BROWN, BLUE, RED, GREEN, YELLOW} ;

    return 0 ;
}