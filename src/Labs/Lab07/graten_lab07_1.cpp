/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 07 Part 1
// Date Modified: 10-30-2026
// AI Models Used: No AI Used
//
/******************************************************/

#include <iostream>
using namespace std ;

class rectangle
{
    public:

        void setDimensions(double len, double wid) ;

        double getArea() ;
        // Return the area of the rectangle
        void print() ;
        // Print the length, width, and area.

    private:
        double length = 1 ;
        double width = 1 ;
} ;

void rectangle::setDimensions(double len, double wid)
{
    // Set the dimensions of the rectangle (length and width)
    length = len ;
    width = wid ;
}

double rectangle::getArea()
{
    // Multiply the length and the width
    return (length * width) ;
}

void rectangle::print()
{
    cout << "Length: " << length
        << "\nWidth: " << width
        << "\nArea: " << getArea() << '\n' ;
}


int main() 
{
    // Direct Object Access
    rectangle rectDirect ;
    rectDirect.setDimensions(10.5, 5.5) ;

    cout << "Using direct object access: " << '\n' ;
    rectDirect.print() ;

    // Check size of object
    // cout << "Rectangle Object Size: " << sizeof(rectangle) << " Bytes" << '\n' ;

    // Dynamically Allocated Object
    rectangle *rectPoint ;
    rectPoint = new rectangle ; // Use new to allocate 16 bytes in memory
    rectPoint ->setDimensions(6.3, 3.8) ;
    cout << "Using pointer access: " << '\n' ;
    rectPoint ->print() ;

    // Delete the dynamically allocated memory and set to nullptr 
    // to avoid dangling pointer problems.
    delete rectPoint ; 
    rectPoint = nullptr ;

    return 0 ;
}