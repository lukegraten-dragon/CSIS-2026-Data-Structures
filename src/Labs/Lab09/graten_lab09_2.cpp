/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 09 Part 2
// Date Modified: 11-19-2026
// AI Models Used: No AI Used
//
/******************************************************/

#include <iostream>
using namespace std ;

// COPIED AS-IS FROM
// ex16-3-doublyLinkedList v2.cpp 

// TASK: Implement member functions
// deleteFirst()
// deleteLast()

// Code I add for this lab will be delimited using a comment bar /######/

/*
===============================================================================
IMPORTANT - DOUBLY LINKED LIST: NODE STRUCTURE AND POINTER LINKS
===============================================================================

1. Comparison with a Singly Linked List (Example 16-1):

   Singly linked list:                 Doubly linked list:

     [10] --> [20] --> [30]             [10] <--> [20] <--> [30]
       next pointer only                 next AND prev pointers

   A doubly linked list supports traversal in BOTH directions.
   Each node contains one integer value and TWO node pointers.

2. One dNode object (conceptual memory layout):

   +----------------+-------------+----------------+
   | prev : dNode*  | data : int  | next : dNode*  |
   +----------------+-------------+----------------+
       points to       node value      points to
       previous node                  next node

   Both prev and next store ADDRESSES, not integer values.
   A default-constructed node starts with data = 0 and both
   pointer members equal to nullptr.

3. A complete doubly linked list containing 10, 20, and 30:

      head                                             last
       |                                                |
       v                                                v
   nullptr <- [10] <----------> [20] <----------> [30] -> nullptr
               |                  |                  |
               +-- prev/next links connect adjacent nodes --+

   Forward direction:  head -> 10 -> 20 -> 30 -> nullptr
   Backward direction: last -> 30 -> 20 -> 10 -> nullptr

   IMPORTANT INVARIANTS:
   - Empty list: head == nullptr AND last == nullptr.
   - First node: head->prev == nullptr.
   - Last node:  last->next == nullptr.
   - For two neighboring nodes A and B:
         A->next == B  AND  B->prev == A.
   - One-node list: head == last (both point to that node).

   NOTE: A list's nodes are individually allocated with new.
   They do not have to be adjacent in memory as array elements are.
===============================================================================
*/

// Node structure for a doubly linked list
class dNode
{
public:
    int data ;
    dNode* next ;  // Pointer to the next node in the list.
    dNode* prev ;  // Pointer to the previous node in the list.

    // Default constructor for dNode
    dNode() : data(0), next(nullptr), prev(nullptr) {}
} ;

class doublyLinkedList
{
private:
    dNode* head ; // Points to the first node (head) of the list.
    dNode* last ; // Points to the last node (tail) of the list, 
                  // allowing easy insertion at the end and backward traversal.

public:
    /*
    CONSTRUCTOR - EMPTY LIST

        head ---> nullptr
        last ---> nullptr

    There is no allocated node yet. The FIRST insertion must update
    BOTH head and last; otherwise one end of the list would be invalid.
    */
    // Default constructor: initializes head and last to nullptr
    doublyLinkedList() : head(nullptr), last(nullptr) {}

    /*
    DESTRUCTOR - RELEASE ALL NODES (O(n) TIME, O(1) EXTRA SPACE)

    Example when the list still contains three nodes:

        head
         |
         v
        [10] <--> [30] <--> [40] --> nullptr

      Iteration 1: save [10], move head to [30], delete [10]
      Iteration 2: save [30], move head to [40], delete [30]
      Iteration 3: save [40], move head to nullptr, delete [40]

    The destructor does not need to repair prev links because the
    ENTIRE list is being destroyed. The saved temp pointer makes it
    possible to delete the old head after moving to the next node.

    MEMORY-SAFETY CAUTION (Rule of Three):
    This class defines a destructor, but it does NOT define a copy
    constructor or copy assignment operator. The compiler-generated
    copying operations would copy head and last POINTER VALUES, not
    clone the nodes. Copying this list by value can lead to sharing
    nodes and double deletion (undefined behavior).

    Do not treat this version as safely copyable. A full implementation
    needs appropriate deep-copy operations or disabled copying.
    */
    // Destructor to free the allocated memory
    ~doublyLinkedList()
    {
        while (head != nullptr)
        {
            dNode* temp = head ;
            head = head->next ;
            delete temp ;
        }
    }

