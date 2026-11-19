#include <iostream>
using namespace std;

/*
================================================================================
EXAMPLE 16-2: LINKED LIST OPERATOR OVERLOADING - TEACHING NOTES
================================================================================

1. Relationship to Example 16-1:
   The node structure and ordinary insert/search/delete/display operations
   remain the same. This example introduces overloaded C++ operators:

       *list            Read the data at the node pointed to by current.
       ++list            Prefix increment: advance, return the updated object.
       list++            Postfix increment: return old state, then advance.
       list1 == list2    Compare current POINTER ADDRESSES, not list contents.
       list1 != list2    Compare whether current addresses differ.
       list2 = list1     Replace list2 nodes with a DEEP COPY of list1 nodes.

2. One Node in Dynamic Memory:

       node object
       +-------------+------------------+
       | data = 10   | next = address   |
       +-------------+------------------+

3. A Singly Linked List:

       current (this example uses current as the HEAD pointer)
          |
          v
       +----------+     +----------+     +-------------+
       | 10 |  o--+---->| 20 |  o--+---->| 30 | nullptr |
       +----------+     +----------+     +-------------+

   The nodes may occupy nonadjacent addresses. The arrows represent pointers,
   NOT physically contiguous array positions.

IMPORTANT DESIGN LIMITATION:
   This example uses current BOTH as the list's head pointer AND as a movable
   cursor for ++. Advancing it loses the list object's path to earlier nodes.
   A robust design keeps a stable head and moves a separate iterator/cursor.
   See the memory-management notes near the end of the class.
================================================================================
*/

class node
{
public:
    int data ;
    node* next ;

    // Default constructor for node
    node() : data(0), next(nullptr) {}
};

class linkedList
{
private:
    node* current ; // Pointer to the head node in the linked list

public:
    // Default constructor: initializes current to nullptr
    linkedList() : current(nullptr) {}

    // Constructor that sets current to a given node pointer
    linkedList(node* ptr) : current(ptr) {}

    // Function to insert a new node at the beginning of the list
    void insertFirst(const int& newItem)
    {
        node* newNode = new node ;    // Create a new node
        newNode->data = newItem ;     // Set data for the new node
        newNode->next = current ;     // Link new node to the current head
        current = newNode ;           // Update head to new node
    }

    // Function to insert a new node at the end of the list
    void insertLast(const int& newItem)
    {
        node* newNode = new node ;    // Create a new node
        newNode->data = newItem ;     // Set data for the new node
        newNode->next = nullptr ;     // Set next to nullptr, as it will be the last node

        if (current == nullptr)       // If the list is empty, make it the first node
        {
            current = newNode ;
        }
        else
        {
            node* temp = current ;
            while (temp->next != nullptr) // Traverse to the last node
            {
                temp = temp->next ;
            }
            temp->next = newNode ;    // Append the new node at the end
        }
    }

    // Function to delete a node with the specified value
    void deleteNode(const int& deleteItem)
    {
        if (current == nullptr) // If the list is empty, do nothing
        {
            cout << "List is empty. Nothing to delete." << endl ;
            return ;
        }

        // If the item to delete is at the head of the list
        if (current->data == deleteItem)
        {
            node* temp = current ;
            current = current->next ;
            delete temp ;
            cout << "Deleted node with value " << deleteItem << " from the head of the list." << endl ;
            return ;
        }

        // Traverse to find the node to delete
        node* temp = current ;
        while (temp->next != nullptr && temp->next->data != deleteItem)
        {
            temp = temp->next ;
        }

        // If the item was not found
        if (temp->next == nullptr)
        {
            cout << "Item " << deleteItem << " not found in the list." << endl ;
        }
        else
        {
            node* nodeToDelete = temp->next ;
            temp->next = temp->next->next ;
            delete nodeToDelete ;
            cout << "Deleted node with value " << deleteItem << endl ;
        }
    }

    // Function to search for an item in the linked list
    bool search(const int& searchItem) const
    {
        node* temp = current ;
        while (temp != nullptr)
        {
            if (temp->data == searchItem) // If item is found
            {
                return true ;
            }
            temp = temp->next ;
        }
        return false ; // Item not found
    }

    // Function to display the linked list
    void display() const
    {
        node* temp = current ;
        while (temp != nullptr)
        {
            cout << temp->data << " -> " ;
            temp = temp->next ;
        }
        cout << "nullptr" << endl ;
    }

