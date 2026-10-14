// Array Initialization during Declaration
#include <iostream> 

using namespace std ;

int main()
{
    int list[10] = {0} ; // Initializes/fills array elements during array declartion
    // int list[10] = {8, 5, 12} ;
    // int list[] = {5, 6, 3} ;
    // int list[25] = {4, 7} ;

    for (int i = 0; i < size(list); i++)
        cout << list[i] << endl ;

    cout << size(list) << '/n' ;
    return 0 ;
}

/*
size() and sizeof() aren't the same function. The former returns the amount of elements in an array while the
latter will return the filesize of the array and cause an out of bounds violation.
*/