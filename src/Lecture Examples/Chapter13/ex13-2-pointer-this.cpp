// Pointer 'this'

/*
In C++, the this pointer is a special pointer available within all non-static 
member functions of a class. It points to the object for which the member 
function is called. This allows access to the calling object's members and is 
particularly useful in situations like returning the current object or 
distinguishing between member variables and parameters with the same name.

Key Points about the this Pointer:
1. Points to the Current Object:
  - this points to the current instance of the class, i.e., the object that is 
    invoking the member function.

2. Only Available in Non-Static Member Functions:
  - The this pointer is only available in non-static member functions because 
    static member functions are not tied to any particular object.

3. Implicit Use:
  - You don’t need to explicitly use this to access member variables or functions, 
    but it can be used to make the code more readable or in cases of name conflicts.

4. Returns the Object Itself:
  - this can be used to return the object itself (often in chained function calls).
*/

#include <iostream>

using namespace std ;

class Rectangle
{
private:
    double length ;
    double width ;

public:
    // Constructor
    Rectangle(double length, double width)
    {
        // Use 'this' to distinguish between member variables and parameters
        this->length = length ;
        this->width = width ;
    }

    // Method to set dimensions
    Rectangle& setDimensions(double length, double width)
    {
        this->length = length ;
        this->width = width ;
        return *this ; // Return the current object by dereferencing 'this'
    }

    // Method to display dimensions
    void display() const
    {
        cout << "Length: " << length << ", Width: " << width << endl ;
    }
} ;

int main()
{
    // Create an object of Rectangle
    Rectangle rect(10.0, 5.0) ;

    // Display the initial dimensions
    rect.display() ;

    // Use the 'this' pointer to return the current object and chain function calls
    rect.setDimensions(15.0, 7.5).display() ;

    return 0 ;
}
/*
1. Constructor and this:
  - In the constructor, we use this->length and this->width to distinguish between 
    the class members and the constructor parameters that have the same names.

2. Returning *this:
  - In the setDimensions function, we return *this (the dereferenced this pointer), 
    which allows us to chain function calls. For example, after calling setDimensions, 
    we immediately call display() on the same object.

3. Chained Function Call:
  - The chaining of rect.setDimensions(15.0, 7.5).display(); works because setDimensions 
    returns the current object, and display is called on that returned object.
*/
