#include <iostream>

using namespace std ;

int main () 
{
    // This program defines standing to be an enumeration type. 
    // The values belonging to standing are FRESHMAN, SOPHOMORE, 
    // JUNIOR, and SENIOR.
    enum standing {FRESHMAN, SOPHOMORE, JUNIOR, SENIOR} ;

    cout << SOPHOMORE << '\n' ;
    return 0 ;
}