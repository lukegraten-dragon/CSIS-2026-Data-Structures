/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Lab 01
// Date Modified: 09-08-2026
//
/******************************************************/

# include <iostream>
using namespace std;

int main ()
{
    // Declare variables
    int base ;
    int height ;
    int area ;

    // Add base and height
    base = 5 ;
    height = 2 ;

    // Compute and display the area of the triangle 1/2(b*h)
    area = (base * height) / 2;

    cout << "Area = " << area << '\n' ;

    return 0 ;
}

/*
Reflection

In this lab section I learned how to declare variables
and use operators to compute the result of two variables
of the same type (in this case, compute the area of a triangle).
*/