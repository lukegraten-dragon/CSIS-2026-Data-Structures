// Arrays as Parameters to Functions
#include <iostream> 

using namespace std ;

void initialize(int list[], int listSize) ; // Arrays as parameters turn into pointers we can interate on.

int main()
{
    int num[3] = {1, 2, 3} ;

    // Before passing num to initialize()
    for (int i = 0; i < 3; i++)
        cout << num[i] << endl ;

    initialize(num, 3) ;

    // After passing num to initialize()
    for (int i = 0; i < 3; i++)
        cout << num[i] << endl ;

    return 0 ;
}

void initialize(int list[], int listSize) // An array is passed as a pointer when being used a parameter, so no & is needed.
{
    for (int count = 0; count < listSize; count++)
        list[count] = 0 ;
}
