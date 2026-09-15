
/*
Write a C++ program that reads one temperature value from the user and displays:

 the value using general floating-point formatting;
 the rounded value using round();
 the value in fixed-point notation with two digits after the decimal point;
 the value in scientific notation with four digits after the decimal point;
 each labeled result using a field width of at least 18 characters.
*/

# include <iostream>
# include <iomanip>

using namespace std ;

int main() 
{
    double temperature ;

    // Grab user input

    cout << "Input a temperature (e.g. 25.3): " ;
    cin >> temperature ;
    cout << '\n' ;

    // Display in various formatting methods
    cout << setprecision(8) ;
    cout << left ;

    cout << setw(18) << "Temperature: " << setw(18) << temperature << '\n' ; // Default/Unmodified
    cout << setw(18) << "Rounded: " << setw(18) << round(temperature) << '\n' ; // Rounded
    cout << fixed << setprecision(2)
        << setw(18) << "Fixed Point: " << setw(18) << temperature << '\n' ; // Fixed Point 2 digits
    cout << scientific << setprecision(4) 
        << setw(18) << "Scientific: " << setw(18) << temperature << '\n' ;

    return 0 ;
}