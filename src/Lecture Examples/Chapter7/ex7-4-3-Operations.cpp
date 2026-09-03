// Operations on Enumeration Types
#include <iostream>

using namespace std ;

int main () 
{
    enum sports {BASKETBALL, FOOTBALL, HOCKEY, BASEBALL, SOCCER, VOLLEYBALL} ;

    sports popularSport ; 
    sports mySport ;

    popularSport = FOOTBALL ;

    mySport = popularSport ;
    
    // No arithmetic operations are allowed on the enumeration type. 
    // So the following statements are illegal.
    mySport = popularSport + 2 ;       //illegal
    popularSport = FOOTBALL + SOCCER ; //illegal
    popularSport = popularSport * 2 ;  //illegal

    // Also, the increment and decrement operations are not allowed 
    // on enumeration types. So the following statements are illegal.
    popularSport++ ; //illegal
    popularSport-- ; //illegal

    return 0 ;
}