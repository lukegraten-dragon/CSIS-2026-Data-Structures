#include <iostream>

using namespace std ;

int main()
{
    int i, j ;

    for (i = 1; i <= 5; i++)      //Line 1
    {                             //Line 2

        for (j = 1; j <= i; j++)  //Line 3
            cout << "* " ;        //Line 4
    
        cout << endl ;            //Line 5
    }                             //Line 6

    return 0 ;
}