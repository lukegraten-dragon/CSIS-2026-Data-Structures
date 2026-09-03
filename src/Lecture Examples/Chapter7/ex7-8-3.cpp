#include <iostream>

using namespace std ;

namespace MyNamespace 
{
    int value = 42 ;
    void display() {
        cout << "Value in MyNamespace: " << value << endl ;
    }
}

namespace AnotherNamespace 
{
    int value = 99 ;
    void display() 
    {
        cout << "Value in AnotherNamespace: " << value << endl ;
    }
}

// Preventing Name Conflicts: In large programs or when using third-party 
// libraries, different code segments may use the same identifier names. 
// A namespace ensures that these names do not clash.

int main() 
{
    MyNamespace::display() ;      // Calls display() from MyNamespace
    AnotherNamespace::display() ; // Calls display() from AnotherNamespace

    return 0 ;
}

