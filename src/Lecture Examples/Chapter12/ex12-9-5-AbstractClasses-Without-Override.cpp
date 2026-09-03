// Abstract Classes with Override Keyword

#include <iostream>

using namespace std ;

// Abstract class shape
class shape
{
public:
    /*
    Because we do not want to include the definitions of the functions draw and move of
    the class shape, we must convert these functions to pure virtual functions.
    */
    // Pure virtual functions
    virtual void draw() const = 0 ;       // Pure virtual function for drawing the shape
    virtual void move(int x, int y) = 0 ; // Pure virtual function for moving the shape
    
    // Virtual destructor to ensure proper cleanup
    virtual ~shape() {}
} ;

// Derived class triangle
class triangle : public shape
{
public:
    // Overriding the draw function
    //
    // This is supposed to override shape::draw, but what if there is a typo?
    void draw() const   // <-- No "override" here
    {
        cout << "Drawing a triangle." << endl ;
    }

    // Overriding the move function
    void move(int x, int y) // <-- No "override" here
    {
        cout << "Moving the triangle to position (" << x << ", " << y << ")." << endl ;
    }
} ;

// Derived class rectangle
class rectangle : public shape
{
public:
    // Overriding the draw function
    void draw() const // <-- No "override" here
    {
        cout << "Drawing a rectangle." << endl ;
    }

    // Overriding the move function
    void move(int x, int y) // <-- No "override" here
    {
        cout << "Moving the rectangle to position (" << x << ", " << y << ")." << endl ;
    }
};

// Main function to demonstrate the abstract class and derived classes
int main()
{
    // Cannot instantiate an abstract class
    // shape s;  // This would result in a compile-time error

    // Create a triangle and a rectangle object using pointers to the abstract class shape
    shape* shapes[2] ;
    shapes[0] = new triangle() ;
    shapes[1] = new rectangle() ;

    // Drawing and moving the shapes
    for (int i = 0; i < 2; ++i)
    {
        shapes[i]->draw() ;
        shapes[i]->move(i * 10, i * 20) ;
    }

    // Clean up memory
    delete shapes[0] ;
    delete shapes[1] ;

    return 0 ;
}

/*
Benefits of override:
    1. Error Prevention: If you make a mistake in the function signature (such as a typo 
       or missing const), the compiler will catch it and issue an error.
    2. Code Clarity: It makes the code more readable by clearly indicating that the function 
       is meant to override a base class function.
    3. Maintenance: If someone changes the base class method signature, and the derived class 
       function no longer matches, the compiler will catch the mismatch.

Summary:
    1. override was introduced in C++11 to ensure that a function in a derived class is 
       correctly overriding a virtual function in the base class.
    2. It provides a compile-time check that catches errors like mismatched signatures or 
       accidental redefinitions, making your code safer and more maintainable.
    3. Although it is not required to use override, it is considered good practice, especially 
       when working with polymorphism and virtual functions.
*/
