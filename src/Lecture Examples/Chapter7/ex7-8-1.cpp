// Namespace
#include <iostream>

using namespace std ;

namespace globalType
{
    const int N = 10 ;
    const double RATE = 7.50 ;
    int count = 0 ;
}

int main () 
{
    cout << globalType::N << endl ;
    cout << globalType::RATE << endl ;
    cout << globalType::count << endl ;

    return 0 ;
}