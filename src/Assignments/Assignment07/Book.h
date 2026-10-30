/******************************************************/
//
// File Name: Book.h
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 07
// Date Modified: 10-30-2026
// AI Use: No AI used.
//
/******************************************************/

#ifndef Book_H
#define Book_H
#include "Media.h"

// Define Class
class Book: public Media
{
    public:
        // Constructors
        Book();
        Book(std::string t, int y, std::string a, int p) ;
        void display() const ;

    private:
        std::string author ;
        int pages ;
} ;

#endif