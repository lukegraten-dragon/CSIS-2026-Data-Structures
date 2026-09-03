// Operations on Pointer Variables

#include <iostream>

using namespace std ;

class studentType {
public:
    string name ;
    int age ;
    double gpa ;

    // Constructor to initialize studentType objects
    studentType(string n, int a, double g)
    {
        name = n ;
        age = a ;
        gpa = g ;
    }
} ;

int main()
{

    int *p, *q ;
    int x = 2, y = 19 ;

    p = &x ;
    q = &y ;

    cout << "p: " << p << endl ; 
    cout << "q: " << q << endl ; 

    if (p == q)
        cout << "p and q point to the same address." << endl ;
    else
        cout << "p and q point to the different addresses." << endl ;

    p = q ;
    cout << "After p = q ;" << endl ;
    if (p == q)
        cout << "p and q point to the same address." << endl ;
    else
        cout << "p and q point to the different addresses." << endl ;

    cout << endl ;

    int *pp ;
    double *qq ;
    char *chPtr ;
    studentType *stdPtr ;

    int xx = 5 ;
    double yy = 18.0 ;
    char ch = 'a' ;

    pp = &xx ;
    qq = &yy ;
    chPtr = &ch ;

    cout << "pp: " << pp << endl ;
    pp++ ;
    cout << "After pp++ ;" << endl << "pp: " << pp << endl ;  // 4 bytes

    cout << "qq: " << qq << endl ;
    qq++ ;
    cout << "After qq++ ;" << endl << "qq: " << qq << endl ; // 8 bytes

    cout << "(void*)chPtr: " << (void*)chPtr << endl ;
    chPtr++ ;
    cout << "After chPtr++ ;" << endl << "(void*)chPtr: " << (void*)chPtr << endl ;  // 1 byte

    /*
    In C++, the reason why we often cast char pointers to (void *) when printing memory addresses, 
    while not needing this cast for int or other types of pointers, comes down to how different 
    data types are handled by cout.

    - What (void *)chPtr Means
      The expression (void *)ptr casts the pointer ptr (which is of type char*) to a void* pointer. 
      In C++, a void* is a "generic" pointer type that can point to any data type, but cannot be 
      dereferenced directly.

      Casting a char* pointer to void* is often done when you want to print the memory address 
      stored in the pointer, rather than having the output system interpret it as a string or 
      character.

    - Why Do We Use (void *) with char*?
      When using cout to print a char* pointer, it has a special behavior: instead of printing 
      the memory address that the pointer holds, it will treat the pointer as a C-style string 
      and print the characters starting at that memory location until it hits 
      a null terminator ('\0'). This is because char* is commonly used in C++ to represent strings.

      Since chPtr is a char*, cout assumes it's the beginning of a string and tries to interpret 
      the data as such, which can result in undefined behavior or strange output (because there 
      is no valid null-terminated string starting at &ch).

      To avoid this, we cast char* to void*, which tells cout to treat the pointer as a generic 
      memory address and simply output the address itself, rather than interpreting it as a string.

    - Why Don't We Need (void *) for int* or Other Pointers?
      For other pointer types like int*, float*, etc., there is no special behavior in cout that 
      treats them as strings, so their values are already treated as memory addresses by default 
      when printed.

    - Summary
      - char* pointers are treated as C-style strings by cout, so to print the memory address stored 
        in a char* pointer, you cast it to void*.
      - Other pointer types (e.g., int*, float*) don't have this special behavior, so you can directly 
        print the pointer without casting it to void*.
    
    By using (void *)chPtr, you're ensuring that the pointer is printed as an address rather than 
    being misinterpreted as a string.

    */

    // Initializing the array of studentType objects using the constructor
    studentType students[3] = {
        studentType("John", 20, 3.5),
        studentType("Alice", 21, 3.8),
        studentType("Bob", 19, 3.6)
    } ;

    // Size of students[0]
    cout << "sizeof(students[0]): " << sizeof(students[0]) << endl ;
    cout << "sizeof(students[1]): " << sizeof(students[1]) << endl ;
    cout << "sizeof(students[2]): " << sizeof(students[2]) << endl ;

    // Example of Pointer Arithmetic with studentType*
    stdPtr = students ;  // stdPtr points to the first element of the array

    cout << "stdPtr (points to first student): " << stdPtr << endl ;
    cout << "Name: " << stdPtr->name << ", Age: " << stdPtr->age << ", GPA: " << stdPtr->gpa << endl ;

    stdPtr++ ;  // Move the pointer to the next student

    cout << "After stdPtr++ (points to second student): " << stdPtr << endl ;
    cout << "Name: " << stdPtr->name << ", Age: " << stdPtr->age << ", GPA: " << stdPtr->gpa << endl ;

    stdPtr++ ;  // Move the pointer to the next student

    cout << "After stdPtr++ (points to third student): " << stdPtr << endl ;
    cout << "Name: " << stdPtr->name << ", Age: " << stdPtr->age << ", GPA: " << stdPtr->gpa << endl ;

    /*
    The size of a class in C++ depends on several factors, including the sizes of its member variables 
    and memory alignment (also known as padding). To determine the exact size of studentType, we need 
    to consider the following:

    Factors that Affect the Size:
    1. Member Variables:

      - std::string name: The size of a std::string is not just the characters in the string, but also 
        the overhead for managing the string (e.g., a pointer to the character array, size, capacity, etc.).
      - int age: Typically 4 bytes (on most systems).
      - double gpa: Typically 8 bytes (on most systems).
    
    2. Padding and Alignment:

      - The compiler often inserts padding to ensure that data members are aligned according to their types. 
        For example, a double usually requires 8-byte alignment, so if it's placed after a member that 
        requires only 4-byte alignment, there may be 4 bytes of padding inserted.
    
    To get the actual size of studentType, you can use the sizeof operator in C++.
    
    Output:
    This will print the size of the studentType class in bytes, based on the system you're running it on.

    Estimating the Size:
    Here’s a rough estimate of the sizes of the member variables:

    - std::string name: The size of a std::string typically includes a pointer to the character data, size, 
      and capacity. On most systems, this can be 24 or 32 bytes (depending on the implementation and platform).
    - int age: 4 bytes.
    - double gpa: 8 bytes.
    
    Estimated Total Size:
    - Assuming 24 bytes for the std::string (it can vary), plus 4 bytes for int, plus 8 bytes for double, 
      the total size without considering padding would be around 36 bytes.
    - However, due to alignment requirements, the compiler may insert padding, potentially increasing 
      the size beyond 36 bytes (possibly 40 or more, depending on the system)
    
    Actual Size:
    - You can run the above code to find the exact size on your system. The result will depend on how 
      the compiler aligns the data members and the platform's architecture (e.g., 32-bit vs 64-bit).
    - For smoke, 48 bytes.

    */

    return 0 ;
}