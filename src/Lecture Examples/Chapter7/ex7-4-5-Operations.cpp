// Operations on Enumeration Types
#include <iostream>

using namespace std ;

int main () 
{
    enum sports {BASKETBALL, FOOTBALL, HOCKEY, BASEBALL, SOCCER, VOLLEYBALL} ;

    sports popularSport ; 

    popularSport = FOOTBALL ;

    // Suppose you want to increment the value of popularSport by 1. 
    // You can use the cast operator as follows:
    popularSport = static_cast<sports>(popularSport - 1) ;
    cout << "" << popularSport << endl ;

    return 0 ; 
}