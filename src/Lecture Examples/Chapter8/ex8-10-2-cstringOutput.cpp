// csting output
#include <iostream> 

using namespace std ;

int main() 
{
    char name[] = {'a', 'b', 'c', 'd', 'e'} ;
    //char name[] = {'a', 'b', 'c', 'd', 'e', '\0'} ;

    cout << name << endl ;
    // outputs the contents of name on the screen. The insertion operator, 
    // <<, continues to write the contents of name until it finds the null 
    // character. Thus, if the length of name is 4, the above statement 
    // outputs only four characters. If name does not contain the null character,
    // then you will see strange output because the insertion operator continues 
    // to output data from memory adjacent to name until a '\0' is found. 
    // For example, see the output of the following program. 
    // (Note that on your computer, you may get a different output.)

    return 0 ;
}
