// Operations on Enumeration Types
#include <iostream>

using namespace std ;

int main () 
{
    enum sports {BASKETBALL, FOOTBALL, HOCKEY, BASEBALL, SOCCER, VOLLEYBALL} ;

    sports popularSport, mySport ; 

    popularSport = FOOTBALL ;

    cout << "FOOTBALL <= SOCCER: " << (FOOTBALL <= SOCCER) << endl ;
    cout << "HOCKEY > BASKETBALL: " << (HOCKEY > BASKETBALL) << endl ;
    cout << "BASEBALL < FOOTBALL: " << (BASEBALL < FOOTBALL) << endl << endl ;

    popularSport = SOCCER ;
    mySport = VOLLEYBALL ;

    cout << "popularSport < mySport: " << (popularSport < mySport) << endl ;

    return 0 ; 
}