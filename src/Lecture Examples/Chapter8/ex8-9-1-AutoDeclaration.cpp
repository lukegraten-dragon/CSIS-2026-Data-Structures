// Auto Declaration
#include <iostream>
#include <iomanip>

using namespace std ;

int main() 
{
    auto a = 10 ;         // deduces 'int'
    auto b = 3.14 ;       // deduces 'double'
    auto c = 'x' ;        // deduces 'char'
    auto d = true ;       // deduces 'bool'

    // Auto acts like a dynamic type checker that can attepmt to infer the expected data type of a value. 
    // Can be helpful when we don't know the data types in advance for certain variables. But it 
    // tends to reduce program optimization, so use sparingly.

    cout << "a: " << setw(4) << a 
         << ", sizeof(a): " << sizeof(a)
         << ", type of a: " << typeid(a).name() << endl ;
    cout << "b: " << setw(4) << b 
         << ", sizeof(b): " << sizeof(b)
         << ", type of b: " << typeid(b).name() << endl ;
    cout << "c: " << setw(4) << c 
         << ", sizeof(c): " << sizeof(c)
         << ", type of c: " << typeid(c).name() << endl ;
    cout << "d: " << setw(4)<< d 
         << ", sizeof(d): " << sizeof(d)
         << ", type of d: " << typeid(d).name() << endl ;
    return 0 ;
}

