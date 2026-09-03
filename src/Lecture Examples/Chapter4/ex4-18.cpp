#include <iostream>

using namespace std ;

int main () 
{
    int temperature = 75 ;

    // In this C++ code, the else in Line 4 is paired with the if in Line 2, 
    // and the else in Line 6 is paired with the if in Line 1. 
    // Note that the else in Line 4 cannot be paired with the if in Line 1. 
    // If you pair the else in Line 4 with the if in Line 1, the if in
    // Line 2 becomes the action statement part of the if in Line 1, 
    // leaving the else in Line 6 dangling. 
    // Also, the statements in Lines 2 though 5 form the statement part of
    // the if in Line 1. The indentation does not determine the pairing, 
    // but should be used to communicate the pairing.

    if (temperature >= 50)                             //Line 1
        if (temperature >= 80)                         //Line 2
            cout << "Good day for swimming." << endl ; //Line 3
        else                                           //Line 4
            cout << "Good day for golfing." << endl ;  //Line 5
    else                                               //Line 6
        cout << "Good day to play tennis." << endl ;   //Line 7

    return 0 ;
}