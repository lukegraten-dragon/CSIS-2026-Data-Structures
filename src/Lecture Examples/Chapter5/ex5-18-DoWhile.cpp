#include <iostream>

using namespace std ;

int main()
{
    int i = 0 ;

    do // Runs the body regardless of whether the condition is true for the first iteration.
    {
        cout << i << " " ;
        i = i + 5 ;
    }
    while (i <= 20) ; // Will run the loop again if the condition is true

    cout << endl ;

    return 0 ;
}