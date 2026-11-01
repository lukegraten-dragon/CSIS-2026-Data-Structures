/******************************************************/
//
// File Name: Book.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 07
// Date Modified: 10-30-2026
// AI Use: No AI used.
//
/******************************************************/

// Implementation file for Book Class
#include <iostream>
#include "Media.h"
#include "Book.h"
using namespace std ;

Book::Book() : Media()
{
    author = "" ;
    pages = 0 ;
}

Book::Book(string t, int y, string a, int p) : Media(t, y)
{
    author = a ;
    pages = p ;
}

void Book::display() const
{
    cout << "Type: Book, " ;

    Media::display() ;
    cout << ", Author: " << author
        << ", Pages: " << pages << '\n';
}