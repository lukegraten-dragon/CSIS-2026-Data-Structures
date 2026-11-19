/*
===============================================================================
 CHAPTER 17 - EXAMPLE 17-6: PRIORITY QUEUE USING A SINGLY LINKED LIST
===============================================================================

1. PRIORITY QUEUE: HIGHEST PRIORITY FIRST

   A regular queue (Examples 17-3 and 17-4) follows FIFO:
       First In, First Out.

   A priority queue instead removes the item with the HIGHEST priority.
   THIS EXAMPLE: a LARGER priority NUMBER means a HIGHER priority.

       enqueue(10, 2)
       enqueue(20, 5)
       enqueue(15, 3)
       enqueue(30, 1)

          FRONT / HIGHEST PRIORITY
                  |
                  v
           +---------+     +---------+     +---------+     +---------+
           | (20, 5) |---->| (15, 3) |---->| (10, 2) |---->| (30, 1) |---> nullptr
           +---------+     +---------+     +---------+     +---------+
               ^
               |
        peek() / dequeue()

   Each pair means (data, priority), NOT (priority, data).
   The next pointers link separately allocated nodes; they are not
   required to be adjacent in physical memory.

2. ORDERED LINKED LIST INVARIANT

   - frontNode is nullptr when the queue is empty.
   - Otherwise, frontNode points to the HIGHEST-priority node.
   - Following next pointers visits NONINCREASING priorities:
              5 >= 3 >= 2 >= 1.
   - The last node has next == nullptr.
   - For EQUAL priorities, older nodes stay before newer ones.
     This provides FIFO processing within a priority level (stable order).

3. COMPARISON WITH PREVIOUS CHAPTER 17 EXAMPLES

   17-4: REGULAR LINKED-LIST QUEUE
     enqueue: always attach to rearNode; O(1).
     dequeue: remove from frontNode; O(1).
     Needs both frontNode and rearNode for constant-time insertion.

   17-5 v2: ARRAY-BASED PRIORITY QUEUE
     Keeps LOW priority at the LEFT, HIGH priority at the RIGHT.
     enqueue: shift elements to make room; worst case O(n).
     dequeue: remove the RIGHTMOST occupied array entry; O(1).

   17-6: LINKED-LIST-BASED PRIORITY QUEUE (THIS EXAMPLE)
     Keeps HIGH priority at the FRONT (LEFT).
     enqueue: search for position, then reconnect pointers; worst O(n).
     dequeue: delete the FRONT node; O(1).
     No maxSize limit in the class; allocation depends on available memory.

4. OPERATION COSTS (n = number of stored nodes)

      Constructor        O(1)
      isEmpty()          O(1)
      enqueue()          O(n) worst case; O(1) for a new highest priority
      dequeue()          O(1)
      peek()             O(1)
      display()          O(n)
      Destructor         O(n), deleting one node at a time
      Storage            O(n) nodes, each containing data/priority/next

   No sorting is done at dequeue time. The list is kept sorted during
   every enqueue, so reading/removing its front node is quick.

5. EDUCATIONAL LIMITATIONS

   - peek()/dequeue() return -1 when empty. A stored value of -1 would
     make this sentinel ambiguous.
   - The class has a destructor but no custom copy constructor or copy
     assignment operator. Default copying shares node addresses and may
     cause dangling pointers, double deletion, or undefined behavior.
     This is the Rule of Three issue discussed in Chapter 13.
   - new node(...) can fail if dynamic memory is exhausted.
   - The class is a CUSTOM implementation, not std::priority_queue.
     A typical standard priority_queue is backed by a heap, not by a
     sorted singly linked list.

===============================================================================
*/
#include <iostream>
using namespace std ;

/*
-------------------------------------------------------------------------------
 NODE: ONE VALUE + ONE PRIORITY + ONE LINK
-------------------------------------------------------------------------------

    node* p
       |
       v
    +-------------+-------------+----------------+
    | data = 20   | priority=5  | next = address |
    +-------------+-------------+----------------+

   data     : the value the client inserts and dequeue() returns.
   priority : determines the ordering of the queue.
   next     : address of the next LOWER-OR-EQUAL priority node,
              or nullptr at the final node.

   Example:
      node* p = new node(20, 5);

   The constructor receives (value=20, prio=5), then stores:
      p->data = 20, p->priority = 5, p->next = nullptr.

   The arrow operator -> accesses members through a pointer.
   new allocates an individual node; delete releases that node.
*/
// Node class to represent each element in the priority queue
class node
{
public:
    int data ;     // Value of the element
    int priority ; // Priority of the element
    node* next ;   // Pointer to the next node

/*
NODE CONSTRUCTOR

One new node starts unlinked:

   newNode --> +---------+----------+----------------+
               |  value  |   prio   | next = nullptr |
               +---------+----------+----------------+

enqueue() later changes next to insert this node into the list.
*/
    // Constructor to initialize a node
    node(int value, int prio)
    {
        data = value ;
        priority = prio ;
        next = nullptr ;
    }
} ;