    /*
    INSERT FIRST - POINTER DIAGRAM

    Goal: insert value 10 before an existing list [20] <--> [30].

    BEFORE:
        head                       last
         |                          |
         v                          v
        [20] <------------------> [30]

        newNode ---> [10]   (prev = nullptr, next = nullptr)

    STEP 1: newNode->next = head;
        [10] ------next------> [20] <--> [30]

    STEP 2: head->prev = newNode;
        [10] <---------------> [20] <--> [30]
              next / prev

    STEP 3: head = newNode;
        head                                    last
         |                                       |
         v                                       v
        [10] <---------------> [20] <---------> [30]

    For an EMPTY list, head = last = newNode. Because the node's
    constructor already set prev and next to nullptr, both boundary
    pointers are correct.

    The ORDER of assignments matters: connect the new node to the
    existing head BEFORE replacing head with the new node.

    TIME COMPLEXITY: O(1) - no traversal of existing nodes.
    */
    // Function to insert a new node at the beginning of the list
    void insertFirst(const int& newItem)
    {
        dNode* newNode = new dNode ;   // Create a new node using the default constructor
        
        newNode->data = newItem ;      // Set data manually

        if (head == nullptr)           // If the list is empty, set head and last to new node
        {
            head = last = newNode ;
        }
        else
        {
            newNode->next = head ;     // Link new node to the current head
            head->prev = newNode ;     // Link current head to new node as previous
            head = newNode ;           // Update head to new node
        }
    }
    /*
    1. Inserts a new node at the beginning of the list.
    2. Creates a new dNode and sets data to newItem.
    3. If the list is empty (head == nullptr), both head and last are set to the new node.
    4. If the list isn’t empty:
       - The new node’s next pointer is set to the current head.
       - The current head node’s prev pointer is set to the new node.
       - head is updated to the new node.
    */
    
    /*
    INSERT LAST - POINTER DIAGRAM

    BEFORE:
        head                         last
         |                            |
         v                            v
        [10] <---------------------> [20]

        newNode ---> [30]   (prev = nullptr, next = nullptr)

    STEP 1: newNode->prev = last;
        [10] <--> [20] <---prev--- [30]

    STEP 2: last->next = newNode;
        [10] <--> [20] <--------> [30]
                   next / prev

    STEP 3: last = newNode;
        head                                    last
         |                                       |
         v                                       v
        [10] <---------------> [20] <---------> [30]

    For an EMPTY list, head = last = newNode.

    WHY IS THIS FASTER THAN insertLast() IN EXAMPLE 16-1?
    The last pointer already gives the address of the final node.
    There is no need to traverse from the head to find the end.
    A singly linked list WITH a maintained tail pointer could also
    achieve O(1) append; the improvement is due to storing last.

    TIME COMPLEXITY: O(1).
    */
    // Function to insert a new node at the end of the list
    void insertLast(const int& newItem)
    {
        dNode* newNode = new dNode ;   // Create a new node using the default constructor
        
        newNode->data = newItem ;      // Set data manually

        if (last == nullptr)           // If the list is empty, set head and last to new node
        {
            head = last = newNode ;
        }
        else
        {
            newNode->prev = last ;     // Link new node to the current last node
            last->next = newNode ;     // Link current last node to new node as next
            last = newNode ;           // Update last to new node
        }
    }
    /*
    1. Inserts a new node at the end of the list.
    2. Creates a new dNode and sets data to newItem.
    3. If the list is empty, both head and last are set to the new node.
    4. If the list isn’t empty:
       - The new node’s prev pointer is set to the current last.
       - The current last node’s next pointer is set to the new node.
       - last is updated to the new node.
    */

