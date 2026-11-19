/*
===============================================================================
CHAPTER 17 - EXAMPLE 17-2: STACK USING A SINGLY LINKED LIST (REVISED)
===============================================================================

1. STACK ABSTRACT DATA TYPE (ADT) - LIFO

    LIFO = Last In, First Out.
    The most recently pushed value is the first value removed by pop().

    Example: push(10), push(20), push(30)

    topNode (TOP)
       |
       v
    +------+-------+     +------+-------+     +------+---------+
    |  30  | next -+---->|  20  | next -+---->|  10  | nullptr |
    +------+-------+     +------+-------+     +------+---------+

    Last In             Second In            First In
    First Out

    Stack order (TOP to BOTTOM): 30 -> 20 -> 10 -> nullptr
    pop() removes 30 first. peek() reads 30 without removing it.

2. HOW EXAMPLE 17-2 DIFFERS FROM EXAMPLE 17-1

   Example 17-1 (Array Stack):
     - Stores values in one dynamically allocated int array.
     - Uses an integer topIndex; an empty stack has topIndex == -1.
     - push() increments topIndex, then stores an element in the array.
     - pop() decrements topIndex but does not delete an array element.

   Example 17-2 (Linked List Stack):
     - Stores each value in a separately allocated node.
     - Uses node* topNode; an empty stack has topNode == nullptr.
     - push() allocates a new node and links it before the old top.
     - pop() moves topNode and deletes the removed node.
     - Uses currentSize to enforce the maxSize limit in this example.

   IMPORTANT: Both implementations provide the same LIFO behavior.
   The external operations are similar; the internal representation differs.

3. REVISED API USED THROUGHOUT CHAPTER 17

   initialize()  : Remove all items and make the stack empty.
   isEmpty()     : True if there is no top node.
   isFull()      : True if currentSize has reached maxSize.
   push(value)   : Add one value at the top.
   pop()         : Remove the top node (does not return its data).
   peek()        : Return the top value without removing it.
   display()     : Print from top to bottom.

   Note: The C++ standard library std::stack uses top(), not peek().
   This is a custom instructional stack class, not std::stack.
*/
#include <iostream>
using namespace std ;

/*
===============================================================================
NODE STRUCTURE
===============================================================================

One linked-list node stores an int and a pointer to the next node:

              +-------------+-----------------+
     node --> | data = 20   | next = address  |
              +-------------+-----------------+

   data : Actual value stored in the stack.
   next : Address of the node immediately below this node.
          The bottom node's next is nullptr.

The default constructor initializes a new node as:

              +-------------+-----------------+
              | data = 0    | next = nullptr  |
              +-------------+-----------------+

After allocating a node, push() replaces its default data value and
sets next to the current top node.

The arrow operator (->) accesses members through a node pointer:

   newNode->data          // data member of the node
   newNode->next          // next pointer of the node
*/
// Node class to represent each element in the stack
class node
{
public:
    int data ;
    node* next ;

    // Default constructor
    node()
    {
        data = 0 ;
        next = nullptr ;
    }
} ;

/*
===============================================================================
STACK DATA MEMBERS AND INVARIANTS
===============================================================================

   topNode     : Points to the top node; nullptr when the stack is empty.
   maxSize     : The maximum permitted number of nodes in this example.
   currentSize : The number of nodes currently stored.

   Example after pushing 10, 20, and 30 into stack(5):

       topNode                           currentSize = 3
          |                              maxSize     = 5
          v
        [30] -> [20] -> [10] -> nullptr

   Expected invariants for valid operations:

       0 <= currentSize <= maxSize
       currentSize == 0  <=>  topNode == nullptr

   Unlike an unbounded linked-list stack, THIS implementation has a
   fixed logical capacity. It creates nodes as needed up to maxSize.

   IMPORTANT: topNode is a POINTER to a node, not an array index.
   The separate traversal pointer used by display() does not move topNode.
*/
class stack
{
private:
    node* topNode ;   // Pointer to the top node in the stack
    int maxSize ;     // Maximum size of the stack
    int currentSize ; // Current number of elements in the stack

public:
    /*
    ---------------------------------------------------------------------------
    CONSTRUCTOR: stack(int size)
    ---------------------------------------------------------------------------

       stack myStack(5);

       topNode     = nullptr      (no nodes have been allocated)
       maxSize     = 5
       currentSize = 0

       Picture:

             topNode ----> nullptr
             currentSize = 0

    Unlike the array-based stack, the constructor does NOT allocate
    an array or any nodes. A node is allocated on each successful push().

    Teaching limitation: This example assumes size is a positive integer;
    it does not validate size <= 0.
    */
    // Constructor to initialize an empty stack with a specified size
    stack(int size)
    {
        topNode = nullptr ;
        maxSize = size ;
        currentSize = 0 ;
    }

