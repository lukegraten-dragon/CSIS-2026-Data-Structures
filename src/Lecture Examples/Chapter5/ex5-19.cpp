#include <iostream>

using namespace std ;

int main()
{
    int i ;

    // The while loop produces nothing, the statement never executes.
    cout << "While Loop started." << endl ;
    i = 11 ;
    while (i <= 10)
    {
        cout << i << " " ;
        i = i + 5 ;
    }
    cout << endl << "While Loop ended." << endl << endl ;

    // The do...while loop outputs the number 11 and also changes the value of i to 16. 
    // This is expected because in a do...while, the statement must always execute at least once.
    cout << "Do...While Loop started." << endl ;
    i = 11 ;
    do
    {
        cout << i << " " ;
        i = i + 5 ;
    }
    while (i <= 10) ;

    cout << endl << "Do...While Loop ended." << endl << endl ;

    return 0 ;
}