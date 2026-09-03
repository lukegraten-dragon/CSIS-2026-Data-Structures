// typedef Statement
#include <iostream>
#include <typeinfo>

using namespace std ;

int main () 
{
    typedef    int _integer ;
    typedef double _double ;

    _integer x = 518 ;
    _double y = 12.12 ;

    cout << x << endl ;
    cout << "Type of x: " << typeid(x).name() << endl << endl ;
    
    cout << y << endl ;
    cout << "Type of y: " << typeid(y).name() << endl ;

    return 0 ;
}