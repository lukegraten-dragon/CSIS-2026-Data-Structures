// The following for loop prints the first 10 nonnegative integers:

#include <iostream>

using namespace std ;

int main()
{
    int i ;

    for (i = 1; i <= 5; i++)
    {
        cout << "Hello!" << endl ;
        cout << "*" << endl ;
    }
    
    cout << "================" << endl ;

    for (i = 1; i <= 5; i++)
        cout << "Hello!" << endl ;
        cout << "*" << endl ;

    return 0 ;
}