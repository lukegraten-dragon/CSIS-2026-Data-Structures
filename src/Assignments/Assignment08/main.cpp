/******************************************************/
//
// File Name: main.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 08
// Date Modified: 11-09-2026
//
/******************************************************/

#include <iostream>
#include "Triangle.h"
#include "Rectangle.h"
#include "Circle.h"

using namespace std;

int main()
{
    // Declare an array of pointers to Shape, size 3
    Shape* shapes[3];

    // Create instances of Circle, Triangle, and Rectangle with centers
    shapes[0] = new Circle(5.0, 2.0, 3.0);
    shapes[1] = new Triangle(3.0, 4.0, 5.0, 0.0, 0.0);
    shapes[2] = new Rectangle(10.0, 5.0, -2.0, 1.0);

    // Display information for each shape
    for (int i = 0; i < 3; i++)
    {
        shapes[i]->display();
    }

    // Example of using distanceTo between shapes
    cout << "Distance between Circle and Triangle centers: "
         << shapes[0]->distanceTo(shapes[1]) << endl;
    cout << "Distance between Triangle and Rectangle centers: "
         << shapes[1]->distanceTo(shapes[2]) << endl;

    // Deallocate memory
    for (int i = 0; i < 3; i++)
    {
        delete shapes[i];
    }

    return 0;
}

/*
Reflection:

Compile Command:
    g++ main.cpp Circle.cpp Rectangle.cpp Shape.cpp Triangle.cpp -o main.out

In this assignment I defined abstract classes with their own
functionality from a base class (shape). Each derived
class had overriden and implemented the virtual area, perimeter, and display functions
listed in the base class.

I also got more experience using header files to define
my classes. 'this->parameter' was used a lot inside constructors or any
case where parameters had a similar name to the private variables. I 
prefer using this approach since it helps with readability.

Overall, I thought this assignment was a fun activity to help
increase my understanding of C++ classes.
*/
