// Student, CSIS 255, Luke Graten, 09.03.2026

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