    /*
    DELETE NODE - THREE CASES AND TWO-WAY RECONNECTION

    The function first searches from head for the FIRST node whose
    data == deleteItem. If there are duplicate values, only the first
    matching node is removed. If no match exists, nothing is deleted.

    CASE A - DELETE HEAD (for example, delete 10):

      BEFORE: head
               |
               v
              [10] <--> [20] <--> [30]

      head = head->next;         // head now points to [20]
      head->prev = nullptr;      // [20] no longer has a predecessor
      delete temp;              // free the old [10] node

      AFTER:          head
                       |
                       v
                      [20] <--> [30]

      If the old head was the ONLY node, new head is nullptr;
      the code also resets last = nullptr.

    CASE B - DELETE LAST (for example, delete 30):

      BEFORE:                     last
                                   |
                                   v
              [10] <--> [20] <--> [30]

      last = last->prev;         // last now points to [20]
      last->next = nullptr;      // [20] has no successor
      delete temp;              // free the old [30] node

      AFTER:            last
                         |
                         v
              [10] <--> [20]

    CASE C - DELETE A MIDDLE NODE (for example, delete 20):

      BEFORE:
            temp->prev       temp          temp->next
                |             |               |
                v             v               v
               [10] <------> [20] <--------> [30]

      STEP 1: temp->prev->next = temp->next;
              [10] --------next--------> [30]

      STEP 2: temp->next->prev = temp->prev;
              [10] <-------prev--------- [30]

      STEP 3: delete temp;

      AFTER:
               [10] <-----------------> [30]

      The TWO assignments are required to preserve links in BOTH
      directions. A singly linked list only reconnects next links.

    IMPORTANT:
    - Relink the neighbors BEFORE deleting the node.
    - Do not access temp after delete temp; it is a dangling pointer.
    - The head and last cases avoid dereferencing missing neighbors.

    TIME COMPLEXITY: O(n) overall because the value must be searched.
    Once a node pointer is already known, unlinking it takes O(1).
    */
    // Function to delete a node with the specified value
    void deleteNode(const int& deleteItem)
    {
        if (head == nullptr) // If the list is empty, do nothing
        {
            cout << "List is empty. Nothing to delete." << endl ;
            return ;
        }

        dNode* temp = head ;

        // Traverse to find the node to delete
        while (temp != nullptr && temp->data != deleteItem)
        {
            temp = temp->next ;
        }

        // If the item was not found
        if (temp == nullptr)
        {
            cout << "Item " << deleteItem << " not found in the list." << endl ;
        }
        else
        {
            // If the node to delete is the head
            if (temp == head)
            {
                head = head->next ;
                if (head != nullptr)
                    head->prev = nullptr ;
                else // If the list is now empty, reset last
                    last = nullptr ;
            }
            // If the node to delete is the last node
            else if (temp == last)
            {
                last = last->prev ;
                if (last != nullptr)
                    last->next = nullptr ;
            }
            // If the node is in the middle
            else
            {
                temp->prev->next = temp->next ;
                temp->next->prev = temp->prev ;
            }
            delete temp ;
            cout << "Deleted node with value " << deleteItem << endl ;
        }
    }
    /*
    1. Deletes a node containing the specified deleteItem value.
    2. Traverses the list from head to find the node with data == deleteItem.
    3. If the node isn’t found (temp == nullptr), displays a message and exits.
    4. If the node is found:
       - If it’s the head node:
         - head is updated to the next node, and head->prev is set to nullptr.
         - If the list is now empty, last is set to nullptr.
       - If it’s the last node:
         - last is updated to the previous node, and last->next is set to nullptr.
       - If it’s a middle node:
         - The node’s prev pointer is updated to bypass the node and connect directly 
           to the next node.
         - The node’s next pointer is updated similarly to connect to the prev node.
    5. Deletes the targeted node to free its memory.
    */

