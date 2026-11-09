#include <iostream>
  
using namespace std ;

class classExample 
{
public:
    void setX(int a) ;
     //Function to set the value of x
     //Postcondition: x = a ;
    
    void print() const ;
     //Function to output the value of x

private:
    int x ;
} ;

int main()
{
    classExample *cExpPtr ;
    classExample cExpObject ;
    /*
    In the preceding declaration, 'cExpObject' is an object of type classExample, and
    'cExpPtr' is a pointer variable of type classExample. The following statement
    stores the address of cExpObject in cExpPtr:
    */
    cExpPtr = &cExpObject ;

    // (*cExpPtr).setX(5) ;
    // (*cExpPtr).print() ;
    /*
    The expression (*cExpPtr).setX(5) is a mixture of pointer dereferencing and the
    class component selection. In C++, the dot operator, ., has a higher precedence than
    the dereferencing operator.
    */
    
    cExpPtr->setX(5) ;
    cExpPtr->print() ;
    
    /*
    As you can see, in the expression (*cExpPtr).setX(5), the parentheses are important.
    However, typos can be problematic. Therefore, to simplify the accessing of
    class or struct components via a pointer, C++ provides another operator called
    the member access operator arrow, ->. The operator -> consists of two consecutive
    symbols: a hyphen and the “greater than” sign.

    The syntax for accessing a class (struct) member using the operator -> is:

    pointerVariableName->classMemberName

    */

    cExpObject.setX(6) ;
    cExpObject.print() ;

    /*
    1. Direct Object Access:

    cExpObject.setX(6);
    cExpObject.print();

    In this case:
    - cExpObject is a directly instantiated object of type classExample.
    - The member functions (setX and print) are called directly on the object 
      cExpObject using the dot operator (.).
    - This is straightforward: since you are working with the object itself, 
      there’s no need for indirection.

    2. Pointer to Object Access:

    cExpPtr->setX(5);
    cExpPtr->print();

    In this case:
    - cExpPtr is a pointer to an object of type classExample. It points to the object cExpObject.
    - The member functions (setX and print) are called indirectly using the pointer 
      cExpPtr and the pointer member access operator (->).
    - The arrow operator (->) is a shorthand for dereferencing the pointer to access 
      the object’s members, equivalent to (*cExpPtr).setX(5).

    3. Why Use One Over the Other?
    - Direct access is simpler when you have the object in hand and don't need to deal with indirection.
    - Pointer access is useful when:
      - You want to manipulate the object dynamically (e.g., using dynamic memory allocation like new).
      - You are passing objects around as pointers in functions.
      - You are dealing with polymorphism (accessing derived class objects through base class pointers).
    */

    return 0 ;
}

void classExample::setX(int a)
{
    x = a ;
} 

void classExample::print() const
{
    cout << "x = " << x << endl ;
}
