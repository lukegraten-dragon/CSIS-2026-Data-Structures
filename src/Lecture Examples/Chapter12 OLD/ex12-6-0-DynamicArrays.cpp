// Dynamic Arrays

#include <iostream>

using namespace std ;

/*
Chapter 8 are called static arrays because their size was fixed at compile time. One of
the limitations of a 'static' array is that every time you execute the program, the size of
the array is fixed, so it might not be possible to use the same array to process different
data sets of the same type. One way to handle this limitation is to declare an array
that is large enough to process a variety of data sets. However, if the array is very big
and the data set is small, such a declaration would result in memory waste. On the
other hand, it would be helpful if, during program execution, you could prompt the
user to enter the size of the array and then create an array of the appropriate size. This
approach is especially helpful if you cannot even guess the array size. In this section,
you will learn how to create arrays during program execution and process such arrays.

An array created during the execution of a program is called a 'dynamic array'. To create
a dynamic array, we use the second form of the new operator.
*/

int main()
{
    int *p ;

    p = new int[10] ;
    /*
    allocates 10 contiguous memory locations, each of type int, and stores the address
    of the first memory location into p. In other words, the operator new creates an array
    of 10 components of type int, it returns the base address of the array, and the assignment
    operator stores the base address of the array into p. Thus, the statement
    */
    *p = 25 ;
    cout << "p: " << p << endl ;
    cout << "*p: " << *p << endl ;
    /*
    stores 25 into the first memory location, and the statements:
    */
    p++ ;
    *p = 35 ;
    cout << "After p++ and *p = 35" << endl ;
    cout << "p: " << p << endl ;
    cout << "*p: " << *p << endl ;
    /*
    store 35 into the second memory location. Thus, by using the increment and decrement
    operations, you can access the components of the array. Of course, after
    performing a few increment operations, it is possible to lose track of the first array
    component. C++ allows us to use array notation to access these memory locations.

    For example, the statements
    p[0] = 25 ;
    p[1] = 35 ;
    store 25 and 35 into the first and second array components, respectively. That is,
    p[0] refers to the first array component, p[1] refers to the second array component,
    and so on. In general, p[i] refers to the (i + 1)th array component. Unlike using
    pointer arithmetic, after the preceding statements execute, p still points to the first
    array component. The following for loop initializes each array component to 0:

    for (int j = 0; j < 10; j++)
        p[j] = 0 ;
    
    When the array notation is used to process the array pointed to by p, p stays fixed at
    the first memory location. Moreover, p is a dynamic array created during program
    execution.
    */

    return 0 ;
}