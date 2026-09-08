/******************************************************/
//
// Minnesota State University Moorhead
// Name: Luke Graten
// Student ID: 17013071
// Assignment 01
// Date Modified: 09-08-2026
//
/******************************************************/

# include <iostream>
# include <string>
using namespace std ;

int main () 
{
    // 1. Predefined Numeric Variables
    int defInt1 = 10 ;
    int defInt2 = 5 ;

    float defFloat1 = 5.18 ;
    float defFloat2 = 12.12 ;

    double defDouble1 = 100.219 ;
    double defDouble2 = 50.456 ;

    // 2. Constant
    const int CONST = 100 ;

    // 3. String Usage
    string addName = "Addition" ;
    string subName =  "Subtraction" ;
    string multName = "Multiplication" ;
    string divName = "Divison" ;

    // 4. Arithmetic Operations and Result Variables
    int addInt = defInt1 + defInt2 ;
    float addFloat = defFloat1 + defFloat2 ;
    double addDouble = defDouble1 + defDouble2 ;

    int subInt = defInt1 - defInt2 ;
    float subFloat = defFloat1 - defFloat2 ;
    double subDouble = defDouble1 - defDouble2 ;

    int multInt = defInt1 * defInt2 ;
    float multFloat = defFloat1 * defFloat2 ;
    double multDouble = defDouble1 * defDouble2 ;

    int divInt = defInt1 / defInt2 ;
    float divFloat = defFloat1 / defFloat2 ;
    double divDouble = defDouble1 / defDouble2 ;

    // 5. Boolean Positivity Checks
    bool addIntPos = (addInt > 0) ;
    bool addFloatPos = (addFloat > 0) ;
    bool addDoublePos = (addDouble > 0) ;

    bool subIntPos = (subInt > 0) ;
    bool subFloatPos = (subFloat > 0) ;
    bool subDoublePos = (subDouble > 0) ;

    bool multIntPos = (multInt > 0) ;
    bool multFloatPos = (multFloat > 0) ;
    bool multDoublePos = (multDouble > 0) ;

    bool divIntPos = (divInt > 0) ;
    bool divFloatPos = (divFloat > 0) ;
    bool divDoublePos = (divDouble > 0) ;

    // 6. Memory Sizes and 7. Output
    cout << "Constant integer: " << CONST << '\n' ;

    cout << addName << " (int): " << addInt << " (positive: " << addIntPos << ") (size: " << sizeof(addInt) << " bytes)" << '\n' ;
    cout << addName << " (float): " << addFloat << " (positive: " << addFloatPos << ") (size: " << sizeof(addFloat) << " bytes)" << '\n' ;
    cout << addName << " (double): " << addDouble << " (positive: " << addDoublePos << ") (size: " << sizeof(addDouble) << " bytes)" << '\n' ;

    cout << subName << " (int): " << subInt << " (positive: " << subIntPos << ") (size: " << sizeof(subInt) << " bytes)" << '\n' ;
    cout << subName << " (float): " << subFloat << " (positive: " << subFloatPos << ") (size: " << sizeof(subFloat) << " bytes)" << '\n' ;
    cout << subName << " (double): " << subDouble << " (positive: " << subDoublePos << ") (size: " << sizeof(subDouble) << " bytes)" << '\n' ;

    cout << multName << " (int): " << multInt << " (positive: " << multIntPos << ") (size: " << sizeof(multInt) << " bytes)" << '\n' ;
    cout << multName << " (float): " << multFloat << " (positive: " << multFloatPos << ") (size: " << sizeof(multFloat) << " bytes)" << '\n' ;
    cout << multName << " (double): " << multDouble << " (positive: " << multDoublePos << ") (size: " << sizeof(multDouble) << " bytes)" << '\n' ;

    cout << divName << " (int): " << divInt << " (positive: " << divIntPos << ") (size: " << sizeof(divInt) << " bytes)" << '\n' ;
    cout << divName << " (float): " << divFloat << " (positive: " << divFloatPos << ") (size: " << sizeof(divFloat) << " bytes)" << '\n' ;
    cout << divName << " (double): " << divDouble << " (positive: " << divDoublePos << ") (size: " << sizeof(divDouble) << " bytes)" << '\n' ;
}


/*
Reflection

In this assignment I learned how to:

- Use int, float, double, string, and bool data types
- Use constants
- Apply boolean conditions 
- Use sizeof() to determine the memory size of certain data types

Something I found challenging was keeping my variable names descriptive and short
while adhering to a standard style as they were used across the program. As a solution, I implemented
all variable names in camelCase and used as little words where possible, while keeping them
descriptive.
*/