    /*
    ---------------------------------------------------------------------------
    DESTRUCTOR: ~stack()
    ---------------------------------------------------------------------------

    For a local object such as `stack myStack(5);`, C++ automatically
    calls the destructor when the object goes out of scope.

    Each pop() deletes one top node:

       Before: topNode -> [30] -> [20] -> [10] -> nullptr
       pop():         delete [30]
       Then:   topNode -> [20] -> [10] -> nullptr
       pop():         delete [20]
       Then:   topNode -> [10] -> nullptr
       pop():         delete [10]
       After:  topNode -> nullptr

    Time Complexity: O(n), where n is the number of remaining nodes.

    Compare with 17-1: the int array is released with delete[] once.
    The linked-list stack must delete each separately allocated node.

    IMPORTANT - RULE OF THREE:
       This class owns dynamically allocated nodes and has a destructor,
       but does not implement a copy constructor or copy assignment.
       The compiler-generated copy operations would copy topNode only,
       causing two stack objects to share nodes (shallow copy).
       Destruction of both copies could cause double deletion and
       undefined behavior. Do not copy this instructional class.
       A robust implementation needs the Rule of Three (or another
       explicit ownership policy).
    */
    // Destructor to free all nodes in the stack
    ~stack()
    {
        while (!isEmpty())
        {
            pop() ;
        }
    }

    /*
    ---------------------------------------------------------------------------
    initialize() - REMOVE ALL NODES
    ---------------------------------------------------------------------------

    Example:

       Before: topNode -> [30] -> [20] -> [10] -> nullptr
       After:  topNode -> nullptr

    The loop repeatedly calls pop(), which deletes each dynamically
    allocated node. Setting currentSize to zero afterward makes the
    empty-state bookkeeping explicit; pop() already decrements it.

    Comparison with 17-1:
       Array version       : topIndex = -1;           O(1)
       Linked-list version : delete every node;       O(n)

    IMPORTANT: Simply writing topNode = nullptr here without deleting
    nodes would lose their addresses and leak allocated memory.
    */
    // Initializes the stack to an empty state
    void initialize()
    {
        while (!isEmpty())
        {
            pop() ;
        }
        currentSize = 0 ;
    }

    /*
    ---------------------------------------------------------------------------
    isEmpty() - EMPTY CONDITION
    ---------------------------------------------------------------------------

       Empty:         topNode -> nullptr     (returns true)
       Not empty:     topNode -> [10] ...    (returns false)

    The linked-list empty condition is based on its top pointer.
    In 17-1, the same logical test was topIndex == -1.

    Time Complexity: O(1).
    */
    // Determines if the stack is empty
    bool isEmpty() const
    {
        return topNode == nullptr ;
    }

    /*
    ---------------------------------------------------------------------------
    isFull() - CAPACITY CONDITION
    ---------------------------------------------------------------------------

    Example with maxSize = 5:
       currentSize = 3  --> false (room for two more values)
       currentSize = 5  --> true  (cannot push another value)

    Even though linked lists allocate memory dynamically, this example
    deliberately enforces a maximum size through currentSize and maxSize.

    Time Complexity: O(1).

    Stack overflow (ADT capacity): pushing when isFull() is true.
    Stack underflow (ADT empty) : popping/peeking when isEmpty() is true.
    These are different from a C++ program's recursive CALL STACK overflow.
    */
    // Determines if the stack is full
    bool isFull() const
    {
        return currentSize == maxSize ;
    }

