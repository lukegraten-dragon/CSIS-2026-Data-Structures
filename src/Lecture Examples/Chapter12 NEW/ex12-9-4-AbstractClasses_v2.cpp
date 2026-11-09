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


/*
    The class shape describes operations that every concrete shape must provide.
    The expressions "= 0" mark draw() and move() as pure virtual functions.
    They do not assign zero to a return value. Because shape has pure virtual
    functions, the following declaration is not allowed:

        shape s ;                 // Error: shape is abstract

    A pointer or reference to shape is allowed:

        shape* p ;                // A pointer to shape
        shape& ref = someShape ;  // If someShape is a concrete derived object

    A derived class must implement all inherited pure virtual functions before
    objects of that derived class can be created. Otherwise, it also remains
    abstract. The override specifier checks that a function really overrides
    a virtual function in the base class. The const in draw() must match the
    const in shape::draw(), or the function would not be an override.

    The inheritance relationship is:

                          +--------------------------------+
                          |        shape (abstract)        |
                          +--------------------------------+
                          | virtual draw() const = 0       |
                          | virtual move(int, int) = 0     |
                          | virtual ~shape()               |
                          +--------------------------------+
                                        ^
                                        |
                            +-----------+-----------+
                            |                       |
                +-----------------------+  +-----------------------+
                | triangle              |  | rectangle             |
                +-----------------------+  +-----------------------+
                | draw() const override |  | draw() const override |
                | move(int, int)        |  | move(int, int)        |
                +-----------------------+  +-----------------------+

    Both triangle and rectangle are concrete classes because they provide
    implementations of draw() and move(). The function names and parameter
    types are shared, but their behaviors are different.


    The statement

        shape* shapes[2] ;

    creates an array of two pointers. It does not construct two shape objects.
    The statements

        shapes[0] = new triangle() ;
        shapes[1] = new rectangle() ;

    create two separate derived-class objects in dynamic storage and save
    their addresses in the pointer array:

                  main()                      Dynamic storage

          +---------------------+       +----------------------+
          | shapes[0] : shape*  |------>| triangle object      |
          +---------------------+       +----------------------+

          +---------------------+       +----------------------+
          | shapes[1] : shape*  |------>| rectangle object     |
          +---------------------+       +----------------------+

    The pointers have the same declared type, shape*, although the objects
    they point to have different types. The objects are not copied or sliced.
    The boxes represent objects, not physical copies of the function code.


    In the loop, both objects are accessed through the same shape interface:

        shapes[i]->draw() ;
        shapes[i]->move(i * 10, i * 20) ;

    Because draw() and move() are virtual, each call is dispatched according
    to the actual object, not merely the type of shapes[i]. For draw():

                          shapes[i]->draw()
                                  |
                        Actual object type
                                  |
                       +----------+----------+
                       |                     |
                       v                     v
                    triangle              rectangle
                       |                     |
                       v                     v
                triangle::draw()     rectangle::draw()

    The two loop iterations behave as follows:

        i = 0 : shapes[0] -> triangle
                draw()       -> "Drawing a triangle."
                move(0, 0)   -> "Moving the triangle to position (0, 0)."

        i = 1 : shapes[1] -> rectangle
                draw()       -> "Drawing a rectangle."
                move(10, 20) -> "Moving the rectangle to position (10, 20)."

    Output:

        Drawing a triangle.
        Moving the triangle to position (0, 0).
        Drawing a rectangle.
        Moving the rectangle to position (10, 20).

    The move() functions print a description of movement. They do not store
    coordinates or move any graphical object in this example.


    The base class declares a virtual destructor:

        virtual ~shape() {}

    The objects are deleted through shape* pointers:

        delete shapes[0] ;
        delete shapes[1] ;

    With a virtual destructor, deleting a derived object through a base-class
    pointer runs the derived-class destructor followed by the base-class
    destructor, then releases the allocated memory:

        delete shapes[0] ;
                |
                v
        triangle destructor
                |
                v
        shape destructor
                |
                v
        Object memory released

    Neither derived class defines a destructor explicitly. C++ supplies one.
    A polymorphic base class intended for deletion through base pointers
    should have a virtual destructor. In modern C++, this destructor could
    also be written as:

        virtual ~shape() = default ;


    Comparison with the preceding examples:

        12-9-0 : Base reference, non-virtual print() -> static binding.
        12-9-1 : Base reference, virtual print() -> dynamic binding.
        12-9-2 : Base pointer, virtual print() -> dynamic binding.
        12-9-3 : Base value parameter -> object slicing removes the derived part.
        12-9-4 : Abstract base class, pure virtual functions, derived objects
                 accessed through base-class pointers.

    A function can use the abstract interface without knowing which concrete
    shape it receives. For example, the following is an independent example,
    not an additional function in this program:

        void displayShape(const shape& s)
        {
            s.draw() ;
        }

    The same displayShape() function can accept either a triangle or a
    rectangle by reference. Using a reference avoids object slicing. A
    pointer is useful when an object might be absent, or when the program
    already works with pointers to objects. A shape object cannot be passed
    by value because shape is abstract.
*/
