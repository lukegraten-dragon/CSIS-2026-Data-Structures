/******************************************************/
//
// File Name: Circle.cpp
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
#include "Circle.h"
using namespace std ;

Circle::Circle() : Shape()
{
    radius = 0 ;
}

Circle::Circle(double radius, double x, double y) : Shape("Circle", x, y)
{
    // Set Circle exclusive member variables
    this->radius = radius ;
}

// Calculate Area and Perimeter
double Circle::area() const
{
    return (3.1415 * pow(radius, 2)) ;
}

double Circle::perimeter() const
{
    return (2 * 3.1415 * radius) ;
}

void Circle::display() const
{
    // Display circle details
    cout << "\nShape: " << shapeName 
        << "\nCenter: (" << CenterX << ", " << CenterY << ")"
        << "\nRadius: " << radius
        << "\nArea: " << area()
        << "\nPerimeter: " << perimeter() << '\n' ;
        
}