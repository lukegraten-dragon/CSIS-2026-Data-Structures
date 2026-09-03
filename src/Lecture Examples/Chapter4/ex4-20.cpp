#include <iostream>

using namespace std ;

int main () 
{
    char gender = 'M' ;
    int age = 24 ;
    double policyRate ;

    // In this code, the else in Line 4 is paired with the if in Line 2. 
    // Note that for the else in Line 4, the most recent incomplete 
    // if is the if in Line 2. 
    // The else in Line 6 is paired with the if in Line 1. 
    // The else in Line 9 is paired with the if in Line 7.
    // Once again, the indentation does not determine the pairing, 
    // but it communicates the pairing.

    if (gender == 'M')            //Line 1
        if (age < 21 )            //Line 2
            policyRate = 0.05 ;   //Line 3
        else                      //Line 4
            policyRate = 0.35 ;   //Line 5
    else if (gender == 'F')       //Line 6
        if (age < 21 )            //Line 7
            policyRate = 0.04 ;   //Line 8
        else                      //Line 9
            policyRate = 0.30 ;   //Line 10

    cout << "policyRate = " << policyRate << endl ;

    return 0 ;
}