// Array Initialization during Declaration
#include <iostream> 

using namespace std ;

int main()
{
   	double sales[5] = {12.25, 32.50, 16.90, 23, 45.68} ;

    // The number of elements in the array
    cout << "1. size(sales): " << size(sales) << endl ;
    cout << "2. (sizeof(sales) / sizeof(sales[0])): " << (sizeof(sales) / sizeof(sales[0])) << endl << endl ;

    for (int i = 0; i < size(sales); i++)
        cout << sales[i] << endl ;
    cout << endl ;

    // Although it is not necessary to specify the size of the array 
    // if it is initialized during declaration, it is a good practice to do so.
    double sales2[] = {12.25, 32.50, 16.90, 23, 45.68} ;

    for (int i = 0; i < size(sales2); i++)
        cout << sales2[i] << endl ;

    return 0 ;
}
