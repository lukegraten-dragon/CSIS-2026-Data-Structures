// typedef Statement
#include <iostream>

using namespace std ;

int main () 
{
    typedef int Boolean ;     //Line 1
    const Boolean True = 1 ;  //Line 2
    const Boolean False = 0 ; //Line 3
    
    Boolean flag ;            //Line 4

    flag = True ;             // Legal

    return 0 ;
}