    /*
    FORWARD TRAVERSAL - FOLLOW next

      head                               last
       |                                  |
       v                                  v
      [10] <--> [20] <--> [30] <--> [40] <--> [50]
       ^        ^        ^        ^        ^
       1        2        3        4        5   (visit order)

      temp = head;
      while (temp != nullptr)
      {
          // print temp->data
          temp = temp->next;
      }

    displayForward() does NOT change head or last. It only moves
    the local temp pointer from node to node.

    Example output:
      10 <-> 20 <-> 30 <-> 40 <-> 50 <-> nullptr

    TIME COMPLEXITY: O(n).
    */
    // Function to display the list from head to last
    void displayForward() const
    {
        dNode* temp = head ;
        while (temp != nullptr)
        {
            cout << temp->data << " <-> " ;
            temp = temp->next ;
        }
        cout << "nullptr" << endl ;
    }
    /*
    1. Traverses and displays the list from head to last.
    2. Each node’s data is printed followed by <->, showing 
       the bidirectional link between nodes.
    3. Ends with nullptr to indicate the end of the list.
    */

    /*
    BACKWARD TRAVERSAL - FOLLOW prev

      head                               last
       |                                  |
       v                                  v
      [10] <--> [20] <--> [30] <--> [40] <--> [50]
       ^        ^        ^        ^        ^
       5        4        3        2        1   (visit order)

      temp = last;
      while (temp != nullptr)
      {
          // print temp->data
          temp = temp->prev;
      }

    The code does not reverse the list or change any connections.
    It simply follows prev pointers starting from last.

    Example output:
      50 <-> 40 <-> 30 <-> 20 <-> 10 <-> nullptr

    TIME COMPLEXITY: O(n).
    */
    // Function to display the list from last to head
    void displayBackward() const
    {
        dNode* temp = last ;
        while (temp != nullptr)
        {
            cout << temp->data << " <-> " ;
            temp = temp->prev ;
        }
        cout << "nullptr" << endl ;
    }
    /*
    1. Traverses and displays the list from last to head.
    2. Each node’s data is printed followed by <->, showing 
       the bidirectional link in reverse.
    3. Ends with nullptr to indicate the start of the list.
    */

    /*#############################################################################*/
    // BEGIN LAB CODE
    void deleteFirst()
    {
        // 1. Initialize a temporary node pointer (temp) to the first element or head in the
        // linked list.
        dNode* temp = head ;

        if (head == nullptr)
        {
            // Check if the list is empty, if so abort function.
            cout << "Sorry, list is empty. Cannot delete anything..." << '\n' ;
            return ;
        }

        // 2. Move the head to the next node in the doubly linked
        // list. HEAD -> 30
        head = temp->next ;

        // 3. Delete the memory allocated to the first node
        // This deletes the entire allocated object, including its pointers.
        delete temp ;

        // 4. Nullify the temporary pointer we created
        // for deallocating memory.
        temp = nullptr ;

        // 5. At the new head, configure the dNode its
        // pointing at to have its prev pointer
        // be updated to the nullptr instead of the
        // deleted dNode's address
        head->prev = nullptr ;
    }

    void deleteLast()
    {
        // 1. Initialize a temporary node pointer (temp) to the last node in the
        // linked list.
        dNode* temp = last ;

        if (last == nullptr)
        {
            // Check if the list is empty, if so abort function.
            cout << "Sorry, list is empty. Cannot delete anything..." << '\n' ;
            return ;
        }

        // 2. Move the last pointer to the previous node in the doubly linked
        // list. LAST -> 40
        last = temp->prev ;

        // 3. Delete the memory allocated to the last node
        // This deletes the entire allocated object, including its pointers.
        delete temp ;

        // 4. Nullify the temporary pointer we created
        // for deallocating memory.
        temp = nullptr ;

        // 5. At the new last endpoint, configure the dNode its
        // pointing at to have its next pointer
        // be updated to the nullptr instead of the
        // deleted dNode's address
        last->next = nullptr ;
    }
    // END LAB CODE
    /*#############################################################################*/
} ;

