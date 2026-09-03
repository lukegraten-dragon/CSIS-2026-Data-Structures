#include <iostream>

using namespace std ;

int main () 
{
    int temperature = 75 ;

    // In this code, the else in Line 4 is paired with the if in Line 2. 
    // Note that for the else in Line 4, the most recent incomplete 
    // if is in Line 2. In this code, the if in Line 1 has no else and 
    // is a one-way selection. Once again, the indentation does not determine
    // the pairing, but it communicates the pairing. 
    // Note that if the value of temperature is less than 70, this code 
    // renders no decision.

    if (temperature >= 70)                             //Line 1
        if (temperature >= 80)                         //Line 2
            cout << "Good day for swimming." << endl ; //Line 3
        else                                           //Line 4
            cout << "Good day for golfing." << endl ;  //Line 5

    return 0 ;
}