#include <iostream>

using namespace std ;

/*
===============================================================================
EXAMPLE 17-1: STACK USING A DYNAMIC ARRAY (REVISED VERSION)
===============================================================================

1. What Is a Stack?
   A stack is a linear data structure based on LIFO:

       LIFO = Last In, First Out

   The LAST element inserted is the FIRST element removed.
   Think of a stack of plates: add a plate at the top and remove a
   plate from the top. We do not remove a plate from the middle.

   Example operations:
       push(10), push(20), push(30)

            +---------+
     TOP -> |   30    | <-- most recently pushed
            +---------+
            |   20    |
            +---------+
            |   10    | <-- first element pushed
            +---------+
              BOTTOM

       pop() removes 30 first; then 20; then 10.

2. Array-Based Stack vs. Linked List
   This example stores all elements in ONE dynamically allocated array.
   The array is allocated when the stack object is constructed.

   Chapter 17-2 will implement the SAME stack operations with nodes
   and pointers. The names push(), pop(), peek(), and isEmpty() remain
   consistent so we can focus on the difference in implementation.

3. Three Important Member Variables

       stackArray : pointer to the dynamically allocated int array
       maxSize    : total array capacity (maximum stack elements)
       topIndex   : index of the current top element

   Example after push(10), push(20), push(30) on a stack of size 5:

         index:          0      1      2      3      4
                      +------+------+------+------+------+
         stackArray ->|  10  |  20  |  30  |  ?   |  ?   |
                      +------+------+------+------+------+
                                       ^
                                       |
                                  topIndex = 2

         maxSize = 5
         number of elements = topIndex + 1 = 3

   The '?' slots are allocated, but they are NOT stack elements.
   With new int[maxSize], their integer values are not initialized.

4. Invariants (Valid State of a Nonzero-Capacity Stack)

       Empty stack: topIndex == -1
       Full stack : topIndex == maxSize - 1
       Otherwise  : -1 < topIndex < maxSize - 1

   The first inserted element goes into array index 0.
   No element is stored at a negative index.

5. Revised Function Names Used in This Chapter

       initialize()   : make the stack logically empty
       isEmpty()      : check whether the stack has no elements
       isFull()       : check whether the array has reached capacity
       push(value)    : insert a value at the TOP
       pop()          : remove the TOP value (does not return it)
       peek()         : read the TOP value without removing it
       display()      : print elements from TOP to BOTTOM

   C++ standard std::stack uses top() instead of peek() and empty()
   instead of isEmpty(). This is our instructional interface.
===============================================================================
*/
class stack
{
private:
    int* stackArray ; // Pointer to the stack array
    int maxSize ;     // Maximum size of the stack
    int topIndex ;    // Index of the top element in the stack

public:
    /*
    CONSTRUCTOR - stack(int size)

    Example: stack myStack(5);

        maxSize = 5
        topIndex = -1
        stackArray --> +---+---+---+---+---+
                       | ? | ? | ? | ? | ? |
                       +---+---+---+---+---+
                         0   1   2   3   4

    Dynamic allocation:
        new int[maxSize] allocates ONE array of maxSize integers.
        The array exists even when the stack is logically empty.
        These integer slots are not value-initialized by this expression.

    Why topIndex = -1?
        Array indexes begin at 0, so -1 indicates NO valid top item.
        The first push() increments it to 0 before storing an element.

    Limitation: this example assumes a positive stack capacity.
    */
    // Constructor to initialize stack with a specified size
    stack(int size)
    {
        maxSize = size ;
        topIndex = -1 ; // Stack is initially empty
        stackArray = new int[maxSize] ; // Dynamically allocate array
    }

    /*
    DESTRUCTOR - ~stack()

    The constructor used new int[maxSize], so the destructor MUST use
    delete[] stackArray (array delete, not scalar delete).

    pop() does not free individual array elements. The entire array is
    released exactly once when the stack object is destroyed.

    IMPORTANT - Rule of Three:
    This class defines a destructor but not a copy constructor or copy
    assignment operator. The compiler-generated copy operations copy
    the stackArray POINTER, not its allocated array. Copying a stack
    object may therefore lead to shared storage and double deletion.
    Safe copying requires proper deep-copy operations (or disabling
    copying). This educational example does not copy stack objects.
    */
    // Destructor to free allocated memory
    ~stack()
    {
        delete[] stackArray ;
    }

    /*
    initialize() - Reset the Stack

    Before:    stackArray = [10, 20, 30, ?, ?], topIndex = 2
    After:     stackArray = [10, 20, 30, ?, ?], topIndex = -1

    The old array values are NOT erased; they simply become invalid
    stack elements because topIndex == -1.

    Time Complexity: O(1)
    */
    // Initializes the stack to an empty state
    void initialize()
    {
        topIndex = -1 ;
    }

    /*
    isEmpty() - Test for Stack Underflow

       topIndex == -1  -> true  (empty)
       topIndex >=  0  -> false (at least one element)

    Used by peek(), pop(), and display() to prevent reading or
    removing an element when none exists.

    Time Complexity: O(1)
    */
    // Determines if the stack is empty
    bool isEmpty() const
    {
        return topIndex == -1 ;
    }

    /*
    isFull() - Test for Stack Overflow

    For maxSize = 5, the last valid array index is 4:

      index:           0    1    2    3    4
                     +----+----+----+----+----+
      stackArray --> | 10 | 20 | 30 | 40 | 50 |
                     +----+----+----+----+----+
                                              ^
                                         topIndex = 4

    The stack is full when topIndex == maxSize - 1.
    The push() function checks this before writing to the array.

    Time Complexity: O(1)
    */
    // Determines if the stack is full
    bool isFull() const
    {
        return topIndex == maxSize - 1 ;
    }

