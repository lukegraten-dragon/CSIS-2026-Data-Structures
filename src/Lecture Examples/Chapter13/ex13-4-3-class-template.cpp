#include <iostream>

using namespace std ;

/*
1. What is a C++ Template Class?
A template class in C++ is a blueprint for creating classes that can work 
with any data type. Instead of writing multiple versions of the same class 
for different data types (e.g., int, double, string), you can write a single 
template class that can be used with any data type.

Key Concepts:
- Generic Programming: Template classes enable generic programming by allowing 
  you to write code that works with any data type.
- Code Reusability: By using templates, you avoid duplicating code for each 
  data type. The same logic works for integers, doubles, strings, or even custom types.
- Type-Safe: Templates are type-safe. The data type is determined at compile-time, 
  meaning the compiler will catch type-related errors during the compilation process.

Basic Syntax of a Class Template

template <typename T>
class MyTemplateClass {
public:
    MyTemplateClass(T value) ;  // Constructor
    void setValue(T value) ;    // Set value
    T getValue() const ;        // Get value

private:
    T data ;  // Member variable of type T
} ;


*/
template <class T>
class MyTemplateClass
{
public:
    void setData(T data) { this->data = data ; }
    T getData() const { return data ; }

private:
    T data ;
} ;
/*
- template <class T>: This declares a template class where T is a placeholder for 
  a data type. The class can be instantiated with any type, such as int, double, 
  string, etc.
- T data: The data member is of type T, meaning it can be any data type specified 
  when the class is instantiated.

2. How to Use a Template Class?
Once you define a template class, you can instantiate objects of that class using 
any data type. 

For example:
*/
int main()
{
    MyTemplateClass<int> intObject ;  // T is int
    intObject.setData(10) ;
    cout << intObject.getData() << endl ;

    MyTemplateClass<double> doubleObject ;  // T is double
    doubleObject.setData(3.14) ;
    cout << doubleObject.getData() << endl ;

    return 0;
}
/*
- MyTemplateClass<int>: This creates an object where T is int.
- MyTemplateClass<double>: This creates an object where T is double.

3. Why Must Template Class Implementations Be in Header Files?
Unlike regular classes, template classes and functions must have their implementation 
available in the same translation unit where they are used. This is because templates 
are not compiled on their own. Instead, the compiler generates code for templates when 
it sees specific instances of them being used (i.e., when you create an object of 
a template class).

Regular Class vs. Template Class Compilation:
- Regular Classes:
  - For regular classes, you can declare the class in a header file (.h) and implement 
    it in a separate .cpp file. The .cpp file is compiled separately, and during linking, 
    the implementation is connected to the declaration.
- Template Classes:
  - Template classes are different because the compiler doesn’t know what type T will be 
    until the template is instantiated (used). Since the template is only compiled when 
    instantiated, the implementation must be available at the time of compilation.
  - Thus, the compiler needs both the declaration and the implementation in the header 
    file to generate the code when a specific type is used.

4. Why Not Separate Template Class Implementation into .cpp Files?
If you try to put the implementation of a template class into a .cpp file, you’ll 
encounter linker errors because the compiler won’t know how to instantiate the template 
functions when they’re needed. The .cpp file is not compiled into code until it’s explicitly included.

This can be summarized by:

- Templates are only compiled when instantiated (when an actual type is provided).
- The compiler must see the full definition (both declaration and implementation) 
  when it instantiates a template.
- If you separate the implementation into a .cpp file, it won’t be available during 
  instantiation, causing errors.

Summary:
1. Template Classes: Templates allow you to create classes or functions that work with 
   any data type, promoting code reuse and flexibility.
2. Why Implement in Header: The implementation of template classes must be included 
   in the header file because the compiler needs to see both the declaration and 
   implementation when instantiating the template with a specific data type.
3. General Rule: Keep both the declaration and implementation of a template class 
   in the same file (usually the header file) to avoid compilation and linker issues.

By following these guidelines, you can use templates effectively in C++ to create flexible, reusable code.
*/

