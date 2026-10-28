/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 06 Part 1
// Date Modified: 10-28-2026
// AI Models Used: No AI Used
//
/******************************************************/
# include <iostream>

using namespace std ;

int main()
{
    int a = 50 ;
    
    // Declare a pointer that references the address of var a
    int *ptr = &a ;

    // Display the value of the pointer (dereference)
    cout << "Value of a using pointer: " << *ptr << '\n' ;

    // Change the value of var a via the pointer
    *ptr = 75 ;

    // Display the value of a
    cout << "Modified value of a: " << a << '\n' ;
}

/*
Post-Lab Reflection:

In this lab exercise I learned how to use a pointer
to reference the memory address of a variable and then modify that variable
by overwriting a new value to the address of that variable through
a pointer.
*/