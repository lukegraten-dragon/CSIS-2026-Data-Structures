/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Lab 02 Part 2
// Date Modified: 09-10-2026
//
/******************************************************/

# include <iostream>
# include <iomanip>
# include <cmath>
using namespace std ;

int main ()
{
    // Declare variables for calculation
    double sideA ;
    double sideB ;
    double hypotenuse ;

    sideA = 6 ;
    sideB = 5 ;

    // Calculate the hypotenuse using <cmath>
    hypotenuse = sqrt((pow(sideA, 2.0)) + pow(sideB, 2.0)) ;

    // Print result of the calculation
    cout << fixed << setprecision(2) ;
    cout << "Hypotenuse: " << hypotenuse << '\n' ;

    return 0 ;
}

/*
Post-Lab Reflection

In this lab section, I learned how to include libraries to 
leverage predefined and well-tested functions to extend
the functionality of my C++ programs.
*/