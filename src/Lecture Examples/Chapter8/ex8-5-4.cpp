// Array Initialization during Declaration
#include <iostream> 

using namespace std ;

int main()
{
    int list[10] = {0} ;
    // int list[10] = {8, 5, 12} ;
    // int list[] = {5, 6, 3} ;
    // int list[25] = {4, 7} ;

    for (int i = 0; i < size(list); i++)
        cout << list[i] << endl ;

    return 0 ;
}