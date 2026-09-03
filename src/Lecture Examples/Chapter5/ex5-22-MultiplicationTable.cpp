#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    int i, j ;

    for (i = 1; i <= 5; i++)           //Line 1
    {                                  //Line 2
        
        for (j = 1; j <= 10; j++)      //Line 3
            cout << setw(3) << i * j ; //Line 4
        
        cout << endl ;                 //Line 5
    }                                  //Line 6

    return 0 ;
}