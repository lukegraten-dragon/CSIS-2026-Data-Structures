// Call by Value and Call by Reference
#include <iostream>

using namespace std ;

void areaAndPerimeter(double length, double width,
                      double& area, double& perimeter) ;

int main()
{
    double length = 10 ; 
    double width  = 5 ;
    double area = 2 ; 
    double perimeter = 19 ;

    cout << "Before calling areaAndPerimeter()" << endl 
         << "length = " << length << endl
         << "width = " << width << endl
         << "area = " << area << endl         
         << "perimeter = " << perimeter << endl << endl ;

    areaAndPerimeter(length, width, area, perimeter) ;

    cout << "After calling areaAndPerimeter()" << endl 
         << "length = " << length << endl
         << "width = " << width << endl
         << "area = " << area << endl         
         << "perimeter = " << perimeter << endl << endl ;

    return 0 ;
}

// Call by Value and Call by Reference
void areaAndPerimeter(double length, double width,
                      double& area, double& perimeter)
{
    area = length * width ;
    perimeter = 2 * (length + width) ;
}