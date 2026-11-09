// Operator Overloading for = Operator

/*
*** Why Overload the Assignment Operator?
Without overloading the assignment operator, the default operator would perform 
a shallow copy, meaning both objects would share the same memory. 
In this case, when one object is destroyed or modified, it could affect the other 
object, leading to unintended behavior. By overloading the assignment operator, 
we ensure a deep copy, so each object has its own independent memory.

The assignment operator (=) in C++ can be overloaded to define 
how one object of a class is assigned to another. 

This is especially important when a class manages resources 
such as 'dynamic memory', as the default assignment operator performs 
a shallow copy, which may not be suitable for resource management.

Key Points:
1. Default Behavior:
  - The default assignment operator copies the values of member variables 
    from one object to another. This is sufficient for simple data members 
    but not for dynamically allocated memory or deep copies.

2. Deep Copy:
  - If your class manages dynamic memory, you should overload the assignment 
    operator to perform a deep copy (i.e., allocate new memory and copy the contents).
*/
#include <iostream>

using namespace std ;

class Array
{
private:
    int* data ;
    int size ;

public:
    // Constructor
    Array(int s) : size(s)
    {
        data = new int[size] ; // Allocate memory for the array
        for (int i = 0; i < size; i++)
            data[i] = 0 ; // Initialize array elements to 0
    }

    // Copy Constructor (for deep copy during initialization)
    Array(const Array& other)
    {
        size = other.size ;
        data = new int[size] ; // Allocate new memory for the deep copy
        for (int i = 0; i < size; i++)
            data[i] = other.data[i] ; // Copy each element
    }

    // Assignment Operator Overloading
    Array& operator=(const Array& other)
    {
        if (this == &other) // Check for self-assignment
            return *this ;

        delete[] data ; // Free the old memory

        size = other.size ; // Copy the size
        data = new int[size] ; // Allocate new memory
        for (int i = 0; i < size; i++)
            data[i] = other.data[i] ; // Copy the elements

        return *this ; // Return *this to allow chained assignments
    }

    // Destructor (to free the allocated memory)
    ~Array()
    {
        delete[] data ;
    }

    // Function to display the array contents
    void display() const
    {
        for (int i = 0; i < size; i++)
            cout << data[i] << " " ;
        cout << endl ;
    }

    // Function to set the value at a given index
    void setValue(int index, int value)
    {
        if (index >= 0 && index < size)
            data[index] = value ;
    }
} ;

int main()
{
    Array arr1(5) ; // Create an array of size 5
    arr1.setValue(0, 10) ;
    arr1.setValue(1, 20) ;
    arr1.setValue(2, 30) ;
    arr1.setValue(3, 40) ;
    arr1.setValue(4, 50) ;

    cout << "arr1: " ;
    arr1.display() ;
    cout << "arr1's address: " << &arr1 << endl << endl ;

    Array arr2(5) ; // Create another array of size 5
    arr2 = arr1 ;   // Use the overloaded assignment operator

    cout << "arr2 after assignment: " ;
    arr2.display() ;
    cout << "arr2's address: " << &arr2 << endl ;

    return 0 ;
}
/*
1. Constructor:
  - The constructor dynamically allocates memory for the array and 
    initializes the elements to 0.

2. Copy Constructor:
  - The copy constructor performs a deep copy of the array. 
    It allocates new memory for data and copies each element from the other array.

3. Assignment Operator Overloading (operator=):
  - In the overloaded assignment operator, we first check for self-assignment. 
    If this and other are the same object, we return *this to avoid unnecessary work.
  - If it's not a self-assignment, we deallocate the old memory (delete[] data) and 
    allocate new memory (new int[size]), then copy the elements from the other object.
  - The function returns *this to allow for chained assignments.

4. Destructor:
  - The destructor ensures that dynamically allocated memory is properly freed 
    when the object is destroyed.
*/
