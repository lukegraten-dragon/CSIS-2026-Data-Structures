/******************************************************/
//
// File Name: shape.h
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 08
// Date Modified: 11-09-2026
// AI Use: No AI used.
//
/******************************************************/

#ifndef Shape_H
#define Shape_H
class Shape
{
    public:
        // Constructors
        Shape() ;
        Shape(string name, double CenterX, double CenterY) ;

        // Virtual Functions (Override and Implement in derived classes)
        virtual double area() const = 0 ;
        virtual 

    protected:
        string shapeName ;
        double CenterX, CenterY ;
} ;

#endif