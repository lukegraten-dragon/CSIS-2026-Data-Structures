// Operator Overloading for relational Operators.

#include <iostream>

using namespace std ;

class Point
{
private:
    int x ;
    int y ;

public:
    // Constructor
    Point(int x = 0, int y = 0) : x(x), y(y) { }

    // Overload the == operator
    bool operator==(const Point& other) const
    {
        return (x == other.x && y == other.y) ;
    }

    // Overload the != operator
    bool operator!=(const Point& other) const
    {
        return !(*this == other) ; // Reuse the overloaded == operator
    }

    // Overload the < operator
    bool operator<(const Point& other) const
    {
        // Compare based on x-coordinate, and if they are equal, compare y-coordinate
        if (x == other.x)
            return y < other.y ;
        return x < other.x ;
    }

    // Overload the > operator
    bool operator>(const Point& other) const
    {
        return !(*this < other) && *this != other ;
    }

    // Function to display the point
    void display() const
    {
        cout << "(" << x << ", " << y << ")" ;
    }
} ;

int main()
{
    Point p1(2, 3) ;
    Point p2(2, 5) ;
    Point p3(2, 3) ;

    // Comparing points using overloaded operators
    cout << "p1: " ; p1.display() ; cout << endl ;
    cout << "p2: " ; p2.display() ; cout << endl ;

    // == and != operators
    if (p1 == p3)
        cout << "p1 is equal to p3" << endl ;
    else
        cout << "p1 is not equal to p3" << endl ;

    if (p1 != p2)
        cout << "p1 is not equal to p2" << endl ;

    // < and > operators
    if (p1 < p2)
        cout << "p1 is less than p2" << endl ;

    if (p2 > p1)
        cout << "p2 is greater than p1" << endl ;

    return 0 ;
}
/*
1. Overloading the == Operator:
  - The operator== compares the x and y values of two Point objects. 
    If both coordinates are the same, it returns true.

2. Overloading the != Operator:
  - The operator!= is implemented by negating the result of the overloaded 
    operator==. If two points are not equal, != returns true.

3. Overloading the < Operator:
  - The operator< compares points based on their x coordinate. 
    If the x values are the same, it compares the y coordinates.

4. Overloading the > Operator:
  - The operator> is defined by using the result of the operator< and operator!=. 
    A point is greater than another if it is not less than or equal to the other point.
*/
