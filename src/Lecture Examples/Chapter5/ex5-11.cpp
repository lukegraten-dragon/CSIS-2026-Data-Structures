#include <iostream>

using namespace std ;

int main()
{
    int i ;

    for (i = 0; i < 5; i++) ; //Line 1
        cout << "*" << endl ; //Line 2

    return 0 ;
}
// The semicolon at the end of the for statement (before 
// the output statement, Line 1) terminates the for loop. 
// The action of this for loop is empty, that is, null.