    /*
    ---------------------------------------------------------------------------
    A. DEREFERENCE OPERATOR: *list
    ---------------------------------------------------------------------------

       current
          |
          v
       [10] -> [20] -> [30] -> nullptr

       cout << *list;    // prints 10
       // Equivalent operator-call syntax: list.operator*()

    - The operator reads current->data without moving current.
    - If current == nullptr, this implementation prints an error and returns
      -1. CAUTION: -1 could also be legitimate list data; it is not a unique
      error indicator.
    - Return type is int (by VALUE), not int&. Therefore *list = 99 is not
      valid with this implementation.
    - The trailing const means the operator cannot reassign current.

    Time Complexity: O(1)
    */
    // Overload dereference operator * to return the data of the first node
    int operator*() const
    {
        if (current == nullptr)
        {
            cout << "List is empty." << endl ;
            return -1 ; // Return a default value indicating an empty list
        }
        return current->data ;
    }
    /*
    Dereference Operator *:
      - int operator*() const returns the data of the current node if it exists, 
        or -1 if the list is empty.
    */

    /*
    ---------------------------------------------------------------------------
    B. PREFIX AND POSTFIX INCREMENT: HOW THE TWO EXPRESSIONS DIFFER
    ---------------------------------------------------------------------------

    Assume both examples start with a current pointer at 10:

       BEFORE either operation:

       current
          |
          v
       [10] -> [20] -> [30] -> nullptr

    PREFIX: ++list
       1. Advance current to current->next.
       2. Return the modified list by REFERENCE (linkedList&).

               current
                  |
                  v
        [10] -> [20] -> [30] -> nullptr

       *(++list) reads 20.

    POSTFIX: list++
       1. Save the OLD state in a temporary linkedList object.
       2. Advance the original object's current pointer to the next node.
       3. Return the saved OLD state by VALUE (linkedList).

       Returned temporary:         Original list after list++:
       temp.current                list.current
            |                           |
            v                           v
           [10] ----------------------> [20] -> [30] -> nullptr
              (the original nodes are shared in this implementation)

       *(list++) reads 10, but *list AFTER that expression reads 20.

    IMPORTANT:
       The ordinary prefix and postfix diagrams above describe expression
       semantics. In THIS class, linkedList temp = *this invokes the default
       COPY CONSTRUCTOR, which SHALLOW-COPIES the current pointer. The saved
       state is NOT an independent copy of the underlying nodes.

    Both increment operations take O(1) time in this implementation.
    */
    // Overload pre-increment operator to move to the next node
    linkedList& operator++()
    {
        if (current != nullptr)
        {
            current = current->next ;
        }
        return *this ;
    }
    /*
    Pre-increment Operator ++:
      - linkedList& operator++() advances the current pointer to the next node, 
        effectively moving forward in the list.

    Explanation:
    
    1. No Parameter:
      - The prefix increment operator does not take any parameters, which 
        distinguishes it from the postfix increment operator (which takes 
        an int parameter as a dummy argument).

    2. Moving the Pointer:
      - We check if current is not nullptr (indicating that the list is not 
        empty and that current isn’t already at the end).
      - If current points to a node, we move current to the next node by 
        setting current = current->next ;.
    
    3. Returning *this:
      - After moving current, we return *this, which is a reference to the 
        modified linkedList object itself.
      - Returning *this allows us to use the result in further expressions, 
        and since it’s a reference, it avoids creating a new copy of
        the linkedList object, making it efficient.
    */

    // Overload postfix increment operator to move to the next node
    linkedList operator++(int)
    {
        linkedList temp = *this ; // Save the current state
        if (current != nullptr)
        {
            current = current->next ; // Move to the next node
        }
        return temp ; // Return the original state
    }
    /*
    Postfix Increment Operator operator++(int):
        1. The int parameter is a dummy parameter that distinguishes this 
           from the prefix increment.
        2. linkedList operator++(int) creates a copy of the current list (temp) 
           before moving to the next node.
        3. Moves the current pointer to the next node in the list.
        4. Returns the original state of the list before the move (stored in temp).
    
    Difference Between Prefix and Postfix Increment
    
    1. Prefix Increment (++list):
      - Moves current to the next node and immediately returns the updated list.
      - Useful when you want to immediately operate on the next node.

    2. Postfix Increment (list++):
      - Returns the current state of the list first, then moves current to the next node.
      - Useful when you want to use the current state, but still advance to the next node afterward.
    */

    /*
    ---------------------------------------------------------------------------
    C. ADDRESS EQUALITY IS NOT VALUE EQUALITY
    ---------------------------------------------------------------------------

       list1.current ---> [10] -> [20] -> nullptr    (nodes at addresses A, B)
       list2.current ---> [10] -> [20] -> nullptr    (nodes at addresses X, Y)

       list1 == list2  is FALSE if A != X, even though both lists contain
       the same sequence of values.

    On the other hand, two objects whose current pointers refer to the SAME
    node compare equal, even if they are different linkedList objects.
    Two empty lists (both current == nullptr) also compare equal.

    These operators perform pointer-identity comparisons, NOT element-by-
    element list comparisons. Both take O(1) time.
    */
    // Overload equality operator to compare with another linkedList's current node
    bool operator==(const linkedList& right) const
    {
        return current == right.current ;
    }
    /*
    Equality Operator ==:
      - bool operator==(const linkedList& right) const compares the current pointer 
        of this list to another linkedList object's current pointer. 
        It returns true if both point to the same node.

    */

