#include <iostream>
using namespace std ;

/*
===============================================================================
 EXAMPLE 17-5 - PRIORITY QUEUE USING A SORTED ARRAY
===============================================================================

1. WHAT IS A PRIORITY QUEUE?

   A regular Queue (Examples 17-3 and 17-4) follows FIFO:
      First In, First Out.

   A Priority Queue removes the element with the HIGHEST priority first.
   In this example, a LARGER priority NUMBER means HIGHER priority.

   Example of elements, shown as (data, priority):

      enqueue(20, 2)    enqueue(30, 3)    enqueue(10, 1)

      Priority processing order (highest first):

          (30, 3) ---> (20, 2) ---> (10, 1)
          highest                      lowest

   17-5 uses an ARRAY. Example 17-6 uses a LINKED LIST.
   Both provide enqueue(), dequeue(), peek(), isEmpty(), and display().

2. AN ELEMENT CONTAINS TWO INTEGERS

                One Element
            +------------+------------+
            |    data    |  priority  |
            +------------+------------+
            |     30     |      3     |
            +------------+------------+

   data     = the number stored in the queue
   priority = the number used to choose removal order

3. SORTED ARRAY LAYOUT - VERY IMPORTANT

   This implementation stores elements in ASCENDING priority order,
   with the HIGHEST priority at the RIGHT END of the occupied array.

       Array index:     0          1          2        3       4
                     +---------+---------+---------+-------+-------+
       queueArray:   | (10, 1) | (20, 2) | (30, 3) | unused| unused|
                     +---------+---------+---------+-------+-------+
                         ^                   ^
                         |                   |
                    LOW priority        HIGH priority
                                          ^
                                          |
                                  peek() / dequeue()

       maxSize     = 5
       currentSize = 3
       Last valid index = currentSize - 1 = 2

   Although the highest-priority element is logically the FRONT of
   the priority queue, this program stores it at the RIGHT END of the
   used array; there is no physical frontIndex or rearIndex.

4. CLASS INVARIANTS

   For a valid queue with positive maxSize:
       0 <= currentSize <= maxSize
       Used elements are queueArray[0] through queueArray[currentSize - 1].
       Priorities in the used array are in nondecreasing order.
       The highest priority is at index currentSize - 1.

   For equal priority numbers, the earliest enqueued element should
   be dequeued first. This is STABLE processing of equal priorities.

5. ONE IMPORTANT CORRECTION FROM THE ORIGINAL EXAMPLE

   ORIGINAL insertion test (incorrect for dequeue() and peek()):
       queueArray[i].priority < priority

   CORRECTED insertion test:
       queueArray[i].priority >= priority

   The original test arranged HIGHER priorities toward the LEFT,
   but dequeue() and peek() read from the RIGHT. As a result, the
   original program removed the LOWEST priority first.

   The corrected test arranges LOWER priorities on the LEFT and
   HIGHER priorities on the RIGHT, matching dequeue() and peek().

   Using >= (not just >) also keeps FIFO order among equal priorities
   when the RIGHTMOST element is removed first.

6. PERFORMANCE SUMMARY

       enqueue()   : O(n) time - shift array elements to insert in order
       dequeue()   : O(1) time - decrease currentSize
       peek()      : O(1) time - access the rightmost valid element
       isEmpty()   : O(1) time
       isFull()    : O(1) time
       display()   : O(n) time
       Storage     : O(maxSize) allocated space

   n = number of elements currently stored in the priority queue.
   Insertion is more expensive than removal because sorted order
   is maintained DURING insertion.

7. LIMITATIONS OF THIS EDUCATIONAL VERSION

   - The queue has a fixed maximum capacity once constructed.
   - The constructor does not validate that size is positive.
   - A dequeue() or peek() on an empty queue returns -1; this is
     ambiguous when -1 is also a valid data value.
   - This class owns a dynamically allocated array. It implements a
     destructor but not a copy constructor or copy assignment operator.
     Default copying would share queueArray, risking double deletion.
     See the Rule of Three from Chapter 13.

===============================================================================
*/
class priorityQueue
{
private:
    /*
    Element groups the VALUE and its PRIORITY in one array entry.

          +------------+------------+
          |    data    |  priority  |
          +------------+------------+
          |     20     |     2      |
          +------------+------------+

    queueArray stores Element objects, not plain integers.
    */
    struct Element
    {
        int data ;
        int priority ;
    };

    Element* queueArray ; // Array to store elements and their priorities
    int maxSize ;         // Maximum size of the priority queue
    int currentSize ;     // Current number of elements in the queue

public:
    /*
    CONSTRUCTOR - priorityQueue(int size)

    Example: priorityQueue pq(5);

       maxSize = 5       // Array capacity
       currentSize = 0   // No valid elements yet

       queueArray ---> [ ? ][ ? ][ ? ][ ? ][ ? ]
                         0    1    2    3    4

    'new Element[maxSize]' allocates an array of Element objects.
    Their int fields are not initialized by this allocation.
    Only indices 0 through currentSize - 1 contain valid queue data.

    Assumption: size is positive. The current code does not check it.
    */
    // Constructor to initialize the queue with a specified size
    priorityQueue(int size)
    {
        maxSize = size ;
        queueArray = new Element[maxSize] ; // Dynamically allocate array
        currentSize = 0 ;
    }

