#include <iostream>
using namespace std;

/*
===============================================================================
IMPORTANT - CIRCULAR SINGLY LINKED LIST: STRUCTURE AND POINTER DIAGRAMS
===============================================================================

1. The Difference Between Singly and Circular Linked Lists

   Ordinary singly linked list (Example 16-1):

      head                                            last node
       |                                                  |
       v                                                  v
      [10] ----> [20] ----> [30] --------------------> nullptr

   Circular singly linked list (this example):

      head                                      last
       |                                         |
       v                                         v
      [10] ----------> [20] ------------------> [30]
       ^                                         |
       |                                         |
       +--------------- last->next --------------+

   IMPORTANT: The final node does NOT point to nullptr.
              The last node points BACK TO the first node.

2. One Node: Its Memory Fields

        +---------------+--------------------+
        |  data : int   |   next : node*     |
        +---------------+--------------------+
        |      20       | address of node    |
        +---------------+--------------------+

   'data' stores the integer value.
   'next' stores the ADDRESS of another node, not its integer data.
   Nodes are separately allocated with 'new'; they do not have to be
   adjacent in memory.

3. Empty List and One-Node Circular List

   Empty list:             After insertFirst(10):

      head -> nullptr            head, last
      last -> nullptr                 |
                                      v
                                    [10] ----+
                                     ^       |
                                     +-------+

   With one node, head == last and head->next == head.
   That single node points to ITSELF to close the circle.

4. List Invariants (Conditions That Must Stay True)

   EMPTY list:
      head == nullptr AND last == nullptr

   NONEMPTY list:
      head != nullptr AND last != nullptr
      last->next == head

   Every node must link to the next one in the same circle.
   Starting at head and repeatedly following next eventually
   returns to head. No normal node's next is nullptr.

5. Terminology and Comparison

   This is a CIRCULAR SINGLY linked list, NOT a doubly linked list.
   Each node has 'next' only; there is no 'prev' member.

   Compared with Example 16-3:
      Doubly:   nodes have both prev and next.
      Circular: this example has only next, but last->next == head.

   A 'last' pointer makes insertLast O(1). Circularity alone does
   not make tail insertion O(1); storing last is what avoids traversal.
===============================================================================
*/

// Node structure for a circular linked list
class node
{
public:
    int data ;
    node* next ;

    // Default constructor for node
    node() : data(0) , next(nullptr) {}
} ;
/*
- class node represents each node in the circular linked list.
- Contains data to store the node's value and a next pointer to point to the next node.
*/

/*
This circularLinkedList class provides insertion at the beginning and end, 
deletion of nodes by value, and display of all nodes in a circular manner. 
The 'last' pointer maintains the circular link by always pointing back to head.
*/
class circularLinkedList
{
private:
    node* head ; // Pointer to the head node
    node* last ; // Pointer to the last node
/*
- node* head: Points to the first node in the circular linked list.
- node* last: Points to the last node in the circular linked list, 
  which helps keep the circular link intact by pointing back to head.
*/

public:
    /*
    CONSTRUCTOR - INITIAL EMPTY STATE

        head ------------> nullptr
        last ------------> nullptr

    No nodes have been allocated yet. On the FIRST insertion, both
    pointers must be updated to the same newly allocated node, and
    that node's next must point back to itself (last->next = head).
    */

    // Default constructor: initializes head and last to nullptr
    circularLinkedList() : head(nullptr) , last(nullptr) {}

    /*
    DESTRUCTOR - BREAK THE CIRCLE, THEN DELETE LIKE A LINEAR LIST

    Example list when the object is about to be destroyed:

        head                            last
         |                               |
         v                               v
        [10] --------> [20] ----------> [30]
         ^                               |
         +-------------------------------+

    A circular list has no nullptr terminator, so the destructor first
    BREAKS THE CIRCLE:

      last->next = nullptr;

    The structure then becomes an ordinary singly linked list:

        head                            last
         |                               |
         v                               v
        [10] --------> [20] ----------> [30] ----> nullptr

    After that, deletion uses the familiar nullptr-terminated loop:

      temp = head            // temp points to [10]
      nextNode = temp->next  // save address of [20]
      delete temp            // delete [10]
      temp = nextNode        // continue with [20]

      Repeat until temp == nullptr.

    WHY BREAK THE CIRCLE FIRST?
      This class already stores last, so last->next can be changed to
      nullptr in O(1) time. Once the cycle is broken, the destructor
      can use the same deletion pattern as an ordinary singly linked
      list, which gives a simple and explicit stopping condition.

    KEY MEMORY-SAFETY RULE:
      Save temp->next BEFORE executing delete temp.
      Never use temp->next after deleting temp: it is invalid then.

    Time Complexity:  O(n) to delete n nodes.
    Extra Space:      O(1) auxiliary pointer storage.

    RULE OF THREE WARNING:
      A destructor is defined, but no copy constructor or copy
      assignment operator is defined in this example.
      Compiler-generated copies duplicate only head and last
      POINTERS, NOT the dynamically allocated nodes (shallow copy).
      Two copied objects could then delete the same nodes twice.
      Do not copy this class by value unless deep-copy operations
      are implemented or copying is explicitly disabled.
    */

