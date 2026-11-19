#include <iostream>
#include <queue> // For queue

using namespace std ;

int main()
{
    // Declare a queue of integers
    queue<int> numbers ;

    // Adding elements to the queue using push()
    numbers.push(10) ; // Add 10 to the queue
    numbers.push(20) ; // Add 20 to the queue
    numbers.push(30) ; // Add 30 to the queue

    // Display the front and back elements of the queue
    cout << "Front element: " << numbers.front() << endl ;
    cout << "Back element: " << numbers.back() << endl ;

    // Removing an element from the queue using pop()
    numbers.pop() ; // Removes the front element (10)
    cout << "After popping, front element: " << numbers.front() << endl ;

    // Add more elements to the queue
    numbers.push(40) ; // Add 40 to the queue
    numbers.push(50) ; // Add 50 to the queue

    // Display all elements by removing them one by one
    cout << "Queue elements (from front to back): " ;
    while (!numbers.empty())
    {
        cout << numbers.front() << " " ; // Display the front element
        numbers.pop() ;                  // Remove the front element
    }
    cout << endl ;

    // Check if the queue is empty
    if (numbers.empty())
    {
        cout << "The queue is now empty." << endl ;
    }
    else
    {
        cout << "The queue is not empty." << endl ;
    }

    return 0 ;
}
