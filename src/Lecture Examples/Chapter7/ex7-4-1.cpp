#include <iostream>

using namespace std ;

int main () 
{
    // Suppose that these statements are in the same program in the same block. 
    // The second enumeration type, compStudent, is not allowed because 
    // the value JOHN was used in the previous enumeration type mathStudent.
    enum mathStudent {JOHN, BILL, CINDY, LISA, RON} ;
    enum compStudent {SUSAN, CATHY, JOHN, WILLIAM} ; //illegal
    
    return 0 ;
}