/*
-------------------------------------------------------------------------------
 PRIORITY QUEUE OBJECT STATE
-------------------------------------------------------------------------------

   The class maintains ONLY one pointer: frontNode.

   Empty queue:
        frontNode ---> nullptr

   Nonempty queue:
        frontNode
            |
            v
          (20,5) ---> (15,3) ---> (10,2) ---> nullptr

   Why no rearNode as in Example 17-4?
   In a regular queue all insertions happen at the rear. Here, insertion
   can happen at the front, middle, or end depending on priority. The
   algorithm locates the insertion position by walking the next links.

   A singly linked list uses no modulo (%) or circular array indices.
*/
class priorityQueue
{
private:
    node* frontNode ; // Pointer to the front node of the priority queue

public:
/*
PRIORITY QUEUE CONSTRUCTOR - O(1)

   priorityQueue pq;

The object begins empty because no nodes have been allocated.

   frontNode
       |
       v
     nullptr

enqueue() is responsible for allocating each later node.
*/
    // Constructor to initialize an empty priority queue
    priorityQueue()
    {
        frontNode = nullptr ;
    }

/*
DESTRUCTOR - ~priorityQueue() - O(n)

A local object, such as "priorityQueue pq;" in main(), is destroyed
automatically when its lifetime ends (normally at the end of main).

Every enqueue() uses new, so every remaining node must be deleted.
Repeated dequeue() operations accomplish this:

   BEFORE: frontNode -> (20,5) -> (15,3) -> (10,2) -> nullptr
   after 1 dequeue(): (15,3) -> (10,2) -> nullptr
   after 2 dequeue(): (10,2) -> nullptr
   after 3 dequeue(): nullptr

The loop checks isEmpty() before dequeue(), so the empty-queue
error message does NOT appear during normal cleanup.

IMPORTANT: Calling dequeue() yourself does not call the destructor.
The destructor is for the end of the entire object's lifetime.
*/
    // Destructor to free memory of all nodes
    ~priorityQueue()
    {
        while (!isEmpty())
        {
            dequeue() ;
        }
    }

/*
isEmpty() - O(1)

   frontNode == nullptr  --> true  (no first node exists)
   frontNode != nullptr  --> false (at least one node exists)

No currentSize variable is needed just to recognize the empty list.
*/
    // Determines if the priority queue is empty
    bool isEmpty() const
    {
        return frontNode == nullptr ;
    }

/*
===========================================================================
enqueue(value, priority) - INSERT IN SORTED PRIORITY ORDER
===========================================================================

GOAL: maintain HIGHEST priority at the FRONT of the linked list.
Worst-case time: O(n) for walking through existing nodes.

CASE A: empty queue OR new priority is strictly highest.

   BEFORE:
     frontNode
         |
         v
       (10,2) -------> (30,1) -------> nullptr

   enqueue(20, 5) creates newNode: (20,5) -> nullptr

   1) newNode->next = frontNode;

       newNode
          |
          v
        (20,5) -------> (10,2) -------> (30,1) -> nullptr
                          ^
                          |
                       frontNode

   2) frontNode = newNode;

       frontNode
          |
          v
        (20,5) -------> (10,2) -------> (30,1) -> nullptr

   IMPORTANT: assign newNode->next FIRST so the old list remains
   reachable. If frontNode changes first, the old head address may
   be lost. If empty, both newNode->next and old frontNode are null.

CASE B: new priority belongs in the MIDDLE or at the END.

   BEFORE:
       frontNode
           |
           v
         (20,5) --------> (10,2) --------> (30,1) -> nullptr

   enqueue(15, 3): new priority = 3 (between 5 and 2).
   current starts at (20,5). Its next node has priority 2.
   Because 2 >= 3 is FALSE, stop before (10,2).

   1) newNode->next = current->next;
   2) current->next = newNode;

   AFTER:
       frontNode
           |
           v
         (20,5) --> (15,3) --> (10,2) --> (30,1) -> nullptr
                     ^
                     |
                   newNode

   At the end, current->next is nullptr and the same two lines
   append the new node after current.

SAME-PRIORITY CASE: STABLE ORDER

   enqueue(10,3), enqueue(20,3), enqueue(30,3)

       frontNode
           |
           v
         (10,3) ---> (20,3) ---> (30,3) ---> nullptr
           older                         newer

   The while condition uses >=, so it passes over nodes that have
   an EQUAL priority, placing the new one AFTER all earlier equals.
   Thus the earlier equal-priority value is dequeued first (FIFO).

The code has two important short-circuit expressions:
   isEmpty() || frontNode->priority < priority
   current->next != nullptr && current->next->priority >= priority

|| does not read frontNode->priority when the queue is empty.
&& does not read current->next->priority if next is nullptr.
Without short-circuiting, either access could dereference nullptr.
*/
    // Inserts a new element into the priority queue
    void enqueue(int value, int priority)
    {
        // Allocate a separate heap node with (data=value, priority=priority).
        // Its constructor sets next to nullptr until we connect it.
        node* newNode = new node(value, priority) ;

        /*
        CASE A TEST:
        - isEmpty(): no old node, so the new node becomes the front.
        - frontNode->priority < priority: strictly larger new number
            should be processed before the previous front node.

        The strict < is intentional: an EQUAL priority is not inserted
        before the older front node; equality is handled by Case B.
        */
        // If the queue is empty or the new node has higher priority than the front
        if (isEmpty() || frontNode->priority < priority)
        {
            // Preserve the OLD front link before replacing frontNode:
            //   newNode -> old front -> remaining nodes.
            newNode->next = frontNode ;
            // The newly allocated node is now first and highest priority.
            frontNode = newNode ;
        }
        else
        {
            /*
            CASE B: the list already has a node with priority >= the
            new priority. Walk from frontNode until the NEXT node has
            a strictly lower priority (or until there is no next node).

            Example insertion (15,3):
                current
                |
                v
                (20,5) -> (10,2) -> (30,1) -> nullptr

                next priority = 2; 2 >= 3 is false.
                Insert new node just after current.
            */
            // Traverse the queue to find the correct position
            node* current = frontNode ;

            // Stop BEFORE the first node whose priority is LOWER than
            // the new priority. Move past all EQUAL priorities to keep
            // same-priority values in their original arrival order.
            // The nullptr test prevents dereferencing a missing next node.
            while (current->next != nullptr && current->next->priority >= priority)
            {
                current = current->next ;
            }

            /*
            POINTER RECONNECTION: DO NOT REVERSE THESE TWO ASSIGNMENTS.

            BEFORE: current ------> oldNext ------> ...
                        newNode ---> nullptr

            STEP 1: newNode->next = current->next;
                    newNode ------> oldNext ------> ...

            STEP 2: current->next = newNode;
                    current -----> newNode -----> oldNext -> ...

            When oldNext is nullptr, the new node becomes the last node.
            No existing nodes are copied or shifted; links are changed.
            */
            newNode->next = current->next ;
            current->next = newNode ;
        }
    }

/*
===========================================================================
dequeue() - REMOVE FRONT (HIGHEST PRIORITY) - O(1)
===========================================================================

The list is already sorted, so no search is necessary.

   BEFORE:
     frontNode
         |
         v
       (20,5) ------> (15,3) ------> (10,2) --> nullptr

   1) Save data = 20 and save old front address in temp:

          temp / frontNode
                   |
                   v
                (20,5) -> (15,3) -> (10,2) -> nullptr

   2) Move frontNode to the second node:

           temp         frontNode
            |               |
            v               v
          (20,5) ------> (15,3) ----> (10,2) -> nullptr

   3) delete temp;             // free the OLD front node

           frontNode
               |
               v
             (15,3) ------> (10,2) ------> nullptr

   4) Return saved data = 20.

Saving the data BEFORE delete matters: the removed node cannot be
read after its memory has been released. In this linked-list
implementation, dequeue() REALLY deletes a node (unlike Example
17-5's array, which only decreases currentSize).

If there was only ONE node, advancing frontNode sets it to nullptr.
This implementation has no rearNode to reset.

If empty, print an error and return -1 (ambiguous if data -1 is valid).
*/
    // Removes and returns the element with the highest priority
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Priority queue is empty. Cannot dequeue." << endl ;
            return -1 ; // Sentinel value for empty queue
        }

        // Save the integer RESULT and the node ADDRESS independently.
        // The integer must survive after the old node is deleted.
        int highestPriorityData = frontNode->data ; // Get the data of the front node
        node* temp = frontNode ;                   // Temporarily store the front node
        // Move the front BEFORE delete, so the remaining nodes stay reachable.
        frontNode = frontNode->next ;              // Move frontNode to the next node
        // delete releases one node created by new node(...), NOT delete[].
        // Never use temp after this statement; it is now a dangling pointer.
        delete temp ;                              // Free memory of the removed node
        return highestPriorityData ;
    }

