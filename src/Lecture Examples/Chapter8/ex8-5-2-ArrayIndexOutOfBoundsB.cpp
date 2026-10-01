// Array Index Out of Bounds
#include <iostream> 

using namespace std ;

int main()
{
   	int list[2] ; 

    list[0] = 5 ;
    list[1] = 10 ;

    //In the following for loop, array index is out of bounds.
    for (int counter = 0; counter <= 2; counter++)
        cout << list[counter] << " " ;

    cout << endl ;

    return 0 ;
}

/*
Trying to access an index that doesn't exist in an array also causes an out of bound access violation.
Its a major memory safety issue and Sanitizers can help catch unseen memory safety violations.
*/