    // Destructor to free the allocated memory
    // First breaks the circular link, then deletes nodes as a linear list,
    // and finally resets head and last to nullptr.
    ~circularLinkedList()
    {
        if (head != nullptr)
        {
            last->next = nullptr ;   // Break the circle first

            node* temp = head ;

            while (temp != nullptr)
            {
                node* nextNode = temp->next ;
                delete temp ;
                temp = nextNode ;
            }
        }
        head = last = nullptr ;
    }

    /*
    INSERT FIRST - STEP-BY-STEP POINTER DIAGRAM

    Goal: insert 10 at the beginning of a list containing 20 and 30.

    BEFORE:

        head                     last
         |                        |
         v                        v
        [20] ------------------> [30]
         ^                        |
         +------------------------+

    Newly allocated node (not connected yet):
        newNode --> [10] --> nullptr

    STEP 1: newNode->next = head;
       New node points to the OLD head.

        [10] ----> [20] ----------> [30]
                   ^                |
                   +----------------+

    STEP 2: head = newNode;
       Head now points to the new node [10].

        head
         |
         v
        [10] ----> [20] ----------> [30]
                   ^                |
                   +----------------+

    STEP 3: last->next = head;
       Repair the circle so the last node points to the NEW head.

        head                                last
         |                                   |
         v                                   v
        [10] ----------> [20] ------------> [30]
         ^                                   |
         +-----------------------------------+

    EMPTY-LIST CASE:
      head = last = newNode;  // both pointers identify the same node
      last->next = head;      // self-link closes the one-node circle

    WHY THE ORDER MATTERS:
      Preserve a link to the old head before changing head.
      Then update last->next to maintain the circular invariant.

    Time Complexity: O(1), regardless of the list length.
    */

    // Function to insert a new node at the beginning of the list
    void insertFirst(const int& newItem)
    {
        node* newNode = new node ;   // Create a new node

        newNode->data = newItem ;    // Set data manually

        if (head == nullptr)         // If the list is empty, initialize head and last
        {
            head = last = newNode ;
            last->next = head ;      // Link last to head, forming a circular structure
        }
        else
        {
            newNode->next = head ;   // Link new node to the current head
            head = newNode ;         // Update head to new node
            last->next = head ;      // Update last to point to the new head
        }
    }
    /*
    1. Creates a new node with data set to newItem.
    2. If the list is empty, head and last are set to the new node, and last->next is 
       set to head to establish the circular link.
    3. If the list is not empty:
       - The new node points to the current head.
       - head is updated to the new node.
       - last->next is updated to point to the new head.
    */

    /*
    INSERT LAST - STEP-BY-STEP POINTER DIAGRAM

    Goal: insert 30 after existing nodes 10 and 20.

    BEFORE:

        head                  last
         |                     |
         v                     v
        [10] ---------------> [20]
         ^                     |
         +---------------------+

    STEP 1: last->next = newNode;
       Link the OLD last node to [30].

        [10] ---> [20] ---> [30] -> nullptr

    STEP 2: last = newNode;
       Move the tail pointer to [30].

        [10] ---> [20] ---> [30] <- last

    STEP 3: last->next = head;
       Close the circle from the NEW last node to head.

        head                                last
         |                                   |
         v                                   v
        [10] ----------> [20] ------------> [30]
         ^                                   |
         +-----------------------------------+

    EMPTY-LIST CASE:
      head = last = newNode;
      last->next = head;  // same node links back to itself

    TIME COMPLEXITY: O(1)
      Thanks to 'last', we do not need a loop to find the end.
    */

