/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 09 Part 1
// Date Modified: 11-19-2026
// AI Models Used: No AI Used
//
/******************************************************/

#include <iostream>
using namespace std ;

// COPIED AS-IS FROM
// ex16-1-linkedList v2.cpp 

// TASK: Implement member functions
// deleteFirst()
// deleteLast()

// Code I add for this lab will be delimited using a comment bar /######/

/*
IMPORTANT - SINGLY LINKED LIST OVERVIEW

1. What Is a Linked List?
   A linked list is a dynamic data structure made of nodes.
   Each node stores:
     - data  : the value in the node
     - next  : a pointer to the next node

   Unlike an array, linked-list elements are NOT stored as one
   contiguous block that we access by index. Instead, each node is
   created separately in dynamic memory and connected by pointers.

2. Node Picture:

      +-------------------+
      | data |   next     |
      +-------------------+

   Example of one node:

      +---------------------------+
      | data = 20 | next = 0xABCD |
      +---------------------------+

   Here, the node stores the integer 20 and the address of the next node.

3. Linked Structure Picture:

      current
         |
         v
      +---------+      +---------+      +---------+
      |  10 | --+----> |  20 | --+----> |  30 | / |
      +---------+      +---------+      +---------+
                                              |
                                              v
                                           nullptr

   - current points to the first node of the list.
   - Each next pointer links one node to the next node.
   - The last node points to nullptr, which marks the end of the list.

4. Important Idea:
   Linked-list insertion and deletion are done by changing pointers,
   not by shifting all elements as in an array-based list.

5. About the Name current:
   In this example, the variable named current actually plays the role
   of the HEAD pointer of the list. It stores the address of the first
   node, not just a temporary current position.
*/

class node
{
public:
    int data ;
    node* next ;

    // Default constructor for node
    // Initializes the node with data = 0 and next = nullptr.
    // nullptr means this node is not currently linked to another node.
    node() : data(0), next(nullptr) {}
} ;

class linkedList
{
private:
    node* current ; // Head pointer: points to the first node in the linked list

public:
    // Default constructor:
    // Creates an empty linked list.
    // When current is nullptr, the list contains no nodes.
    linkedList() : current(nullptr) {}

    // Constructor that sets current to a given node pointer.
    // This allows the list to start from an already existing node.
    // In this program, main() uses the default constructor instead.
    linkedList(node* ptr) : current(ptr) {}

    /*
    insertFirst(newItem)

    Purpose:
      Insert a new node at the beginning of the list.

    Before:
         current
            |
            v
          [10] -> [20] -> [30] -> nullptr

    After insertFirst(5):
         current
            |
            v
           [5] -> [10] -> [20] -> [30] -> nullptr

    Steps:
      1. Create a new node.
      2. Store newItem in the node.
      3. Make the new node point to the old first node.
      4. Move current so it points to the new node.

    Time Complexity: O(1)
    No traversal is needed.
    */
    void insertFirst(const int& newItem)
    {
        node* newNode = new node ;    // Create a new node in dynamic memory

        newNode->data = newItem ;     // Store the new value
        newNode->next = current ;     // Link the new node to the old head
        current = newNode ;           // Update head to the new node
    }

