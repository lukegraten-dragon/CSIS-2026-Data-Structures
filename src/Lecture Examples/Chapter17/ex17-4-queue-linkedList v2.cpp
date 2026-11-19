/*
===============================================================================
CHAPTER 17 - EXAMPLE 17-4: QUEUE USING A SINGLY LINKED LIST (REVISED)
===============================================================================

1. QUEUE ABSTRACT DATA TYPE (ADT): FIFO = FIRST IN, FIRST OUT

   The first item inserted is the first item removed.
   enqueue(value) inserts at REAR; dequeue() removes from FRONT.

   Example: enqueue(10), enqueue(20), enqueue(30)

      DEQUEUE                                                ENQUEUE
       (remove)                                                (add)
          |                                                      |
          v                                                      v
       FRONT                                                    REAR
          |                                                      |
          v                                                      v
      +------+--------+     +------+--------+     +------+----------+
      |  10  | next --+---->|  20  | next --+---->|  30  | nullptr  |
      +------+--------+     +------+--------+     +------+----------+

   dequeue() removes and returns 10; peek() reads 10 without removal.
   The diagram shows logical pointer connections; nodes do NOT have
   to occupy adjacent physical memory locations.

2. COMPARE WITH THE STACK EXAMPLES (17-1, 17-2)

   STACK: LIFO (Last In, First Out)
     push() and pop() both work at TOP.

   QUEUE: FIFO (First In, First Out)
     enqueue() adds at REAR; dequeue() removes at FRONT.

   In Example 17-2, topNode points to the stack's first node.
   In Example 17-4, frontNode and rearNode track BOTH ends.

3. COMPARE WITH EXAMPLE 17-3: ARRAY-BASED QUEUE

   17-3 Circular Array                 17-4 Singly Linked List
   ------------------------------      --------------------------------
   Uses queueArray (int*)             Uses separate heap-allocated nodes
   Tracks frontIndex and rearIndex    Tracks frontNode and rearNode
   Uses modulo (%) to wrap indices    Follows next pointers (no modulo)
   dequeue(): advances frontIndex     dequeue(): deletes the front node
   enqueue(): writes to array slot    enqueue(): allocates a new node
   initialize(): O(1)                 initialize(): O(n)

   Both versions offer FIFO behavior. Both impose maxSize in THESE
   teaching examples, although a linked list need not be fixed-size.

4. REVISED API (CONSISTENT ACROSS CHAPTER 17)

   initialize()  : Remove all nodes; make the queue empty.
   isEmpty()     : Check whether frontNode == nullptr.
   isFull()      : Check whether currentSize == maxSize.
   enqueue(x)    : Add x at the rear.
   dequeue()     : Remove and RETURN the front value (int).
   peek()        : Read the front value without removal.
   display()     : Print values from front to rear.

   Note: This is a CUSTOM queue class, not std::queue. The C++
   standard std::queue uses push(), pop(), front(), and empty().
*/
#include <iostream>
using namespace std ;

/*
===============================================================================
NODE STRUCTURE: ONE DATA VALUE + ONE NEXT POINTER
===============================================================================

   A singly linked-list node contains:

               +---------------+-------------------+
      node --> | data = 20     | next = address    |
               +---------------+-------------------+

   data : integer value stored in this node.
   next : pointer to the NEXT node, or nullptr at the rear.

   When the node constructor finishes:

               +---------------+-------------------+
      node --> | data = 0      | next = nullptr    |
               +---------------+-------------------+

   enqueue() sets data to the requested value and links the new node.
   The -> operator accesses a member through a pointer:

      newNode->data = element;
      newNode->next = nullptr;

   This queue is NOT circular: rearNode->next is nullptr.
*/
// Node class to represent each element in the queue
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
QUEUE OBJECT STATE AND POINTER INVARIANTS
===============================================================================

   Four private members:

     frontNode   : address of first node (next item to dequeue)
     rearNode    : address of final node (where enqueue adds an item)
     maxSize     : maximum number of items permitted by this example
     currentSize : number of nodes currently stored

   EMPTY QUEUE:

     frontNode ---> nullptr
     rearNode  ---> nullptr
     currentSize = 0

   ONE-NODE QUEUE:

     frontNode ---+
                  |
                  v
               +------+----------+
               |  10  | nullptr  |
               +------+----------+
                  ^
                  |
     rearNode ----+

   THREE-NODE QUEUE:

     frontNode                                  rearNode
         |                                         |
         v                                         v
     +------+-------+    +------+-------+    +------+----------+
     |  10  | next -+--->|  20  | next -+--->|  30  | nullptr  |
     +------+-------+    +------+-------+    +------+----------+

   Invariants maintained by correct enqueue()/dequeue():
     - An empty queue has both pointers equal to nullptr.
     - A nonempty queue has frontNode and rearNode both non-null.
     - The final node's next pointer is nullptr.
     - currentSize equals the number of linked nodes.

   IMPORTANT: The pointers are not the data itself. They store ADDRESSES.
   Each successful enqueue creates one node using new; each successful
   dequeue destroys one node using delete.