    // Overload not-equal operator to compare with another linkedList's current node
    bool operator!=(const linkedList& right) const
    {
        return current != right.current ;
    }
    /*
    Not-equal Operator !=:
      - bool operator!=(const linkedList& right) const returns the opposite of ==.
    */

    /*
    ---------------------------------------------------------------------------
    D. DEEP-COPY ASSIGNMENT: list2 = list1
    ---------------------------------------------------------------------------

    This is COPY ASSIGNMENT (the destination object already exists).
    It is NOT the same operation as copy initialization:

        linkedList list2;      // Default constructor
        list2 = list1;        // operator=(const linkedList&) : DEEP COPY

        linkedList list3 = list1;  // Copy constructor : SHALLOW COPY here!

    Illustration of the assignment operator's intended result:

       list1.current --> [20] -> [30] -> [40] -> nullptr
                          A       B       C       (original nodes)

       list2.current --> [20] -> [30] -> [40] -> nullptr
                          X       Y       Z       (NEW nodes)

       A != X, B != Y, C != Z.
       The VALUES match, but the NODES are different objects.

    Steps used in operator=:

       STEP 1: if (this != &other)
           Avoid deleting/rebuilding the exact same object during list = list.

       STEP 2: Delete all previously owned nodes reached from current.
           Each delete frees one dynamically allocated node.

       STEP 3: Walk through the source using otherCurrent.
           Allocate a NEW destination node for each source node.

       STEP 4: Connect each new node to the end of the destination chain.

       STEP 5: return *this;
           The returned linkedList& allows chained assignments such as
           list3 = list2 = list1.

    WHY DOES THE CODE USE node** tail?

       A node* stores a node address.
       A node** stores the ADDRESS OF A node* POINTER VARIABLE.

       At the beginning, the new destination list is empty:

           current = nullptr
           tail = &current

           current
              |
              v
           nullptr

           tail ----> [the current pointer slot]

       First iteration, after *tail = new node:

           current ----> [20 | nullptr]
           tail ----> [current pointer slot]

       Then tail = &((*tail)->next):

           current ----> [20 | next = nullptr]
                                 ^
                                 |
                               tail points to THIS next-pointer slot

       Next iteration, *tail = new node:

           current ----> [20 | o---->] [30 | nullptr]
                                            ^
                                            |
                  tail moves to the new [30] node's next-pointer slot

       After the last iteration:

           current ----> [20] ----> [30] ----> [40] ----> nullptr

    Key expressions:

       node** tail = &current;     // Address of the destination head pointer
       *tail = new node;          // Fill the pointer slot with a node address
       (*tail)->data = ...;       // Initialize the newly created node
       (*tail)->next = nullptr;   // New end of the chain
       tail = &((*tail)->next);   // Point to the NEXT pointer slot

    Thus one loop handles both the FIRST node (current) and every following
    node (previousNode->next) without a separate insertion case.

    Complexity: O(m + n) time, where m is the old destination length and n is
    the source length; O(n) additional heap space for the copied nodes.

    LIMITATIONS OF THIS TEACHING IMPLEMENTATION:
       - If allocation with new throws after old nodes have been deleted,
         the original destination contents have already been lost.
       - The self-assignment check only detects the SAME linkedList object;
         it does not detect different objects sharing node addresses.
         Aliased lists can make deletion/copy unsafe.
       - There is no destructor or user-defined deep-copy constructor.
         This is not a complete, safe Rule-of-Three implementation.
    */
    // Overloaded assignment operator for deep copy
    linkedList& operator=(const linkedList& other)
    {
        if (this != &other) // Check for self-assignment
        {
            // Clear the existing list
            while (current != nullptr)
            {
                node* temp = current ;
                current = current->next ;
                delete temp ;
            }

            // Copy nodes from the other list
            node* otherCurrent = other.current ;
            node** tail = &current ; // Tail pointer to build the new list

            while (otherCurrent != nullptr)
            {
                *tail = new node ;
                (*tail)->data = otherCurrent->data ;
                (*tail)->next = nullptr ;

                tail = &((*tail)->next) ; // Move to the next position
                otherCurrent = otherCurrent->next ;
            }
        }
        return *this ;
    }
    /*
    Explanation of the Assignment Operator
    
    1. Self-Assignment Check:
      - if (this != &other) checks if we’re assigning the list to itself. 
        If this and &other are the same, the function returns immediately 
        to avoid unnecessary work.
    
    2. Clearing the Current List:
      - We first delete all nodes in the current list to avoid memory leaks.

    3. Deep Copy of other:
      - We use a pointer (otherCurrent) to traverse the other list and copy each node.
      - We maintain a tail pointer to build the new list by dynamically allocating 
        new nodes with the same data as other.
      - After copying, each node in this is a new object, independent of other.
    
    4. Returning *this:
      - The function returns *this to allow for chaining of assignment operations 
        (e.g., list3 = list2 = list1 ;).
    */
    /*
    ---------------------------------------------------------------------------
    E. MEMORY OWNERSHIP AND RULE OF THREE - IMPORTANT CAUTION
    ---------------------------------------------------------------------------

    - insertFirst() and insertLast() allocate nodes using new.
    - deleteNode() deletes matching nodes when explicitly requested.
    - This class has NO DESTRUCTOR, so remaining nodes are not released by
      the class when a linkedList object is destroyed.
    - The compiler-generated COPY CONSTRUCTOR copies the current pointer
      only (SHALLOW COPY). operator++(int) uses that copy constructor.
    - The custom operator= performs a DEEP COPY for non-aliased lists.
    - Since ++ advances current itself, the earlier nodes may become
      unreachable through that object. In main(), after list1++, the node
      containing 10 is no longer reachable through list1.current.

    In a safer design, the linked-list container would own nodes through a
    stable head pointer. A separate iterator would handle * and ++.
    A full implementation must define safe construction, destruction, and
    copying/moving (or explicitly disable copying).

    Rule of Three (for an owning, copyable class):
       1. Destructor
       2. Copy constructor
       3. Copy assignment operator

    Do NOT simply add a destructor to this class without addressing shallow
    copies and ownership: doing so can introduce DOUBLE DELETE errors.
    */
} ;