/*
peek() - READ THE FRONT VALUE WITHOUT DELETING IT - O(1)

    frontNode
        |
        v
      (20,5) ---> (15,3) ---> (10,2) ---> nullptr

    peek() == 20; node links are not changed and no delete occurs.
    The RETURN VALUE is only data (20), not the priority (5).

    Compare Example 17-5 v2:
      Array peek():       queueArray[currentSize - 1].data
      Linked-list peek(): frontNode->data

    Empty queue: print a message and return the sentinel -1.
    'const' means this member function does not mutate its object.
*/
    // Returns the element with the highest priority without removing it
    int peek() const
    {
        if (isEmpty())
        {
            cout << "Priority queue is empty. No front element." << endl ;
            return -1 ; // Sentinel value for empty queue
        }
        return frontNode->data ;
    }

/*
display() - WALK FROM FRONT TO nullptr - O(n)

    frontNode
        |
        v
      (20,5) ---> (15,3) ---> (10,2) ---> (30,1) ---> nullptr
         ^           ^           ^           ^
         |           |           |           |
       print       print       print       print

    A TEMPORARY pointer 'current' walks the list. The actual
    frontNode stays at the original first node, so display() does
    not change the queue or its priorities.

    Output order is highest priority to lowest priority.
    Each displayed pair has the form (data, priority).
*/
    // Displays all elements in the priority queue along with their priorities
    void display() const
    {
        if (isEmpty())
        {
            cout << "Priority queue is empty." << endl ;
        }
        else
        {
            cout << "Priority queue elements (value, priority): " ;
            node* current = frontNode ;
            while (current != nullptr)
            {
                cout << "(" << current->data << ", " << current->priority << ") " ;
                current = current->next ;
            }
            cout << endl ;
        }
    }
} ;