    /*
    ---------------------------------------------------------------------------
    push(element) - INSERT AT THE TOP
    ---------------------------------------------------------------------------

    Example: push(30) into an existing stack containing 20 and 10.

    BEFORE:

       topNode
          |
          v
        [20] ----> [10] ----> nullptr

    STEP 1: node* newNode = new node;
            newNode->data = 30;

       newNode --> [30] --> nullptr
       topNode --> [20] --> [10] --> nullptr

    STEP 2: newNode->next = topNode;

       newNode --> [30] ----> [20] ----> [10] ----> nullptr
                               ^
                               |
                            topNode

    STEP 3: topNode = newNode;

       topNode
          |
          v
        [30] ----> [20] ----> [10] ----> nullptr

    STEP 4: currentSize++;

       currentSize: 2 -> 3

    CRITICAL ORDER:
       First link the new node to the old top, THEN change topNode.
       Reversing these steps without preserving the old top address
       can disconnect the existing nodes and cause a memory leak.

    The operation is the same pointer pattern as insertFirst() in
    Chapter 16's singly linked list.

    Time Complexity: O(1) for the linked-list pointer operations.
    A full stack prints a message and does not allocate a new node.
    */
    // Pushes a new element onto the stack
    void push(int element)
    {
        if (isFull())
        {
            cout << "Stack is full. Cannot push " << element << "." << endl ;
        }
        else
        {
            node* newNode = new node ; // Create a new node
            newNode->data = element ;   // Set the data of the new node
            newNode->next = topNode ;   // Link new node to the current top node
            topNode = newNode ;         // Update the top to the new node
            currentSize++ ;             // Increment current size
        }
    }

    /*
    ---------------------------------------------------------------------------
    peek() - READ TOP VALUE WITHOUT REMOVING IT
    ---------------------------------------------------------------------------

       topNode
          |
          v
        [30] -> [20] -> [10] -> nullptr

       peek() returns 30.
       The nodes, topNode, and currentSize remain unchanged.

    Unlike the array-based version's stackArray[topIndex], this
    version obtains the value using topNode->data.

    For an empty stack, this example prints an error and returns -1.
    LIMITATION: -1 is also a valid int stored by push(-1), so it is
    an ambiguous sentinel rather than a robust error-reporting API.

    Time Complexity: O(1).
    */
    // Returns the top element of the stack
    int peek() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element." << endl ;
            return -1 ; // Returning -1 as a sentinel value for empty stack
        }
        return topNode->data ;
    }

    /*
    ---------------------------------------------------------------------------
    pop() - REMOVE AND DELETE THE TOP NODE
    ---------------------------------------------------------------------------

    BEFORE:

       topNode
          |
          v
        [30] ----> [20] ----> [10] ----> nullptr

    STEP 1: node* temp = topNode;

       temp and topNode both point to the node containing 30.

    STEP 2: topNode = topNode->next;

       temp         topNode
        |              |
        v              v
       [30] --------> [20] ----> [10] ----> nullptr

    STEP 3: delete temp;

       topNode
          |
          v
        [20] ----> [10] ----> nullptr

    STEP 4: currentSize--;

       currentSize: 3 -> 2

    CRITICAL ORDER:
       Save the old top, advance topNode, THEN delete the old node.
       Never follow temp->next after delete temp; temp is then dangling.

    Compare with 17-1:
       Array pop()       : topIndex--;       (logical removal)
       Linked-list pop(): delete temp;      (releases node memory)

    NOTE: pop() returns void. To use the top value, call peek() BEFORE
    pop(), while checking for an empty stack appropriately.

    Time Complexity: O(1).
    */
    // Removes the top element of the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty. Cannot pop." << endl ;
        }
        else
        {
            node* temp = topNode ;
            topNode = topNode->next ;
            delete temp ;      // Free memory of removed node
            currentSize-- ;    // Decrement current size
        }
    }

    /*
    ---------------------------------------------------------------------------
    display() - TRAVERSE TOP TO BOTTOM
    ---------------------------------------------------------------------------

       topNode
          |
          v
        [30] ----> [20] ----> [10] ----> nullptr
          ^          ^          ^
          |          |          |
        print 30   print 20   print 10

       Output: Stack elements (top to bottom): 30 20 10

    Traversal uses a TEMPORARY pointer:
       node* current = topNode;
       while (current != nullptr) {
           ... print current->data ...
           current = current->next;
       }

    Only current moves. topNode remains at the actual top node,
    and display() does not change the contents of the stack.

    Time Complexity: O(n), because it visits each existing node once.
    */
    // Displays all elements in the stack from top to bottom
    void display() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl ;
        }
        else
        {
            node* current = topNode ;
            cout << "Stack elements (top to bottom): " ;
            while (current != nullptr)
            {
                cout << current->data << " " ;
                current = current->next ;
            }
            cout << endl ;
        }
    }
} ;