/*
================================================================================
MAIN() EXECUTION TRACE
================================================================================

1. After insertFirst(30), insertFirst(20), insertFirst(10),
   insertLast(40), and insertLast(50):

       list1.current
            |
            v
          [10] -> [20] -> [30] -> [40] -> [50] -> nullptr

2. *list1 prints 10.

3. list1++ moves list1.current from 10 to 20.
   IMPORTANT: the program uses POSTFIX ++, not prefix ++.

       list1.current
            |
            v
          [20] -> [30] -> [40] -> [50] -> nullptr

   The earlier [10] node has not been deleted; list1 can no longer reach it.

4. otherList stores one NEW node [10]. Therefore list1 == otherList
   is false because their current pointers refer to different nodes.

5. list2 = list1 invokes DEEP-COPY ASSIGNMENT:

       list1.current ---> [20] -> [30] -> [40] -> [50] -> nullptr
       list2.current ---> [20] -> [30] -> [40] -> [50] -> nullptr

   The nodes are distinct despite their equal values.

6. list1.insertLast(40) modifies ONLY list1:

       list1: [20] -> [30] -> [40] -> [50] -> [40] -> nullptr
       list2: [20] -> [30] -> [40] -> [50]         -> nullptr

7. There is no destructor in this source, so the remaining dynamically
   allocated nodes are not freed by linkedList at program end.
================================================================================
*/

int main()
{
    linkedList list1 ;

    // Inserting elements
    list1.insertFirst(30) ;
    list1.insertFirst(20) ;
    list1.insertFirst(10) ;
    list1.insertLast(40) ;
    list1.insertLast(50) ;

    // Displaying the list
    cout << "Linked List after insertions: " ;
    list1.display() ;

    // Testing overloaded operators
    cout << "Dereference operator * on head node: " << *list1 << endl ;

    //++list1 ; // Move to the next node (prefix)
    list1++ ; // Move to the next node (postfix)
    cout << "After post-increment operator++, current data is: " << *list1 << endl ;

    linkedList otherList ;
    otherList.insertFirst(10) ; // Another list to compare with

    if (list1 == otherList)
    {
        cout << "The two lists are equal (point to the same node)." << endl ;
    }
    else
    {
        cout << "The two lists are not equal (point to different nodes)." << endl ;
    }

    linkedList list2 ;
    list2 = list1 ; // Using the overloaded assignment operator

    cout << "Copied list2 (after assignment): " ;
    list2.display() ;

    // Modify list1 to check for deep copy
    list1.insertLast(40) ;
    cout << "Modified list1: " ;
    list1.display() ;

    cout << "Unchanged list2: " ;
    list2.display() ;

    return 0 ;
}
