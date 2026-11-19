#include <iostream>
#include <list>
#include <algorithm> // For sort

using namespace std ;

int main()
{
    // Declare a list of integers
    list<int> numbers ;

    // Adding elements to the list using push_back
    numbers.push_back(10) ; // Add 10 to the end
    numbers.push_back(5) ;  // Add 5 to the end
    numbers.push_back(20) ; // Add 20 to the end
    numbers.push_back(15) ; // Add 15 to the end

    // Display the original list
    cout << "Original list: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Adding elements to the front of the list using push_front
    numbers.push_front(25) ; // Add 25 to the front
    cout << "After adding 25 to the front: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Removing elements from the list
    numbers.pop_back() ; // Remove the last element
    numbers.pop_front() ; // Remove the first element
    cout << "After removing front and back elements: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Sorting the list in ascending order
    numbers.sort() ;
    cout << "Sorted list: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Reversing the list
    numbers.reverse() ;
    cout << "Reversed list: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Insert an element at a specific position
    auto it = numbers.begin() ;
    advance(it, 2) ; // Move iterator to the third position
    numbers.insert(it, 50) ; // Insert 50 at the third position
    cout << "After inserting 50 at the third position: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Erase an element at a specific position
    it = numbers.begin() ;
    advance(it, 1) ; // Move iterator to the second position
    numbers.erase(it) ; // Erase the element at the second position
    cout << "After erasing the second element: " ;
    for (int num : numbers)
    {
        cout << num << " " ;
    }
    cout << endl ;

    // Clearing all elements in the list
    numbers.clear() ;
    cout << "After clearing, size of the list: " << numbers.size() << endl ;

    return 0 ;
}
