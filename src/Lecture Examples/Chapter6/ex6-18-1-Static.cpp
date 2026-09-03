//Program: Static and automatic variables
#include <iostream>
   
using namespace std ; 

void test() ; 

int main()
{
    int count ;

    for (count = 1; count <= 5; count++)
        test() ;
	
    return 0 ;
}

// A variable for which memory is allocated at block entry and deallocated at block exit
// is called an automatic variable. A variable for which memory remains allocated as
// long as the program executes is called a static variable. Global variables are static
// variables, and by default, variables declared within a block are automatic variables.
// You can declare a static variable within a block by using the reserved word static.
void test()
{
    static int x = 0 ;
    int y = 10 ;

    x = x + 2 ;
    y = y + 1 ;
	
    cout << "Inside test x = " << x << " and y = "
         << y << endl ;
}
