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

    // Outer::Inner accesses the nested namespace. Though nested namespaces
    // aren't a good practice.
    return 0 ;
}
