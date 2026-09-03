// ENUMERATION TYPES AND LOOPS
#include <iostream>

using namespace std ;

int main () 
{
    enum sports {BASKETBALL, FOOTBALL, HOCKEY, BASEBALL, SOCCER, VOLLEYBALL} ;

    sports mySport ; 

    // Recall that the enumeration type is an integral type and that, using the cast operator 
    // (that is, type name), you can increment, decrement, and compare the values of the 
    // enumeration type. Therefore, you can use these enumeration types in loops. 
    for (mySport = BASKETBALL; mySport <= VOLLEYBALL; mySport = static_cast<sports>(mySport + 1))
    {
        cout << "mySport: " << mySport << endl ;
    }

    return 0 ; 
}