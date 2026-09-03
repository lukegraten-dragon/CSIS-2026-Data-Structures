// Range-Based For Loops
//

// 1. Basic Form:

//     for (declaration : container) {
//         // body of the loop
//     }
//     - declaration: This can be a variable, reference, or auto.
//     - container: Any iterable container like arrays, vectors, or maps.
//
// 2. Modifying Elements: To modify elements within the container, 
//    use a reference (auto& or the specific type like int&).
// 3. Const References: Use const auto& to avoid copying elements 
//    when you don't need to modify them.

#include <iostream>

using namespace std ;

int main() 
{
    int arr[] = {10, 20, 30, 40, 50} ;

    // Basic Usage with Arrays:
    cout << "Array elements: " ;
    for (int x : arr)  // x is a copy of each element
    {
        cout << x << " " ;
    }
    cout << endl ;

    // Using auto declaration
    cout << "Array elements: " ;
    for (auto x : arr)
    {
        cout << x << " " ;
    }
    cout << endl ;

    // sum of all elements in arr
    int sum = 0 ;
    for (int x : arr)
        sum = sum + x ;
    cout << "sum of all element in arr: " << sum << endl ;

    // Modifying Elements Using References
    cout << "Array elements: " ;
    for (auto& x : arr)
    {
        x = x * 2 ;
    }
    for (const auto& x : arr)
    {
        cout << x << " " ;
    }
    cout << endl ;

    // Range-Based For Loop with Strings
    string str = "Hello, world!" ;

    cout << "Characters in the string: " ;
    for (char ch : str) {  // iterate over each character in the string
        cout << ch << " " ;
    }
    cout << endl ;

    // Range-Based For Loop with Const Values
    cout << "Array elements (const): ";
    for (const int& num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0 ;
}
