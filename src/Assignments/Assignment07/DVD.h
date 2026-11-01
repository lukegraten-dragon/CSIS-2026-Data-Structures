/******************************************************/
//
// File Name: DVD.h
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 07
// Date Modified: 10-30-2026
// AI Use: No AI used.
//
/******************************************************/
#ifndef DVD_H
#define DVD_H
#include "Media.h"

// Define Class
class DVD: public Media
{
    public:
        DVD() ;
        DVD(std::string t, int y, int d) ;
        void display() const ;

    private:
        int duration ;
} ;

#endif