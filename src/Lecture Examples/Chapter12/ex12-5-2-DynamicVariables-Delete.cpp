// Delete

#include <iostream>
#include <cstring>

using namespace std ;

int main()
{
    // Suppose you have the following declaration:
    int *p ;
    // This statement declares p to be a pointer variable of type int. Next, consider the
    // following statements:
    p = new int ;  //Line 1
    *p = 54 ;      //Line 2
    p = new int ;  //Line 3
    *p = 73 ;      //Line 4

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
    or a few million times. There would be a good amount of 'memory leak'. The program
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

    ***** Most Important Note *****
    To avoid the memory leak, you should delete the memory allocated before reassigning p 
    to a new memory block Line 3. (Refer to the next example code!!!)
    */

    return 0 ;
}
