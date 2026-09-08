/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Lab 01
// Date Modified: 09-08-2026
//
/******************************************************/

# include <iostream>
using namespace std ;

int main ()
{
    // Declare variables and conversion constants
    double miles ;
    double kilometers ;
    const double FACTOR = 1.609344 ;

    miles = 15 ;

    // Convert from miles to kilometers
    kilometers = miles * FACTOR ;
    cout << miles << " miles = " << kilometers << " kilometers" << '\n' ;

    return 0 ;
}

/*
Reflection

In this lab section I learned how to use constants,
double precision data typed variables, and computing the result.

The constant FACTOR was used as a conversion factor that couldn't
be modified later during program execution, while the variable
miles was used to compute the kilometers variable via the FACTOR constant.

To preserve precision, all variables were implemented as double.
*/