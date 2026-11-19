/******************************************************/
//
// File Name: Shape.cpp
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
#include "Shape.h"
using namespace std ;

// Constructors
Shape::Shape()
{
    // Default Constructor
    shapeName = "Undefined" ;
    CenterX = 0 ;
    CenterY = 0 ;
}

Shape::Shape(string shapeName, double CenterX, double CenterY)
{
    this->shapeName = shapeName ;
    this->CenterX = CenterX ;
    this->CenterY = CenterY ;
}

// Setters and Getters
void Shape::setCenter(double CenterX, double CenterY)
{
    this->CenterX = CenterX ;
    this->CenterY = CenterY ;
}

double Shape::getCenterX()
{
    return CenterX ;
}

double Shape::getCenterY()
{
    return CenterY ;
}

double Shape::distanceTo(Shape* other) const
{
    // Implement Euclidean distance calculation
    // Handle nullptrs safely without
    // dereferencing the pointer
    // (to avoid nullptr exception)

    // Note on 2D Euclidean Distance
    // d = sqrt( [(x_2 - x_1]^2 + [(y_2 - y_1]^2 )

    // Check if other object pointer is nullptr
    if (other == nullptr)
    {
        cout << "Distance calculation failed, cannot dereference a null pointer!" << '\n' ;
        return 0 ;
    }
    else
    {
        return sqrt(pow((other->CenterX - CenterX), 2) + pow((other->CenterY - CenterY), 2)) ;
    }
}
