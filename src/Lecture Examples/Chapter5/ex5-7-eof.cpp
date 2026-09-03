// The following code uses an EOF-controlled 
// while loop to find the sum of a set of numbers:

#include <iostream>

using namespace std ;

int main()
{
    int sum = 0;
    int num;

    cin >> num;

    // Until the input reaches EOF (usually triggered 
    // by pressing Ctrl + D on Linux
    // by pressing Ctrl + Z on Windows
    while (cin)
    {
        sum = sum + num ; //Add the number to sum
        cin >> num ;      //Get the next number
    }

    cout << "Sum = " << sum << endl ;
    
    return 0 ;
}