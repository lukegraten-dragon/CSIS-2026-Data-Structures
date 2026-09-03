#include <iostream>

using namespace std ;

void swap1(int a, int b) ;
void swap2(int& a, int& b) ;

int main()
{
    int a = 2 ;
    int b = 19 ;

    cout << "*** Call by Value" << endl  
         << "Before calling swap1()" << endl 
         << "a = " << a << endl
         << "b = " << b << endl << endl ;

    swap1(a, b) ;

    cout << "After calling swap1()" << endl 
         << "a = " << a << endl
         << "b = " << b << endl << endl ;
    
    cout << "*** Call by Reference" << endl  
         << "Before calling swap2()" << endl 
         << "a = " << a << endl
         << "b = " << b << endl << endl ;

    swap2(a, b) ;

    cout << "After calling swap2()" << endl 
         << "a = " << a << endl
         << "b = " << b << endl << endl ;

    return 0 ;
}

// Call by Value
void swap1(int a, int b)
{
    int tmp = a ;
    a = b ;
    b = tmp ;
}

// Call by Reference
void swap2(int& a, int& b)
{
    int tmp = a ;
    a = b ;
    b = tmp ;
}


