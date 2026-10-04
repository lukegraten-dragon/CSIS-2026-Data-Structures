/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Course: CSIS 255
// Lab 05 Part 2
// Date Modified: 10-04-2026
//
/******************************************************/

# include <iostream>
using namespace std ;

void increment (int& integer) {
    // Uses Pass-By-Reference (PBR)

    integer++ ;
}

void displayValues (const int& integer)
{
    
}


int main ()
{
    int numOne = 0 ;
    int numTwo = 0 ;

    cout << "Enter the first number: " ;
    cin >> numOne ;
    cout << "Enter the second number: " ;
    cin >> numTwo ;

    // Before incrementing
    cout << "Before incrementing:" << '\n' ;
    cout << "*** num1 = " << numOne << '\n' ;
    cout << "*** num2 = " << numTwo << '\n' ;

    // Increment variables via PBR
    increment(numOne) ;

    // After Incrementing
    cout << "After incrementing:" << '\n' ;
    cout << "*** num1 = " << numOne << '\n' ;
    cout << "*** num2 = " << numTwo << '\n' ;


    return 0 ;
}

/*
Post Lab Reflection:

*/