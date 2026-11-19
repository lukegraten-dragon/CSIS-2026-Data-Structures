/******************************************************/
//
// File Name: Shape.h
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
        Shape(std::string shapeName, double CenterX, double CenterY) ;

        // Shape setter and getter functions
        void setCenter(double CenterX, double CenterY) ;
        double getCenterX() ;
        double getCenterY() ;

        // Calculate the Euclidean Distance Between this shape
        // and another shape
        double distanceTo(Shape* other) const ;

        // Virtual Functions (Override and Implement in derived classes)
        virtual double area() const = 0 ;
        virtual double perimeter() const = 0 ;
        virtual void display() const = 0 ;

        // Virtual Destructor
        virtual ~Shape() {} ;

    protected:
        std::string shapeName ;
        double CenterX, CenterY ;
} ;

#endif