// Abstract Classes

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
    void draw() const override
    {
        cout << "Drawing a triangle." << endl ;
    }

    // Overriding the move function
    void move(int x, int y) override
    {
        cout << "Moving the triangle to position (" << x << ", " << y << ")." << endl ;
    }
} ;

// Derived class rectangle
class rectangle : public shape
{
public:
    // Overriding the draw function
    void draw() const override
    {
        cout << "Drawing a rectangle." << endl ;
    }

    // Overriding the move function
    void move(int x, int y) override
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
Key Concepts in the Code:

1. Abstract Class (shape):
  - The class shape is an abstract class because it contains pure virtual functions 
    (draw() and move()).
  - A class with at least one pure virtual function is considered abstract, 
    and you cannot instantiate an abstract class.

2. Pure Virtual Functions:
  - draw() and move() are declared as pure virtual functions (= 0), meaning that 
    they must be overridden in any derived class.

3. Derived Classes (triangle and rectangle):
  - Both derived classes (triangle and rectangle) override the draw() and move() functions.
  - Each derived class provides its own implementation of these functions.

4. Polymorphism:
  - In the main() function, we create objects of triangle and rectangle using pointers to 
    the base class shape.
  - When calling the draw() and move() functions, the correct version of the function 
    (from the derived class) is called, demonstrating polymorphism.

5. Memory Management:
  - The objects are created dynamically using new, and delete is used to free the memory.
*/
