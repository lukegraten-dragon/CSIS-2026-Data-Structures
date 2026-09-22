// You can count backward using a for loop if the for loop 
// control expressions are set correctly.
#include <iostream>

using namespace std ;

int main()
{
    int i ;

    for (i = 10; i >= 1; i--) // Decrements loop variable. But same functionality as before.
        cout << " " << i ;
    cout << endl ;

    return 0 ;
}