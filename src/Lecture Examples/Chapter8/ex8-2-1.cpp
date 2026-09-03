// Accessing Array Components
#include <iostream>

using namespace std ;

int main()
{ 
    const int ARRAY_SIZE = 10 ;
    int list[ARRAY_SIZE] ;

    // When you declare an array, its size must be specified. 
    // For example, you cannot do the following:
    int arraySize ;                           //Line 1

    cout << "Enter the size of the array: " ; //Line 2
    cin >> arraySize ;                        //Line 3
    cout << endl ;                            //Line 4

    int list[arraySize];                      //Line 5; not allowed

    // The statement in Line 2 asks the user to enter the size of 
    // the array when the program executes. The statement in Line 3 
    // inputs the size of the array into arraySize. When the compiler 
    // compiles Line 1, the value of the variable arraySize is unknown. 
    // Thus, when the compiler compiles Line 5, the size of the array 
    // is unknown and the compiler will not know how much memory space 
    // to allocate for the array. In Chapter 12, you will learn how to 
    // specify the size of an array during program execution and then 
    // declare an array of that size using pointers. Arrays that are 
    // created by using pointers during program execution are called 
    // 'dynamic arrays'. For now, whenever you declare an array, 
    // its size must be known.
}