// Shallow versus Deep Copy and Pointers

#include <iostream>
#include <iomanip>

using namespace std ;

int main()
{
    int *first ;
    int *second ;

    first = new int[5] ;
    /*
              +-----+-----+-----+-----+-----+
    first --->|     |     |     |     |     |
              +-----+-----+-----+-----+-----+    
    */

    for (int i=0; i < 5; i++)
        first[i] = i + 1 ;
    /*
               +-----+-----+-----+-----+-----+
    first ---->|  1  |  2  |  3  |  4  |  5  |
               +-----+-----+-----+-----+-----+    
    */

    second = first ;
    /*
               +-----+-----+-----+-----+-----+
    first ---->|  1  |  2  |  3  |  4  |  5  |
               +-----+-----+-----+-----+-----+     
                  ^
                  |
    second -------+
    */

    delete [] second ;
    /*
    After this statement executes, the array pointed to by second is deleted.

    first  ---->
    
    second ---->

    Because first and second point to the same array, after the statement

    delete [] second ;
    
    executes, first becomes invalid; that is, first (as well as second) are now dangling
    pointers. Therefore, if the program later tries to access the memory pointed to by
    first, either the program will access the wrong memory or it will terminate in an
    error. This case is an example of a shallow copy. More formally, in a "shallow copy",
    two or more pointers of the same type point to the same memory; that is, they point
    to the same data.
    */
    
    /*
    On the other hand, suppose that instead of the earlier statement, second = first;, 
    we have the following statements:
    */
    second = new int[5] ;

    for (int j = 0; j < 5; j++)
        second[j] = first[j] ;

    /*
    The first statement creates an array of 10 components of type int, and the base address
    of the array is stored in second. The second statement copies the array pointed to by
    first into the array pointed to by second

               +-----+-----+-----+-----+-----+
    first ---->|  1  |  2  |  3  |  4  |  5  |
               +-----+-----+-----+-----+-----+

               +-----+-----+-----+-----+-----+
    second --->|  1  |  2  |  3  |  4  |  5  |
               +-----+-----+-----+-----+-----+

    Both first and second now point to their own data. If second deletes its memory,
    there is no effect on first. This case is an example of a deep copy. More formally, in
    a "deep copy", two or more pointers of the same type each point to their own copy of
    the data.
    From the preceding discussion, it follows that you must know when to use a shallow
    copy and when to use a deep copy.

    */

    return 0 ;
}
