#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std ;

// Functor class for ascending order
class AscendingOrder
{
public:
    bool operator()(int a, int b) const
    {
        return a < b ; // Returns true if a should appear before b
    }
} ;

// Functor class for descending order
class DescendingOrder
{
public:
    bool operator()(int a, int b) const
    {
        return a > b ; // Returns true if a should appear before b
    }
} ;

int main()
{
    // Initialize a vector with some values
    vector<int> numbers = {40, 10, 30, 20, 50} ;

    // Display the original vector
    cout << "Original vector: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Sort the vector in ascending order using the AscendingOrder functor
    sort(numbers.begin(), numbers.end(), AscendingOrder()) ;
    cout << "Sorted in ascending order: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Sort the vector in descending order using the DescendingOrder functor
    sort(numbers.begin(), numbers.end(), DescendingOrder()) ;
    cout << "Sorted in descending order: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    return 0 ;
}
