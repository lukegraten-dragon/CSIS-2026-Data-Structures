/******************************************************/
//
// File Name: Media.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 07
// Date Modified: 10-30-2026
// AI Use: No AI used.
//
/******************************************************/

// Implementation file for Media Class
#include <iostream>
#include "Media.h"
using namespace std ;

Media::Media()
{
    title = "" ;
    year = 0 ;
}

Media::Media(string t, int y)
{
    title = t ;
    year = y ;
}

void Media::display() const
{
    cout << "Title: " << title
        << ", Year: " << year ;
}