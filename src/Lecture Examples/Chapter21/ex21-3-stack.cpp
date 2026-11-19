#include <iostream>
#include <stack> // For stack

using namespace std ;

int main()
{
    // Declare a stack of integers
    stack<int> numbers ;

    // Adding elements to the stack using push()
    numbers.push(10) ; // Push 10 onto the stack
    numbers.push(20) ; // Push 20 onto the stack
    numbers.push(30) ; // Push 30 onto the stack

    // Display the top element of the stack
    cout << "Top element: " << numbers.top() << endl ;

    // Pop an element from the stack
    numbers.pop() ; // Removes the top element (30)
    cout << "After popping, top element: " << numbers.top() << endl ;

    // Push more elements onto the stack
    numbers.push(40) ; // Push 40 onto the stack
    numbers.push(50) ; // Push 50 onto the stack

    // Display all elements by popping the stack until empty
    cout << "Stack elements (from top to bottom): " ;
    while (!numbers.empty())
    {
        cout << numbers.top() << " " ; // Display the top element
        numbers.pop() ;               // Remove the top element
    }
    cout << endl ;

    // Check if the stack is empty
    if (numbers.empty())
    {
        cout << "The stack is now empty." << endl ;
    }
    else
    {
        cout << "The stack is not empty." << endl ;
    }

    return 0 ;
}
