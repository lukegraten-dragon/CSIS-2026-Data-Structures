/******************************************************/
//
// File Name: Rectangle.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 08
// Date Modified: 11-09-2026
// AI Use: No AI used.
//
/******************************************************/

#include <iostream>
#include "Rectangle.h"
using namespace std ;

Rectangle::Rectangle() : Shape()
{
    // Set default values for Rectangle
    length = 0 ;
    width = 0 ;
}

Rectangle::Rectangle(double length, double width, double x, double y) : Shape("Rectangle", x, y)
{
    // Set Rectanlge exclusive member variables
    this->length = length ;
    this->width = width ;
}

// Calculate Area and Perimeter
double Rectangle::area() const 
{
    return (length * width) ;
}

double Rectangle::perimeter() const
{
    return 2 * (length + width) ;
}

void Rectangle::display() const
{
    // Display Rectangle details
    cout << "\nShape: " << shapeName 
        << "\nCenter: (" << CenterX << ", " << CenterY << ")"
        << "\nLength: " << length << ", Width: " << width
        << "\nArea: " << area()
        << "\nPerimeter: " << perimeter() << '\n' ;
        
}