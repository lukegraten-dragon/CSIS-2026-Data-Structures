/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 08 Part 1
// Date Modified: 11-09-2026
// AI Models Used: No AI Used
//
/******************************************************/

#include <iostream>
#include <iomanip>
using namespace std ;

// 3D Box Class
class Box
{
    public:
        // Constructors
        Box() ;
        Box(const int& length, const int& width, const int& height) ;

        // Helper Function
        void displayBox(const string& name) ;

        // Overload Operators
        int operator=(Box& other)
        {
            // Overload the = operator to copy dimensions into a new box
            return other.height = height, other.width = width, other.length = length ;
        }

        bool operator==(const Box& other) const
        {
            // Compare volumes of self and other object
            return (length * width * height) == (other.length * other.width * other.height) ;
        }

        bool operator!=(const Box& other) const
        {
            // Compare volumes of self and other object
            return (length * width * height) != (other.length * other.width * other.height) ;
        }

        bool operator<(const Box& other) const
        {
            // Compare volumes to see which has less.
            return  (length * width * height) < (other.length * other.width * other.height) ;
        }

        bool operator>(const Box& other) const
        {
            // Compare volumes to see which has less.
            return  (length * width * height) > (other.length * other.width * other.height) ;
        }


    private:
        // Member variables
        int length ;
        int width ;
        int height ;

} ;

Box::Box()
{
    // Set default values
    length = 1 ;
    width = 1 ;
    height = 1 ;
}

Box::Box(const int& length, const int& width, const int& height)
{
    this->length = length ;
    this->width = width ;
    this->height = height ;
}

void Box::displayBox(const string& name)
{
    cout << "Box " << name << ": " << "(" 
        << length << ", "
        << width << ", "
        << height << ")" << '\n' ;
}

// Main program

int main()
{
    // Initialize Box Objects
    Box BoxOne(3, 4, 5) ;
    Box BoxTwo(3, 4, 5) ;
    Box BoxThree(6, 7, 8) ;

    // Print dimensions
    BoxOne.displayBox("1") ;
    BoxTwo.displayBox("2") ;
    BoxThree.displayBox("3") ;

    // Use overloaded = operator to copy Box 1 into Box 4
    Box BoxFour = BoxOne ; 
    cout << '\n';
    cout << "After assignment, Box 4 (assigned from Box 1) : " ; 
    BoxFour.displayBox("4") ;
    cout << '\n'; 

    // Use overloaded == comparison operator
    cout << "Box 1 == Box 2: " << boolalpha << (BoxOne == BoxTwo) << noboolalpha << '\n' ;
    cout << "Box 1 == Box 3: " << boolalpha << (BoxOne == BoxThree) << noboolalpha << '\n' ;

    // Use overloaded != operator
    cout << "Box 1 != Box 2: " << boolalpha << (BoxOne != BoxTwo) << noboolalpha << '\n' ;
    cout << "Box 1 != Box 3: " << boolalpha << (BoxOne != BoxThree) << noboolalpha << '\n' ;

    // Use overloaded < operator
    cout << "Box 1 < Box 3: " << boolalpha << (BoxOne < BoxThree) << noboolalpha << '\n' ;
    // Use overloaded > operator
    cout << "Box 3 > Box 1: " << boolalpha << (BoxThree > BoxOne) << noboolalpha << '\n' ;

    return 0 ;
}