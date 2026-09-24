#include <iostream>

using namespace std ;

int main()
{
    int i, j ;

    for (i = 1; i <= 5; i++)      //Line 1 // Run loop 5 times
    {                             //Line 2

        for (j = 1; j <= i; j++)  //Line 3 // Run nested loop based on main loop iteration value. (If i = 2, then the nested loop runs twice)
            cout << "* " ;        //Line 4
    
        cout << endl ;            //Line 5
    }                             //Line 6

    return 0 ;
}