// Student, CSIS 255, Luke Graten, 09.03.2026

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