*/
class queue
{
private:
    node* frontNode ;  // Pointer to the front element in the queue
    node* rearNode ;   // Pointer to the rear element in the queue
    int maxSize ;      // Maximum size of the queue
    int currentSize ;  // Current number of elements in the queue

public:
/*
    ===========================================================================
    CONSTRUCTOR: queue(int size)
    ===========================================================================

    Example: queue myQueue(5);

       frontNode = nullptr    // There is no first node yet.
       rearNode  = nullptr    // There is no last node yet.
       maxSize = 5           // The queue can hold at most five nodes.
       currentSize = 0       // Initially zero nodes exist.

    Unlike the array-based queue in 17-3, this constructor does not
    allocate space for five elements. Nodes are created one at a time
    in enqueue(). The capacity limit is a policy implemented by isFull().
*/
    // Constructor to initialize an empty queue with a specified maximum size
    queue(int size)
    {
        frontNode = nullptr ;
        rearNode = nullptr ;
        maxSize = size ;
        currentSize = 0 ;
    }

/*
    ===========================================================================
    DESTRUCTOR: ~queue()
    ===========================================================================

    The destructor calls initialize(), which deletes all remaining nodes.
    A LOCAL queue object is automatically destroyed when its scope ends:

       int main()
       {
           queue myQueue(5);  // Constructor is called.
           ...
       }                       // Destructor is called automatically.

    Memory cleanup:
       [10] -> [20] -> [30] -> nullptr
         |       |       |
         v       v       v
       delete  delete  delete        (by repeated dequeue())

    Time complexity: O(n), where n is the number of remaining nodes.
    For a heap-allocated queue object created with new, the owner must
    eventually delete that object (or use an appropriate smart pointer).
*/
    // Destructor to free all nodes in the queue
    ~queue()
    {
        initialize() ;
    }

/*
    ===========================================================================
    initialize(): CLEAR EVERY NODE
    ===========================================================================

    Before:
      frontNode                           rearNode
          |                                  |
          v                                  v
        [10] ----------> [20] -----------> [30] -> nullptr

    During initialize():
      1. isEmpty() is false while a front node exists.
      2. dequeue() removes the front node and calls delete on it.
      3. Repeat until frontNode becomes nullptr.
      4. Set currentSize to 0 (already zero after successful dequeues).

    After:
      frontNode ---> nullptr
      rearNode  ---> nullptr
      currentSize = 0

    17-3 Array Queue: initialize() resets index integers in O(1).
    17-4 Linked Queue: initialize() destroys n nodes in O(n).

    Note: dequeue() returns an int, but this function intentionally
    ignores the return value because the purpose is simply to clear.
*/
    // Initializes the queue to an empty state
    void initialize()
    {
        while (!isEmpty())
        {
            dequeue() ;
        }
        currentSize = 0 ;
    }

/*
    ===========================================================================
    isEmpty(): DETECT THE EMPTY STATE
    ===========================================================================

    Return true when frontNode == nullptr.
    This works because enqueue() sets both pointers on the FIRST insertion,
    and dequeue() resets rearNode when the LAST node is removed.

    The function does not traverse the linked list.
    Time complexity: O(1).
*/
    // Determines if the queue is empty
    bool isEmpty() const
    {
        return frontNode == nullptr ;
    }

/*
    ===========================================================================
    isFull(): ENFORCE THE CAPACITY LIMIT
    ===========================================================================

    Return true when currentSize == maxSize.

    Example: maxSize = 5, currentSize = 5 -> full.
    The linked-list representation does not intrinsically require a fixed
    capacity. This implementation deliberately limits the queue size.

    A failed enqueue() does not allocate a new node or change the queue.
    Time complexity: O(1).
*/
    // Determines if the queue is full
    bool isFull() const
    {
        return currentSize == maxSize ;
    }

/*
    ===========================================================================
    enqueue(element): INSERT A NEW NODE AT THE REAR
    ===========================================================================

    CASE A - EMPTY QUEUE; enqueue(10)

    Before:
       frontNode ---> nullptr
       rearNode  ---> nullptr

    Allocate and initialize:
       newNode = new node
       newNode->data = 10
       newNode->next = nullptr

    Set BOTH endpoints to the same first node:
       frontNode = newNode;
       rearNode  = newNode;

       frontNode ---+
                    |
                    v
                  [10] -> nullptr
                    ^
                    |
       rearNode ----+

    CASE B - NONEMPTY QUEUE; enqueue(30)

    Before:
       frontNode            rearNode
           |                   |
           v                   v
         [10] -------------> [20] -> nullptr

    STEP 1. Allocate a separate node and initialize its fields:

         newNode
            |
            v
          [30] -> nullptr

    STEP 2. Link the OLD rear node to the new node:

         rearNode->next = newNode;

       frontNode            rearNode          newNode
           |                   |                 |
           v                   v                 v
         [10] -------------> [20] ----------> [30] -> nullptr

    STEP 3. Move rearNode to the new node:

         rearNode = newNode;

       frontNode                              rearNode
           |                                     |
           v                                     v
         [10] -------------> [20] ----------> [30] -> nullptr

    STEP 4. Increase currentSize by one.

    ORDER MATTERS:
       rearNode->next = newNode;   // Connect the existing chain FIRST.
       rearNode = newNode;         // Then move the rear pointer.

    Reversing these statements would lose the old rear link and fail
    to connect the existing queue correctly.

    The rear node is known directly; no traversal is required.
    Time complexity: O(1), excluding allocator implementation details.
*/
    // Adds a new element to the rear of the queue
    void enqueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot add " << element << "." << endl ;
        }
        else
        {
            node* newNode = new node ;
            newNode->data = element ;
            newNode->next = nullptr ;

            if (isEmpty())
            {
                frontNode = newNode ;
                rearNode = newNode ;
            }
            else
            {
                rearNode->next = newNode ; // Link new node to the rear of the queue
                rearNode = newNode ;       // Update rearNode to the new node
            }
            currentSize++ ; // Increment the current size
        }
    }

