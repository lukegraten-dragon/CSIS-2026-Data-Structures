#include <iostream>

using namespace std ;

namespace MathOperations 
{
    int add(int a, int b) 
    {
        return a + b ;
    }
}

// Defining and Using Namespaces: You can define your own namespace 
// using the namespace keyword. Inside the namespace, you can declare 
// variables, functions, classes, etc. To access them, you must prefix 
// them with the namespace name (e.g., MyNamespace::variable).

int main() 
{
    int result = MathOperations::add(5, 3) ;
    cout << "Result: " << result << endl ;

    return 0 ;
}
