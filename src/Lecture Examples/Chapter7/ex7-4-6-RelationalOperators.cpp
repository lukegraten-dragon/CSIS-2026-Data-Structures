// Operations on Enumeration Types
#include <iostream>

using namespace std ;

int main () 
{
    enum sports {BASKETBALL, FOOTBALL, HOCKEY, BASEBALL, SOCCER, VOLLEYBALL} ;

    sports popularSport, mySport ; 

    popularSport = FOOTBALL ;

    // Prints a boolean value (1 = True, 0 = False) to the terminal
    cout << "FOOTBALL <= SOCCER: " << (FOOTBALL <= SOCCER) << endl ; // True
    cout << "HOCKEY > BASKETBALL: " << (HOCKEY > BASKETBALL) << endl ; // True
    cout << "BASEBALL < FOOTBALL: " << (BASEBALL < FOOTBALL) << endl << endl ; // False

    popularSport = SOCCER ;
    mySport = VOLLEYBALL ;

    cout << "popularSport < mySport: " << (popularSport < mySport) << endl ; 

    return 0 ; 
}