/******************************************************/
//
// File Name: graten_07.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 07
// Date Modified: 10-28-2026
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
Reflection:
Write your required reflection here. Replace this instruction text with a short
but meaningful paragraph describing what you learned from completing Assignment 07.
Your reflection may discuss inheritance, base and derived classes, constructors,
const member functions, reusing Media::display(), challenges you encountered,
and how you solved them.
*/
