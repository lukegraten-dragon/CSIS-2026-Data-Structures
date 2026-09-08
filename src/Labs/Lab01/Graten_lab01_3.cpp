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

int main()
{
    // Declare variables
    int fahrenheit = 110 ;
    double celsius ;

    // FIX: Use a decimal value (double) to prevent the divison result from being rounded down to 0
    // and fix the subtle semantic error.
    celsius = 5.0 / 9 * (fahrenheit - 32) ;
    cout << fahrenheit << " degree F = " << celsius << " degree C. " << endl ;

    return 0 ;
}

/*
Reflection

In this lab section I discovered a subtle semantic error
in how data is operated on can have a huge impact on the result.
Using this knowledge, I'll keep a sharper eye on how variables
are operated on so future programs behave as intended.
*/