/*
    ===========================================================================
    dequeue(): REMOVE THE FRONT NODE AND RETURN ITS VALUE
    ===========================================================================

    BEFORE:  frontNode                           rearNode
                |                                   |
                v                                   v
              [10] ----------> [20] ------------> [30] -> nullptr

    STEP 1. Save the address of the node to delete:

         node* temp = frontNode;

    STEP 2. Save its DATA before freeing memory:

         int frontData = frontNode->data;  // frontData = 10

    STEP 3. Advance the front pointer:

         frontNode = frontNode->next;

                   temp       frontNode            rearNode
                     |            |                   |
                     v            v                   v
                   [10] ------> [20] --------------> [30] -> nullptr

    STEP 4. Free the old front node and decrement currentSize:

         delete temp;
         currentSize--;

       frontNode                  rearNode
           |                         |
           v                         v
         [20] --------------------> [30] -> nullptr

    STEP 5. If there are NO remaining nodes, also set rearNode to nullptr.

    SPECIAL CASE - REMOVE THE ONLY NODE:

       Before:
          frontNode --+
                      v
                     [10] -> nullptr
                      ^
          rearNode ---+

       After moving frontNode and deleting the old node:
          frontNode ---> nullptr
          rearNode  ---> nullptr  // Must reset to avoid dangling pointer!

    STEP 6. Return the saved value (frontData).

    IMPORTANT:
      - Never read temp->data or temp->next AFTER delete temp.
      - A successful dequeue() does real dynamic-memory deallocation,
        unlike array-based dequeue(), which just advances frontIndex.
      - The function returns -1 on empty queue; -1 is also a valid int,
        so this sentinel cannot distinguish all valid values from errors.

    Time complexity: O(1).
*/
    // Removes the front element from the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl ;
            return -1 ; // Returning -1 as a sentinel value for empty queue
        }
        else
        {
            node* temp = frontNode ;
            int frontData = frontNode->data ;
            frontNode = frontNode->next ;
            delete temp ; // Free memory of removed node
            currentSize-- ; // Decrement the current size

            if (frontNode == nullptr) // If queue becomes empty
            {
                rearNode = nullptr ;
            }

            return frontData ;
        }
    }

