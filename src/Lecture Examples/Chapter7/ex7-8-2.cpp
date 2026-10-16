// Namespace
#include <iostream>

using namespace std ;

namespace globalType
{
    const int N = 10 ;
    const double RATE = 7.50 ;
    int count = 0 ;
}

using namespace globalType ;

int main () 
{
    cout << N << endl ;
    cout << RATE << endl ;

    // Use the scope resolution operator to fix
    // ambiguity between differing namespace
    cout << globalType::count << endl ;

    return 0 ;
}