/******************************************************/
//
// File Name: DVD.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 07
// Date Modified: 10-30-2026
// AI Use: No AI used.
//
/******************************************************/

// Implementation file for DVD Class
#include <iostream>
#include "Media.h"
#include "DVD.h"
using namespace std ;

DVD::DVD() : Media()
{
    duration = 0 ;
}

DVD::DVD(string t, int y, int d) : Media(t, y)
{
    duration = d ;
}

void DVD::display() const 
{
    cout << "Type: DVD, " ;

    Media::display() ;
    cout << ", Duration: " << duration << '\n';
}