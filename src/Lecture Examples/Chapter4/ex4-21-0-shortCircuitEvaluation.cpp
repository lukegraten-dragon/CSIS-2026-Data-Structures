// Short-circuit evaluation (of a logical expression): 
// A process in which the computer evaluates a logical expression 
// from left to right and stops as soon as the final value of
// the expression is known.

#include <iostream>

using namespace std ;

int main () 
{
    int age = 24 ;
    int x = 7 ;
    char grade = 'A' ;

    cout << ((age >= 21) || ( x == 5)) << endl ;   //Line 1
    cout << ((grade == 'A') && (x >= 7)) << endl ; //Line 2

    return 0 ;
}