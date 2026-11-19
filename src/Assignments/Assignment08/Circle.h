/******************************************************/
//
// File Name: Circle.h
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 08
// Date Modified: 11-09-2026
// AI Use: No AI used.
//
/******************************************************/

#ifndef Circle_H
#define Circle_H
#include "Shape.h"

class Circle: public Shape
{
    public:
        // Constructors
        Circle() ;
        Circle(double radius, double x, double y) ;

        // Implemented Derived Functions
        double area() const override ;
        double perimeter() const override ;
        void display() const override ;

    private:
        double radius ;
} ;

#endif