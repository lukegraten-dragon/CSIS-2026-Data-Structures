/*
===============================================================================
EXAMPLE 17-3 - QUEUE USING A CIRCULAR ARRAY (REVISED)
===============================================================================

IMPORTANT CONCEPTS

1. QUEUE = FIFO (FIRST IN, FIRST OUT)

   The first element inserted is the first one removed.
   Elements are added at the REAR and removed at the FRONT.

          DEQUEUE (remove)                       ENQUEUE (add)
                 <----                               <----
        FRONT                                         REAR
          |                                            |
          v                                            v
        +------+       +------+       +------+       +------+
        |  10  | ----> |  20  | ----> |  30  | ----> |  40  |
        +------+       +------+       +------+       +------+

   Example:
       enqueue(10); enqueue(20); enqueue(30);
       Logical queue: FRONT -> 10 -> 20 -> 30 <- REAR
       dequeue() returns 10, leaving: 20 -> 30.

2. COMPARE WITH EXAMPLE 17-1 / 17-2 (STACK)

   Stack: LIFO; push and pop both operate at TOP.
   Queue: FIFO; enqueue at REAR, dequeue at FRONT.

   Stack operation                 Queue operation
   -----------------------         ------------------------
   push(value)                     enqueue(value)
   pop()                           dequeue() (returns int)
   peek() -> TOP value             peek() -> FRONT value
   isEmpty()                       isEmpty()
   isFull()                        isFull()

3. WHY A CIRCULAR ARRAY?

   The underlying memory is still a regular, contiguous C++ array.
   "Circular" means that indices wrap from maxSize - 1 back to 0.
   This allows the queue to REUSE a slot freed by an earlier dequeue.
   Existing elements are never shifted to the left.

   With maxSize = 5, an index progresses as follows:

       0 -> 1 -> 2 -> 3 -> 4 -> 0 -> 1 -> ...

   The wrap-around calculation is:

       (index + 1) % maxSize

   This code assumes a positive queue capacity (maxSize > 0).

4. FIVE MEMBER VARIABLES AND THEIR ROLES

   queueArray  : dynamically allocated array holding the values
   maxSize     : maximum number of elements that the queue can hold
   frontIndex  : array index of the next element to remove
   rearIndex   : array index of the most recently inserted element
   currentSize : number of LOGICALLY valid queue elements

   For maxSize = 5, after enqueue(10), enqueue(20), enqueue(30):

       Array index:      0       1       2       3       4
                      +-------+-------+-------+-------+-------+
       queueArray --> |  10   |  20   |  30   |   ?   |   ?   |
                      +-------+-------+-------+-------+-------+
                         ^               ^
                         |               |
                      FRONT            REAR

       frontIndex = 0, rearIndex = 2, currentSize = 3
       Logical order: 10 -> 20 -> 30

   '?' denotes an array element not yet initialized by this program.
   Only currentSize elements starting at frontIndex belong to the queue.

5. IMPORTANT DISTINCTION: PHYSICAL VS. LOGICAL ORDER

   After a dequeue and several enqueues, the FRONT can be at a
   higher array index than the REAR. The logical order is determined
   by frontIndex and currentSize, not by reading array slots from 0.

6. PERFORMANCE SUMMARY (n = currentSize)

   initialize() : O(1)       isEmpty() : O(1)
   isFull()     : O(1)       enqueue() : O(1)
   dequeue()    : O(1)       peek()    : O(1)
   display()    : O(n)

   Capacity is fixed by the constructor. This example does not resize
   its array automatically when the queue becomes full.

7. MEMORY MANAGEMENT AND CLASS COPYING

   Constructor: new int[maxSize]
   Destructor : delete[] queueArray

   The compiler-generated copy constructor / assignment operator would
   copy the queueArray POINTER, not allocate an independent array.
   Copying queue objects therefore risks double deletion (Rule of Three).
   This educational example does not copy queue objects.
===============================================================================
*/

#include <iostream>
using namespace std ;