    /*
    push(element) - Insert at the Top

    The essential statement is:

        stackArray[++topIndex] = element;

    ++topIndex is PRE-INCREMENT:
      STEP 1: increase topIndex by 1
      STEP 2: write element into stackArray[topIndex]

    Example, starting with an empty stack (topIndex = -1):

      push(10): topIndex -1 -> 0; stackArray[0] = 10
      push(20): topIndex  0 -> 1; stackArray[1] = 20
      push(30): topIndex  1 -> 2; stackArray[2] = 30

            +------+                   +------+
      2     |  30  | <-- TOP           |  30  |
            +------+                   +------+
      1     |  20  |                   |  20  |
            +------+                   +------+
      0     |  10  | <-- BOTTOM        |  10  |
            +------+                   +------+

    Do NOT replace ++topIndex with topIndex++ here:
        stackArray[topIndex++] = element;
    On the first push, that would attempt stackArray[-1] BEFORE
    increasing topIndex, causing an out-of-bounds access.

    When isFull() is true, push() prints an error and makes no change.

    Time Complexity: O(1)
    */
    // Adds a new element to the top of the stack
    void push(int element)
    {
        if (isFull())
        {
            cout << "Stack is full. Cannot push " << element << "." << endl ;
        }
        else
        {
            stackArray[++topIndex] = element ;
        }
    }

    /*
    peek() - Read the Top Without Removing It

    Example:
        stackArray = [10, 20, 30, ?, ?]
        topIndex = 2
        peek() returns stackArray[2] == 30

    peek() does NOT change topIndex; subsequent peek() calls return
    the same value unless another operation changes the stack.

    Empty-stack limitation:
        This educational version prints an error and returns -1.
        But -1 is also a valid int that a user could push, so the
        caller cannot always tell an empty stack from a stored -1.
        A robust interface could throw an exception or use a separate
        success indicator.

    Time Complexity: O(1)
    */
    // Returns the top element of the stack
    int peek() const
    {
        if (isEmpty())
        {
            cout << "Stack is empty. No top element." << endl ;
            return -1 ; // Returning -1 as a sentinel value for empty stack
        }
        else
        {
            return stackArray[topIndex] ;
        }
    }

    /*
    pop() - Remove the Top Element (Logical Removal)

    Before pop():
                    +------+
      topIndex=2 -> |  30  |
                    +------+
                    |  20  |
                    +------+
                    |  10  |
                    +------+

    After pop():
                    +------+
       index 2      |  30  | <-- old value may remain in memory
                    +------+
      topIndex=1 -> |  20  | <-- new TOP
                    +------+
                    |  10  |
                    +------+

    The statement topIndex-- does NOT clear stackArray[2].
    It removes the value LOGICALLY by reducing the range of valid
    stack elements. A later push() will overwrite that position.

    Unlike the revised Queue dequeue(), this Stack pop() returns void.
    Use peek() first if you need the value before removing it.

    When isEmpty() is true, pop() prints an error and does nothing.
    This is called stack UNDERFLOW (removal from an empty stack).

    Time Complexity: O(1)
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
            topIndex-- ;
        }
    }

    /*
    display() - Visit Stack Elements from TOP to BOTTOM

    Example:

        index:     0     1     2     3     4
                 +-----+-----+-----+-----+-----+
                 | 10  | 20  | 30  |  ?  |  ?  |
                 +-----+-----+-----+-----+-----+
                             topIndex = 2

    The loop:
        for (int i = topIndex; i >= 0; i--)

    prints index 2, then 1, then 0:
        30 20 10

    This is the reverse of the order in which those values were pushed.
    If the stack is empty, display() prints "Stack is empty."

    Time Complexity: O(n), where n = topIndex + 1 is the number of
    currently valid stack elements.
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
            cout << "Stack elements (top to bottom): " ;
            for (int i = topIndex; i >= 0; i--)
            {
                cout << stackArray[i] << " " ;
            }
            cout << endl ;
        }
    }
} ;

/*
===============================================================================
MAIN PROGRAM - STEP-BY-STEP EXECUTION TRACE
===============================================================================

    Operation             topIndex      Stack (TOP -> BOTTOM)
    ----------------------------------------------------------------
    stack myStack(5)          -1        empty
    push(10)                  0        10
    push(20)                  1        20 -> 10
    push(30)                  2        30 -> 20 -> 10
    peek()                    2        returns 30; stack unchanged
    pop()                     1        20 -> 10
    peek()                    1        returns 20; stack unchanged
    pop()                     0        10
    pop()                    -1        empty
    isEmpty()                -1        true
    display()                -1        prints "Stack is empty."
    pop() on empty stack     -1        prints an underflow message

    EXPECTED OUTPUT:

    Stack elements (top to bottom): 30 20 10
    Top element: 30
    Top element after pop: 20
    Stack elements (top to bottom): 20 10
    Stack empty: Yes
    Stack is empty.
    Stack is empty. Cannot pop.

    TIME COMPLEXITY SUMMARY:

    Operation           Time Complexity
    -----------------------------------
    initialize()        O(1)
    isEmpty()           O(1)
    isFull()            O(1)
    push()              O(1)
    pop()               O(1)
    peek()              O(1)
    display()           O(n)

    Allocated storage: O(maxSize) integers, regardless of the number
    of elements currently in the stack.

    IMPORTANT DISTINCTION:
    "Stack" in this example is an abstract data structure implemented
    with a dynamic array. It is not the same thing as the CALL STACK
    used by functions and recursive calls in Chapter 15.

    TEACHING TAKEAWAY:
    The two essential statements are:
        stackArray[++topIndex] = element;   // PUSH
        topIndex--;                         // POP

    LIFO behavior is achieved by managing topIndex, not by shifting
    all of the array elements after each insertion or removal.
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
