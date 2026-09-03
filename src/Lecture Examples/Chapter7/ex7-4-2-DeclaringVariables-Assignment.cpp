// variable declation and assignment
#include <iostream>

using namespace std ;

int main () 
{
    enum sports {BASKETBALL, FOOTBALL, HOCKEY, BASEBALL, SOCCER, VOLLEYBALL} ;

    sports popularSport ; 
    sports mySport ;

    popularSport = FOOTBALL ;
    cout << "popularSport = " << popularSport << endl ;

    mySport = popularSport ;
    cout << "mySport = " << mySport << endl ;

    return 0 ;
}