class queue
{
    /*
    QUEUE STATE (ARRAY-BASED)

       maxSize = 5, currentSize = 3

            index:    0       1       2       3       4
                   +-------+-------+-------+-------+-------+
                   |  10   |  20   |  30   |   ?   |   ?   |
                   +-------+-------+-------+-------+-------+
                      ^               ^
                      |               |
                  frontIndex       rearIndex

       The first valid element is at queueArray[frontIndex].
       The last valid element is at queueArray[rearIndex].
       Each index is an integer, NOT a pointer.
       currentSize is essential for distinguishing EMPTY from FULL
       after the indices wrap around.
    */
private:
    int* queueArray ;  // Array to store queue elements
    int maxSize ;      // Maximum size of the queue
    int frontIndex ;   // Index of the front element in the queue
    int rearIndex ;    // Index of the rear element in the queue
    int currentSize ;  // Current number of elements in the queue

public:
    /*
    CONSTRUCTOR: queue(int size)

    When main executes queue myQueue(5):

      maxSize = 5
      queueArray = new int[5]   // allocate five int slots
      initialize()             // initialize logical state

      index:             0     1     2     3     4
                       +-----+-----+-----+-----+-----+
      queueArray -----> |  ?  |  ?  |  ?  |  ?  |  ?  |
                       +-----+-----+-----+-----+-----+

      frontIndex = 0; rearIndex = -1; currentSize = 0

    IMPORTANT: new int[5] here does not initialize each int to zero.
    The queue starts logically empty regardless of array contents.
    A sensible capacity must be greater than zero; this class does
    not validate the constructor's size argument.
    */
    // Constructor to initialize the queue with a specified size
    queue(int size)
    {
        maxSize = size ;
        queueArray = new int[maxSize] ; // Dynamically allocate array
        initialize() ;
    }

    /*
    DESTRUCTOR: ~queue()

    The queue object in main is a LOCAL object:

        queue myQueue(5);

    The destructor runs automatically when the object leaves scope.
    It releases the single dynamic array with delete[].

        new int[maxSize]   <---- matched with ---->   delete[] queueArray

    dequeue() does NOT delete individual int elements, because the
    elements reside in one array rather than in separately allocated nodes.
    */
    // Destructor to free allocated memory
    ~queue()
    {
        delete[] queueArray ;
    }

    /*
    initialize() - RESET THE LOGICAL QUEUE STATE

        frontIndex  = 0
        rearIndex   = -1
        currentSize = 0

    The existing array is not deleted and its slots are not cleared.
    The method simply marks the queue as EMPTY and resets the indices.
    It is also called by the constructor.

    Time Complexity: O(1)
    */
    // Initializes the queue to an empty state
    void initialize()
    {
        // The first valid array index is 0.
        // The first enqueued element will be stored at index 0.
        frontIndex = 0;

        // -1 indicates that no element has been enqueued yet.
        // On the first enqueue:
        // rearIndex = (-1 + 1) % maxSize = 0.
        // Therefore, the first element is inserted at index 0.
        rearIndex = -1;

        // The queue initially contains no valid elements.
        // currentSize == 0 means the queue is empty,
        // regardless of the values left in the array.
        currentSize = 0;
    }

    /*
    isEmpty() - CHECK FOR QUEUE UNDERFLOW

    Return true if there are no logically valid elements.
    Checking currentSize is reliable even after wrap-around.

        EMPTY: currentSize == 0

    A dequeue or peek attempted on an empty queue is an UNDERFLOW case.
    Time Complexity: O(1)
    */
    // Determines if the queue is empty
    bool isEmpty() const
    {
        return currentSize == 0 ;
    }

    /*
    isFull() - CHECK FOR QUEUE OVERFLOW

    Return true if every available array slot belongs to the queue.

        FULL: currentSize == maxSize

    A new enqueue on a full queue is rejected without changing the data.
    Example: maxSize = 5 and currentSize = 5 -> isFull() is true.

    Time Complexity: O(1)
    */
    // Determines if the queue is full
    bool isFull() const
    {
        return currentSize == maxSize ;
    }

