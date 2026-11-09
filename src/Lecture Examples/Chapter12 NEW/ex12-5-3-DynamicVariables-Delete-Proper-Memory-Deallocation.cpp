// Proper Memory Deallocation

/*
Here's the modified version of the code and comments, which includes corrections 
for memory management and avoids memory leaks by ensuring that dynamic memory is 
properly deallocated:
*/

#include <iostream>
#include <cstring>

using namespace std ;

int main()
{
    // Suppose you have the following declaration:
    int *p ;
    // This statement declares p to be a pointer variable of type int.
    
    // Allocate dynamic memory and assign its address to p.
    p = new int ;  // Line 1: p points to newly allocated memory.
    *p = 54 ;      // Line 2: Assign value 54 to the memory location pointed to by p.
    
    // Free the previously allocated memory before allocating new memory to avoid memory leaks.
    delete p ;     // Free the memory allocated in Line 1.

    // Allocate new dynamic memory and assign its address to p.
    p = new int ;  // Line 3: p points to a new memory location.
    *p = 73 ;      // Line 4: Assign value 73 to the new memory location pointed to by p.

    // Free the memory allocated in Line 3 to avoid memory leaks.
    delete p ;     // Free the memory allocated in Line 3.

    // Set p to nullptr after deleting the memory to avoid dangling pointer issues.
    p = nullptr ;

    /*
    a) p after the execution of p = new int ;
                    1500
        +-----+     +---------+
      p |     | --> |         |
        +-----+     +---------+
        (Pointer 'p' now holds the address '1500', where memory is allocated.)

    b) p and *p after the execution of *p = 54 ;
                    1500
        +-----+     +---------+
      p |     | --> |    54   |
        +-----+     +---------+
        (Value 54 is now stored at address 1500.)

    c) After delete p, the memory at address '1500' is freed, and 'p' should be set 
       to nullptr to avoid a dangling pointer.

    d) p after the execution of p = new int ;
                    1800
        +-----+     +---------+
      p |     | --> |         |
        +-----+     +---------+
        (Pointer 'p' now points to a new address '1800'.)

    e) p and *p after the execution of *p = 73 ;
                    1800
        +-----+     +---------+
      p |     | --> |    73   |
        +-----+     +---------+
        (Value 73 is now stored at address 1800.)

    f) After delete p, the memory at address '1800' is freed, and 'p' should be set 
       to nullptr to avoid a dangling pointer.

    Without the 'delete' statement before reallocating p, the memory allocated 
    in Step b would be lost, causing a memory leak. Repeated allocation without 
    proper deletion would eventually exhaust available memory.

    To avoid this, it's crucial to free dynamic memory when it's no longer needed 
    using the delete operator:

    delete pointerVariable ;    // to deallocate a single dynamic variable
    delete [] pointerVariable ; // to deallocate a dynamically created array

    After freeing the memory, it is good practice to set the pointer to nullptr 
    to prevent it from becoming a dangling pointer.
    */

    return 0 ;
}
