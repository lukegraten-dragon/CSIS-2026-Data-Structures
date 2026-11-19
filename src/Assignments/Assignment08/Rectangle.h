/******************************************************/
//
// File Name: Rectangle.h
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 08
// Date Modified: 11-09-2026
// AI Use: No AI used.
//
/******************************************************/

#ifndef Rectangle_H
#define Rectangle_H
#include "Shape.h"

class Rectangle: public Shape
{
    public:
        // Constructors
        Rectangle() ;
        Rectangle(double length, double width, double x, double y) ;

        // Implemented Derived Functions
        double area() const override ;
        double perimeter() const override ;
        void display() const override ;

    private:
        double length ;
        double width ;
} ;

#endif