// Student, CSIS 255, Luke Graten, 09.03.2026

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