    /*
    insertLast(newItem)

    Purpose:
      Insert a new node at the end of the list.

    If the list is empty:
         current
            |
            v
         nullptr

      insertLast(40)

         current
            |
            v
          [40] -> nullptr

    If the list is not empty:
         current
            |
            v
          [10] -> [20] -> [30] -> nullptr

      insertLast(40)

         current
            |
            v
          [10] -> [20] -> [30] -> [40] -> nullptr

    Key idea:
      We must traverse the list until we reach the last node,
      which is the node whose next is nullptr.

    Time Complexity: O(n)
    The current version does not store a tail pointer,
    so we must start from the head and walk to the end.
    */
    void insertLast(const int& newItem)
    {
        node* newNode = new node ;    // Create a new node

        newNode->data = newItem ;     // Set data for the new node
        newNode->next = nullptr ;     // It will be the last node

        if (current == nullptr)       // If the list is empty, make it the first node
        {
            current = newNode ;       // current points to the newNode address in memory
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

    /*
    deleteNode(deleteItem)

    Purpose:
      Delete the first node whose data matches deleteItem.

    Important cases handled:
      1. The list is empty.
      2. The node to delete is the first node (head).
      3. The node to delete is in the middle or at the end.
      4. The item is not found.

    Why do we need the previous node?
      In a singly linked list, each node only knows the address of the NEXT node.
      Therefore, to remove a node, we must first find the node BEFORE it,
      so we can change its next pointer.

    Example: delete 20 from

         current
            |
            v
          [10] -> [20] -> [30] -> [40] -> nullptr

      temp points to 10.
      nodeToDelete points to 20.

      Before relinking:
         [10] ----> [20] ----> [30]

      After:
         [10] ----------------> [30]
                delete [20]

    Core statement:
         temp->next = temp->next->next;

    This skips over the node being deleted.

    Time Complexity: O(n)
    In the worst case, we may search through the whole list.
    */
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

        // Traverse to find the node BEFORE the node to delete.
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

    /*
    search(searchItem)

    Purpose:
      Traverse the list and check whether searchItem exists.

    Traversal pattern used in linked lists:
      node* temp = current;
      while (temp != nullptr)
      {
          ... process temp ...
          temp = temp->next;
      }

    Example traversal:
         current
            |
            v
         [10] -> [20] -> [30] -> nullptr

      temp visits:
         10, then 20, then 30, then nullptr

    Return value:
      true  : item found
      false : item not found

    Time Complexity: O(n)
    */
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

    /*
    display()

    Purpose:
      Print all nodes from the head to the end of the list.

    Example output:
      10 -> 20 -> 30 -> nullptr

    The word nullptr at the end means:
      "There is no next node after this point."

    This function uses the same traversal pattern as search().

    Time Complexity: O(n)
    */
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
    NOTE ABOUT MEMORY MANAGEMENT

    This example dynamically allocates nodes using new,
    but it does NOT define a destructor.

    That means when the linkedList object goes out of scope,
    any remaining nodes are not automatically deleted by this class.

    For a production-quality linked list, we should add:
      - a destructor
      - a copy constructor
      - a copy assignment operator

    This connects to the Rule of Three.

    Example destructor idea:

      ~linkedList()
      {
          while (current != nullptr)
          {
              node* temp = current;
              current = current->next;
              delete temp;
          }
      }
    */

    /*#############################################################################*/
    // deleteFirst()

    void deleteFirst()
    {
        // 1. Initialize a temporary node pointer (temp) to the first element or head in the
        // linked list.
        node* temp = current ;

        if (temp == nullptr)
        {
            // Check if the list is empty, if so abort function.
            cout << "Sorry, list is empty. Cannot delete anything..." << '\n' ;
            return ;
        }

        // 2. Move the head (current) to the next node
        // e.g current -> 20 NOT current -> 10
        current = current->next ;

        // 3. Delete the dynamically allocated memory that temp is pointing
        // using delete.
        delete temp ;

        // 4. Nullify our temporary pointer we created earlier to delete the memory
        // now that its been deallocated.
        temp = nullptr ;
    }

    // deleteLast()
    void deleteLast()
    {
        // 1. Initialize a temporary node pointer (temp) that
        // points to the head of the linked list. 
        node* temp = current ;
        node* nodeToDelete ;

        if (temp == nullptr)
        {
            // Check if the list is empty, if so abort function.
            cout << "Sorry, list is empty. Cannot delete anything..." << '\n' ;
            return ;
        }

        // 2. Navigate temp to the end of the list so it
        // points to the second to last node.
        while (temp != nullptr)
        {
            temp = temp->next ; // Dereference the next pointer in the chain and
                                // assign it to temp.

            // cout << "Temp is currently: " << temp->data << '\n'; // DEBUG

            if (temp->next->next == nullptr)
            {
                // Check if pointer after next node is nullptr, if so,
                // we are in the second to last node of the linked list.
                // Then we should break out of this loop.
                break ;
            }
        }

        // 3. Point nodeToDelete to the node after
        // temp is currently pointing to (second to last)
        nodeToDelete = temp->next ;

        // cout << "Dereference nodeToDelete: " << nodeToDelete->data << '\n'; // DEBUG

        // 4. Change temp->next (currently pointing to the the last node)
        // so it points to the nullptr. The list now terminates at this node.
        temp->next = nullptr ;

        // 5. Delete the dynamically allocated memory that temp is pointing
        // using delete.
        delete nodeToDelete ;

        // 5. Nullify the temporary pointers we created to deallocate the memory.
        temp = nullptr ;
        nodeToDelete = nullptr ;
    }

    /*#############################################################################*/
} ;

int main()
{
    linkedList list ;

    // Inserting elements
    list.insertFirst(30) ;
    list.insertFirst(20) ;
    list.insertFirst(10) ;
    list.insertLast(40) ;
    list.insertLast(50) ;

    // Displaying the list
    cout << "Linked List after insertions: " ;
    list.display() ;

    /*#############################################################################*/
    // Delete the first node
    list.deleteFirst() ;

    cout << "Deleted the first node from the list." << '\n' ;
    cout << "Linked List after deleteFirst(): " ;
    list.display() ;

    // Delete the last node
    list.deleteLast() ;


    cout << "Deleted the last node from the list." << '\n' ;
    cout << "Linked List after deleteLast(): " ;
    list.display() ;

    cout << "Linked List after deleting first and last nodes: " ;
    list.display() ;
    /*#############################################################################*/

    // // Searching for elements
    // int searchValue = 20 ;
    // if (list.search(searchValue))
    // {
    //     cout << "Item " << searchValue << " found in the list." << endl ;
    // }
    // else
    // {
    //     cout << "Item " << searchValue << " not found in the list." << endl ;
    // }

    // searchValue = 60 ;
    // if (list.search(searchValue))
    // {
    //     cout << "Item " << searchValue << " found in the list." << endl ;
    // }
    // else
    // {
    //     cout << "Item " << searchValue << " not found in the list." << endl ;
    // }

    // // Deleting nodes
    // list.deleteNode(20) ;
    // list.deleteNode(50) ;
    // list.deleteNode(60) ; // Trying to delete a non-existent item

    // // Displaying the list after deletions
    // cout << "Linked List after deletions: " ;
    // list.display() ;

    return 0 ;
}

/*
Lab Reflection:
In this lab section I got to implement a delete first
and delete function to delete the first or last nodes of a
singly linked list.

Implementing the deleteFirst() function was easy, as I just needed
to create a temporary node pointer, reassign the node current (head)
was pointing at, delete the allocated memory of the node
that temp pointed to, and nullify the temp pointer.

The challenge I encountered was for deleteLast(). I needed to
successfully navigate through the linked list and somehow stop
at the second to last node. I ended up implementing a conditional
that broke out of the loop whenever the node pointer after the next node
was nullptr. 

After that, the deletion process was the same.

*/