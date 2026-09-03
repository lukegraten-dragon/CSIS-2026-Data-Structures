#include <iostream>

using namespace std ;
 
int main()   
{  
    const double CONVERSION = 2.54 ;
    const int NO_OF_STUDENTS = 20 ;
    const char BLANK = ' ' ;


    // NOTE: Will crash program at runtime since constants are immutable
    //NO_OF_STUDENTS = 21 ;


    // Extra cout statements to avoid compiler warnings about unused variables
    cout << "NOTE: This is extra stuff so the program compiles." << '\n' ;
    cout << "CONVERSION = " << CONVERSION << '\n' ;
    cout << "NO_OF_STUDENTS = " << NO_OF_STUDENTS << '\n' ;
    cout << "BLANK = " << BLANK << '\n' ;
    return 0 ;
}