#include "unorderedArrayList.h"
#include <iostream>

using namespace std;

int main()
{
    // Create an unordered array list with a maximum size of 10
    unorderedArrayList myList(10) ;

    // Insert elements at the end of the list
    myList.insertEnd(5) ;
    myList.insertEnd(10) ;
    myList.insertEnd(15) ;

    // Display the elements of the list
    cout << "List after inserting elements at the end: " ;
    myList.print() ;  // Output: 5 10 15

    // Insert an element at index 1
    myList.insertAt(1, 20) ;
    cout << "List after inserting 20 at index 1: " ;
    myList.print() ;  // Output: 5 20 10 15

    // Remove an element from the list (value = 10)
    myList.remove(10) ;
    cout << "List after removing 10: " ;
    myList.print() ;  // Output: 5 20 15

    // Attempt to remove an element not in the list (value = 100)
    myList.remove(100) ;  // Output: Item not found in the list.

    // Insert more elements at the end
    myList.insertEnd(25) ;
    myList.insertEnd(30) ;
    cout << "List after inserting more elements at the end: " ;
    myList.print() ;  // Output: 5 20 15 25 30

    // Attempt to insert at an invalid index
    myList.insertAt(100, 40) ;  // Output: The position of the item to be inserted is out of range.

    // Clear the list
    myList.clearList() ;
    cout << "List after clearing: " ;
    myList.print() ;  // Output: List is empty.

    return 0 ;
}
