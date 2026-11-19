/******************************************************/
//
// File Name: Triangle.h
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 08
// Date Modified: 11-09-2026
// AI Use: No AI used.
//
/******************************************************/

#ifndef Triangle_H
#define Triangle_H
#include "Shape.h"

class Triangle : public Shape
{
    public:
        // Constructors
        Triangle() ;
        Triangle(double side1, double side2, double side3, double x, double y) ;

        // Implemented Derived Functions
        double area() const override ;
        double perimeter() const override ;
        void display() const override ;

    private:
        double side1, side2, side3 ;
} ;

#endif