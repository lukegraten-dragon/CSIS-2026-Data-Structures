/*
In the previous sections, you learned how to declare pointer variables, how to store
the address of a variable into a pointer variable of the same type as the variable, and
how to manipulate data using pointers. However, you learned how to use pointers to
manipulate data only into memory spaces that were created using other variables. In
other words, the pointers manipulated data into already existing memory spaces. But
you could have accessed these memory spaces through the variables that were used
to create them. So what is the benefit of using pointers? In this section, you will learn
about the power behind pointers. In particular, you will learn how to allocate and
deallocate memory during program execution using pointers.

Variables that are created during program execution are called 'dynamic variables'.
With the help of pointers, C++ creates dynamic variables. C++ provides two operators,
'new' and 'delete', to create and destroy dynamic variables, respectively. When a
program requires a new variable, the operator new is used. When a program no longer
needs a dynamic variable, the operator delete is used.

In C++, new and delete are reserved words.
*/

#include <iostream>
#include <cstring>

using namespace std ;

int main()
{
    // Operator 'new'
    // The operator new has two forms: one to allocate a single variable and another to allocate
    // an array of variables. The syntax to use the operator new is:

    // new dataType ;          //to allocate a single variable
    // new dataType[intExp] ;  //to allocate an array of variables

    // in which intExp is any expression evaluating to a positive integer.
    // The operator new allocates memory (as a variable) of the designated type and returns
    // a pointer to it — that is, the address of this allocated memory. Moreover, the allocated
    // memory is uninitialized.
    //
    // Consider the following declaration:
    int *p ;
    char *q ;
    int x ;
    
    // The statement
    p = &x ;
    // stores the address of x in p. However, no new memory is allocated. 

    // On the other hand, consider the following statement:
    p = new int ;
    // This statement creates a variable during program execution somewhere in memory
    // and stores the address of the allocated memory in p. The allocated memory is accessed
    // via pointer dereferencing—namely, *p. 
    
    // Similarly, the statement
    q = new char[16] ;
    // creates an array of 16 components of type char and stores the base address of the
    // array in q.

    // Because a dynamic variable is unnamed, it cannot be accessed directly. It is accessed
    // indirectly by the pointer returned by new. The following statements illustrate this
    // concept:

    int *pp ;       //pp is a pointer of type int
    char *name ;    //name is a pointer of type char
    string *str ;   //str is a pointer of type string
    
    pp = new int ;   //allocates memory of type int and stores
                     //the address of the allocated memory in p

    *pp = 28 ;       //stores 28 in the allocated memory

    name = new char[5] ;   //allocates memory for an array of five
                           //components of type char and stores the
                           //base address of the array in name

    strcpy(name, "John") ; //stores John in name
    cout << "name: " << name << endl ;

    str = new string ;  //allocates memory of type string
                        //and stores the address of the
                        //allocated memory in str

    *str = "Sunny Day" ; //stores the string "Sunny Day" in
                         //the memory pointed to by str
    cout << "*str: " << *str << endl ;

    return 0 ;
}