/*
===============================================================================
 MAIN() WALKTHROUGH: PRIORITY QUEUE STATE AFTER EACH OPERATION
===============================================================================

   Queue is printed from front (highest priority) to end (lowest).

   Operation                  Contents (data, priority)
   ------------------------   ----------------------------------------------
   priorityQueue pq           Empty (frontNode = nullptr)
   enqueue(10, 2)             (10,2)
   enqueue(20, 5)             (20,5) -> (10,2)
   enqueue(15, 3)             (20,5) -> (15,3) -> (10,2)
   enqueue(30, 1)             (20,5) -> (15,3) -> (10,2) -> (30,1)
   display()                  Prints all four nodes
   peek()                     Returns 20; list unchanged
   dequeue()                  Returns 20; delete (20,5)
   display()                  (15,3) -> (10,2) -> (30,1)
   dequeue()                  Returns 15; delete (15,3)
   display()                  (10,2) -> (30,1)
   end of main                Destructor deletes (10,2), then (30,1)

   EXPECTED OUTPUT:

   Priority queue elements (value, priority): (20, 5) (15, 3) (10, 2) (30, 1)
   Front element: 20
   Priority queue elements (value, priority): (15, 3) (10, 2) (30, 1)
   Priority queue elements (value, priority): (10, 2) (30, 1)

   Note: peek() and dequeue() return VALUES, but the existing main()
   ignores the values returned by both dequeue() calls.

   CLASS DISCUSSION QUESTIONS

   1) Why does enqueue() take O(n) in the worst case?
   2) Why can dequeue() remove the highest-priority node in O(1)?
   3) What happens if two nodes have exactly the same priority?
   4) Why must newNode->next be assigned before current->next?
   5) Why does the destructor call dequeue() in a loop?
   6) What goes wrong if this class is copied with the default copy?
===============================================================================
*/
int main()
{
    priorityQueue pq ; // Create a priority queue

    pq.enqueue(10, 2) ;
    pq.enqueue(20, 5) ;
    pq.enqueue(15, 3) ;
    pq.enqueue(30, 1) ;

    pq.display() ; // Expected output: (20, 5) (15, 3) (10, 2) (30, 1)

    cout << "Front element: " << pq.peek() << endl ; // Expected output: 20

    pq.dequeue() ;
    pq.display() ; // Expected output: (15, 3) (10, 2) (30, 1)

    pq.dequeue() ;
    pq.display() ; // Expected output: (10, 2) (30, 1)

    return 0 ;
}