    // Function to insert a new node at the end of the list
    void insertLast(const int& newItem)
    {
        node* newNode = new node ;   // Create a new node
        
        newNode->data = newItem ;    // Set data manually

        if (head == nullptr)         // If the list is empty, initialize head and last
        {
            head = last = newNode ;
            last->next = head ;      // Link last to head, forming a circular structure
        }
        else
        {
            last->next = newNode ;   // Link current last to new node
            last = newNode ;         // Update last to new node
            last->next = head ;      // Update last to point to head, keeping it circular
        }
    }
    /*
    1. Similar to insertFirst, but adds the node at the end of the list.
    2. If the list is empty, head and last are set to the new node, 
       with last->next pointing to head.
    3. Otherwise:
       - The current last->next is set to the new node.
       - last is updated to the new node, and last->next is updated to head 
         to maintain the circular link.
    */

    /*
    DELETE NODE - FOUR CASES WITH POINTER DIAGRAMS

    deleteNode(deleteItem) searches from head and removes only the
    FIRST node whose data equals deleteItem.

    SEARCH VARIABLES:
      temp -> node being examined
      prev -> node immediately BEFORE temp in traversal order

    At each unsuccessful step:
      prev = temp;
      temp = temp->next;

    The do-while condition 'temp != head' prevents an endless loop.
    If the search returns to head, the item does not exist.

    CASE A: EMPTY LIST
        head = nullptr, last = nullptr
        -> Nothing to delete; print an informational message.

    CASE B: ONE NODE - delete 10

        head, last                 After deletion:
            |                       head -> nullptr
            v                       last -> nullptr
           [10] --+
            ^     |
            +-----+

      delete head;
      head = last = nullptr;

    CASE C: DELETE HEAD - delete 10 from [10, 20, 30]

      BEFORE:
        head                           last
         |                              |
         v                              v
        [10] --------> [20] ---------> [30]
         ^                              |
         +------------------------------+

      head = head->next;  // new head is [20]
      last->next = head;  // circle now closes at [20]
      delete temp;        // release old node [10]

      AFTER:
          head              last
           |                 |
           v                 v
          [20] -----------> [30]
           ^                 |
           +-----------------+

    CASE D: DELETE LAST - delete 30 from [10, 20, 30]

      BEFORE:
        head                           last
         |                              |
         v                              v
        [10] --------> [20] ---------> [30]
         ^                              |
         +------------------------------+

      prev points to [20]; temp points to [30].
      prev->next = head;  // [20] -> [10]
      last = prev;        // last now points to [20]
      delete temp;        // release [30]

      AFTER:
          head              last
           |                 |
           v                 v
          [10] -----------> [20]
           ^                 |
           +-----------------+

    CASE E: DELETE MIDDLE - delete 20 from [10, 20, 30]

      BEFORE:
        head                           last
         |                              |
         v                              v
        [10] --------> [20] ---------> [30]
         ^               ^              |
         |             temp             |
         +------------------------------+
        prev -> [10]

      prev->next = temp->next; // [10] bypasses [20], points to [30]
      delete temp;             // release isolated node [20]

      AFTER:
          head              last
           |                 |
           v                 v
          [10] -----------> [30]
           ^                 |
           +-----------------+

    NOTE ON THE FIRST MATCH:
      If the list contains duplicate values, this function deletes
      the FIRST matching node and then returns immediately.

    Time Complexity: O(n) for searching in the worst case.
    Changing links and deleting a KNOWN node is O(1) when the
    required predecessor pointer is already available.
    */

    // Function to delete a node with the specified value
    void deleteNode(const int& deleteItem)
    {
        if (head == nullptr) // If the list is empty, do nothing
        {
            cout << "List is empty. Nothing to delete." << endl ;
            return ;
        }

        node* temp = head ;
        node* prev = nullptr ;

        // Check if head node contains the item to delete
        do
        {
            if (temp->data == deleteItem) // If node is found
            {
                if (temp == head) // If deleting the head node
                {
                    if (head == last) // Only one node in the list
                    {
                        delete head ;
                        head = last = nullptr ;
                    }
                    else
                    {
                        head = head->next ;
                        last->next = head ; // Update last to point to new head
                        delete temp ;
                    }
                }
                else if (temp == last) // If deleting the last node
                {
                    prev->next = head ; // Update previous node to point to head
                    last = prev ;       // Update last to the previous node
                    delete temp ;
                }
                else // Deleting a middle node
                {
                    prev->next = temp->next ;
                    delete temp ;
                }
                cout << "Deleted node with value " << deleteItem << endl ;
                return ;
            }
            prev = temp ;
            temp = temp->next ;
        } while (temp != head) ;

        cout << "Item " << deleteItem << " not found in the list." << endl ;
    }
    /*
    1. Deletes the first node with a value matching deleteItem.
    2. Traverses the list starting from head, keeping track of the previous node (prev).
    3. Handles cases:
       - Head node: Updates head to head->next and adjusts last->next to point to the new head.
       - Last node: Updates prev->next to head and updates last to prev.
       - Middle node: prev->next is updated to temp->next to bypass the deleted node.

    */

