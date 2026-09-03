#include <iostream> 

using namespace std ;

int main()
{
    int num ; // 5, 20, -10
    
    // Sometimes logical expressions do not behave as you might expect.

    cout << "Enter an integer: " ;
    cin >> num ;
    cout << endl ;

    if (0 <= num <= 10) // 0 <= 5 <= 10 --> (0 <= 5) <= 10 --> 1 <= 10 --> 1
    // if (0 <= num && num <= 10)
        cout << num << " is within 0 and 10." << endl ;
    else
        cout << num << " is not within 0 and 10." << endl ;

    return 0 ;
}