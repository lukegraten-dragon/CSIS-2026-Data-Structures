// Operator Overloading + and <<

/*
Operator overloading in C++ allows you to redefine the way operators work for 
user-defined types (like classes or structs). It provides a way to implement 
custom behaviors for operators when they are applied to objects of a class.

Key Points about Operator Overloading:

1. Syntax for Overloading Operators:
  - Operators can be overloaded by defining special member functions or 
    friend functions using the keyword operator followed by the operator symbol.
  - Example:
    return_type operator symbol (parameters);

2. Rules for Operator Overloading:
  - You cannot create new operators, only overload existing ones.
  - Some operators, like . (member access), :: (scope resolution), ?: (ternary), and sizeof, cannot be overloaded.
  - At least one operand of the overloaded operator must be a user-defined type (like a class or struct).
  - Overloading does not change the precedence or associativity of operators.

3. Types of Operators You Can Overload:
  - Arithmetic operators (+, -, *, /)
  - Relational operators (==, !=, <, >, <=, >=)
  - Assignment operator (=)
  - Subscript operator ([])
  - Increment/Decrement operators (++, --)
*/

#include <iostream>

using namespace std ;

class Complex
{
private:
    double real ;
    double imag ;

public:
    // Constructor
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) { }

    // Overload the + operator to add two Complex objects
    Complex operator+(const Complex& other)
    {
        return Complex(real + other.real, imag + other.imag) ;
    }
    /*
    Overloading the + operator:
    - We define a member function operator+ that takes a const Complex& as its parameter.
    - Inside the function, we return a new Complex object where the real and imaginary 
      parts are summed separately.
    */

    // Overload the << operator to print the Complex object
    friend ostream& operator<<(ostream& os, const Complex& c)
    {
        os << c.real << " + " << c.imag << "i" ;
        return os ;
    }
    /*
    Overloading the << operator:
    - We define a friend function operator<< to allow the ostream object (cout in this case) 
      to directly output a Complex object.
    - The function takes an ostream& and a const Complex& as parameters and returns 
      the same ostream& object after printing.
    */
};

int main()
{
    Complex c1(3.0, 4.0) , c2(1.0, 2.0) ;

    // Use the overloaded + operator
    Complex c3 = c1 + c2 ;

    // Use the overloaded << operator
    cout << "c1: " << c1 << endl ;
    cout << "c2: " << c2 << endl ;
    cout << "c1 + c2: " << c3 << endl ;

    return 0 ;
}