    /*
    DISPLAY - WHY CIRCULAR TRAVERSAL USES DO-WHILE

    Compare termination conditions:
      Ordinary singly linked list: stop when temp == nullptr.
      Circular linked list:        stop when temp == head AGAIN.

    Circular list:

        head                                last
         |                                   |
         v                                   v
        [10] ----------> [20] ------------> [30]
         ^                                   |
         +-----------------------------------+

    Trace of display() with these three nodes:

      Before loop: temp = head (node 10)

      Iteration 1: print 10; temp = 20; 20 != head -> continue
      Iteration 2: print 20; temp = 30; 30 != head -> continue
      Iteration 3: print 30; temp = 10; 10 == head -> stop

      Printed result:
        10 -> 20 -> 30 -> (back to head)

    WHY DO-WHILE?
      The body executes before checking the stopping condition,
      allowing the first node to be processed exactly once.
      The method FIRST checks head != nullptr to handle empty lists.

    DO NOT use while (temp != nullptr) on a proper circular list:
      it would keep visiting the same nodes forever.

    Time Complexity: O(n) to visit each of n nodes exactly once.
    */

    // Function to display the list
    void display() const
    {
        if (head == nullptr)
        {
            cout << "List is empty." << endl ;
            return ;
        }

        node* temp = head ;
        do
        {
            cout << temp->data << " -> " ;
            temp = temp->next ;
        } while (temp != head) ;
        cout << "(back to head)" << endl ;
    }
    /*
    Traverses the list from head and prints each node’s data until it circles back to head.
    */
} ;

/*
===============================================================================
SUMMARY - OPERATION COSTS AND MEMORY-SAFETY NOTES
===============================================================================

Operation                Time         Explanation
----------------------   ----------   ----------------------------------------
insertFirst(newItem)     O(1)         Update head and last->next.
insertLast(newItem)      O(1)         'last' avoids searching for the tail.
deleteNode(value)        O(n)         May search all n nodes.
display()                O(n)         Visits each node once.
~circularLinkedList()    O(n)         Breaks the circle, then deletes each node.

SPACE:
  Storing n nodes takes O(n) total memory.
  Each insertion creates one node with new.
  The methods above use O(1) extra working pointer storage.

DESTRUCTOR DESIGN:
  The destructor intentionally changes last->next from head to nullptr
  before deletion. This temporarily converts the circular list into a
  linear singly linked list so deletion can stop at nullptr.

COMPARE WITH PRIOR EXAMPLES:
  Example 16-1: ordinary singly list; tail->next == nullptr.
  Example 16-3: doubly list; prev + next support both directions.
  Example 16-4: circular singly list; last->next == head during normal use.

CAUTION - RULE OF THREE:
  This example owns dynamic nodes and defines a destructor but does
  not define a copy constructor or copy assignment operator.
  A default shallow copy can lead to shared nodes and double deletion.
  A production implementation should handle ownership and copying.

MAIN EXECUTION TRACE:

  insertFirst(30) : 30 -> (back to head)
  insertFirst(20) : 20 -> 30 -> (back to head)
  insertFirst(10) : 10 -> 20 -> 30 -> (back to head)
  insertLast(40)  : 10 -> 20 -> 30 -> 40 -> (back to head)
  insertLast(50)  : 10 -> 20 -> 30 -> 40 -> 50 -> (back to head)
  deleteNode(20)  : 10 -> 30 -> 40 -> 50 -> (back to head)
  deleteNode(50)  : 10 -> 30 -> 40 -> (back to head)
  deleteNode(60)  : no change (60 not found)

IMPORTANT TAKEAWAY:
  After every insertion or deletion of a NONEMPTY circular list,
  the essential invariant remains: last->next == head.
===============================================================================
*/

int main()
{
    circularLinkedList cList ;

    // Inserting elements at the beginning
    cList.insertFirst(30) ;
    cList.insertFirst(20) ;
    cList.insertFirst(10) ;

    // Inserting elements at the end
    cList.insertLast(40) ;
    cList.insertLast(50) ;

    // Displaying the list
    cout << "Circular Linked List: " ;
    cList.display() ;

    // Deleting nodes
    cList.deleteNode(20) ;
    cList.deleteNode(50) ;
    cList.deleteNode(60) ; // Trying to delete a non-existent item

    // Displaying the list after deletions
    cout << "Circular Linked List after deletions: " ;
    cList.display() ;

    return 0 ;
}
