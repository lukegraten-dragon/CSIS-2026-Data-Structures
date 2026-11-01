/******************************************************/
//
// File Name: Magazine.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 07
// Date Modified: 10-30-2026
// AI Use: No AI used.
//
/******************************************************/

// Implementation file for Magazine Class
#include <iostream>
#include "Media.h"
#include "Magazine.h"
using namespace std ;

Magazine::Magazine() : Media()
{
    Magazine::Media() ;
    issueNumber = 0 ;
}

Magazine::Magazine(string t, int y, int i) : Media(t, y)
{
    Magazine::Media(t, y) ;
    issueNumber = i ;
}

void Magazine::display() const
{
    cout << "Type: Magazine, " ;

    Media::display() ;
    cout << ", Issue Number: " << issueNumber << '\n';
}