/*
===============================================================================
MAIN PROGRAM - EXECUTION TRACE AND COMPLEXITY SUMMARY
===============================================================================

Insertion trace:

    insertFirst(30):   [30]
    insertFirst(20):   [20] <--> [30]
    insertFirst(10):   [10] <--> [20] <--> [30]
    insertLast(40):    [10] <--> [20] <--> [30] <--> [40]
    insertLast(50):    [10] <--> [20] <--> [30] <--> [40] <--> [50]

Deletion trace:

    deleteNode(20):    [10] <--> [30] <--> [40] <--> [50]
    deleteNode(50):    [10] <--> [30] <--> [40]
    deleteNode(60):    Item not found; the list stays unchanged.

Expected output:

    List (Forward): 10 <-> 20 <-> 30 <-> 40 <-> 50 <-> nullptr
    List (Backward): 50 <-> 40 <-> 30 <-> 20 <-> 10 <-> nullptr
    Deleted node with value 20
    Deleted node with value 50
    Item 60 not found in the list.
    List after deletions (Forward): 10 <-> 30 <-> 40 <-> nullptr
    List after deletions (Backward): 40 <-> 30 <-> 10 <-> nullptr

Complexity (n = number of nodes currently in the list):

    Operation             Time            Extra space
    -------------------------------------------------
    insertFirst()         O(1)            O(1) per new node
    insertLast()          O(1)            O(1) per new node
    deleteNode(value)     O(n)            O(1)
    displayForward()      O(n)            O(1)
    displayBackward()     O(n)            O(1)
    ~doublyLinkedList()   O(n)            O(1)

Teaching points:
    1. Node = data + prev pointer + next pointer.
    2. Keep both ends (head and last) correct after every change.
    3. Update BOTH directions when linking or unlinking neighbors.
    4. A destructor frees allocated nodes, but safe copying still
       requires the Rule of Three to be addressed.
===============================================================================
*/

int main()
{
    doublyLinkedList dList ;

    // Inserting elements at the beginning
    dList.insertFirst(30) ;
    dList.insertFirst(20) ;
    dList.insertFirst(10) ;

    // Inserting elements at the end
    dList.insertLast(40) ;
    dList.insertLast(50) ;

    /*#############################################################################*/
    // BEGIN LAB CODE
    cout << "Linked List after insertions: " ;
    dList.displayForward() ;

    dList.deleteFirst() ;
    cout << "Deleted the first node from the list." << '\n' ;
    cout << "Linked List after deleteFirst(): " ;
    dList.displayForward() ;
    // dList.displayBackward() ; 


    dList.deleteLast() ;
    cout << "Deleted the last node from the list." << '\n' ;
    cout << "Linked List after deleteLast(): " ;
    dList.displayForward() ;
    // dList.displayBackward() ;

    cout << "Linked List after deleting first and last nodes: " ;
    dList.displayForward() ;
    // END LAB CODE
    /*#############################################################################*/

    // // Displaying the list from head to last
    // cout << "List (Forward): " ;
    // dList.displayForward() ;

    // // Displaying the list from last to head
    // cout << "List (Backward): " ;
    // dList.displayBackward() ;

    // // Deleting nodes
    // dList.deleteNode(20) ;
    // dList.deleteNode(50) ;
    // dList.deleteNode(60) ; // Trying to delete a non-existent item

    // // Displaying the list after deletions
    // cout << "List after deletions (Forward): " ;
    // dList.displayForward() ;

    // cout << "List after deletions (Backward): " ;
    // dList.displayBackward() ;

    return 0 ;
}

/*
Lab Section Reflection:

In this lab section, I implemented a custom deleteFirst() and deleteLast()
function to delete the first and last nodes in a doubly linked list.

Since there were pointers for both the head and the last node, this lab
was considerably easier in some ways, as I didn't have to navigate through
the list to reach the end.

The process was largely the same as the first section, create temporary pointer,
move endpoint pointer (head/last), delete allocated node memory,
nullify temporary pointer. 

At the end I needed to adjust
the prev or next pointer (depending on the delete function)
so it was nullptr (to properly terminate the list agains).
*/