    /*
    enqueue(element) - INSERT AT REAR (FIFO)

    STEP 1. Check isFull() so an occupied slot is not overwritten.
    STEP 2. Move rearIndex one step, wrapping around if necessary:

                rearIndex = (rearIndex + 1) % maxSize;

    STEP 3. Store element at queueArray[rearIndex].
    STEP 4. Increment currentSize.

    EXAMPLE A - FIRST THREE INSERTIONS (maxSize = 5)

      Start: frontIndex = 0, rearIndex = -1, currentSize = 0

      enqueue(10) -> rearIndex = 0
      enqueue(20) -> rearIndex = 1
      enqueue(30) -> rearIndex = 2

      index:         0       1       2       3       4
                   +-------+-------+-------+-------+-------+
                   |  10   |  20   |  30   |   ?   |   ?   |
                   +-------+-------+-------+-------+-------+
                      ^               ^
                    FRONT            REAR

      Logical order: 10 -> 20 -> 30

    EXAMPLE B - REUSING INDEX 0 AFTER WRAP-AROUND

      Suppose dequeue() removed 10, and then 40 and 50 were added:

      index:         0       1       2       3       4
                   +-------+-------+-------+-------+-------+
                   |  10   |  20   |  30   |  40   |  50   |
                   +-------+-------+-------+-------+-------+
                      ^       ^                       ^
                      |       |                       |
                    STALE   FRONT                    REAR

      frontIndex = 1, rearIndex = 4, currentSize = 4
      Index 0 contains a STALE value (10); it is not in the queue.

      Now enqueue(60):

          rearIndex = (4 + 1) % 5 = 0
          queueArray[0] = 60

      index:         0       1       2       3       4
                   +-------+-------+-------+-------+-------+
                   |  60   |  20   |  30   |  40   |  50   |
                   +-------+-------+-------+-------+-------+
                      ^       ^
                      |       |
                     REAR   FRONT

      Physical array:  60, 20, 30, 40, 50
      LOGICAL queue:   20 -> 30 -> 40 -> 50 -> 60
      currentSize = 5 (FULL)

    This wrap-around reuses freed array space WITHOUT shifting data.
    Time Complexity: O(1)
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
            // Move rearIndex circularly
            rearIndex = (rearIndex + 1) % maxSize ;
            queueArray[rearIndex] = element ;
            currentSize++ ;
        }
    }

    /*
    dequeue() - REMOVE AND RETURN THE FRONT VALUE

    Compared with the ORIGINAL example's void deleteQueue(), the REVISED
    int dequeue() returns the removed value to the caller.

    STEP 1. Check isEmpty() to prevent underflow.
    STEP 2. Save the original front value BEFORE changing frontIndex.
    STEP 3. Advance frontIndex circularly using % maxSize.
    STEP 4. Decrement currentSize and return the saved value.

    EXAMPLE: dequeue() after enqueue(10), enqueue(20), enqueue(30)

      Before:
        index:       0       1       2       3       4
                   +-------+-------+-------+-------+-------+
                   |  10   |  20   |  30   |   ?   |   ?   |
                   +-------+-------+-------+-------+-------+
                      ^               ^
                    FRONT            REAR

        frontElement = queueArray[0] = 10
        frontIndex = (0 + 1) % 5 = 1
        currentSize: 3 -> 2

      After:
        index:       0       1       2       3       4
                   +-------+-------+-------+-------+-------+
                   |  10   |  20   |  30   |   ?   |   ?   |
                   +-------+-------+-------+-------+-------+
                      ^       ^       ^
                     STALE  FRONT    REAR

        Returns 10; logical queue: 20 -> 30.

    IMPORTANT: The number 10 was not erased from array memory.
    It simply stopped being part of the logical queue and can be
    overwritten by a future enqueue after the rear wraps around.

    Empty-queue behavior: print a message and return -1.
    CAUTION: -1 is also a valid integer value, so it cannot always
    distinguish a failure from a successfully removed value of -1.

    Time Complexity: O(1)
    */
    // Removes the front element from the queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue." << endl ;
            return -1 ; // Return -1 as sentinel value for empty queue
        }
        else
        {
            int frontElement = queueArray[frontIndex] ;
            // Move frontIndex circularly
            frontIndex = (frontIndex + 1) % maxSize ;
            currentSize-- ;
            return frontElement ;
        }
    }

    /*
    peek() - READ FRONT WITHOUT REMOVING IT

    This returns queueArray[frontIndex], but leaves all queue state
    (frontIndex, rearIndex, currentSize) unchanged.

      Queue: FRONT -> [20] -> [30] -> [40] <- REAR
                          peek() returns 20

    Compare:
      Stack peek() = most recently pushed element (TOP).
      Queue peek() = earliest remaining enqueued element (FRONT).

    In the standard C++ std::queue interface, this is named front().
    This chapter's REVISED educational interface uses peek().

    Empty-queue behavior: print an error and return -1.
    Time Complexity: O(1)
    */
    // Returns the front element of the queue
    int peek() const
    {
        if (isEmpty())
        {
            cout << "Queue is empty. No front element." << endl ;
            return -1 ; // Return -1 as sentinel value for empty queue
        }
        return queueArray[frontIndex] ;
    }

    /*
    display() - PRINT THE LOGICAL QUEUE ORDER

    DO NOT start at queueArray[0] unless frontIndex happens to be 0.
    Wrap-around means the physical array order may differ from the
    logical FIFO order.

    KEY EXPRESSION:

        int index = (frontIndex + i) % maxSize;

    This visits exactly currentSize valid elements starting from FRONT.

    EXAMPLE AFTER WRAP-AROUND

      Array index:    0      1      2      3      4
                    +------+------+------+------+------+
                    |  60  |  20  |  30  |  40  |  50  |
                    +------+------+------+------+------+
                        ^      ^
                       REAR  FRONT

      frontIndex = 1, currentSize = 5, maxSize = 5

      i        (frontIndex + i) % maxSize        printed value
      -------------------------------------------------------
      0                  1                           20
      1                  2                           30
      2                  3                           40
      3                  4                           50
      4                  0                           60

      Output: Queue elements (front to rear): 20 30 40 50 60

    The for loop stops after currentSize elements, so it does not
    accidentally print unused or stale array slots.

    Time Complexity: O(n), where n = currentSize.
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
            cout << "Queue elements (front to rear): " ;
            for (int i = 0; i < currentSize; i++)
            {
                int index = (frontIndex + i) % maxSize ;
                cout << queueArray[index] << " " ;
            }
            cout << endl ;
        }
    }
} ;

/*
===============================================================================
MAIN() - COMPLETE EXECUTION TRACE FOR A CAPACITY-5 CIRCULAR QUEUE
===============================================================================

  Statement                 FRONT   REAR   SIZE   Logical queue
  -----------------------------------------------------------------------
  queue myQueue(5)            0      -1      0    (empty)
  enqueue(10)                0       0      1    10
  enqueue(20)                0       1      2    10 -> 20
  enqueue(30)                0       2      3    10 -> 20 -> 30
  peek() -> 10               0       2      3    unchanged
  dequeue() -> 10            1       2      2    20 -> 30
  enqueue(40)                1       3      3    20 -> 30 -> 40
  enqueue(50)                1       4      4    20 -> 30 -> 40 -> 50
  enqueue(60)                1       0      5    20 -> 30 -> 40 -> 50 -> 60
  enqueue(70) REJECTED       1       0      5    unchanged (FULL)

  At the end, rearIndex has wrapped from 4 to 0, but frontIndex is 1.
  The physical array stores [60, 20, 30, 40, 50].
  The logical queue order is 20 -> 30 -> 40 -> 50 -> 60.

  EXPECTED OUTPUT:

    Queue elements (front to rear): 10 20 30
    Front element: 10
    Queue elements (front to rear): 20 30
    Queue is full. Cannot add 70.
    Queue elements (front to rear): 20 30 40 50 60

  KEY TEACHING POINTS:
    - FIFO: enqueue at REAR, dequeue at FRONT.
    - Circular array: index 4 wraps to 0 when maxSize = 5.
    - The modulo operator (%) implements that wrap-around.
    - currentSize distinguishes an empty queue from a full one.
    - dequeue() returns a value; peek() does not remove anything.
    - Do not confuse physical array order with logical queue order.
    - The class allocates memory with new[] and frees it with delete[].
===============================================================================
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
