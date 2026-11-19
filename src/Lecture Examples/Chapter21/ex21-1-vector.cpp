#include <iostream>
#include <vector>
#include <algorithm> // For sort

using namespace std ;

int main()
{
    // Declare a vector of integers
    vector<int> numbers ;

    // Adding elements to the vector using push_back
    numbers.push_back(10) ; // Add 10
    numbers.push_back(5) ;  // Add 5
    numbers.push_back(20) ; // Add 20
    numbers.push_back(15) ; // Add 15

    // Display the original vector
    cout << "Original vector: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Accessing elements using index
    cout << "Element at index 2: " << numbers[2] << endl ;

    // Inserting an element at a specific position
    numbers.insert(numbers.begin() + 2, 25) ; // Insert 25 at index 2
    cout << "After inserting 25 at index 2: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Removing an element at a specific position
    numbers.erase(numbers.begin() + 3) ; // Remove element at index 3
    cout << "After removing element at index 3: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Sorting the vector in ascending order
    sort(numbers.begin(), numbers.end()) ;
    cout << "Sorted vector: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Reversing the vector order
    reverse(numbers.begin(), numbers.end()) ;
    cout << "Reversed vector: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Display the size of the vector
    cout << "Size of the vector: " << numbers.size() << endl ;

    // Clearing all elements in the vector
    numbers.clear() ; // Remove all elements
    cout << "After clearing, size of the vector: " << numbers.size() << endl ;

    return 0 ;
}
