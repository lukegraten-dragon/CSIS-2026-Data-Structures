#include <iostream>
#include <vector>
#include <list>

using namespace std ;

int main()
{
    // Initialize a vector
    vector<int> numbers = {10, 20, 30, 40, 50} ;

    // Using a standard iterator to traverse the vector
    cout << "Vector elements (using iterator): " ;
    for (vector<int>::iterator it = numbers.begin() ; it != numbers.end() ; ++it)
    {
        cout << *it << " " ;
    }
    cout << endl ;

    // Modifying elements using an iterator
    cout << "Modifying vector elements by multiplying by 2: " ;
    for (vector<int>::iterator it = numbers.begin() ; it != numbers.end() ; ++it)
    {
        *it *= 2 ; // Modify the element
        cout << *it << " " ;
    }
    cout << endl ;

    // Using a reverse iterator to traverse the vector
    cout << "Vector elements (using reverse iterator): " ;
    for (vector<int>::reverse_iterator rit = numbers.rbegin() ; rit != numbers.rend() ; ++rit)
    {
        cout << *rit << " " ;
    }
    cout << endl ;

    // Initialize a list
    list<string> words = {"Hello", "World", "STL", "Iterators"} ;

    // Using a constant iterator to traverse the list
    cout << "List elements (using const iterator): " ;
    for (list<string>::const_iterator it = words.cbegin() ; it != words.cend() ; ++it)
    {
        cout << *it << " " ; // Cannot modify elements with const_iterator
    }
    cout << endl ;

    // Using an iterator to insert elements into the list
    auto it = words.begin() ;
    advance(it, 2) ; // Move iterator to the third position
    words.insert(it, "C++") ; // Insert "C++" before "STL"

    cout << "List elements after insertion: " ;
    for (list<string>::iterator lit = words.begin() ; lit != words.end() ; ++lit)
    {
        cout << *lit << " " ;
    }
    cout << endl ;

    return 0 ;
}
