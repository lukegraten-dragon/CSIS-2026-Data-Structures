/*

*/

#include <iostream>
#include <cstring>

using namespace std ;

int main()
{
    // Suppose you have the following declaration:
    int *p;
    // This statement declares p to be a pointer variable of type int. Next, consider the
    // following statements:
    p = new int;  //Line 1
    *p = 54;      //Line 2
    p = new int;  //Line 3
    *p = 73;      //Line 4

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

    c) p after the execution of p = new int ;
                    1500
                    +---------+
                    |    54   |
                    +---------+
                    1800
        +-----+     +---------+
      p |     | --> |         |
        +-----+     +---------+
        (Pointer 'p' now points to a new address '1800', leaving the old block 
        at address '1500' still containing 54 but unreachable, causing a memory leak.)

    d) p and *p after the execution of *p = 73 ;
                    1500
                    +---------+
                    |    54   | <-- Memory Leak
                    +---------+
                    1800
        +-----+     +---------+
      p |     | --> |    73   |
        +-----+     +---------+
        (Value 73 is now stored at address 1800.)
        (The old memory block at address 1500 still contains 54 but is now unreachable.)

    Imagine what would happen if you executed statements, such as Line 3, a few thousand
    or a few million times. There would be a good amount of memory leak. The program
    might then run out of memory spaces for data manipulation, which would result in
    an abnormal termination of the program.

    The question at hand is how to avoid memory leak. When a dynamic variable is no
    longer needed, it can be destroyed; that is, its memory can be deallocated. The C11
    operator delete is used to destroy dynamic variables. The syntax to use the operator
    delete has two forms:

    delete pointerVariable ; //to deallocate a single
                             //dynamic variable
    delete [] pointerVariable ; //to deallocate a dynamically
                                //created array

    Thus, given the declarations of the previous section, the statements

    delete pp ;
    delete [] name ;
    delete str ;
    
    deallocate the memory spaces that the pointers pp, name, and str point to.
    Suppose pp and name are pointer variables, as declared previously. Notice that an
    expression such as
    
    delete pp ;
    or
    delete [] name ;

    only marks the memory spaces that these pointer variables point to as deallocated.

    Depending on the particular operating system, after these statements execute, these
    pointer variables may still contain the addresses of the deallocated memory spaces.
    In this case, we say that these pointers are 'dangling'. Therefore, if later you access the
    memory spaces via these pointers without properly initializing them, depending on
    the particular system, either the program will access a wrong memory space, which
    may result in corrupting data now stored in those spaces, or the program may terminate
    with an error message. One way to avoid this pitfall is to set these pointers to
    nullptr after the delete operation. Also note that for the operator delete to work
    properly, the pointer must point to a valid memory space.

    ---------------------------------------------------------------------------
    HOW TO PREVENT THE MEMORY LEAK IN LINES 1-4
    ---------------------------------------------------------------------------

    Original problem:

        p = new int;   // Line 1: allocate first integer
        *p = 54;       // Line 2: store 54
        p = new int;   // Line 3: overwrite the ONLY pointer to the first block
        *p = 73;       // Line 4: store 73 in the second block

    The first block remains allocated, but its address has been lost.
    This is a MEMORY LEAK.

    Corrected version (delete the first block BEFORE Line 3):

        int *p;
        p = new int;   // Line 1: allocate first integer
        *p = 54;       // Line 2: store 54

        delete p;      // Release the first block containing 54
        p = nullptr;   // Avoid leaving p as a dangling pointer

        p = new int;   // Line 3: allocate another integer
        *p = 73;       // Line 4: store 73

        delete p;      // Release the second block, too
        p = nullptr;

    MEMORY DIAGRAM (1500 and 1800 are illustrative addresses only):

    A) After Lines 1-2:

                          address 1500
        +--------+        +----------+
      p |  1500  | -----> |    54    |
        +--------+        +----------+
                           allocated

    B) After 'delete p;':

                          address 1500
        +--------+        +----------+
      p |  1500  | - - -> | RELEASED |
        +--------+        +----------+
             p still contains an old address: DANGLING POINTER.
             The released memory must NOT be accessed through *p.

    C) After 'p = nullptr;':

        +---------+       +----------+
      p | nullptr |       | RELEASED |
        +---------+       +----------+
            No valid target; p no longer holds the old address.

    D) After Lines 3-4 (new allocation):

                          address 1800
        +--------+        +----------+
      p |  1800  | -----> |    73    |
        +--------+        +----------+
                           allocated
        The first block has already been released: NO MEMORY LEAK.
        In an actual run, new may reuse address 1500 instead of 1800.

    E) After the final 'delete p; p = nullptr;':

        +---------+       Second block: RELEASED
      p | nullptr |
        +---------+       No allocated blocks remain from this example.

    KEY IDEA:
    delete frees the dynamically allocated object; it does NOT delete the
    pointer variable itself or automatically assign nullptr to it.
    Always release an owned allocation before overwriting its only pointer.

    */

    return 0 ;
}