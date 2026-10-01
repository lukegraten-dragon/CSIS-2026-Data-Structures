// Namespace
#include <iostream>

using namespace std ;

namespace globalType
{
    /*
    Nampespace members that can be called outside
    the namespace via
    globalType::varName
    */
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