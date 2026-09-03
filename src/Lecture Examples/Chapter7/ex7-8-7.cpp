#include <iostream>

using namespace std ;

namespace Outer 
{
    namespace Inner 
    {
        int value = 10 ;
    }
}

// Nested Namespaces: Namespaces can be nested within other namespaces, 
// and you can use the scope resolution operator (::) to access members.

int main() 
{
    cout << "Inner namespace value: " << Outer::Inner::value << endl ;

    return 0 ;
}