/*
    ===========================================================================
    peek(): READ THE FRONT WITHOUT REMOVING IT
    ===========================================================================

      frontNode                               rearNode
          |                                      |
          v                                      v
        [10] ------------> [20] --------------> [30] -> nullptr

    peek() returns frontNode->data (10), leaving all links and
    currentSize unchanged. dequeue() would remove 10 and return it.

    17-3 Array Queue:  return queueArray[frontIndex];
    17-4 Linked Queue: return frontNode->data;

    An empty queue returns -1 after printing a message; see the
    sentinel-value limitation in the dequeue() comment above.

    Time complexity: O(1).
*/
    // Returns the front element of the queue
    int peek() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No front element." << endl ;
            return -1 ; // Returning -1 as a sentinel value for empty queue
        }
        return frontNode->data ;
    }

/*
    ===========================================================================
    display(): TRAVERSE FROM FRONT TO REAR
    ===========================================================================

      frontNode                               rearNode
          |                                      |
          v                                      v
        [10] ------------> [20] --------------> [30] -> nullptr
          ^                  ^                    ^
          |                  |                    |
        print              print                print

    Use a TEMPORARY traversal pointer:

       node* current = frontNode;
       while (current != nullptr)
       {
           ... current->data ...
           current = current->next;
       }

    The local pointer current advances, but the actual frontNode and
    rearNode remain unchanged. Printed order: 10 20 30.

    Time complexity: O(n) for n current elements.
*/
    // Displays all elements in the queue from front to rear
    void display() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty." << endl ;
        }
        else
        {
            node* current = frontNode ;
            cout << "Queue elements (front to rear): " ;
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
MAIN(): STEP-BY-STEP EXECUTION TRACE
===============================================================================

  maxSize = 5. Queue values are listed in FIFO order (FRONT -> REAR).

    Operation              currentSize       Logical queue
    --------------------   -----------       ------------------------
    queue myQueue(5)            0            empty
    enqueue(10)                 1            10
    enqueue(20)                 2            10 -> 20
    enqueue(30)                 3            10 -> 20 -> 30
    peek() -> 10                3            10 -> 20 -> 30
    dequeue() -> 10             2            20 -> 30
    enqueue(40)                 3            20 -> 30 -> 40
    enqueue(50)                 4            20 -> 30 -> 40 -> 50
    enqueue(60)                 5            20 -> 30 -> 40 -> 50 -> 60
    enqueue(70) FAILS           5            20 -> 30 -> 40 -> 50 -> 60

  EXPECTED OUTPUT:

    Queue elements (front to rear): 10 20 30
    Front element: 10
    Queue elements (front to rear): 20 30
    Queue is full. Cannot add 70.
    Queue elements (front to rear): 20 30 40 50 60

  The 17-3 Revised Array Queue produces the same external output,
  despite a different internal data representation.

  IMPORTANT - TIME COMPLEXITY COMPARISON

    Operation          17-3 Array Queue        17-4 Linked Queue
    ----------------   --------------------    ---------------------
    enqueue()          O(1)                    O(1)
    dequeue()          O(1)                    O(1)
    peek()             O(1)                    O(1)
    isEmpty()          O(1)                    O(1)
    isFull()           O(1)                    O(1)
    initialize()       O(1)                    O(n)
    display()          O(n)                    O(n)
    destructor         O(1) for int[]          O(n)

  MEMORY MANAGEMENT - RULE OF THREE

  This class owns dynamically allocated nodes and has a destructor,
  but it does NOT provide a custom copy constructor or copy assignment.
  Default copying duplicates the POINTERS, not the nodes:

      queue1.frontNode --+
                         +----> [10] -> [20] -> nullptr
      queue2.frontNode --+

  Both objects would then claim ownership of the same nodes. When one
  destroys those nodes, the other retains dangling pointers. This can
  lead to double deletion, use-after-free, and undefined behavior.

  A safer implementation must define appropriate copying semantics
  (deep copy or explicitly disabled copying) and follow the Rule of Three.
  Also validate that maxSize is positive in a more robust implementation.

  CLASSROOM TAKEAWAY:
  Queue = FIFO. Use rearNode for O(1) insertion, frontNode for O(1)
  removal, and delete removed nodes to avoid memory leaks.
*/
int main()
{
    queue myQueue(5) ; // Create a queue with maximum size 5

    myQueue.enqueue(10) ;
    myQueue.enqueue(20) ;
    myQueue.enqueue(30) ;

    myQueue.display() ; // Display queue elements: Expected output: 10 20 30

    cout << "Front element: " << myQueue.peek() << endl ; // Expected output: 10

    myQueue.dequeue() ;
    myQueue.display() ; // Display queue elements after deletion: Expected output: 20 30

    myQueue.enqueue(40) ;
    myQueue.enqueue(50) ;
    myQueue.enqueue(60) ;
    myQueue.enqueue(70) ;

    myQueue.display() ;

    return 0 ;
}
