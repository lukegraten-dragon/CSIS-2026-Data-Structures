// Abstract Classes without Override Keyword

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
} ;

// Main function to demonstrate the abstract class and derived classes
int main()
{
    // Cannot instantiate an abstract class
    // shape s ;  // This would result in a compile-time error

    // Create a triangle and a rectangle object using pointers to the abstract class shape
    shape* shapes[2] ;
    shapes[0] = new triangle() ;
    shapes[1] = new rectangle() ;

    // Drawing and moving the shapes
    for (int i = 0 ; i < 2 ; ++i)
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


/*
    The declarations in shape are pure virtual functions:

        virtual void draw() const = 0 ;
        virtual void move(int x, int y) = 0 ;

    A class with a pure virtual function is abstract. An object of shape
    cannot be created directly, but a shape pointer can refer to an object
    of a derived class. Both triangle and rectangle implement the two
    required functions, so objects of these classes can be created.

                        +---------------------------+
                        |      shape (abstract)     |
                        +---------------------------+
                        | draw() const = 0          |
                        | move(int, int) = 0        |
                        | virtual ~shape()          |
                        +---------------------------+
                                    ^
                         +----------+----------+
                         |                     |
                +----------------+    +----------------+
                |    triangle    |    |   rectangle    |
                +----------------+    +----------------+
                | draw() const   |    | draw() const   |
                | move(int, int) |    | move(int, int) |
                +----------------+    +----------------+

    The functions in the derived classes override the base-class
    functions even though the keyword override does not appear in their
    declarations. The matching names, parameters, and const qualifiers
    are what make them overrides. Adding override asks the compiler to
    check this relationship explicitly.

    For example, these two declarations both override shape::draw():

        void draw() const ;             // Without override
        void draw() const override ;    // With override

    The keyword does not change the runtime behavior of a correctly
    overridden virtual function. It helps detect mistakes in the
    derived-class declaration.

    Consider a missing const qualifier:

        // Base class shape:
        virtual void draw() const = 0 ;

        // An incorrect declaration in triangle:
        void draw() ;                   // Does not override draw() const

    The two functions are different because the const qualifier on a
    member function is significant. With this mistake, triangle has not
    implemented the inherited pure virtual draw() const function and
    therefore remains abstract. Attempting new triangle() causes a
    compilation error, even without the override keyword.

    If the incorrect declaration were instead written as:

        void draw() override ;

    the compiler would report that this declaration does not override
    a base-class virtual function. The diagnostic points directly to
    the mismatch rather than only to the attempted creation of an
    abstract triangle object.

    The distinction is especially useful with an ordinary (non-pure)
    virtual function. Suppose a base class defines:

        virtual void print() const ;

    and a derived class mistakenly declares:

        void print() ;                  // Missing const

    This does not override the base function. The derived class can
    still be concrete, but a call through a base-class pointer or
    reference will use the base-class print() instead of the intended
    derived-class function. Declaring void print() override would make
    this mismatch a compile-time error.

    In main(), shapes is an array of two shape pointers. It is not an
    array of shape objects:

        shape* shapes[2] ;
        shapes[0] = new triangle() ;
        shapes[1] = new rectangle() ;

                 main()                           Dynamic objects

        +--------------------+              +--------------------+
        | shapes[0] (shape*) |------------->| triangle           |
        +--------------------+              +--------------------+

        +--------------------+              +--------------------+
        | shapes[1] (shape*) |------------->| rectangle          |
        +--------------------+              +--------------------+

    The calls shapes[i]->draw() and shapes[i]->move(...) use virtual
    dispatch. The actual object type determines the function executed:

                  shapes[i]->draw()
                           |
                 +---------+---------+
                 |                   |
             triangle            rectangle
                 |                   |
                 v                   v
         triangle::draw()     rectangle::draw()

    The loop starts with i = 0 and then uses i = 1. Its output is:

        Drawing a triangle.
        Moving the triangle to position (0, 0).
        Drawing a rectangle.
        Moving the rectangle to position (10, 20).

    The output is identical to example 12-9-4, which includes override
    in the derived-class declarations. Both programs use dynamic
    binding because draw() and move() are virtual in shape.

    The virtual destructor in shape is also significant. The objects
    were created as triangle and rectangle, but they are deleted
    through pointers of type shape*:

        delete shapes[0] ;
        delete shapes[1] ;

    A virtual base-class destructor ensures that the appropriate derived
    destructor is invoked before the base destructor when an object is
    deleted through a base-class pointer.

    In short, overriding and override are not the same thing. A matching
    derived-class function overrides a virtual function automatically.
    Writing override makes the compiler verify that it really does.
*/
