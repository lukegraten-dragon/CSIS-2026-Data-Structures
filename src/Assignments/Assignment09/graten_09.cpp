/******************************************************/
//
// File Name: graten_09.cpp
// Minnesota State University Moorhead
// Name: Luke Graten
// StarID: ft4513wq
// Assignment 09
// Date Modified: 11-12-2026
// AI Use: Minimal (Debugging Only)
//
/******************************************************/

#include <iostream> 
using namespace std ;

// Class Template Definition
template <class T>
class MyArray
{
    public:
        MyArray(int size) {
            // Store size metadata and dynamically
            // allocate memory for the array of T type.
            this->size = size ;
            this->arr = new T[size] ; }                             // DEBUGGED
        
        MyArray(const MyArray &other) {
            // This constructor performs a deep-copy
            // from an existing Array class object to a new
            // Array object.
            
            // 1. Get size from other array object
            // Dynamically allocate memory.
            this->size = other.getSize() ;
            this->arr = new T[size] ;                               // DEBUGGED

            // 2. Copy all elements from other array using for loop.
            for (int element = 0 ; element < size ; element++)
            {
                this->arr[element] = other.arr[element] ;
            }
        }

        ~MyArray() {
            // Destructor
            // 1. Deallocate array memory
            // 2. Nullify the array pointer
            delete[] arr ;
            arr = nullptr ;                                         // DEBUGGED
        }

        // Helper Function
        int getSize() const {return size ; }

        // Overloaded Operators
        void operator=(MyArray &other) { 
            // Copy one MyArray object to another using a deep copy.

            // NOTE: Length comparison isn't required as we're
            // overwriting this MyArray object entirely.
            
            // 1. Deallocate existing memory.
            delete[] this->arr ;

            // 2. Reallocate memory for the arr pointer based on the other's
            // MyArray object size requirements.
            this->size = other.size ;
            this->arr = new T[other.size] ;

            // 3. Copy all elements from other array using for loop.
            for (int element = 0 ; element < this->size ; element++)
            {
                this->arr[element] = other.arr[element] ;
            }
        }

        // Non-const
        T& operator[](int index) { 
            // Provide write access to elements by index, 
            // as used in the provided main()
            // function, and perform bounds checking.

            // NOTE: Error handling is needed to verify
            // if we're accessing a valid index within bounds.

            // 1. Verify whether index parameter is valid.
            // Exit program if not.
            if (index < 0 || index >= size)
            {
                cout << "ERROR: The overloaded [] operator needs an index that is within bounds!"
                    << " Valid Index Range: 0 through " << (size -1) << "." << '\n' ;

                exit(-1) ;
            }   

            // 2. Read or write to specified index.
            return arr[index] ;
        }

        // Const
        const T& operator[](int index) const { 
            // Provide read access to elements by index, 
            // as used in the provided main()
            // function, and perform bounds checking.

            // NOTE: Error handling is needed to verify
            // if we're accessing a valid index within bounds.

            // 1. Verify whether index parameter is valid.
            // Exit program if not.
            if (index < 0 || index >= size)
            {
                cout << "ERROR: The overloaded [] operator needs an index that is within bounds!"
                    << " Valid Index Range: 0 through " << (size -1) << "." << '\n' ;

                exit(-1) ;
            }
            // 2. Read or write to specified index.
            return arr[index] ;
        }

        bool operator==(const MyArray &other) { 
            // Return whether two MyArray objects have the same 
            // size and contain identical
            // elements.

            // 1. Check Array lengths
            if (this->size != other.getSize())
            {
                return false ;
            }

            // 2. Check if elements are identical using for loop
            for (int element = 0 ; element < size ; element++)
            {
                if (this->arr[element] != other.arr[element])
                {
                    return false ;
                }
            }
            
            // 3. All checks have passed, so return True.
            return true ;
        }
 
