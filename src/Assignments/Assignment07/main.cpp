/******************************************************/
//
// File Name: graten_07.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 07
// Date Modified: 10-30-2026
// AI Use: No AI used.
//
/******************************************************/

#include <iostream>

#include "Book.h"
#include "Magazine.h"
#include "DVD.h"

int main() {
    // Create objects of the derived classes
    Book book("The Catcher in the Rye", 1951, "J.D. Salinger", 277);
    Magazine magazine("National Geographic", 2023, 102);
    DVD dvd("The Matrix", 1999, 136);

    // Display the details of each media
    book.display();
    magazine.display();
    dvd.display();

    return 0;
}

/*
Compilation Command:
g++ main.cpp Media.cpp Book.cpp Magazine.cpp DVD.cpp -o main.out

Reflection:
    In this lab I got to learn how to apply class inheritance
    to create derived classes with common member functions and
    variables.

    A minor challenge I encountered was with separating
    class declarations and implementations in separate files.
    I initially forgot to implement header guards, so my program
    wouldn't compile correctly. But after reviewing the example
    code I included them, making program compile properly.

    Another challenge was implementing the constructors.
    I initially thought that I could call the base class constructors
    inside the derived class constructor, but that wasn't the case.

    Derived::Derived(args) : Media(args)

    With this fix, the member variables were properly being
    set, and would appear in the program output.

    Type: Book, Title: , Year: 0, Author: J.D. Salinger, Pages: 277 // [Bad output]
    Type: Book, Title: The Catcher in the Rye, Year: 1951, Author: J.D. Salinger, Pages: 277 // [Good output]

*/
