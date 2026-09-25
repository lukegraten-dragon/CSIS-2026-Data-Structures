/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 04 Part 2
// Date Modified: 09-24-2026
//
/******************************************************/

# include <iostream>
# include <iomanip>

using namespace std ;

int main ()
{
    char printedChar = '*' ;
    int rowAmount ;

    // Request user input
    cout << "Enter a number of rows: " ;
    cin >> rowAmount ;
    

    // Print the triangle
    // i -> row iteration level
    // j -> character slot to be printed
    for (int i = 0 ; i <= rowAmount ; i++)
    {
        // Outer loop: Set the row.
        for (int k = 0 ; k < (rowAmount - i) ; k++)
        {
            // Create the spaces
            cout << setw(2) << ' ' ;
        }

        for (int j = 0 ; j < i ; j++)
        {
            // Print the character inside the row
            cout << setw(2) << printedChar ;
        }
        cout << '\n' ;
    }

    return 0 ;
}

/*
Post Lab Reflection:

This lab section was somewhat difficult.

First I created a nested loop structure. Where the amount of rows 
would iterate through the outer loop. The inner loop
would then be responsible for printing out the number of *

This created the triangle. But to invert it, I
calculated that in the reference example where the triangle is
correctly position each space before
the * was equivalent to (rowAmount = i), where i
was the iterator variable in the outermost loop.

Using a dual-nested loop structure I printed the necessary amount of spaces
before I printed all the required * .

*/