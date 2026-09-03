#include "unorderedArrayList.h"
#include <iostream>

using namespace std ;

int main()
{
    // Create two unordered array lists, one for int and one for double
    unorderedArrayList<int> intList(10) ;
    unorderedArrayList<double> doubleList(10) ;

    // Insert elements into the int list
    intList.insertEnd(5) ;
    intList.insertEnd(10) ;
    intList.insertEnd(15) ;

    // Display the elements of the int list
    cout << "Int List after inserting elements at the end: " ;
    intList.print() ;  // Output: 5 10 15

    // Insert an element at index 1 in the int list
    intList.insertAt(1, 20) ;
    cout << "Int List after inserting 20 at index 1: " ;
    intList.print() ;  // Output: 5 20 10 15

    // Remove an element from the int list (value = 10)
    intList.remove(10) ;
    cout << "Int List after removing 10: " ;
    intList.print() ;  // Output: 5 20 15

    // Insert more elements at the end of the int list
    intList.insertEnd(25) ;
    intList.insertEnd(30) ;
    cout << "Int List after inserting more elements at the end: " ;
    intList.print() ;  // Output: 5 20 15 25 30

    // Clear the int list
    intList.clearList() ;
    cout << "Int List after clearing: " ;
    intList.print() ;  // Output: List is empty

    // Insert elements into the double list
    doubleList.insertEnd(5.5) ;
    doubleList.insertEnd(10.1) ;
    doubleList.insertEnd(15.75) ;

    // Display the elements of the double list
    cout << "Double List after inserting elements at the end: " ;
    doubleList.print() ;  // Output: 5.5 10.1 15.75

    // Insert an element at index 1 in the double list
    doubleList.insertAt(1, 20.22) ;
    cout << "Double List after inserting 20.22 at index 1: " ;
    doubleList.print() ;  // Output: 5.5 20.22 10.1 15.75

    // Remove an element from the double list (value = 10.1)
    doubleList.remove(10.1) ;
    cout << "Double List after removing 10.1: " ;
    doubleList.print() ;  // Output: 5.5 20.22 15.75

    // Insert more elements at the end of the double list
    doubleList.insertEnd(25.5) ;
    doubleList.insertEnd(30.75) ;
    cout << "Double List after inserting more elements at the end: " ;
    doubleList.print() ;  // Output: 5.5 20.22 15.75 25.5 30.75

    // Clear the double list
    doubleList.clearList() ;
    cout << "Double List after clearing: " ;
    doubleList.print() ;  // Output: List is empty

    return 0 ;
}
