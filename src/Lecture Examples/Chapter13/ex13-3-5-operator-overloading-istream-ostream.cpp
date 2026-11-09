// Operator Overloading for >> and << operators

/*
1. Friend Functions:
   - Both >> and << operators are generally implemented as friend 
     functions of the class.
   - This is because the left-hand operand is not an object of the 
     class (it's an istream or ostream), and friend functions allow 
     non-member functions to access the private and protected members 
     of the class.
   - Syntax:

    friend istream& operator>>(istream& in, ClassName& obj) ;
    friend ostream& operator<<(ostream& out, const ClassName& obj) ;

2. Return Type:
   - The >> operator should return a reference to the input stream (istream&) 
     to allow for input chaining.
   - The << operator should return a reference to the output stream (ostream&) 
     to allow for output chaining.
   - This enables statements like cin >> obj1 >> obj2; or cout << obj1 << obj2; 
     to work correctly.

3. Pass by Reference:
   - Both operators take their streams (istream for >> and ostream for <<) 
     as the first parameter by reference. This ensures that the actual stream 
    object is modified and that large objects are not unnecessarily copied.
   - For the >> operator, the second parameter is passed by non-const reference 
     (ClassName&) because the function modifies the object.
   - For the << operator, the second parameter is passed by constant reference 
     (const ClassName&) because it only reads data from the object without modifying it.

4. Error Checking (Optional):
   - When overloading >>, it's a good idea to include error checking. 
     For example, check if the input is valid and handle errors gracefully. 
     This can prevent crashes or unexpected behavior when invalid data is entered.
   - You can check the state of the input stream using in.fail() or in.eof() 
     to detect issues with input.

5. Symmetry with Built-in Types:
   - Overloading these operators should maintain symmetry with how built-in 
     types work in C++. For example:
   - The input >> operator should read the same way cin >> var; works for 
     primitive types.
   - The output << operator should work like cout << var; for built-in types.

6. Chaining:
   - By returning the stream reference (istream& or ostream&), you allow for 
     operator chaining. This means multiple operations can be done in one line.

7. Const Correctness:
   - For <<, use const for the class object to ensure the object isn’t modified 
     during output.
   - >> doesn't need to be const because it modifies the object (e.g., reading 
     and setting data).

8. Format and Style:
   - You have control over the input/output format. For example, you can prompt 
     the user for input inside the >> operator or format the output in a specific 
     way inside the << operator.

*** Summary of the Process:
1. Friend Functions: To allow access to private members and accommodate streams 
   as the first argument.
2. Return Type: Return istream& for >> and ostream& for << to enable chaining.
3. Pass by Reference: Pass streams by reference and class objects by reference 
   for efficiency.
4. Chaining: Enables statements like cin >> obj1 >> obj2; and cout << obj1 << obj2; to work.
5. Error Checking: (Optional but recommended) for better error handling during input.
6. Const Correctness: Use const for << operator to protect the object from modifications 
   during output.
*/

#include <iostream>
#include <string>

using namespace std ;

class Person
{
private:
    string name ;
    int age ;

public:
    // Default Constructor
    Person() : name(""), age(0) { }

    // 'Friend' function to overload >> operator for input
    friend istream& operator>>(istream& in, Person& person) ;

    // 'Friend' function to overload << operator for output
    friend ostream& operator<<(ostream& out, const Person& person) ;
};

// Overloading the >> operator (input stream)
istream& operator>>(istream& in, Person& person)
{
    cout << "Enter name: " ;
    in >> person.name ;
    cout << "Enter age: " ;
    in >> person.age ;
    return in ; // Return the input stream to allow chaining
}

// Overloading the << operator (output stream)
ostream& operator<<(ostream& out, const Person& person)
{
    out << "Name: " << person.name << ", Age: " << person.age ;
    return out ; // Return the output stream to allow chaining
}

int main()
{
    Person p1 ;

    // Use the overloaded >> operator to input data into p1
    cin >> p1 ;

    // Use the overloaded << operator to display p1
    cout << p1 << endl ;

    return 0 ;
}
/*
1. Overloading >> (Input Operator):
   - The >> operator is used to extract name and age from 
     the input stream (cin).
   - It takes an istream& as the first parameter and a Person& 
     as the second parameter.
   - It returns the istream& to support chaining of input operations.

2. Overloading << (Output Operator):
   - The << operator is used to output the name and age of a Person object 
     to an output stream (cout).
   - It takes an ostream& as the first parameter and a const Person& 
     as the second parameter.
   - It returns the ostream& to support chaining of output operations.

3. Chaining:
   - Both the >> and << operators return their respective streams, 
     which allows multiple input/output operations to be chained together.
*/
