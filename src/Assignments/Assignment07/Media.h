/******************************************************/
//
// File Name: Media.h
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 07
// Date Modified: 10-30-2026
// AI Use: No AI used.
//
/******************************************************/

#ifndef Media_H
#define Media_H
class Media
{
    public:
        // Constructor
        Media() ;
        Media(std::string t, int y) ;

        // Public Functions
        void display() const ;

    private:
        std::string title ;
        int year ;
} ;
#endif