// Operator Overloading for [] operator

/*
In C++, the subscript operator ([]) can be overloaded to allow objects of 
a class to be indexed as if they were arrays. Overloading the [] operator 
provides a way to access elements inside a user-defined data structure 
using array-like syntax.

Key Points about Overloading the [] Operator:
1. Return Type:
   - The [] operator must return a reference (&) if the elements are to be 
     modifiable. Otherwise, it can return a constant reference or value 
     for read-only access.

2. Argument:
   - The [] operator takes one argument, typically an integer, which represents the index.

3. Can Be Overloaded for Both const and non-const Objects:
   - You can provide two overloads of the [] operator: one that returns 
     a modifiable reference for non-const objects and another that returns 
     a constant reference for const objects.
*/

#include <iostream>
using namespace std;

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

    // Destructor
    ~Array()
    {
        delete[] data ;
    }

    // Overload the subscript operator [] for non-const objects
    int& operator[](int index)
    {
        if (index >= 0 && index < size)
            return data[index] ; // Return a reference to the element
        else
        {
            cout << "Index out of bounds" << endl ;
            // It's better to throw an exception in real applications
            exit(1) ;
        }
    }

    // Overload the subscript operator for const objects
    const int& operator[](int index) const
    {
        if (index >= 0 && index < size)
            return data[index] ; // Return a constant reference to the element
        else
        {
            cout << "Index out of bounds" << endl ;
            exit(1) ;
        }
    }

    // Function to get the size of the array
    int getSize() const
    {
        return size ;
    }

    // Function to display the array contents
    void display() const
    {
        //cout << "Array at address " << this << ": " ;
        for (int i = 0; i < size; i++)
            cout << data[i] << " " ;
        cout << endl ;
    }
};

int main()
{
    Array arr(5) ; // Create an array of size 5

    // Use the overloaded [] operator to set values
    arr[0] = 10 ;
    arr[1] = 20 ;
    arr[2] = 30 ;
    arr[3] = 40 ;
    arr[4] = 50 ;

    // Display the array
    arr.display() ;

    // Access the elements using the overloaded [] operator
    cout << "arr[2]: " << arr[2] << endl ;

    // Test const version of the [] operator
    const Array constArr(3) ; // Const array
    cout << "constArr[0]: " << constArr[0] << endl ; // Access using const version

    return 0 ;
}
/*
1. Non-const Subscript Operator:
   - The operator[] for non-const objects returns a reference to the data[index]. 
     This allows modifying the element at that index, as shown by arr[0] = 10;.

2. Const Subscript Operator:
   - The operator[] for const objects returns a constant reference. 
     This allows read-only access to elements in a const object, ensuring that 
     the object cannot be modified through this operator.

3. Error Handling:
   - The operator checks if the index is valid. If the index is out of bounds, 
     it prints an error message and terminates the program. In real applications, 
     it's better to throw an exception.
*/