    /*
    DESTRUCTOR - ~priorityQueue()

    Called automatically when a local priorityQueue object leaves scope.
    'delete[]' releases the entire dynamically allocated Element array.
    There is no 'delete' for each Element because Elements are stored
    in one array rather than separately created linked-list nodes.

    IMPORTANT: A destructor alone does not make copying safe.
    The class also needs proper copying rules (Rule of Three), or
    copying should be disabled. This program does not copy the queue.
    */
    // Destructor to free allocated memory
    ~priorityQueue()
    {
        delete[] queueArray ;
    }

    /*
    isEmpty(): O(1)

       currentSize == 0  -> true  (no valid elements)
       currentSize >  0  -> false

    Values may remain in the physical array after dequeue(), but
    those slots are outside the logically occupied range.
    */
    // Determines if the priority queue is empty
    bool isEmpty() const
    {
        return currentSize == 0 ;
    }

    /*
    isFull(): O(1)

       currentSize == maxSize -> true

    Before enqueue(), check capacity to avoid writing past the array.
    Example: maxSize = 5, currentSize = 5 -> no room for another element.
    */
    // Determines if the priority queue is full
    bool isFull() const
    {
        return currentSize == maxSize ;
    }

    /*
    ENQUEUE(element, priority) - SORTED INSERTION

    Goal:
       Insert an Element while keeping priorities in ASCENDING order
       from LEFT (lowest) to RIGHT (highest).

    Important corrected condition:
       queueArray[i].priority >= priority

    Start at the LAST valid array entry, scan LEFT, and shift entries
    with priority >= the new priority one position to the RIGHT.
    Then store the new element in the newly opened position.

    Example A: Add three elements in this order:
       enqueue(20, 2)
       enqueue(30, 3)
       enqueue(10, 1)

       After enqueue(20, 2):
       Index:      0          1          2
                +---------+----------+----------+
                | (20, 2) |  unused  |  unused  |
                +---------+----------+----------+

       After enqueue(30, 3):
       Index:      0          1          2
                +---------+---------+----------+
                | (20, 2) | (30, 3) |  unused  |
                +---------+---------+----------+

       Enqueue(10, 1): Shift both occupied entries RIGHT:

            BEFORE:  [ (20,2) ][ (30,3) ][ unused ]
            SHIFT 1: [ (20,2) ][ (30,3) ][ (30,3) ]
            SHIFT 2: [ (20,2) ][ (20,2) ][ (30,3) ]
            INSERT:  [ (10,1) ][ (20,2) ][ (30,3) ]

       Highest priority is NOW at index currentSize - 1.

    Example B: Equal priorities and STABLE FIFO ordering:

       enqueue(30, 3)    // Inserted first
       enqueue(40, 3)    // Inserted second

       Internal array (left to right):
             [ (40,3) ][ (30,3) ]

       dequeue() takes the RIGHTMOST element, so (30,3) leaves FIRST.
       This is why >= rather than > matters for equal priorities.

    Complexity:
       Best case  O(1): new element belongs at the far right.
       Worst case O(n): every existing element must shift right.
       Auxiliary working space is O(1); storage is already allocated.

    IMPORTANT:
       The original file used '< priority', which sorted the opposite
       way from the location used by dequeue() and peek(). The line
       below is intentionally corrected to '>= priority'.
    */
    // Adds a new element to the priority queue based on its priority
    void enqueue(int element, int priority)
    {
        if (isFull())
        {
            cout << "Priority Queue is full. Cannot add " << element << "." << endl ;
            return ;
        }

        // Insert the element in sorted order based on priority
        int i ;
        for (i = currentSize - 1; i >= 0 && queueArray[i].priority >= priority; i--)
        {
            queueArray[i + 1] = queueArray[i] ; // Shift elements to make space
        }

        // Insert the new element at the correct position
        queueArray[i + 1].data = element ;
        queueArray[i + 1].priority = priority ;
        currentSize++ ;
    }

