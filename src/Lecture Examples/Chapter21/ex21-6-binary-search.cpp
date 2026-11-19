#include <iostream>
#include <vector>
#include <algorithm> // For sort and binary_search

using namespace std ;

int main()
{
    // Initialize a vector with unsorted elements
    vector<int> numbers = {40, 10, 30, 20, 50} ;

    // Display the original vector
    cout << "Original vector: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Sorting the vector (required for binary_search)
    sort(numbers.begin(), numbers.end()) ;
    cout << "Sorted vector: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Search for an element using binary_search
    int value_to_search = 30 ;
    bool found = binary_search(numbers.begin(), numbers.end(), value_to_search) ;

    if (found)
    {
        cout << "Element " << value_to_search << " found in the vector." << endl ;
    }
    else
    {
        cout << "Element " << value_to_search << " not found in the vector." << endl ;
    }

    // Search for an element not in the vector
    value_to_search = 60 ;
    found = binary_search(numbers.begin(), numbers.end(), value_to_search) ;

    if (found)
    {
        cout << "Element " << value_to_search << " found in the vector." << endl ;
    }
    else
    {
        cout << "Element " << value_to_search << " not found in the vector." << endl ;
    }

    return 0 ;
}