/*
===============================================================================
TIME COMPLEXITY SUMMARY - ARRAY STACK VS. LINKED-LIST STACK
===============================================================================

    Operation       17-1 Array Stack       17-2 Linked-List Stack
    ---------       ----------------       ----------------------
    push()                O(1)                     O(1)
    pop()                 O(1)                     O(1)
    peek()                O(1)                     O(1)
    isEmpty()             O(1)                     O(1)
    isFull()              O(1)                     O(1)
    initialize()          O(1)                     O(n)
    display()             O(n)                     O(n)
    destructor            O(1)*                    O(n)

    n = number of elements currently in the stack.
    * The array-stack destructor performs one delete[] for an int array.
      This row counts array-element cleanup work for this simple int-only
      implementation; general array element destruction may take O(n).

    Memory considerations:
      - The array stack allocates space for maxSize ints at construction.
      - The linked-list stack allocates one node (data + next pointer)
        for each successful push(), and releases it at pop()/destruction.
      - Both versions set a logical maxSize in this course example.
      - Each node allocation can have additional allocator overhead.

===============================================================================
MAIN PROGRAM EXECUTION TRACE
===============================================================================

    Operation             currentSize       TOP -> BOTTOM
    ------------------    -----------       ----------------------------
    stack myStack(5)           0            nullptr
    push(10)                   1            10
    push(20)                   2            20 -> 10
    push(30)                   3            30 -> 20 -> 10
    display()                  3            prints: 30 20 10
    peek()                     3            returns 30; no removal
    pop()                      2            20 -> 10
    peek()                     2            returns 20; no removal
    display()                  2            prints: 20 10
    pop()                      1            10
    pop()                      0            nullptr
    isEmpty()                  0            true
    display()                  0            prints: Stack is empty.
    pop()                      0            prints: Stack is empty. Cannot pop.

    EXPECTED CONSOLE OUTPUT:

    Stack elements (top to bottom): 30 20 10
    Top element: 30
    Top element after pop: 20
    Stack elements (top to bottom): 20 10
    Stack empty: Yes
    Stack is empty.
    Stack is empty. Cannot pop.

    LESSON CONNECTION:
    Chapter 16 insertFirst() and head-node deletion are exactly the
    pointer techniques used here for push() and pop(). Chapter 17
    adds the LIFO restriction: only the top node is accessed/removed.
===============================================================================
*/
int main()
{
    stack myStack(5) ; // Create a stack of size 5

    myStack.push(10) ;
    myStack.push(20) ;
    myStack.push(30) ;

    myStack.display() ; // Display stack elements: Expected output: 30 20 10

    cout << "Top element: " << myStack.peek() << endl ; // Expected output: 30

    myStack.pop() ;
    cout << "Top element after pop: " << myStack.peek() << endl ; // Expected output: 20

    myStack.display() ; // Display stack elements after pop: Expected output: 20 10

    myStack.pop() ;
    myStack.pop() ;
    cout << "Stack empty: " << (myStack.isEmpty() ? "Yes" : "No") << endl ; // Expected output: Yes

    myStack.display() ; // Expected output: Stack is empty.

    myStack.pop() ; // Attempt to pop from empty stack

    return 0 ;
}
