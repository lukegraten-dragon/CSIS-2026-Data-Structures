// The following for loop prints the first 10 nonnegative integers:

#include <iostream>

using namespace std ;

int main()
{
    int i ;

    for (i = 1; i <= 5; i++)
    {
        cout << "Hello!" << endl ; // Print these statements 5 times
        cout << "*" << endl ;
    }
    
    cout << "================" << endl ;

    // Scope is implied even if we don't explicitly declare curly braces. Good practice to use curly braces to know where a certain scope begins and ends.
    for (i = 1; i < 5; i++)
        cout << "Hello!" << endl ;
        cout << "*" << endl ;

    return 0 ;
}