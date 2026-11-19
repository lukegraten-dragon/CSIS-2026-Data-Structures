/******************************************************/
//
// File Name: Triangle.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 08
// Date Modified: 11-09-2026
// AI Use: No AI used.
//
/******************************************************/

#include <iostream>
#include <cmath>
#include "Triangle.h"
using namespace std ;

Triangle::Triangle() : Shape()
{
    // Set default values for Triangle
    side1 = 0 ;
    side2 = 0 ;
    side3 = 0 ;
}

Triangle::Triangle(double side1, double side2, double side3, double x, double y) : Shape("Triangle", x, y)
{
    // Set Triangle exclusive member variables
    this->side1 = side1 ;
    this->side2 = side2 ;
    this->side3 = side3 ;
}

// Calculate Area and Perimeter
double Triangle::area() const
{
    // Herons formula note
    // s = semiperimeter
    // s = (1/2) * perimeter()
    // s = (1/2) * (a + b + c)

    // Area
    // sqrt(s(s-a) * (s-b) * (s-c))
    double semiP = perimeter() ;
    return sqrt(semiP*(semiP-side1) * (semiP-side2) * (semiP-side3)) ;
}

double Triangle::perimeter() const
{
    // Perimeter = a + b + c
    return (side1 + side2 + side3) ;
}

void Triangle::display() const
{
    // Display Triangle details
    cout << "\nShape: " << shapeName 
        << "\nCenter: (" << CenterX << ", " << CenterY << ")"
        << "\nSides " << side1 << ", " << side2 << ", "  << side3
        << "\nArea: " << area()
        << "\nPerimeter: " << perimeter() << '\n' ;
        
}