/******************************************************/
//
// File Name: main.cpp
// Minnesota State University Moorhead
// Name: John Doe
// StarID: ab1234cd
// Assignment 08
// Date Modified: MM-DD-YYYY
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
Replace this instruction text with a short but meaningful paragraph describing
what you learned from completing Assignment 08.
*/
