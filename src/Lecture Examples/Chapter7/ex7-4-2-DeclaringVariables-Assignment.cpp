// variable declation and assignment
#include <iostream>

using namespace std ;

int main () 
{
    // Default value for an enum identifier is based on the placement in the list.
    enum sports {BASKETBALL, FOOTBALL, HOCKEY, BASEBALL, SOCCER, VOLLEYBALL} ;

    sports popularSport ; 
    sports mySport ;

    popularSport = BASEBALL ;
    cout << "popularSport = " << popularSport << endl ;

    mySport = popularSport ;
    cout << "mySport = " << mySport << endl ;

    return 0 ;
}