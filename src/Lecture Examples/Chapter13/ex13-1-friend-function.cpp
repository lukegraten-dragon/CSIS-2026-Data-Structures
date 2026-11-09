// Friend Function

/*
In C++, a 'friend' function is a function that is not a member of a class 
but is granted access to the class's private and protected members. 
The friend keyword is used to declare a friend function inside a class definition.

Key Points about Friend Functions:
1. Not a Member of the Class:
  - A friend function is not a member function of the class, meaning it does not 
    belong to the class object and is called like a regular function.

2. Access to Private and Protected Members:
  - Even though it's not a member, a friend function has access to the private and 
    protected members of the class in which it's declared as a friend.

3. Declared in the Class, Defined Outside:
  - A friend function is declared inside the class with the keyword friend, 
    but its definition is outside the class, similar to regular functions.

4. Useful for Operator Overloading:
  - Friend functions are often used to overload operators that need to access 
    private members but can't be implemented as member functions, 
    such as << or >> for stream operations.
*/
#include <iostream>

using namespace std ;

class Box
{
private:
    double length ;
    double width ;
    double height ;

public:
    // Constructor
    Box(double l, double w, double h) : length(l), width(w), height(h) { }

    // Friend function to calculate volume
    friend double calculateVolume(const Box& box) ;
} ;

// Definition of the friend function
double calculateVolume(const Box& box) // Wihtout Box::
{
    // Access private members directly
    return box.length * box.width * box.height ;
}

int main()
{
    // Create an object of Box
    Box myBox(5.0, 3.0, 4.0) ;

    // Call the friend function
    double volume = calculateVolume(myBox) ;

    // Output the result
    cout << "Volume of the box: " << volume << endl ;

    return 0 ;
}
/*
1. Friend Function Declaration:
  - Inside the Box class, we declare calculateVolume as a friend function 
    using the friend keyword. This grants it access to the private members 
    length, width, and height.

2. Friend Function Definition:
  - The friend function calculateVolume is defined outside the Box class. 
    It takes a const Box& parameter, allowing it to access the Box object's 
    private members to compute the volume.

3. Calling the Friend Function:
  - In main(), we create a Box object myBox, and then call calculateVolume(myBox) 
    to calculate the volume of the box.
*/