        MyArray<T> operator+(const MyArray &other) { 
            // Add corresponding elements of two same-sized MyArray objects and return a new
            // MyArray containing the result.

            // NOTE: Error handling is needed to check
            // If both arrays are of the same size.

            // 1. Check Array lengths
            // Exit program if lengths are not identical.
            if (this->size != other.getSize())
            {
                cout << "The MyArray objects aren't the same size!" << '\n' ;
                exit(-2) ;
            }

            // 2. Create new array object to return later
            MyArray<T> newArr(size) ;

            // 3. Copy all elements from other array using for loop.
            for (int element = 0 ; element < size ; element++)
            {
                newArr[element] = this->arr[element] + other.arr[element] ;
            }

            // 4. Return the new MyArray object
            return newArr ;
        }

        friend ostream& operator<<(ostream& out, const MyArray& myArr) {
            // Display the array elements inside square brackets and separated by commas, for
            // example [1, 2, 3].

            // 1. Use for loop to iterate through
            // array elements.

            out << "[" ;

            for (int element = 0 ; element < myArr.getSize() ; element++)
            {
                if (element > 0)
                {
                    out << ", " ;
                }
                out << myArr[element] ;
            }

            out << "]" ;
            // 2. Return the stream object
            return out ;
        }

    private:
        // Array pointer and size metadata
        T *arr ;
        int size ;

} ;


// Template main. DO NOT CHANGE!!! 
int main()
{
    // Test with integer arrays
    MyArray<int> array1(3) ;
    array1[0] = 1 ;
    array1[1] = 2 ;
    array1[2] = 3 ;

    MyArray<int> array2(3) ;
    array2[0] = 4 ;
    array2[1] = 5 ;
    array2[2] = 6 ;

    // Display initial arrays
    cout << "array1: " << array1 << endl ;
    cout << "array2: " << array2 << endl ;

    // Test indexing operator and getSize()
    cout << "array1[1]: " << array1[1] << endl ;
    cout << "array1 size: " << array1.getSize() << endl ;

    // Test equality with arrays of different sizes
    MyArray<int> array3(1) ;
    array3[0] = 1 ;
    cout << "array1 == array3 (different sizes): "
         << (array1 == array3 ? "True" : "False") << endl ;

    // Test assignment operator with arrays of different sizes
    array3 = array1 ;
    cout << "array3 (after assignment from array1): " << array3 << endl ;

    // Test equality operator after assignment
    cout << "array1 == array2: " << (array1 == array2 ? "True" : "False") << endl ;
    cout << "array1 == array3: " << (array1 == array3 ? "True" : "False") << endl ;

    // Modify array3 and show that array1 remains unchanged
    array3[1] = 20 ;
    cout << "Modified array3: " << array3 << endl ;
    cout << "array1 (should be unchanged): " << array1 << endl ;
    cout << "array1 == array3 (after modification): "
         << (array1 == array3 ? "True" : "False") << endl ;

    // Test addition operator
    MyArray<int> arraySum = array1 + array2 ;
    cout << "array1 + array2: " << arraySum << endl ;

    // Test with double arrays
    MyArray<double> array4(3) ;
    array4[0] = 1.1 ;
    array4[1] = 2.2 ;
    array4[2] = 3.3 ;
    cout << "array4: " << array4 << endl ;

    // Test copy constructor and verify deep-copy behavior
    MyArray<double> array5 = array4 ;
    cout << "array5 (copied from array4): " << array5 << endl ;

    array5[0] = 9.9 ;
    cout << "Modified array5: " << array5 << endl ;
    cout << "array4 (should be unchanged): " << array4 << endl ;

    // Test addition with double arrays
    MyArray<double> array6 = array4 + array5 ;
    cout << "array4 + array5: " << array6 << endl ;

    return 0 ;
}

/*
Reflection:

    In this assignment I got to learn how to use operator overloading, and template
    classes to create a flexible MyArray object. Similar to Lab08, the MyArray
    object could be deep copied to a new object and it could be compared with another MyArray object
    using the overloaded == operator.

    A challenge I encountered in this assignment was with memory bugs. My initial implementation
    would encounter runtime errors due to a segmentation fault caught by the sanitizers
    I have configured in my build environment (I have been using custom Clang flags in a tasks.json file since the start of the semester). 
    
    Debugging it was a bit tricky as the ASan error log
    didn't have enough information and only printed a line where the crash occurred and that I was
    dereferencing a null pointer. After using AI (see report) to help diagnose and debug, my program ran as intended.
*/