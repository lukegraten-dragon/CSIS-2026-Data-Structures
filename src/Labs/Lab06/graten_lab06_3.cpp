/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 06 Part 3
// Date Modified: 10-19-2026
// AI Models Used: No AI Used
//
/******************************************************/

# include <iostream>

using namespace std ;

int main()
{
    // Initialize array of 5 objects
    int my_array[5] = {10, 20, 30, 40, 50} ;
    int *pointer_address ;

    // Dereference the initial element
    pointer_address = &my_array[0] ;

    cout << "Array elements: " ;
    
    for (int i = 0 ; i < 5 ; i++)
    {
        // Test: Print out all memory addresses in the array
        // So I can better understand how this works.
        // pointer_address = &my_array[i] ;
        /*
        0x16b3ae340
        0x16b3ae344
        0x16b3ae348
        0x16b3ae34c
        0x16b3ae350 
        */

        // Get the value for the ith element
        // using pointer arithmetic
        int address_value = *(pointer_address + i) ;

        // Print the value of the ith element
        cout << address_value << " " ;
    }

    cout << '\n' ;

    // Print the values of the 2nd and 4th element using
    // pointer arithmetic
    int address_value_2 = *(pointer_address + 1);
    cout << "Second Element: " << address_value_2 << '\n' ;

    int address_value_4 = *(pointer_address + 3);
    cout << "Fourth Element: " << address_value_4 << '\n' ;

    return 0 ;
}

/*
Post Lab Reflection:
As an alternative to using array subcripting array[i]
I used pointer arithmetic to increment over the memory addresses of
the elements in an array.

I then dereferenced the contents of the array elements using a loop to
print every integer value. Finally, I retrieved the values of specific array
elements using pointer arithmetic as well.
*/