#include <iostream>

using namespace std ;

namespace MathOperations 
{
    int add(int a, int b) 
    {
        return a + b ;
    }
}

// The using declaration allows you to bring a specific name 
// from a namespace into the current scope, avoiding namespace 
// qualification for that identifier only.

using MathOperations::add;  // Only bringing add() into scope

int main() 
{
    int result = add(5, 3) ;
    cout << "Result: " << result << endl ;

    return 0 ;
}