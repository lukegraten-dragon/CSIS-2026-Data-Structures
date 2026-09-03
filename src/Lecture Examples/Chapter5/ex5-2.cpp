#include <iostream>

using namespace std ;

int main()
{
    int i = 20 ;           //Line 1

    while (i < 20)         //Line 2
    {                      //Line 3
        cout << i << " " ; //Line 4
        i = i + 5 ;        //Line 5
    }                      //Line 6
    cout << endl ;         //Line 7
    
    return 0 ;
}