    /*
    DEQUEUE() - REMOVE AND RETURN HIGHEST PRIORITY

    With the corrected sorted array, the RIGHTMOST VALID element
    has the highest priority.

    Before:
       Index:          0          1          2
                   +---------+---------+---------+
                   | (10,1)  | (20,2)  | (30,3)  |
                   +---------+---------+---------+
       currentSize = 3

    Operation:
       currentSize--              // 3 -> 2
       return queueArray[2].data  // returns 30

    After (logical contents):
       Index:          0          1          2
                   +---------+---------+---------+
                   | (10,1)  | (20,2)  | (30,3)  |
                   +---------+---------+---------+
                                         ^
                                    no longer valid
       currentSize = 2

    The old value (30,3) can remain in physical memory. Reducing
    currentSize logically removes it; the next enqueue() may overwrite
    that array position. No elements need to be shifted.

    Time Complexity: O(1)

    If empty, the code prints a message and returns -1. Using -1 as
    an error sentinel is ambiguous if -1 is valid stored data.
    */
    // Removes and returns the element with the highest priority
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty. Cannot dequeue." << endl ;
            return -1 ; // Sentinel value for empty queue
        }

        currentSize-- ;
        return queueArray[currentSize].data ; // Return data at the highest-priority end of the array
    }

    /*
    PEEK() - LOOK AT THE HIGHEST PRIORITY (NO REMOVAL)

       queueArray[currentSize - 1].data

    Example: [ (10,1) ][ (20,2) ][ (30,3) ]
                                         ^
                                       peek()

    Returns 30. Does NOT change currentSize or the array.
    Difference:
       peek()    = read the highest-priority value
       dequeue() = remove and return the highest-priority value

    Time Complexity: O(1)
    */
    // Returns the element with the highest priority without removing it
    int peek() const
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty. No front element." << endl ;
            return -1 ; // Sentinel value for empty queue
        }

        return queueArray[currentSize - 1].data ; // Highest priority is stored at the last valid index
    }

    /*
    DISPLAY() - PRINT FROM HIGHEST TO LOWEST PRIORITY

    Internal array (lowest to highest):
       [ (10,1) ][ (20,2) ][ (30,3) ]
         index 0                 index 2

    Display iterates from currentSize - 1 DOWN TO 0:
       (30, 3) (20, 2) (10, 1)

    Note: Display order is the REVERSE of the array's physical order.
    It matches the order in which elements would be dequeued.

    Time Complexity: O(n)
    */
    // Displays all elements in the priority queue
    void display() const
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty." << endl ;
            return ;
        }

        cout << "Priority Queue elements (value, priority): " ;
        for (int i = currentSize - 1; i >= 0; i--)
        {
            cout << "(" << queueArray[i].data << ", " << queueArray[i].priority << ") " ;
        }
        cout << endl ;
    }
};

/*
===============================================================================
 MAIN() EXECUTION TRACE - CORRECTED PRIORITY ORDER
===============================================================================

  priorityQueue pq(5)    : size = 0, capacity = 5

  Operation                Occupied array (LEFT -> RIGHT)
  -----------------------------------------------------------------------
  enqueue(20, 2)           [(20,2)]
  enqueue(30, 3)           [(20,2), (30,3)]
  enqueue(10, 1)           [(10,1), (20,2), (30,3)]
  peek()                   returns 30; array unchanged
  dequeue()                returns 30; [(10,1), (20,2)]
  enqueue(60, 5)           [(10,1), (20,2), (60,5)]
  enqueue(50, 4)           [(10,1), (20,2), (50,4), (60,5)]
  enqueue(40, 3)           [(10,1), (20,2), (40,3), (50,4), (60,5)]

  The FINAL internal array is:

  Index       0         1         2         3         4
           +--------+--------+--------+--------+--------+
           | (10,1) | (20,2) | (40,3) | (50,4) | (60,5) |
           +--------+--------+--------+--------+--------+
                                                    ^
                                            highest priority

  Final display() prints RIGHT TO LEFT:
      (60, 5) (50, 4) (40, 3) (20, 2) (10, 1)

  EXPECTED PROGRAM OUTPUT:

  Priority Queue elements (value, priority): (30, 3) (20, 2) (10, 1)
  Front element (highest priority): 30
  Priority Queue elements (value, priority): (20, 2) (10, 1)
  Priority Queue elements (value, priority): (60, 5) (50, 4) (40, 3) (20, 2) (10, 1)

  Comparison with normal Queue (Example 17-3):
      Regular Queue:    enqueue O(1), dequeue O(1)  (FIFO)
      Priority Queue:   enqueue O(n), dequeue O(1)  (sorted array)

  Comparison with linked-list Priority Queue (Example 17-6):
      Both keep items ordered by priority so the highest priority is
      removed first. Array insertion shifts Elements; linked-list
      insertion changes node pointers.

  NOTE: main() does not exercise equal priorities after the correction.
  Inserting equal priorities is still supported; see the enqueue()
  comment for why the corrected >= comparison preserves FIFO ties.
===============================================================================
*/
int main()
{
    priorityQueue pq(5) ; // Create a priority queue with maximum size 5

    pq.enqueue(20, 2) ;
    pq.enqueue(30, 3) ;
    pq.enqueue(10, 1) ;

    pq.display() ; // Expected output: (30, 3) (20, 2) (10, 1)

    cout << "Front element (highest priority): " << pq.peek() << endl ; // Expected output: 30

    pq.dequeue() ;
    pq.display() ; // Expected output: (20, 2) (10, 1) 

    pq.enqueue(60, 5) ;
    pq.enqueue(50, 4) ;
    pq.enqueue(40, 3) ;

    pq.display() ; // Expected output: (60, 5) (50, 4) (40, 3) (20, 2) (10, 1)

    return 0 ;
}
