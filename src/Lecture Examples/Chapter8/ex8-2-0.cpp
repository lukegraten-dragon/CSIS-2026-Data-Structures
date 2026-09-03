// Accessing Array Components
#include <iostream>

using namespace std ;

int main()
{
    // The general form (syntax) used for accessing an array component is:
    // arrayName[indexExp]
    // in which indexExp, called the 'index', is any expression whose value 
    // is a nonnegative integer. The index value specifies the position of 
    // the component in the array.
    // In C++, [] is an operator called the 'array subscripting operator'. 
    // Moreover, in C++, the array index starts at 0

    int list[10] ;

    list[5] = 34 ;
    list[3] = 63 ; // is equivalent to i = 3 ; list[i] = 63 ;

    list[3] = 10 ;
    list[6] = 35 ;
    list[5] = list[3] + list[6] ;

    cout << "list[3]: " << list[3] << endl
         << "list[6]: " << list[6] << endl
         << "list[5]: " << list[5] << endl ;

    int i = 4 ;
    list[2 * i - 3] = 58 ;

    cout << "i: " << i << endl 
         << "list[2 * i - 3]: " << list[2 * i - 3] << endl ;
}