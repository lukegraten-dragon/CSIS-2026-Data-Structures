#include <iostream>

using namespace std ;

int main () 
{
    // // These are illegal enumeration types because none of the values is an identifier.
    // enum grades {'A', 'B', 'C', 'D', 'F'} ; //illegal enumeration type
    // enum places {1ST, 2ND, 3RD, 4TH} ;      //illegal enumeration type

    // The following are legal enumeration types
    enum grades {A, B, C, D, F} ;
    enum places {FIRST, SECOND, THIRD, FOURTH} ;
    
    return 0 ;
}