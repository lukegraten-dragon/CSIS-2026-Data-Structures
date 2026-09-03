// You can increment (or decrement) the loop control variable 
// by any fixed number. In the following for loop, the variable 
// is initialized to 1; at the end of the for loop, i is incremented by 2.

#include <iostream>

using namespace std ;

int main()
{
    int i ;

    for (i = 1; i <= 20; i = i + 2)
        cout << " " << i ;
    cout << endl ;

    return 0 ;
}