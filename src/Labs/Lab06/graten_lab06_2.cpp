/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 06 Part 2
// Date Modified: 10-28-2026
// AI Models Used: No AI Used
//
/******************************************************/
# include <iostream>

using namespace std ;

void rotate(int& value1, int& value2, int& value3)
{
    /* 
    Rotate the values of all 3 parameters:
    a, b, c -> b, c, a
    1, 2, 3 -> 2, 3, 1

    Achieves this using pointers.
    */

    // Assign pointer to the parameters' memory addresses
    int *ptr_a = &value1 ; // a's memory address
    int *ptr_b = &value2 ; // b's memory address
    int *ptr_c = &value3 ; // c's memory address

    // 'Dereference' the pointers to get the values they are referring to
    // Otherwise they will remain as raw addresses
    int x = *ptr_a ;
    int y = *ptr_b ;
    int z = *ptr_c ;

    // Rotate the original pointers by overwriting their original memory
    // addresses with the dereferenced values.
    *ptr_a = y ;
    *ptr_b = z ;
    *ptr_c = x ;

}

int main()
{
    // Pre-rotation variables
    int a = 10 ;
    int b = 20 ;
    int c = 30 ;

    cout << "Before rotation: \n"
    << "a = " << a
    << ", b = " << b
    << ", c = " << c
    << '\n' ;

    rotate(a, b, c) ;

    cout << "After rotation: \n"
    << "a = " << a
    << ", b = " << b
    << ", c = " << c
    << '\n' ;
}

/*
Post Lab Reflection:

In this lab I got to explore more on how to create pointers
and dereference them to get the values they acutally have.

I then used those dereferenced values to overwrite the original
memory each pointer had with the new values. In other words
I created the illusion of rotation by just saving values
and overwriting memory.
*/