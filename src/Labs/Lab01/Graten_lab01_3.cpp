// Student, CSIS 255, Luke Graten, 09.03.2026

# include <iostream>
using namespace std ;

int main()
{
    // Declare variables
    int fahrenheit = 110 ;
    int celsius ;

    // Compute temperatures.
    // Since they all use int, 5 / 9 rounds down to 0, so
    // putting it first in order will multiply whatever is in the
    // parenthesis by 0. Which will return a 0

    celsius = (fahrenheit - 32) * 5 / 9 ;
    cout << fahrenheit << " degree F = " << celsius << " degree C. " << endl ;

    return 0 ;
}